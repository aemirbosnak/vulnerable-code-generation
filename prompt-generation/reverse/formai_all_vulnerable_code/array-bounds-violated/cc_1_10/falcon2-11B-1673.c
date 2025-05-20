//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

typedef struct node {
    char symbol;
    int freq;
    struct node *left;
    struct node *right;
} node;

node* createNode(char symbol, int freq) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->symbol = symbol;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void buildHuffmanTree(node* root, int totalFreq) {
    if (totalFreq == 0)
        return;

    node* newNode = createNode(' ', totalFreq);
    root->left = newNode;
    root->right = newNode;

    buildHuffmanTree(newNode->left, totalFreq/2);
    buildHuffmanTree(newNode->right, totalFreq/2);
}

void huffmanEncoding(node* root, char* str) {
    if (!root)
        return;

    node* traverse = root;
    char* output = (char*) malloc(strlen(str) + 1);
    int len = strlen(str);
    int i = 0;

    while (str[len - 1]!= '\0') {
        if (str[len - 1] == traverse->symbol) {
            output[i++] = traverse->symbol;
            traverse = traverse->left;
        } else {
            output[i++] = traverse->symbol;
            traverse = traverse->right;
        }
        len--;
    }
    output[i] = '\0';
    printf("Huffman encoded string: %s\n", output);
    free(output);
}

int main() {
    char str[] = "Huffman Coding Implementation";
    int freq[26] = {0};

    for (int i = 0; str[i]!= '\0'; i++) {
        freq[str[i] - 'a']++;
    }

    node* root = createNode('\0', 0);
    buildHuffmanTree(root, 26 * (26 + 1));

    huffmanEncoding(root, str);

    return 0;
}