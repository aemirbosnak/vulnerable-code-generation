//FormAI DATASET v1.0 Category: Binary search trees ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

struct Node{ // defining a structure for binary search tree node
    int data; 
    struct Node *left; // pointer to left child
    struct Node *right; // pointer to right child
};

// function to create a new node and initialize its data and its left and right child pointers
struct Node* createNode(int value){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); //creating dynamic memory allocation
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// function to insert a new node in BST
struct Node* insert(struct Node* root, int value){
    if(root == NULL){ // If the tree is empty, return a new node
        return createNode(value);
    }
    if(value < root->data){ //if the given value is less than the root value, recur for the left subtree
        root->left = insert(root->left, value);
    }
    else{ // else, recur for the right subtree
        root->right = insert(root->right, value);
    }
    return root;
}

// function to traverse the tree in inorder (left, root, right)
void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    struct Node *root = NULL;  // pointer to the root node
    int value;
    char choice = 'y';
    printf("Welcome to Binary Search Tree Program!\n");
    while(choice == 'y'){ // continue taking input until user wishes to add more nodes
        printf("\nPlease enter a new node value: ");
        scanf("%d", &value);
        root = insert(root, value); //inserting value in the BST
        printf("\nDo you want to add another node? (y/n): ");
        scanf(" %c", &choice);
    }
    printf("\nInorder Traversal of Binary Search Tree: ");
    inorder(root); //traversing the BST in inorder
    return 0;
}