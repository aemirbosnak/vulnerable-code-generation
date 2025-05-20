//Code Llama-13B DATASET v1.0 Category: Huffman Coding Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256
#define MAX_CODE_LENGTH 32

// Structure to store a node in the Huffman tree
typedef struct {
    int weight;
    char code[MAX_CODE_LENGTH];
    int code_length;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node with the given weight
Node* newNode(int weight) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->weight = weight;
    node->code_length = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to create a new leaf node with the given character and weight
Node* newLeafNode(char ch, int weight) {
    Node* node = newNode(weight);
    node->code[0] = ch;
    node->code_length = 1;
    return node;
}

// Function to merge two nodes with the given weights
Node* mergeNodes(Node* left, Node* right) {
    Node* node = newNode(left->weight + right->weight);
    node->left = left;
    node->right = right;
    return node;
}

// Function to encode a character using the Huffman code
void encode(char ch, Node* root, char* code, int code_length) {
    if (root == NULL) {
        return;
    }
    if (root->code_length == 0) {
        root->code[0] = ch;
        root->code_length = 1;
    } else {
        encode(ch, root->left, code, code_length);
        encode(ch, root->right, code, code_length);
    }
}

// Function to decode a character using the Huffman code
char decode(char* code, int code_length, Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->code_length == code_length) {
        return root->code[0];
    } else {
        return decode(code, code_length, root->left);
    }
}

// Function to build the Huffman tree from the given weights
Node* buildTree(int* weights, int size) {
    Node* nodes[size];
    for (int i = 0; i < size; i++) {
        nodes[i] = newLeafNode(i, weights[i]);
    }
    for (int i = 0; i < size - 1; i++) {
        Node* left = nodes[i];
        Node* right = nodes[i + 1];
        Node* merged = mergeNodes(left, right);
        nodes[i] = merged;
    }
    return nodes[0];
}

// Function to encode a string using the Huffman tree
void huffmanEncode(char* input, char* output, int length, Node* tree) {
    int code_length = 0;
    for (int i = 0; i < length; i++) {
        char ch = input[i];
        encode(ch, tree, output, code_length);
        code_length += tree->code_length;
    }
}

// Function to decode a string using the Huffman tree
void huffmanDecode(char* input, char* output, int length, Node* tree) {
    int code_length = 0;
    for (int i = 0; i < length; i++) {
        char ch = decode(input, code_length, tree);
        output[i] = ch;
        code_length += tree->code_length;
    }
}

int main() {
    int weights[MAX_CHARS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(weights) / sizeof(weights[0]);
    Node* tree = buildTree(weights, size);
    char input[MAX_CHARS] = "Hello, World!";
    char output[MAX_CHARS] = "";
    huffmanEncode(input, output, strlen(input), tree);
    printf("Encoded string: %s\n", output);
    huffmanDecode(output, input, strlen(output), tree);
    printf("Decoded string: %s\n", input);
    return 0;
}