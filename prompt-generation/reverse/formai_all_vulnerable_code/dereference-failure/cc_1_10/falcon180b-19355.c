//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CHARS 256
#define MAX_CODES 4096

typedef struct {
    char ch;
    int freq;
    int code;
} huffmanNode;

int compareFreq(const void* a, const void* b) {
    huffmanNode* nodeA = (huffmanNode*)a;
    huffmanNode* nodeB = (huffmanNode*)b;
    return nodeA->freq - nodeB->freq;
}

void buildHuffmanTree(huffmanNode* nodes, int n, int code, int* codeTable) {
    int i;
    for (i = 0; i < n; i++) {
        codeTable[nodes[i].ch] = code;
        code += 1;
    }
}

void encodeMessage(char* message, int* freqTable, int codeTable[]) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        printf("%c", codeTable[message[i]]);
    }
}

int main() {
    FILE* inputFile;
    char* message;
    int freqTable[MAX_CHARS] = {0};
    int codeTable[MAX_CHARS] = {0};
    huffmanNode nodes[MAX_CHARS];
    int n = 0;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: cannot open file.\n");
        return 1;
    }

    while ((message = fgets(message, sizeof(message), inputFile))!= NULL) {
        int m = strlen(message);
        int j;
        for (j = 0; j < m; j++) {
            freqTable[message[j]]++;
        }
    }

    fclose(inputFile);

    for (int i = 0; i < MAX_CHARS; i++) {
        if (freqTable[i] > 0) {
            nodes[n].ch = i;
            nodes[n].freq = freqTable[i];
            nodes[n].code = -1;
            n++;
        }
    }

    qsort(nodes, n, sizeof(huffmanNode), compareFreq);

    int code = 0;
    buildHuffmanTree(nodes, n, code, codeTable);

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: cannot open file.\n");
        return 1;
    }

    while ((message = fgets(message, sizeof(message), inputFile))!= NULL) {
        int m = strlen(message);
        int j;
        for (j = 0; j < m; j++) {
            printf("%c", codeTable[message[j]]);
        }
    }

    fclose(inputFile);

    return 0;
}