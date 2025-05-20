//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a Huffman Tree node
struct HuffmanNode {
    char symbol;
    int frequency;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
};

// Define a symbol frequency struct
struct SymbolFrequency {
    char symbol;
    int frequency;
};

// Define a function to sort symbol frequency array in ascending order of frequency
void sortSymbolFrequency(struct SymbolFrequency symbolFrequency[], int size) {
    int i, j;
    struct SymbolFrequency temp;
    for(i=0; i<size; i++) {
        for(j=i+1; j<size; j++) {
            if(symbolFrequency[i].frequency > symbolFrequency[j].frequency) {
                temp = symbolFrequency[i];
                symbolFrequency[i] = symbolFrequency[j];
                symbolFrequency[j] = temp;
            }
        }
    }
}

// Define a function to create and return a new Huffman Tree node
struct HuffmanNode* createNewHuffmanNode(char symbol, int frequency) {
    struct HuffmanNode* newNode = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    newNode->symbol = symbol;
    newNode->frequency = frequency;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Define a function to create a Huffman Tree and return its root node
struct HuffmanNode* buildHuffmanTree(struct SymbolFrequency symbolFrequency[], int size) {
    sortSymbolFrequency(symbolFrequency, size); // Sort symbol frequency array
    int i, j;
    struct HuffmanNode *root = NULL, *newNode, *leftNode, *rightNode;
    for(i=0; i<size-1; i++) {
        leftNode = createNewHuffmanNode(symbolFrequency[i].symbol, symbolFrequency[i].frequency);
        rightNode = createNewHuffmanNode(symbolFrequency[i+1].symbol, symbolFrequency[i+1].frequency);
        newNode = createNewHuffmanNode('$', leftNode->frequency + rightNode->frequency);
        newNode->left = leftNode;
        newNode->right = rightNode;
        if(i == size-2) {
            root = newNode;
        }
        else {
            for(j=i+2; j<size; j++) {
                if(newNode->frequency < symbolFrequency[j].frequency) {
                    // Insert newNode in the symbolFrequency array
                    int k;
                    for(k=size-1; k>j; k--) {
                        symbolFrequency[k] = symbolFrequency[k-1];
                    }
                    symbolFrequency[k].symbol = '$';
                    symbolFrequency[k].frequency = newNode->frequency;
                    break;
                }
            }
            // Move leftNode and rightNode to the new index positions
            for(j=i+1; j<size-1; j++) {
                if(symbolFrequency[j].frequency > leftNode->frequency) {
                    int k;
                    for(k=j+1; k<size; k++) {
                        symbolFrequency[k-1] = symbolFrequency[k];
                    }
                    symbolFrequency[size-1].symbol = leftNode->symbol;
                    symbolFrequency[size-1].frequency = leftNode->frequency;
                    break;
                }
                else {
                    symbolFrequency[j-1] = symbolFrequency[j];
                }
            }
            for(j=i+2; j< size-1; j++) {
                if(symbolFrequency[j].frequency > rightNode->frequency) {
                    int k;
                    for(k=j+1; k<size; k++) {
                        symbolFrequency[k-1] = symbolFrequency[k];
                    }
                    symbolFrequency[size-1].symbol = rightNode->symbol;
                    symbolFrequency[size-1].frequency = rightNode->frequency;
                    break;
                }
                else {
                    symbolFrequency[j-1] = symbolFrequency[j];
                }
            }
            size--;
        }
    }
    return root;
}

// Define a function to traverse the Huffman Tree and map the symbols to their corresponding codes
void traverseHuffmanTree(struct HuffmanNode* root, char code[], int level, char symbolCode[][10]) {
    if(root->left == NULL && root->right == NULL) {
        code[level] = '\0';
        strcpy(symbolCode[(int)root->symbol - 97], code);
        return;
    }
    code[level] = '0';
    traverseHuffmanTree(root->left, code, level+1, symbolCode);
    code[level] = '1';
    traverseHuffmanTree(root->right, code, level+1, symbolCode);
}

// Define a function to perform Huffman encoding
void huffmanEncoding(char message[]) {
    int i;
    int count[26] = {0};
    for(i=0; message[i]!='\0'; i++) {
        count[(int)message[i] - 97]++;
    }
    struct SymbolFrequency symbolFrequency[26];
    int size = 0;
    for(i=0; i<26; i++) {
        if(count[i] > 0) {
            symbolFrequency[size].symbol = (char)(i + 97);
            symbolFrequency[size].frequency = count[i];
            size++;
        }
    }
    struct HuffmanNode *root = buildHuffmanTree(symbolFrequency, size);
    char code[10];
    char symbolCode[26][10];
    traverseHuffmanTree(root, code, 0, symbolCode);
    printf("Symbol\tFrequency\tCode\n");
    for(i=0; i<26; i++) {
        if(count[i] > 0) {
            printf("%c\t%d\t\t%s\n", (char)(i + 97), count[i], symbolCode[i]);
        }
    }
    printf("Encoded Message: ");
    for(i=0; message[i]!='\0'; i++) {
        printf("%s", symbolCode[(int)message[i] - 97]);
    }
    printf("\n");
}

int main() {
    char message[50];
    printf("Enter a message to be encoded: ");
    scanf("%[^\n]%*c", message);
    huffmanEncoding(message);
    return 0;
}