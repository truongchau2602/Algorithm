#include<iostream>
using namespace std;

class BST
{
public:
    int key;
    BST* parent;
    BST* left_subtree;
    BST* right_subtree;
    BST();
    BST(int root)
    {
          key = root;
          left_subtree=NULL;
          right_subtree=NULL;
    };

    void PostorderTreeWalk(BST* node)
    {

        if(node == NULL)
        {
            //cout<<"Null"<<endl;
            return;
        }
        PostorderTreeWalk(node->left_subtree);
        PostorderTreeWalk(node->right_subtree);
        cout<<"Node: "<<node->key<<endl;
    }

    void Inorder(BST* root)
    {
        if (!root) {
            return;
        }
        //cout<<"Algorithm stands at:"<<root->key<<endl;
        Inorder(root->left_subtree);
        cout << root->key << endl;
        Inorder(root->right_subtree);
    }

     void TreeSearch(BST* x, int k) // from node x, search for a key k
    {
        if(x==NULL)
        {
            cout<<"Cannot find x in tree";
            return;
        }

        cout<<"Algorithm travels at:"<<x->key<<endl;

        if(x->key == k)
        {
            cout<<"Find "<<x->key<<endl;

        }
        if (k < x->key) TreeSearch(x->left_subtree,k);
        if (k > x->key) TreeSearch(x->right_subtree,k);
    }
    BST* Tree_Minimum(BST* x)
    {
        while (x->left_subtree != NULL)
        {
            x = x->left_subtree;
        }
        return x;

    }

    BST* Tree_Maximum(BST* x)
    {
        while (x->right_subtree != NULL)
        {
            x = x->right_subtree;
        }
        return x;

    }
    BST* Insert(BST* root, int value)
    {
        if(root==NULL)
        {
            cout<<"Successfully at:"<<value<<endl;
            return new BST(value);
        }

        if(value > root->key)
        {
            root->right_subtree = Insert(root->right_subtree, value);
            root->right_subtree->parent = root;
        }
        else
        {
            root->left_subtree= Insert(root->left_subtree, value);
            root->left_subtree->parent = root;
        }
        cout<<"Final transfer to: "<<root->key<<endl;
        return root;
    }


};
BST ::BST()
	: key(0)
	, left_subtree(NULL)
	, right_subtree(NULL)
{
}

int main()
{

    BST b, *root = NULL;
    root = b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);

    b.Inorder(root);

}
