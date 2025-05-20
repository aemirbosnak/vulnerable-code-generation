//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

// Function prototype
Node* createNode(int data);
void insertNode(Tree* tree, int data);
void printTree(Node* node, int space);
int height(Node* node);
int countLeaves(Node* node);
void visualizeTree(Tree* tree);

int main() {
    Tree tree;
    tree.root = NULL;

    int data;
    printf("Enter numbers to insert into the binary tree (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) break;
        insertNode(&tree, data);
    }

    printf("\nVisualizing the Binary Tree:\n");
    visualizeTree(&tree);

    return 0;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insertNode(Tree* tree, int data) {
    Node* newNode = createNode(data);
    if (tree->root == NULL) {
        tree->root = newNode;
        return;
    }

    Node* current = tree->root;
    Node* parent = NULL;

    while (1) {
        parent = current;
        if (data < current->data) {
            current = current->left;
            if (current == NULL) {
                parent->left = newNode;
                return;
            }
        } else {
            current = current->right;
            if (current == NULL) {
                parent->right = newNode;
                return;
            }
        }
    }
}

void printTree(Node* node, int space) {
    if (node == NULL) return;

    space += 5; // Increase distance between levels

    printTree(node->right, space); // Process right child first

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" "); // Print space denoting level
    printf("%d\n", node->data); // Print node's data

    printTree(node->left, space); // Process left child
}

int height(Node* node) {
    if (node == NULL)
        return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int countLeaves(Node* node) {
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    
    return countLeaves(node->left) + countLeaves(node->right);
}

void visualizeTree(Tree* tree) {
    int treeHeight = height(tree->root);
    printf("Tree Height: %d\n", treeHeight);
    printf("Number of Leaves: %d\n", countLeaves(tree->root));
    printTree(tree->root, 0);
}