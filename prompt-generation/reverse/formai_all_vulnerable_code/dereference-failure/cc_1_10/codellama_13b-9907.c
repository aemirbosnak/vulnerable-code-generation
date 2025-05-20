//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

// Define the tree structure
typedef struct tree {
    Node *root;
    int size;
} Tree;

// Create a new node
Node* newNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a node into the tree
void insert(Tree *tree, int data) {
    if (tree->root == NULL) {
        tree->root = newNode(data);
        tree->size++;
    } else {
        Node *curr = tree->root;
        while (curr != NULL) {
            if (curr->data > data) {
                if (curr->left == NULL) {
                    curr->left = newNode(data);
                    tree->size++;
                    break;
                }
                curr = curr->left;
            } else {
                if (curr->right == NULL) {
                    curr->right = newNode(data);
                    tree->size++;
                    break;
                }
                curr = curr->right;
            }
        }
    }
}

// Find the node with the given data
Node* find(Tree *tree, int data) {
    if (tree->root == NULL) {
        return NULL;
    } else {
        Node *curr = tree->root;
        while (curr != NULL) {
            if (curr->data == data) {
                return curr;
            } else if (curr->data > data) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return NULL;
    }
}

// Delete the node with the given data
void delete(Tree *tree, int data) {
    Node *curr = find(tree, data);
    if (curr != NULL) {
        Node *parent = NULL;
        if (curr->left == NULL && curr->right == NULL) {
            if (curr == tree->root) {
                tree->root = NULL;
            } else if (parent->left == curr) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
            free(curr);
            tree->size--;
        } else if (curr->left == NULL) {
            if (curr == tree->root) {
                tree->root = curr->right;
            } else if (parent->left == curr) {
                parent->left = curr->right;
            } else {
                parent->right = curr->right;
            }
            free(curr);
            tree->size--;
        } else if (curr->right == NULL) {
            if (curr == tree->root) {
                tree->root = curr->left;
            } else if (parent->left == curr) {
                parent->left = curr->left;
            } else {
                parent->right = curr->left;
            }
            free(curr);
            tree->size--;
        } else {
            Node *min = curr->right;
            while (min->left != NULL) {
                min = min->left;
            }
            curr->data = min->data;
            delete(tree, min->data);
        }
    }
}

// Print the tree inorder
void printInorder(Tree *tree) {
    if (tree->root != NULL) {
        printInorder(tree->root->left);
        printf("%d ", tree->root->data);
        printInorder(tree->root->right);
    }
}

int main() {
    Tree *tree = (Tree*)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->size = 0;

    insert(tree, 10);
    insert(tree, 20);
    insert(tree, 30);
    insert(tree, 40);
    insert(tree, 50);
    insert(tree, 25);

    printInorder(tree);
    printf("\n");

    delete(tree, 20);
    printInorder(tree);
    printf("\n");

    delete(tree, 10);
    printInorder(tree);
    printf("\n");

    delete(tree, 40);
    printInorder(tree);
    printf("\n");

    delete(tree, 50);
    printInorder(tree);
    printf("\n");

    delete(tree, 30);
    printInorder(tree);
    printf("\n");

    delete(tree, 25);
    printInorder(tree);
    printf("\n");

    return 0;
}