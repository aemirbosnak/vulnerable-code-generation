//FormAI DATASET v1.0 Category: Binary search trees ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>

// defining a node for the Binary search tree
struct node{
    int data;
    struct node* left;
    struct node* right;
};

// function to create a new node with given data
struct node* create_node(int key){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = key;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// function to insert a new node having given key in the Binary search tree
struct node* insert(struct node* root, int key){
    if(root == NULL){
        return create_node(key);
    }
    if(key < root->data){
        root->left = insert(root->left, key);
    }
    else if(key > root->data){
        root->right = insert(root->right, key);
    }
    return root;
}

// function to traverse the Binary search tree in inorder manner
void inorder_traversal(struct node* root){
    if(root != NULL){
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int main(){
    struct node* root = NULL;
    int n;
    printf("Enter the total number of elements to be inserted: ");
    scanf("%d", &n);
    printf("Enter the elements (space separated): ");
    for(int i=0; i<n; i++){
        int key;
        scanf("%d", &key);
        root = insert(root, key);
    }
    printf("Binary Search Tree in Inorder manner: ");
    inorder_traversal(root);
    return 0;
}