//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LEN 10
#define MAX_CHARS 256

typedef struct {
    int freq;
    char code[MAX_CODE_LEN];
} HuffmanNode;

typedef struct {
    HuffmanNode *left;
    HuffmanNode *right;
    int freq;
} HuffmanTree;

void createHuffmanCode(char *str, int len, HuffmanNode *root) {
    int i;
    for (i = 0; i < len; i++) {
        str[i] = '\0';
        root[i].freq = 0;
        strcat(str, &str[i]);
        root[i].code[0] = '\0';
    }
}

void buildHuffmanTree(HuffmanNode *root, int len) {
    int i;
    for (i = 0; i < len; i++) {
        root[i].freq = 1;
    }
    int j = 0;
    while (j < len - 1) {
        int min1 = 0x7FFFFFFF;
        int min2 = 0x7FFFFFFF;
        int minIndex = 0;
        int secIndex = 0;
        int k;
        for (k = 0; k < len - 1; k++) {
            if (root[k].freq < min1) {
                min2 = min1;
                min1 = root[k].freq;
                minIndex = k;
            } else if (root[k].freq < min2 && root[k].freq!= min1) {
                min2 = root[k].freq;
                secIndex = k;
            }
        }
        root[minIndex].freq += root[secIndex].freq;
        root[secIndex].freq = 0;
        strcat(root[minIndex].code, "0");
        strcat(root[secIndex].code, "1");
        root[secIndex].freq = 0;
        j++;
    }
}

void encodeHuffman(char *str, int len, HuffmanNode *root) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%c ", str[i]);
        printf("%s ", root[i].code);
    }
}

void decodeHuffman(char *str, int len, HuffmanNode *root) {
    int i, j, k;
    for (i = 0; i < len; i++) {
        if (str[i] == '0') {
            for (j = 0; j < MAX_CHARS; j++) {
                if (root[j].code[0] == '0') {
                    printf("%c", j);
                    break;
                }
            }
        } else if (str[i] == '1') {
            for (j = 0; j < MAX_CHARS; j++) {
                if (root[j].code[0] == '1') {
                    printf("%c", j);
                    break;
                }
            }
        }
    }
}

int main() {
    char str[MAX_CHARS];
    int len;
    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);
    HuffmanNode root[MAX_CHARS];
    createHuffmanCode(str, len, root);
    buildHuffmanTree(root, len);
    printf("Huffman Encoded string:\n");
    encodeHuffman(str, len, root);
    printf("\n");
    printf("Huffman Decoded string:\n");
    decodeHuffman(str, len, root);
    return 0;
}