//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Function to create a binary tree node
struct Node {
    int freq;
    char data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int freq, char data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->freq = freq;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform in-order traversal
void inOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%c %d\n", root->data, root->freq);
    inOrder(root->right);
}

// Function to build Huffman code tree
void buildHuffmanTree(struct Node* root, int freq[], int size) {
    if (size == 0) {
        return;
    }
    struct Node* newNode = createNode(freq[0], '0');
    root->left = newNode;
    buildHuffmanTree(newNode->left, freq, size-1);
    root->right = createNode(freq[1], '1');
    root->left->freq = freq[0];
    root->right->freq = freq[1];
}

// Function to convert Huffman code tree to actual code
void convertHuffmanCode(struct Node* root, char* code) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        *code = root->data;
        return;
    }
    convertHuffmanCode(root->left, code);
    convertHuffmanCode(root->right, code);
}

// Function to print Huffman code tree
void printHuffmanTree(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%c %d\n", root->data, root->freq);
    printHuffmanTree(root->left);
    printHuffmanTree(root->right);
}

int main() {
    int freq[256];
    int size = 0;
    int i = 0;

    // Read frequencies from input file
    FILE* inputFile = fopen("input.txt", "r");
    while (fscanf(inputFile, "%c %d", &freq[i], &size)!= EOF) {
        i++;
    }
    fclose(inputFile);

    // Build Huffman code tree
    struct Node* root = NULL;
    buildHuffmanTree(root, freq, size);

    // Convert Huffman code tree to actual code
    char code[size];
    convertHuffmanCode(root, code);

    // Print Huffman code tree
    printf("Huffman code tree:\n");
    printHuffmanTree(root);

    // Print actual code
    printf("Actual code: %s\n", code);

    return 0;
}