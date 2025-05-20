//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HuffmanNode {
    int frequency;
    char character;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
};

void printHuffmanTree(struct HuffmanNode* root) {
    if (root == NULL)
        return;
    printHuffmanTree(root->left);
    printf("%c (%d) -> ", root->character, root->frequency);
    printHuffmanTree(root->right);
}

void createHuffmanTree(struct HuffmanNode** root, struct HuffmanNode** huffmanTree, int numberOfCodes) {
    if (numberOfCodes == 0)
        return;
    struct HuffmanNode* newNode = malloc(sizeof(struct HuffmanNode));
    newNode->frequency = 0;
    newNode->character = '\0';
    newNode->left = NULL;
    newNode->right = NULL;
    *root = newNode;

    createHuffmanTree(root, &newNode->left, numberOfCodes/2);
    createHuffmanTree(root, &newNode->right, numberOfCodes/2);
    *huffmanTree = newNode;
}

void assignCodes(struct HuffmanNode* huffmanTree, char* string) {
    struct HuffmanNode* currentNode = huffmanTree;
    int i = 0;
    while (currentNode!= NULL) {
        if (currentNode->character == string[i]) {
            int code = i * 10 + currentNode->frequency;
            printf("%c -> %d\n", string[i], code);
            string[i] = (char)code;
        }
        currentNode = currentNode->left;
        i++;
    }
}

int main() {
    int numberOfCodes;
    printf("Enter number of codes: ");
    scanf("%d", &numberOfCodes);

    struct HuffmanNode* huffmanTree;
    struct HuffmanNode* root = malloc(sizeof(struct HuffmanNode));
    root->frequency = 0;
    root->character = '\0';
    root->left = NULL;
    root->right = NULL;
    createHuffmanTree(&root, &huffmanTree, numberOfCodes);

    char* string = "This is a test string for compression using Huffman algorithm";
    assignCodes(huffmanTree, string);

    printf("Compressed string: %s\n", string);
    printHuffmanTree(huffmanTree);

    free(root);
    free(huffmanTree);
    return 0;
}