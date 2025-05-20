//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256

typedef struct {
    int freq;
    char ch;
} freq_t;

void build_tree(char str[], int len, freq_t *tree) {
    int i;
    freq_t *node = (freq_t*)malloc(MAX_CHARS * sizeof(freq_t));

    for (i = 0; i < MAX_CHARS; i++) {
        node[i].freq = 0;
        node[i].ch = '\0';
    }

    for (i = 0; i < len; i++) {
        freq_t temp = {1, str[i]};
        int j = 0;

        while (node[j].ch!= '\0' && node[j].ch!= str[i]) {
            j++;
        }

        if (node[j].ch == '\0') {
            node[j].ch = str[i];
            node[j].freq = 1;
        } else {
            node[j].freq++;
        }
    }

    for (i = 0; i < MAX_CHARS; i++) {
        if (node[i].freq > 0) {
            tree[i] = node[i];
        }
    }

    free(node);
}

void encode(char str[], int len, freq_t tree[], char code[]) {
    int i;

    for (i = 0; i < len; i++) {
        int j = 0;

        while (tree[j].ch!= str[i]) {
            j++;
        }

        code[i] = (char)j;
    }
}

void decode(char code[], int len, freq_t tree[]) {
    int i;

    for (i = 0; i < len; i++) {
        printf("%c", tree[(int)code[i]].ch);
    }
}

int main() {
    char str[1000];
    int len;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    freq_t tree[MAX_CHARS];

    build_tree(str, len, tree);

    char code[len];

    encode(str, len, tree, code);

    printf("\nCompressed string: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", code[i]);
    }

    printf("\n\nDecompressed string: ");
    decode(code, len, tree);

    return 0;
}