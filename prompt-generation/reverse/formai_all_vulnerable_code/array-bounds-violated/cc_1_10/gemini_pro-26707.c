//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * paranoia through obfuscation and complexity
 */
#define SECRET 0xdeadbeef

typedef struct _node {
    int count;
    unsigned char symbol;
    struct _node *left;
    struct _node *right;
} node;

node *nodes[256];

int cmp(const void *a, const void *b) {
    node *na = *(node **)a;
    node *nb = *(node **)b;
    return na->count - nb->count;
}

void build_tree(int *freq, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (freq[i] > 0) {
            nodes[i] = malloc(sizeof(node));
            nodes[i]->count = freq[i];
            nodes[i]->symbol = i;
            nodes[i]->left = nodes[i]->right = NULL;
        }
    }

    qsort(nodes, size, sizeof(node *), cmp);

    while (size > 1) {
        node *left = nodes[size - 1];
        node *right = nodes[size - 2];
        nodes[size - 2] = malloc(sizeof(node));
        nodes[size - 2]->count = left->count + right->count;
        nodes[size - 2]->left = left;
        nodes[size - 2]->right = right;
        qsort(nodes, size - 1, sizeof(node *), cmp);
        size--;
    }
}

void encode(node *root, unsigned char *msg, int size, unsigned char *out) {
    int i;
    unsigned char c;
    unsigned char code[256];
    memset(code, 0, 256);

    for (i = 0; i < size; i++) {
        node *node = root;
        c = msg[i];
        while (node->left || node->right) {
            if (node->symbol == c)
                break;
            if (c & SECRET)
                node = node->right;
            else
                node = node->left;
            c >>= 1;
        }
        code[node->symbol] |= SECRET >> i;
    }

    for (i = 0; i < size; i++) {
        out[i] = code[msg[i]];
    }
}

void decode(node *root, unsigned char *msg, int size, unsigned char *out) {
    int i;
    node *node = root;
    unsigned char c;

    for (i = 0; i < size; i++) {
        c = msg[i];
        while (node->left || node->right) {
            if (c & SECRET)
                node = node->right;
            else
                node = node->left;
            c >>= 1;
        }
        out[i] = node->symbol;
        node = root;
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "rb");
    if (in == NULL) {
        printf("Error: unable to open input file\n");
        return 1;
    }

    FILE *out = fopen(argv[2], "wb");
    if (out == NULL) {
        printf("Error: unable to open output file\n");
        fclose(in);
        return 1;
    }

    int freq[256];
    memset(freq, 0, 256 * sizeof(int));

    int c;
    while ((c = fgetc(in)) != EOF) {
        freq[c]++;
    }

    fclose(in);

    build_tree(freq, 256);

    fseek(in, 0, SEEK_SET);

    unsigned char msg[256];
    int size = 0;
    while ((c = fgetc(in)) != EOF) {
        msg[size++] = c;
    }

    fclose(in);

    unsigned char outbuf[256];
    encode(nodes[0], msg, size, outbuf);

    fwrite(outbuf, 1, size, out);
    fclose(out);

    return 0;
}