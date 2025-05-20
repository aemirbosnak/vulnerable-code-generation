//FormAI DATASET v1.0 Category: Binary search trees ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
} Tree_Node;

Tree_Node* create_node(int data) {
    Tree_Node* new_node = (Tree_Node*)malloc(sizeof(Tree_Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Tree_Node* insert_node(Tree_Node* root, int data) {
    if (root == NULL) {
        root = create_node(data);
    } else if (data <= root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

bool find_node(Tree_Node* root, int data) {
    if (root == NULL) {
        return false;
    } else if (root->data == data) {
        return true;
    } else if (data < root->data) {
        return find_node(root->left, data);
    } else {
        return find_node(root->right, data);
    }
}

void inorder(Tree_Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Tree_Node* root = NULL;
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 70);
    root = insert_node(root, 60);
    root = insert_node(root, 80);
    
    printf("Inorder traversal of binary search tree is: ");
    inorder(root);
    
    int data;
    printf("\nEnter a number to search: ");
    scanf("%d", &data);
    
    if (find_node(root, data)) {
        printf("%d is found in binary search tree.\n", data);
    } else {
        printf("%d is not found in binary search tree.\n", data);
    }
    
    return 0;
}