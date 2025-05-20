//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX_CHARS 256
#define MAX_CODES 4096
#define MAX_CODE_LEN 16

typedef struct {
    char ch;
    int freq;
    int code;
    int len;
} node;

node huffman_tree[MAX_CHARS];

void swap(node *a, node *b) {
    node temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) {
    node *x = (node *)a;
    node *y = (node *)b;
    return x->freq - y->freq;
}

void build_tree(int n) {
    int i;
    for (i = 0; i < n; i++) {
        huffman_tree[i].freq = 0;
        huffman_tree[i].code = 0;
        huffman_tree[i].len = 0;
    }
    for (i = 0; i < n; i++) {
        scanf("%c", &huffman_tree[i].ch);
        huffman_tree[i].freq++;
    }
    qsort(huffman_tree, n, sizeof(node), compare);
}

void encode(int n, int code, int len) {
    if (len == MAX_CODE_LEN) {
        printf("Error: code too long\n");
        exit(1);
    }
    if (n == 1) {
        printf("%c -> %s\n", huffman_tree[n].ch, huffman_tree[n].code);
        return;
    }
    int i;
    for (i = 0; i < n; i++) {
        if (huffman_tree[i].freq > 0) {
            encode(n - 1, code + "0", len + 1);
            encode(n - huffman_tree[i].freq, code + "1", len + 1);
            break;
        }
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    if (n > MAX_CHARS) {
        printf("Error: too many characters\n");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        scanf("%c", &huffman_tree[i].ch);
        huffman_tree[i].freq++;
    }
    build_tree(n);
    printf("Huffman codes:\n");
    encode(n, "", 0);
    return 0;
}