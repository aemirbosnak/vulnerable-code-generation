//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a node in the Huffman tree
struct Node {
    char ch;
    int freq;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with given frequency and character
struct Node* newNode(char ch, int freq) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Function to calculate the frequency of a character in the input string
int calcFreq(char ch, char* str) {
    int count = 0;
    while(*str!= '\0') {
        if(*str == ch)
            count++;
        str++;
    }
    return count;
}

// Function to build the Huffman tree from the input string
struct Node* buildTree(char* str) {
    int n = strlen(str);
    struct Node* nodes[n];
    for(int i=0; i<n; i++) {
        nodes[i] = newNode(str[i], calcFreq(str[i], str));
    }
    for(int i=n-1; i>=1; i--) {
        for(int j=0; j<i; j++) {
            if(nodes[j]->freq < nodes[i]->freq) {
                struct Node* temp = nodes[j];
                nodes[j] = nodes[i];
                nodes[i] = temp;
            }
        }
    }
    return nodes[0];
}

// Function to generate the Huffman codes for the characters in the input string
void generateCodes(struct Node* node, char* code, char* str) {
    if(node == NULL)
        return;
    if(node->left == NULL && node->right == NULL) {
        printf("%c -> %s\n", node->ch, code);
        return;
    }
    generateCodes(node->left, code, str);
    generateCodes(node->right, code, str);
}

// Function to encode the input string using the Huffman codes
void encode(char* str, char* codes) {
    int n = strlen(str);
    int i = 0;
    while(i<n) {
        printf("%c ", str[i]);
        while(codes[i]!= '\0') {
            printf("%c", codes[i]);
            i++;
        }
        i++;
    }
}

// Function to decode the encoded string using the Huffman codes
void decode(char* str, char* codes) {
    int n = strlen(str);
    int i = 0;
    while(i<n) {
        printf("%c ", str[i]);
        while(codes[i]!= '\0') {
            printf("%c", codes[i]);
            i++;
        }
        i++;
    }
}

// Main function to read the input string, build the Huffman tree, generate the Huffman codes, encode the input string, and decode the encoded string
int main() {
    char str[1000];
    printf("Enter the input string: ");
    scanf("%s", str);
    struct Node* tree = buildTree(str);
    char codes[26] = {'\0'};
    generateCodes(tree, codes, str);
    printf("\nHuffman codes:\n");
    for(int i=0; i<26; i++) {
        if(codes[i]!= '\0')
            printf("%c -> %s\n", i+'A', codes[i]);
    }
    printf("\nEncoded string:\n");
    encode(str, codes);
    printf("\nDecoded string:\n");
    decode(str, codes);
    return 0;
}