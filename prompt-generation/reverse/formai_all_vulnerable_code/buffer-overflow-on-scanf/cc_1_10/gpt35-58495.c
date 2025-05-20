//FormAI DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

//Struct to represent a node in the Binary Tree
struct BinaryTreeNode{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

//Function to create a new Binary Tree node
struct BinaryTreeNode* newBinaryTreeNode(int data){
    struct BinaryTreeNode* node = (struct BinaryTreeNode*) malloc(sizeof(struct BinaryTreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

//Function to insert a new node in the Binary Tree
struct BinaryTreeNode* insertBinaryTreeNode(struct BinaryTreeNode* node, int data){
    if(node==NULL)
        return(newBinaryTreeNode(data));
    else{
        if(data <= node->data)
            node->left = insertBinaryTreeNode(node->left, data);
        else
            node->right = insertBinaryTreeNode(node->right, data);
        return(node);
    }
}

//Function to print the Binary Tree in InOrder Traversal
void printInOrderTraversal(struct BinaryTreeNode* node){
    if(node==NULL)
        return;
    printInOrderTraversal(node->left);
    printf("%d ",node->data);
    printInOrderTraversal(node->right);
}

//Main function
int main(){
    struct BinaryTreeNode *root = NULL;
    printf("Welcome to the visualizer program for Binary Tree data structure!\n\n");
    printf("The program allows you to enter elements of Binary Tree and then prints it in the InOrder Traversal.\n\n");
    printf("How many nodes do you want to insert in the Binary Tree? : ");
    int n; scanf("%d",&n);
    printf("\n");
    for(int i=1; i<=n; i++){
        printf("Enter node %d : ",i);
        int x; scanf("%d",&x);
        root = insertBinaryTreeNode(root, x);
    }
    printf("\nBinary Tree in InOrder traversal : ");
    printInOrderTraversal(root);
    printf("\n");
    return 0;
}