//Code Llama-13B DATASET v1.0 Category: Huffman Coding Implementation ; Style: curious
// Huffman Coding Implementation in C
// Curious Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Huffman Tree Node Structure
typedef struct node {
    char value;
    int frequency;
    struct node *left;
    struct node *right;
} Node;

// Huffman Tree Structure
typedef struct tree {
    Node *root;
    int size;
} Tree;

// Create a new node with the given value and frequency
Node *createNode(char value, int frequency) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a new node into the Huffman tree
void insertNode(Tree *tree, Node *node) {
    if (tree->root == NULL) {
        tree->root = node;
        tree->size++;
        return;
    }

    Node *current = tree->root;
    while (current != NULL) {
        if (current->frequency > node->frequency) {
            if (current->left == NULL) {
                current->left = node;
                tree->size++;
                return;
            }
            current = current->left;
        } else {
            if (current->right == NULL) {
                current->right = node;
                tree->size++;
                return;
            }
            current = current->right;
        }
    }
}

// Build the Huffman tree from the given frequency table
Tree *buildTree(int *frequencies, int size) {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->size = 0;

    for (int i = 0; i < size; i++) {
        insertNode(tree, createNode(i, frequencies[i]));
    }

    return tree;
}

// Encode the given string using the Huffman tree
char *encode(Tree *tree, char *str) {
    char *encoded = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    char *current = encoded;

    for (int i = 0; i < strlen(str); i++) {
        Node *node = tree->root;
        while (node != NULL) {
            if (node->value == str[i]) {
                break;
            } else if (node->value < str[i]) {
                node = node->right;
            } else {
                node = node->left;
            }
        }

        if (node == NULL) {
            printf("Error: character not found in tree\n");
            return NULL;
        }

        while (node != tree->root) {
            if (node->left == NULL) {
                *current++ = '0';
                node = node->right;
            } else {
                *current++ = '1';
                node = node->left;
            }
        }

        *current++ = '1';
    }

    *current = '\0';
    return encoded;
}

// Decode the given encoded string using the Huffman tree
char *decode(Tree *tree, char *encoded) {
    char *decoded = (char *)malloc(sizeof(char) * (strlen(encoded) + 1));
    char *current = decoded;

    Node *node = tree->root;
    for (int i = 0; i < strlen(encoded); i++) {
        if (encoded[i] == '0') {
            node = node->left;
        } else {
            node = node->right;
        }

        if (node->left == NULL && node->right == NULL) {
            *current++ = node->value;
            node = tree->root;
        }
    }

    *current = '\0';
    return decoded;
}

int main() {
    // Example frequency table
    int frequencies[] = {5, 9, 12, 13, 16, 45};

    // Build the Huffman tree
    Tree *tree = buildTree(frequencies, sizeof(frequencies) / sizeof(int));

    // Encode the string "hello world"
    char *encoded = encode(tree, "hello world");
    printf("Encoded string: %s\n", encoded);

    // Decode the encoded string
    char *decoded = decode(tree, encoded);
    printf("Decoded string: %s\n", decoded);

    return 0;
}