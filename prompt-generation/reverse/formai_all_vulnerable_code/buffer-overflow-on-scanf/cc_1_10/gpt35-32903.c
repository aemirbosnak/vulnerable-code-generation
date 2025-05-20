//FormAI DATASET v1.0 Category: Binary search trees ; Style: brave
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};

typedef struct Node node;

node * createNode(int value){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node * createBST(node *root, int value){
    if(root == NULL){
        return createNode(value);
    }else if(value < root->data){
        root->left = createBST(root->left, value);
    }else if(value > root->data){
        root->right = createBST(root->right, value);
    }
    return root;
}

void inOrderTraversal(node *root){
    if(root != NULL){
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);   
    }
}

int main(){
    node *root = NULL;
    int size, value;
    printf("Enter the size of the Binary Search Tree: ");
    scanf("%d", &size);
    printf("Enter %d values to create BST: ", size);
    for(int i=0;i<size;i++){
        scanf("%d", &value);
        root = createBST(root, value);
    }
    printf("\nIn-order Traversal of Binary Search Tree: ");
    inOrderTraversal(root);
    printf("\n");
    return 0;
}