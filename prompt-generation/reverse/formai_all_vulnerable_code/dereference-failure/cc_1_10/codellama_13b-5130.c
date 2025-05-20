//Code Llama-13B DATASET v1.0 Category: Huffman Coding Implementation ; Style: accurate
/*
 * Huffman Coding Implementation in C
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a node in the Huffman tree
typedef struct Node {
    char symbol;
    int frequency;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* newNode(char symbol, int frequency) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->symbol = symbol;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to build the Huffman tree
Node* buildTree(int* frequencies) {
    int n = sizeof(frequencies) / sizeof(frequencies[0]);
    Node* nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = newNode(i, frequencies[i]);
    }

    // Sort the nodes by frequency
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nodes[i]->frequency > nodes[j]->frequency) {
                Node* temp = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = temp;
            }
        }
    }

    // Build the Huffman tree
    while (n > 1) {
        Node* left = nodes[0];
        Node* right = nodes[1];
        Node* parent = newNode('0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        nodes[0] = parent;
        n--;
    }

    return nodes[0];
}

// Function to encode the input string
void encode(Node* root, char* input, int* code) {
    int i = 0;
    while (input[i] != '\0') {
        Node* node = root;
        while (node->left != NULL) {
            if (node->symbol == input[i]) {
                code[i] = node->frequency;
                break;
            }
            if (input[i] < node->symbol) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        i++;
    }
}

// Function to decode the encoded string
void decode(Node* root, int* code, char* output) {
    int i = 0;
    while (code[i] != '\0') {
        Node* node = root;
        while (node->left != NULL) {
            if (node->frequency == code[i]) {
                output[i] = node->symbol;
                break;
            }
            if (code[i] < node->frequency) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        i++;
    }
}

// Main function
int main() {
    char input[] = "hello world";
    int frequencies[] = { 5, 7, 8, 12, 15, 18, 20, 25 };
    Node* root = buildTree(frequencies);
    int code[strlen(input)];
    encode(root, input, code);
    char output[strlen(input)];
    decode(root, code, output);
    printf("Encoded string: ");
    for (int i = 0; i < strlen(input); i++) {
        printf("%d ", code[i]);
    }
    printf("\n");
    printf("Decoded string: %s\n", output);
    return 0;
}