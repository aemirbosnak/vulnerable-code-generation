//Code Llama-13B DATASET v1.0 Category: Huffman Coding Implementation ; Style: interoperable
// Huffman Coding Implementation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Huffman Tree Node Structure
typedef struct HuffmanTreeNode {
    char data;
    int freq;
    struct HuffmanTreeNode* left;
    struct HuffmanTreeNode* right;
} HuffmanTreeNode;

// Create a new Huffman Tree Node
HuffmanTreeNode* createNode(char data, int freq) {
    HuffmanTreeNode* node = (HuffmanTreeNode*) malloc(sizeof(HuffmanTreeNode));
    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Build Huffman Tree
HuffmanTreeNode* buildHuffmanTree(char* str) {
    int len = strlen(str);
    int freq[256] = {0};
    for (int i = 0; i < len; i++) {
        freq[str[i]]++;
    }
    HuffmanTreeNode* root = NULL;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            HuffmanTreeNode* node = createNode(i, freq[i]);
            if (root == NULL) {
                root = node;
            } else {
                HuffmanTreeNode* parent = NULL;
                HuffmanTreeNode* current = root;
                while (current != NULL) {
                    parent = current;
                    if (current->freq < node->freq) {
                        current = current->left;
                    } else {
                        current = current->right;
                    }
                }
                if (parent->freq < node->freq) {
                    parent->left = node;
                } else {
                    parent->right = node;
                }
            }
        }
    }
    return root;
}

// Print Huffman Tree
void printHuffmanTree(HuffmanTreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%c (%d)\n", root->data, root->freq);
    printHuffmanTree(root->left);
    printHuffmanTree(root->right);
}

// Huffman Coding
void huffmanCoding(char* str, HuffmanTreeNode* root) {
    int len = strlen(str);
    char* encoded = (char*) malloc(len * sizeof(char));
    int i = 0;
    while (i < len) {
        HuffmanTreeNode* current = root;
        while (current->left != NULL || current->right != NULL) {
            if (str[i] == current->data) {
                break;
            }
            if (str[i] < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        encoded[i] = current->data;
        i++;
    }
    printf("Encoded string: %s\n", encoded);
}

int main() {
    char str[] = "this is an example for huffman coding";
    HuffmanTreeNode* root = buildHuffmanTree(str);
    printHuffmanTree(root);
    huffmanCoding(str, root);
    return 0;
}