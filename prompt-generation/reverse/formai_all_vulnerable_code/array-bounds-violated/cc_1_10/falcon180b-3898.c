//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CHARS 256
#define MAX_TREE_DEPTH 1000
#define NODE_COUNT 2

typedef struct {
    int freq;
    char ch;
} Node;

Node tree[MAX_CHARS];

void buildTree(char str[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        if (str[i]!= '\0') {
            tree[str[i]].freq++;
        }
    }
}

void buildHuffmanTree(int len) {
    int i, j, k, minIndex;
    Node temp;
    for (i = 0; i < len; i++) {
        if (tree[i].freq!= 0) {
            minIndex = i;
            for (j = i + 1; j < len; j++) {
                if (tree[j].freq < tree[minIndex].freq) {
                    minIndex = j;
                }
            }
            temp = tree[i];
            tree[i] = tree[minIndex];
            tree[minIndex] = temp;
        }
    }
}

void encode(char str[], int len, FILE *fp) {
    int i;
    for (i = 0; i < len; i++) {
        fprintf(fp, "%c", str[i]);
    }
}

void decode(FILE *fp, char str[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        str[i] = fgetc(fp);
    }
}

int main() {
    char inputStr[MAX_CHARS], outputStr[MAX_CHARS];
    FILE *inputFile, *outputFile;
    int len;

    // Read input file
    inputFile = fopen("input.txt", "rb");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    len = fread(inputStr, sizeof(char), MAX_CHARS, inputFile);
    fclose(inputFile);

    // Build Huffman tree
    buildTree(inputStr, len);
    buildHuffmanTree(MAX_CHARS);

    // Encode input string
    encode(inputStr, len, outputFile);

    // Output encoded string length
    printf("Encoded string length: %d\n", len);

    // Decode encoded string
    rewind(outputFile);
    decode(outputFile, outputStr, len);

    // Output decoded string
    printf("Decoded string: %s\n", outputStr);

    fclose(outputFile);
    return 0;
}