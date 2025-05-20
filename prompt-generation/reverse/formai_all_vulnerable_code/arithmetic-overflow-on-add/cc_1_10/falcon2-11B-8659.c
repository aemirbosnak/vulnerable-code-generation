//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct node {
    int frequency;
    char symbol;
    struct node* left;
    struct node* right;
} Node;

// Function to construct a Huffman tree from the given frequency array
Node* constructHuffmanTree(int frequency[], int n) {
    if (n == 1) {
        Node* node = (Node*) malloc(sizeof(Node));
        node->frequency = frequency[0];
        node->symbol = 'A';
        return node;
    }

    int i, j;
    int minIndex = 0;
    for (i = 1; i < n; i++) {
        if (frequency[i] < frequency[minIndex]) {
            minIndex = i;
        }
    }

    // Combine the two minimum frequency nodes
    Node* node1 = constructHuffmanTree(frequency, minIndex);
    Node* node2 = constructHuffmanTree(frequency + minIndex + 1, n - minIndex - 1);

    node1->frequency += node2->frequency;
    node1->symbol = 'A';

    // Free memory for node2
    free(node2);

    node1->left = node2;
    node1->right = NULL;

    return node1;
}

// Function to create a Huffman encoded string
void createHuffmanCode(Node* root, char* encodedString, int encodedLength) {
    if (root == NULL) {
        return;
    }

    // Encode the character and update the encoded string
    if (root->symbol!= '\0') {
        encodedString[encodedLength] = root->symbol;
        encodedLength++;
    }

    // Recursively encode the left and right child nodes
    createHuffmanCode(root->left, encodedString, encodedLength);
    createHuffmanCode(root->right, encodedString, encodedLength);
}

// Function to create Huffman encoded string for a given string
char* createHuffmanEncodedString(char* inputString) {
    int n;
    int frequency[26];

    for (n = 0; inputString[n]!= '\0'; n++) {
        frequency[inputString[n] - 'A']++;
    }

    Node* root = constructHuffmanTree(frequency, n);

    // Allocate memory for encoded string
    char* encodedString = (char*) malloc(sizeof(char) * (n + 1));
    encodedString[n] = '\0';

    createHuffmanCode(root, encodedString, 0);

    return encodedString;
}

int main() {
    char inputString[] = "ABCD";
    char* encodedString = createHuffmanEncodedString(inputString);

    printf("Original String: %s\n", inputString);
    printf("Encoded String: %s\n", encodedString);

    return 0;
}