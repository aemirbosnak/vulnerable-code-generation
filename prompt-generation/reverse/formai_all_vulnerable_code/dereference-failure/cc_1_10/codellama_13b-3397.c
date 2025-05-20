//Code Llama-13B DATASET v1.0 Category: Huffman Coding Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a Huffman tree node
struct HuffmanNode {
    int value;
    int frequency;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
};

// Structure to represent a Huffman tree
struct HuffmanTree {
    struct HuffmanNode* root;
    int size;
};

// Function to create a new Huffman tree
struct HuffmanTree* createHuffmanTree(int arr[], int size) {
    struct HuffmanTree* tree = (struct HuffmanTree*)malloc(sizeof(struct HuffmanTree));
    tree->root = NULL;
    tree->size = size;

    // Create a leaf node for each element in the array
    for (int i = 0; i < size; i++) {
        struct HuffmanNode* node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
        node->value = arr[i];
        node->frequency = 1;
        node->left = NULL;
        node->right = NULL;

        // Add the node to the tree
        if (tree->root == NULL) {
            tree->root = node;
        } else {
            struct HuffmanNode* current = tree->root;
            struct HuffmanNode* parent;
            while (current != NULL) {
                parent = current;
                if (node->value < current->value) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            if (node->value < parent->value) {
                parent->left = node;
            } else {
                parent->right = node;
            }
        }
    }

    // Repeat the process until there is only one node left
    while (tree->size > 1) {
        // Find the two nodes with the lowest frequency
        struct HuffmanNode* min1 = tree->root;
        struct HuffmanNode* min2 = tree->root;
        while (min1 != NULL) {
            if (min1->frequency < min2->frequency) {
                min2 = min1;
            }
            min1 = min1->left;
        }

        // Create a new node with the sum of the frequencies of the two nodes
        struct HuffmanNode* node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
        node->value = min1->value + min2->value;
        node->frequency = min1->frequency + min2->frequency;
        node->left = min1;
        node->right = min2;

        // Add the new node to the tree
        if (tree->root == min1 || tree->root == min2) {
            tree->root = node;
        } else {
            struct HuffmanNode* current = tree->root;
            struct HuffmanNode* parent;
            while (current != NULL) {
                parent = current;
                if (node->value < current->value) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            if (node->value < parent->value) {
                parent->left = node;
            } else {
                parent->right = node;
            }
        }

        // Remove the two nodes with the lowest frequency
        min1->left = NULL;
        min1->right = NULL;
        min2->left = NULL;
        min2->right = NULL;

        // Update the tree size
        tree->size--;
    }

    return tree;
}

// Function to traverse the Huffman tree and print the Huffman codes
void printHuffmanCodes(struct HuffmanTree* tree) {
    struct HuffmanNode* current = tree->root;
    int code = 0;
    int i = 0;
    while (current != NULL) {
        if (current->left == NULL && current->right == NULL) {
            printf("%c: %d\n", current->value, code);
        }
        if (current->left != NULL) {
            code = code * 2 + 0;
            current = current->left;
        } else {
            code = code * 2 + 1;
            current = current->right;
        }
    }
}

int main() {
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    struct HuffmanTree* tree = createHuffmanTree(arr, size);
    printHuffmanCodes(tree);

    return 0;
}