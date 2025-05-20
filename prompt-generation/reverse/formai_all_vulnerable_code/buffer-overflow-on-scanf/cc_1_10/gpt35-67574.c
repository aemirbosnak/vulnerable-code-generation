//FormAI DATASET v1.0 Category: Binary search trees ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) { 
        root = createNode(data); 
    }
    else if (data <= root->data) { 
        root->left = insert(root->left, data); 
    }
    else { 
        root->right = insert(root->right, data); 
    }
    return root; 
}

void preOrder(Node* root) { 
    if (root == NULL) 
        return; 
    printf("%d ", root->data); 
    preOrder(root->left); 
    preOrder(root->right); 
} 

int main() {
    printf("Welcome to the Binary Search Tree Program!\n");
    printf("Please enter the number of nodes you want to create: ");
    int n;
    scanf("%d", &n);
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        printf("Enter node data: ");
        int data;
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("Pre-order Traversal of BST: ");
    preOrder(root);
    printf("\nThank you for using the program.\n");
    return 0;
}