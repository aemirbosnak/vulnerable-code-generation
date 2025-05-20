//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>

//Node structure definition
struct node{
    int data;
    struct node* left;
    struct node* right;
};

//Function to create a new node with given data
struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//Function to insert data into the BST
struct node* insert(struct node* root, int data){
    if(root == NULL){
        return newNode(data);
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    }
    else if(data > root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

//Function to search for a node with given data
struct node* search(struct node* root, int data){
    if(root == NULL || root->data == data){
        return root;
    }
    if(data < root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}

//Function to print the BST inorder
void inorder(struct node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

//Main function
int main(){
    struct node* root = NULL;

    //Inserting nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    //Printing BST inorder
    printf("Inorder traversal of the BST is - ");
    inorder(root);
    printf("\n");

    //Searching for a node
    struct node* searchNode = search(root, 40);
    if(searchNode!= NULL){
        printf("Node with data %d found in the BST\n", searchNode->data);
    }
    else{
        printf("Node with data %d not found in the BST\n", 40);
    }

    return 0;
}