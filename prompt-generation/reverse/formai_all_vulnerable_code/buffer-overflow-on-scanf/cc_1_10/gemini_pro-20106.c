//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#define MAX_TREE_SIZE 256

typedef struct huffman_node {
    int frequency;
    int code;
    struct huffman_node *left;
    struct huffman_node *right;
} huffman_node;

typedef struct huffman_tree {
    int size;
    huffman_node *nodes[MAX_TREE_SIZE];
} huffman_tree;

void create_tree(const int *frequencies, huffman_tree *tree);
void encode(const huffman_tree *tree, const char *input, char *output);
void decode(const huffman_tree *tree, const char *input, char *output);
void print_tree(const huffman_tree *tree);
void free_tree(huffman_tree *tree);

int main() {
    int frequencies[256] = {0};

    // Read the input string
    char input[1024];
    printf("Enter the string to be compressed:\n");
    scanf("%s", input);

    // Calculate the frequencies of each character
    for (int i = 0; input[i]; i++) {
        frequencies[input[i]]++;
    }

    // Create the Huffman tree
    huffman_tree tree;
    create_tree(frequencies, &tree);

    // Encode the input string
    char output[1024];
    encode(&tree, input, output);

    // Print the encoded string
    printf("Encoded string:\n%s\n", output);

    // Decode the encoded string
    char decoded[1024];
    decode(&tree, output, decoded);

    // Print the decoded string
    printf("Decoded string:\n%s\n", decoded);

    // Print the Huffman tree
    print_tree(&tree);

    // Free the Huffman tree
    free_tree(&tree);

    return 0;
}

void create_tree(const int *frequencies, huffman_tree *tree) {
    // Initialize the tree
    tree->size = 0;
    for (int i = 0; i < MAX_TREE_SIZE; i++) {
        tree->nodes[i] = NULL;
    }

    // Create a queue of nodes
    huffman_node *nodes[MAX_TREE_SIZE];
    int front = 0;
    int rear = -1;

    // Insert the nodes into the queue
    for (int i = 0; i < MAX_TREE_SIZE; i++) {
        if (frequencies[i] > 0) {
            huffman_node *node = malloc(sizeof(huffman_node));
            node->frequency = frequencies[i];
            node->code = 0;
            node->left = NULL;
            node->right = NULL;
            nodes[++rear] = node;
        }
    }

    // Build the Huffman tree
    while (front <= rear) {
        // Get the two nodes with the smallest frequencies
        huffman_node *left = nodes[front++];
        huffman_node *right = nodes[front++];

        // Create a new node
        huffman_node *parent = malloc(sizeof(huffman_node));
        parent->frequency = left->frequency + right->frequency;
        parent->code = 0;
        parent->left = left;
        parent->right = right;

        // Insert the new node into the queue
        int i = front;
        while (i <= rear && parent->frequency > nodes[i]->frequency) {
            i++;
        }
        for (int j = rear; j >= i; j--) {
            nodes[j + 1] = nodes[j];
        }
        nodes[i] = parent;
        rear++;
    }

    // Set the root of the tree
    tree->nodes[0] = nodes[front];
    tree->size++;
}

void encode(const huffman_tree *tree, const char *input, char *output) {
    // Initialize the output string
    output[0] = '\0';

    // Encode each character in the input string
    for (int i = 0; input[i]; i++) {
        huffman_node *node = tree->nodes[0];
        while (node->left || node->right) {
            if (input[i] & (1 << (7 - node->code))) {
                node = node->right;
            } else {
                node = node->left;
            }
            node->code++;
        }
        strcat(output, node->code);
    }
}

void decode(const huffman_tree *tree, const char *input, char *output) {
    // Initialize the output string
    output[0] = '\0';

    // Decode each bit in the input string
    huffman_node *node = tree->nodes[0];
    for (int i = 0; input[i]; i++) {
        if (input[i] == '0') {
            node = node->left;
        } else if (input[i] == '1') {
            node = node->right;
        }
        if (!node->left && !node->right) {
            output[strlen(output)] = node->code;
            node = tree->nodes[0];
        }
    }
}

void print_tree(const huffman_tree *tree) {
    // Print the nodes of the tree
    for (int i = 0; i < tree->size; i++) {
        huffman_node *node = tree->nodes[i];
        if (node->left) {
            printf("%d -> %d (0)\n", node->code, node->left->code);
        }
        if (node->right) {
            printf("%d -> %d (1)\n", node->code, node->right->code);
        }
    }
}

void free_tree(huffman_tree *tree) {
    // Free the nodes of the tree
    for (int i = 0; i < tree->size; i++) {
        free(tree->nodes[i]);
    }

    // Free the tree itself
    free(tree);
}