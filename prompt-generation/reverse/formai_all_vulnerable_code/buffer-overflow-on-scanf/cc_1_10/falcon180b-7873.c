//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS 256
#define MAX_CODES 4096
#define MAX_CODE_LEN 12

typedef struct {
    int freq;
    char ch;
} Node;

Node tree[MAX_CHARS];

void build_tree(char text[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (text[i]!= '\n') {
            tree[text[i]].freq++;
        }
    }
    for (i = 0; i < MAX_CHARS; i++) {
        if (tree[i].freq > 0) {
            tree[i].freq = 0;
            j = 1;
            while (j < MAX_CODES) {
                if (tree[j].freq == 0) {
                    tree[j].freq = 1;
                    tree[i].freq += tree[j].freq;
                    break;
                }
                else if (tree[j].freq > 0) {
                    tree[j].freq++;
                }
                j++;
            }
        }
    }
}

void encode(char text[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (text[i]!= '\n') {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}

void decode(char text[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (text[i]!= '\n') {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}

void main() {
    char text[MAX_CHARS];
    int n, i;
    printf("Enter the text: ");
    scanf("%s", text);
    n = strlen(text);
    build_tree(text, n);
    printf("The frequency of each character is:\n");
    for (i = 0; i < MAX_CHARS; i++) {
        if (tree[i].freq > 0) {
            printf("%c: %d\n", tree[i].ch, tree[i].freq);
        }
    }
    printf("\nThe Huffman codes for each character are:\n");
    for (i = 0; i < MAX_CODES; i++) {
        if (tree[i].freq > 0) {
            printf("%c: %s\n", tree[i].ch, tree[i].freq == 1? "0" : "1");
        }
    }
    printf("\nThe encoded text is:\n");
    encode(text, n);
    printf("\nThe decoded text is:\n");
    decode(text, n);
}