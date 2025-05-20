//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 256
#define MAX_CODES 4096

typedef struct {
    char character;
    int frequency;
    int code;
} HuffmanNode;

int compareHuffmanNodes(const void *node1, const void *node2) {
    HuffmanNode *n1 = (HuffmanNode *) node1;
    HuffmanNode *n2 = (HuffmanNode *) node2;
    return n1->frequency - n2->frequency;
}

void buildHuffmanTree(HuffmanNode *nodes, int numNodes) {
    int i, j;
    for (i = 0; i < numNodes - 1; i++) {
        for (j = i + 1; j < numNodes; j++) {
            if (nodes[j].frequency < nodes[i].frequency) {
                HuffmanNode temp = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = temp;
            }
        }
    }
}

void buildHuffmanCodeTable(HuffmanNode *nodes, int numNodes, char *codeTable) {
    int i, j;
    for (i = 0; i < numNodes; i++) {
        strcpy(codeTable + 2 * i, "");
    }
    for (i = 0; i < numNodes; i++) {
        if (nodes[i].frequency > 0) {
            codeTable[0] = '\0';
            strcat(codeTable, "1");
            strcat(codeTable, "0");
            buildHuffmanCodeTable(nodes, numNodes, codeTable + 2 * i);
        }
    }
}

int main() {
    char inputText[MAX_CHARACTERS];
    int inputLength;
    int i;

    printf("Enter a text to compress:\n");
    scanf("%s", inputText);
    inputLength = strlen(inputText);

    HuffmanNode nodes[MAX_CHARACTERS];
    int numNodes = 0;
    for (i = 0; i < MAX_CHARACTERS; i++) {
        if (inputText[i]!= '\0') {
            nodes[numNodes].character = inputText[i];
            nodes[numNodes].frequency = 1;
            numNodes++;
        }
    }

    qsort(nodes, numNodes, sizeof(HuffmanNode), compareHuffmanNodes);

    char huffmanCodeTable[MAX_CODES];
    buildHuffmanCodeTable(nodes, numNodes, huffmanCodeTable);

    FILE *outputFile;
    outputFile = fopen("output.txt", "w");

    for (i = 0; i < inputLength; i++) {
        fprintf(outputFile, "%c", huffmanCodeTable[inputText[i]]);
    }

    fclose(outputFile);

    return 0;
}