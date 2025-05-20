//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS 256
#define MAX_CODES 4096
#define CODE_SIZE 16

typedef struct {
    char ch;
    int freq;
    int code;
} node;

node tree[MAX_CHARS];
int code[MAX_CHARS];
int code_size;

void build_tree(char text[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (isalpha(text[i])) {
            if (tree[text[i]].freq == 0) {
                tree[text[i]].freq = 1;
                tree[text[i]].code = (int) '0';
                code_size += 1;
            } else {
                tree[text[i]].freq += 1;
            }
        }
    }
}

void build_codes() {
    int i, j;
    for (i = 0; i < MAX_CHARS; i++) {
        if (tree[i].freq > 0) {
            code[i] = (int) '0';
            for (j = 1; j < CODE_SIZE; j++) {
                code[i] = code[i] * 2 + (tree[i].code & 1);
                tree[i].code >>= 1;
            }
        }
    }
}

void encode(char text[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (isalpha(text[i])) {
            printf("%c", code[text[i]]);
        }
    }
}

void decode(char text[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (isalpha(text[i])) {
            j = 0;
            while (tree[text[i]].code!= (int) text[i] >> j & 1) {
                printf("%c", (char) (tree[text[i]].code >> j & 1));
                j++;
            }
        }
    }
}

int main() {
    char text[1000];
    int n;
    printf("Enter the text: ");
    scanf("%s", text);
    n = strlen(text);
    build_tree(text, n);
    build_codes();
    printf("Encoded text: ");
    encode(text, n);
    printf("\n");
    printf("Decoded text: ");
    decode(text, n);
    printf("\n");
    return 0;
}