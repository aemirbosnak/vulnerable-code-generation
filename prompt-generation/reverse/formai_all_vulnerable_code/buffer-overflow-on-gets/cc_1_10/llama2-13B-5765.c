//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MIN_LENGTH 10

// Structure to store the tree nodes
typedef struct node {
    char data[MAX_LENGTH];
    struct node *left;
    struct node *right;
} node_t;

// Function to create a new node
node_t *new_node(char *data) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    strcpy(node->data, data);
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the tree
void insert_node(node_t **root, char *data) {
    if (*root == NULL) {
        *root = new_node(data);
    } else {
        if (strcmp((*root)->data, data) < 0) {
            insert_node(&(*root)->left, data);
        } else {
            insert_node(&(*root)->right, data);
        }
    }
}

// Function to traverse the tree
void traverse(node_t *root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%s\n", root->data);
        traverse(root->right);
    }
}

int main() {
    srand(time(NULL));
    node_t *root = NULL;

    for (int i = 0; i < 10; i++) {
        char data[MAX_LENGTH];
        gets(data);
        insert_node(&root, data);
    }

    traverse(root);

    return 0;
}