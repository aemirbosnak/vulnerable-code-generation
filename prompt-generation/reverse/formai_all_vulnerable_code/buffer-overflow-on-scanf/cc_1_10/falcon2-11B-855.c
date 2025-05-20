//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create Huffman tree
void createHuffmanTree(int *frequency, int *heap) {
    int i, j, root;

    root = 0;

    for (i = 1; i < 256; i++) {
        if (heap[i] > heap[root]) {
            root = i;
        }
    }

    while (root!= 0) {
        int left = root << 1;
        int right = left + 1;
        root = left;

        for (i = 0; i < 256; i++) {
            if (heap[i] > heap[right]) {
                right = i;
            }
        }

        heap[root] += heap[right];
        heap[right] = 0;
    }
}

// Function to calculate Huffman codes
void huffmanCodes(int *frequency, int *heap, char *str, int length) {
    int i, j, k, root;
    char *huffmanCodes;

    createHuffmanTree(frequency, heap);

    root = 0;

    for (i = 0; i < length; i++) {
        int bit = 0;
        for (j = 1; j < 256; j++) {
            if (heap[j] > heap[root]) {
                root = j;
            }
        }

        if (str[i] == '0') {
            bit = root << 1;
        } else {
            bit = root + 1;
        }

        huffmanCodes = (char *)malloc(sizeof(char) * 256);

        for (k = 1; k < 256; k++) {
            if (heap[k] > heap[root]) {
                root = k;
            }
        }

        huffmanCodes[root] = '0';

        for (j = 1; j < 256; j++) {
            if (heap[j] > heap[root]) {
                root = j;
            }
        }

        huffmanCodes[root] = '1';

        str[i] = huffmanCodes[bit];
    }

    printf("Huffman codes are: %s\n", str);
}

int main() {
    int frequency[256];
    int heap[256];
    char str[1000];
    int length;

    printf("Enter the frequency of each character:\n");
    for (length = 0; length < 256; length++) {
        scanf("%d", &frequency[length]);
    }

    printf("Enter the string:\n");
    scanf("%s", str);

    huffmanCodes(frequency, heap, str, length);

    return 0;
}