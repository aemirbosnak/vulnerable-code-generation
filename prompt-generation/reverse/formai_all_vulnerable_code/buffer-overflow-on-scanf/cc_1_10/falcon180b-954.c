//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256
#define MAX_CODE_LEN 12

typedef struct {
    char ch;
    int freq;
    int code;
} Node;

Node tree[MAX_CHAR];

void initTree() {
    int i;
    for (i = 0; i < MAX_CHAR; i++) {
        tree[i].freq = 0;
        tree[i].code = 0;
    }
}

void buildTree(char text[], int len) {
    int i, j;
    for (i = 0; i < len; i++) {
        if (tree[text[i]].freq == 0) {
            tree[text[i]].freq = 1;
        } else {
            tree[text[i]].freq++;
        }
    }
    for (i = 0; i < MAX_CHAR; i++) {
        if (tree[i].freq > 0) {
            tree[i].code = (int) 'a' + i;
        }
    }
    for (i = 0; i < MAX_CHAR; i++) {
        if (tree[i].freq > 0 && tree[i].code == 0) {
            tree[i].code = (int) 'a' + i;
        }
    }
}

void encode(char text[], int len, FILE *outFile) {
    int i, j;
    for (i = 0; i < len; i++) {
        if (tree[text[i]].code == 0) {
            fprintf(outFile, "%c", text[i]);
        } else {
            fprintf(outFile, "%c", tree[text[i]].code);
        }
    }
}

void decode(FILE *inFile, char text[], int len) {
    int i, j;
    char ch;
    for (i = 0; i < len; i++) {
        ch = fgetc(inFile);
        if (ch >= (int) 'a' && ch <= (int) 'z') {
            text[i] = ch;
        } else {
            for (j = 0; j < MAX_CHAR; j++) {
                if (tree[j].code == ch) {
                    text[i] = j;
                    break;
                }
            }
        }
    }
}

int main() {
    char text[1000];
    int len, i;
    FILE *inFile, *outFile;
    printf("Enter the input file name: ");
    scanf("%s", text);
    inFile = fopen(text, "r");
    if (inFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    fseek(inFile, 0, SEEK_END);
    len = ftell(inFile);
    fseek(inFile, 0, SEEK_SET);
    text[len] = '\0';
    fclose(inFile);
    initTree();
    buildTree(text, len);
    printf("Enter the output file name: ");
    scanf("%s", text);
    outFile = fopen(text, "w");
    if (outFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }
    encode(text, len, outFile);
    fclose(outFile);
    printf("Compression completed.\n");
    return 0;
}