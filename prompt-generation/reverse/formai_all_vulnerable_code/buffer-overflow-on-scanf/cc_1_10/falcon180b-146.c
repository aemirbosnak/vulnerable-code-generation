//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 15
#define MAX_SYMBOLS 256
#define MAX_TREE_HEIGHT 15

typedef struct {
    int freq;
    char ch;
} node;

void calc_freq(char *str, int len, node *htab) {
    int i = 0;
    while (i < len) {
        if (htab[str[i]].freq == 0) {
            htab[str[i]].freq = 1;
        } else {
            htab[str[i]].freq++;
        }
        i++;
    }
}

void build_tree(node *htab, int len) {
    int i, j;
    node *left, *right;

    for (i = 0; i < len; i++) {
        if (htab[i].freq > 0) {
            left = (node *)malloc(sizeof(node));
            right = (node *)malloc(sizeof(node));

            left->freq = htab[i].freq;
            left->ch = '\0';

            right->freq = 0;
            right->ch = '\0';

            htab[i].freq = 0;

            if (left->freq > 0) {
                left->ch = i;
            }

            if (right->freq > 0) {
                right->ch = i;
            }

            if (left->freq == 0 && right->freq == 0) {
                free(left);
                free(right);
            }
        }
    }
}

void build_code(node *htab, int len, char *code) {
    int i, j;
    char *p = code;

    for (i = 0; i < len; i++) {
        if (htab[i].freq > 0) {
            *p++ = (char)i;
        }
    }

    for (i = 0; i < len; i++) {
        if (htab[i].freq > 0) {
            j = 0;
            while (j < MAX_CODE_LENGTH) {
                if ((code[j] & 1) == 0) {
                    code[j] |= 1 << i;
                }
                j++;
            }
        }
    }
}

void encode(char *str, int len, node *htab, char *code) {
    int i = 0;
    while (i < len) {
        printf("%c", code[str[i]]);
        i++;
    }
}

int main() {
    char str[100];
    node htab[MAX_SYMBOLS];
    char code[MAX_CODE_LENGTH];

    printf("Enter the string to be encoded: ");
    scanf("%s", str);

    int len = strlen(str);

    calc_freq(str, len, htab);
    build_tree(htab, len);
    build_code(htab, len, code);

    printf("Huffman codes are:\n");
    encode(str, len, htab, code);

    return 0;
}