//Code Llama-13B DATASET v1.0 Category: Huffman Coding Implementation ; Style: excited
// Huffman Coding Implementation in C
// By Excited Student

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a node in the Huffman tree
typedef struct node {
    char data;
    int weight;
    struct node *left;
    struct node *right;
} node;

// Function to create a new node
node *create_node(char data, int weight) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->weight = weight;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to build the Huffman tree
node *build_tree(char *str) {
    int len = strlen(str);
    node *root = create_node(str[0], 1);
    for (int i = 1; i < len; i++) {
        root = create_node(str[i], 1);
        root->left = root;
        root->right = root;
    }
    return root;
}

// Function to traverse the Huffman tree
void traverse(node *root) {
    if (root == NULL) {
        return;
    }
    traverse(root->left);
    traverse(root->right);
    printf("%c", root->data);
}

// Function to encode a string
char *encode(char *str, node *root) {
    int len = strlen(str);
    char *encoded = (char *)malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        node *curr = root;
        while (curr != NULL) {
            if (str[i] == curr->data) {
                encoded[i] = curr->data;
                break;
            } else if (str[i] < curr->data) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }
    return encoded;
}

// Function to decode a string
char *decode(char *str, node *root) {
    int len = strlen(str);
    char *decoded = (char *)malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        node *curr = root;
        while (curr != NULL) {
            if (str[i] == curr->data) {
                decoded[i] = curr->data;
                break;
            } else if (str[i] < curr->data) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }
    return decoded;
}

// Driver code
int main() {
    char *str = "hello";
    node *root = build_tree(str);
    char *encoded = encode(str, root);
    printf("Encoded string: %s\n", encoded);
    char *decoded = decode(encoded, root);
    printf("Decoded string: %s\n", decoded);
    return 0;
}