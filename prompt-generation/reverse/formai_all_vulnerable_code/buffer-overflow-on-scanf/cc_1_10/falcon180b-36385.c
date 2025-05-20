//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS 256
#define MAX_CODES 4096
#define MAX_CODE_LEN 12

typedef struct {
    char ch;
    int freq;
    int code;
    int len;
} Node;

Node tree[MAX_CHARS];
int codeTable[MAX_CHARS];
int codeTableSize = 0;
int maxFreq = 0;
int charCount = 0;

void buildTree(char *str, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (isalpha(str[i])) {
            tree[str[i]].freq++;
            charCount++;
        }
    }
}

void buildCodeTable() {
    int i;
    for (i = 0; i < MAX_CHARS; i++) {
        if (tree[i].freq > 0) {
            codeTable[codeTableSize++] = i;
            tree[i].code = codeTableSize - 1;
        }
    }
}

void encode(FILE *fp, char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            fprintf(fp, "%c", tree[str[i]].code);
        } else {
            fprintf(fp, "%c", str[i]);
        }
    }
}

void decode(FILE *fp) {
    int i;
    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        if (ch >= 0 && ch <= MAX_CHARS) {
            printf("%c", ch);
        } else {
            int code = ch;
            while (tree[code].len == 0) {
                code = (code - 1) / 2;
            }
            printf("%c", tree[code].ch);
            code = (code - 1) / 2;
        }
    }
}

int main() {
    char input[1000];
    scanf("%s", input);
    buildTree(input, strlen(input));
    buildCodeTable();
    char outputFileName[20];
    sprintf(outputFileName, "output.txt");
    FILE *outputFile = fopen(outputFileName, "wb");
    encode(outputFile, input);
    fclose(outputFile);
    char inputFileName[20];
    sprintf(inputFileName, "output.txt");
    FILE *inputFile = fopen(inputFileName, "rb");
    decode(inputFile);
    fclose(inputFile);
    return 0;
}