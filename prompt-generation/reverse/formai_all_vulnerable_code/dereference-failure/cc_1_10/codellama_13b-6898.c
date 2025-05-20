//Code Llama-13B DATASET v1.0 Category: Huffman Coding Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in Huffman tree
typedef struct HuffmanNode {
    int data;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

// Function to create a new Huffman node
HuffmanNode* newHuffmanNode(int data, HuffmanNode* left, HuffmanNode* right) {
    HuffmanNode* node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    node->data = data;
    node->left = left;
    node->right = right;
    return node;
}

// Function to traverse the Huffman tree and print the codes
void traverseAndPrintCodes(HuffmanNode* root, int* codes, int codeLength) {
    if (root == NULL) {
        return;
    }

    // Print the code for the current node
    printf("%d", root->data);

    // Recursively traverse the left and right sub-trees
    traverseAndPrintCodes(root->left, codes, codeLength);
    traverseAndPrintCodes(root->right, codes, codeLength);
}

// Function to build the Huffman tree
HuffmanNode* buildHuffmanTree(int* frequencies, int size) {
    // Create a priority queue to store the nodes of the Huffman tree
    HuffmanNode* nodes[size];
    for (int i = 0; i < size; i++) {
        nodes[i] = newHuffmanNode(frequencies[i], NULL, NULL);
    }

    // Create a min heap to store the nodes of the Huffman tree
    HuffmanNode* minHeap[size];
    for (int i = 0; i < size; i++) {
        minHeap[i] = nodes[i];
    }

    // Build the Huffman tree
    while (size > 1) {
        // Find the two nodes with the lowest frequencies
        HuffmanNode* min1 = minHeap[0];
        HuffmanNode* min2 = minHeap[1];
        for (int i = 2; i < size; i++) {
            if (minHeap[i]->data < min1->data) {
                min1 = minHeap[i];
            } else if (minHeap[i]->data < min2->data) {
                min2 = minHeap[i];
            }
        }

        // Create a new node with the sum of the frequencies of the two nodes
        HuffmanNode* newNode = newHuffmanNode(min1->data + min2->data, min1, min2);

        // Remove the two nodes from the min heap
        minHeap[0] = minHeap[size - 1];
        minHeap[size - 1] = NULL;
        size--;

        // Add the new node to the min heap
        minHeap[size] = newNode;
        size++;
    }

    // Return the root node of the Huffman tree
    return minHeap[0];
}

// Function to print the codes for the given input string
void printHuffmanCodes(char* input, int* frequencies, int size) {
    // Build the Huffman tree
    HuffmanNode* root = buildHuffmanTree(frequencies, size);

    // Traverse the Huffman tree and print the codes
    int codes[size];
    traverseAndPrintCodes(root, codes, 0);
}

int main() {
    // Example input string
    char input[] = "aabbbcccccccccc";

    // Calculate the frequency of each character in the input string
    int frequencies[256] = {0};
    for (int i = 0; i < strlen(input); i++) {
        frequencies[(int)input[i]]++;
    }

    // Print the Huffman codes for the input string
    printHuffmanCodes(input, frequencies, 256);

    return 0;
}