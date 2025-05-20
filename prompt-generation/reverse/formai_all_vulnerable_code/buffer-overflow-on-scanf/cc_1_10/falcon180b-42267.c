//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX_CHARS 256
#define MAX_CODES 4096

typedef struct {
    char ch;
    int freq;
    int code;
} node;

void build_tree(node *tree, int n) {
    int i;
    for (i = 0; i < n; i++) {
        tree[i].freq = 0;
        tree[i].code = 0;
    }
    int j = 0;
    for (i = 0; i < n; i++) {
        if (tree[i].freq > 0) {
            tree[j++] = tree[i];
        }
    }
    n = j;
    for (i = 0; i < n - 1; i++) {
        int min_index = i;
        for (j = i + 1; j < n; j++) {
            if (tree[j].freq < tree[min_index].freq) {
                min_index = j;
            }
        }
        node temp = tree[i];
        tree[i] = tree[min_index];
        tree[min_index] = temp;
    }
}

void encode(node *tree, char *text, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", text[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        if (tree[i].freq > 0) {
            printf("%c ", tree[i].ch);
        }
    }
    printf("\n");
}

void decode(node *tree, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", tree[i].ch);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%d ", tree[i].code);
    }
    printf("\n");
}

int main() {
    char text[MAX_CHARS];
    int n, i;
    printf("Enter the text: ");
    scanf("%s", text);
    n = strlen(text);
    node tree[MAX_CHARS];
    build_tree(tree, n);
    encode(tree, text, n);
    decode(tree, n);
    return 0;
}