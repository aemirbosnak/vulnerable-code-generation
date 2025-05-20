//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int key;
    struct node* left;
    struct node* right;
} node;

node* create_node(int key) {
    node* temp = (node*) malloc(sizeof(node));
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node* insert(node* root, int key) {
    if(root == NULL) {
        return create_node(key);
    }
    if(key < root->key) {
        root->left = insert(root->left, key);
    } else if(key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

void visualize_tree(node* root, int space) {
    if(root == NULL) {
        return;
    }
    space += 10;
    visualize_tree(root->right, space);
    printf("\n");
    for(int i=10; i<space; i++) {
        printf(" ");
    }
    printf("%d\n", root->key);
    visualize_tree(root->left, space);
}

int main() {
    node* root = NULL;
    int n, key;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the node keys: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &key);
        root = insert(root, key);
    }
    printf("Tree Visualization:");
    visualize_tree(root, 0);
    return 0;
}