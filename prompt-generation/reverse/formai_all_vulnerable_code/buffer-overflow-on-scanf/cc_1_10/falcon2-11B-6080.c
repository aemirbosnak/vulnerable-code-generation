//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure for the Huffman tree
struct Node {
    int freq;
    char ch;
    struct Node* left;
    struct Node* right;
};

// Function to build the Huffman tree
void buildHuffmanTree(struct Node** root, int** freq, int size) {
    int i, j, k, l;
    struct Node* curr, *prev, *newNode;
    int min, minIndex;

    // Build Huffman tree
    for (i = 0; i < size; i++) {
        curr = (struct Node*) malloc(sizeof(struct Node));
        curr->freq = freq[i];
        curr->ch = '0' + i;
        curr->left = curr->right = NULL;

        // Insert the node into the priority queue
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (freq[minIndex] > freq[j]) {
                minIndex = j;
            }
        }
        if (minIndex!= i) {
            prev = *root;
            while (prev->freq > curr->freq) {
                prev = prev->left;
            }
            if (prev->right == NULL) {
                prev->right = curr;
            } else {
                newNode = (struct Node*) malloc(sizeof(struct Node));
                newNode->freq = curr->freq;
                newNode->ch = '0' + i;
                newNode->left = curr;
                newNode->right = prev->right;
                prev->right = newNode;
            }
        }
    }

    // Traverse the tree and print the Huffman codes
    *root = curr;
    for (i = 0; i < size; i++) {
        curr = *root;
        while (curr!= NULL) {
            printf("%c", curr->ch);
            if (curr->left!= NULL) {
                printf("%c", '0');
            }
            if (curr->right!= NULL) {
                printf("%c", '1');
            }
            curr = curr->left;
        }
        printf("\n");
    }
}

// Function to encode a string using Huffman coding
void encodeString(char* str, struct Node** root, int* freq) {
    int i, j, k;
    struct Node* curr, *prev;

    // Encode the string
    for (i = 0; str[i]!= '\0'; i++) {
        curr = *root;
        while (curr!= NULL) {
            if (str[i] == curr->ch) {
                for (j = 0; j < curr->freq; j++) {
                    for (k = 0; k < (j + 1); k++) {
                        printf("%c", '0');
                    }
                    printf("%c", '1');
                }
                break;
            }
            prev = curr;
            curr = curr->left;
        }
    }
    printf("\n");
}

// Function to decode a string using Huffman coding
void decodeString(char* str, struct Node** root, int* freq) {
    int i, j, k;
    struct Node* curr, *prev;

    // Decode the string
    for (i = 0; str[i]!= '\0'; i++) {
        curr = *root;
        while (curr!= NULL) {
            if (str[i] == '0') {
                prev = curr;
                curr = curr->left;
            } else if (str[i] == '1') {
                prev = curr;
                curr = curr->right;
            } else {
                printf("Invalid character\n");
                return;
            }
            if (curr->left!= NULL) {
                printf("%c", curr->ch);
                for (j = 0; j < curr->freq; j++) {
                    for (k = 0; k < (j + 1); k++) {
                        printf("%c", '0');
                    }
                    printf("%c", '1');
                }
                curr = prev;
            }
        }
    }
    printf("\n");
}

int main() {
    char str[100];
    struct Node* root;
    int freq[100];
    int size;

    // Get the string and its frequency from the user
    printf("Enter the string: ");
    scanf("%s", str);
    printf("Enter the frequency of each character: ");
    for (size = 0; str[size]!= '\0'; size++) {
        scanf("%d", &freq[size]);
    }

    // Build the Huffman tree
    buildHuffmanTree(&root, freq, size);

    // Encode the string using Huffman coding
    printf("Encoded string:\n");
    encodeString(str, &root, freq);

    // Decode the encoded string using Huffman coding
    printf("Decoded string:\n");
    decodeString(str, &root, freq);

    return 0;
}