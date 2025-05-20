//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Define the binary search tree structure
typedef struct Tree {
    Node* root;
} Tree;

// Create a new node with the given data
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Create a new binary search tree
Tree* create_tree() {
    Tree* new_tree = (Tree*) malloc(sizeof(Tree));
    if (new_tree == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_tree->root = NULL;
    return new_tree;
}

// Insert a node with the given data into the tree
void insert_node(Tree* tree, int data) {
    if (tree->root == NULL) {
        tree->root = create_node(data);
    } else {
        Node* current = tree->root;
        while (true) {
            if (data < current->data) {
                if (current->left == NULL) {
                    current->left = create_node(data);
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == NULL) {
                    current->right = create_node(data);
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
}

// Print the tree in order traversal
void print_tree(Node* node) {
    if (node == NULL) {
        return;
    }
    print_tree(node->left);
    printf("%d ", node->data);
    print_tree(node->right);
}

// Main function
int main() {
    srand(time(NULL));
    int num_nodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    Tree* tree = create_tree();
    for (int i = 0; i < num_nodes; i++) {
        int data = rand() % 100;
        insert_node(tree, data);
    }
    printf("The tree in order traversal:\n");
    print_tree(tree->root);
    return 0;
}