//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int getHeight(struct node* root)
{
    if(root==NULL)
        return 0;
    else
    {
        int lheight = getHeight(root->left);
        int rheight = getHeight(root->right);
        return (lheight>rheight)? lheight+1 : rheight+1;
    }
}
void inorder(struct node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder(struct node* root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node* root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void levelOrder(struct node* root)
{
    if(root==NULL)
        return;
    struct node* temp = root;
    struct node* q[MAX];
    q[0] = temp;
    int level = 1;
    while(q[level-1]!=NULL && q[level]!=NULL)
    {
        printf("%d ",q[level]->data);
        if(q[level]->left!=NULL)
            q[level+1] = q[level]->left;
        if(q[level]->right!=NULL)
            q[level+1] = q[level]->right;
        level++;
    }
}
int main()
{
    int n,choice,data;
    struct node* root = NULL;
    printf("1.Inorder traversal\n2.Preorder traversal\n3.Postorder traversal\n4.Level order traversal\n5.Exit\n");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nInorder traversal of binary tree: "); inorder(root); printf("\n");
                    break;
            case 2: printf("\nPreorder traversal of binary tree: "); preorder(root); printf("\n");
                    break;
            case 3: printf("\nPostorder traversal of binary tree: "); postorder(root); printf("\n");
                    break;
            case 4: printf("\nLevel order traversal of binary tree: "); levelOrder(root); printf("\n");
                    break;
            case 5: exit(0);
            default: printf("\nWrong Choice!! Try Again!!");
        }
    }while(choice!=5);
    return 0;
}