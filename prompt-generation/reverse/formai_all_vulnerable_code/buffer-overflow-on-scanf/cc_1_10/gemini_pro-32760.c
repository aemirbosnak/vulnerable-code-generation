//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char c;
    int freq;
    struct node *left, *right;
} node;

node *create_node(char c, int freq) {
    node *n = (node *)malloc(sizeof(node));
    n->c = c;
    n->freq = freq;
    n->left = n->right = NULL;
    return n;
}

node *insert_node(node *root, node *n) {
    if (root == NULL) {
        return n;
    }
    if (n->freq < root->freq) {
        root->left = insert_node(root->left, n);
    } else {
        root->right = insert_node(root->right, n);
    }
    return root;
}

void print_huffman(node *root, char *code) {
    if (root == NULL) {
        return;
    }
    if (root->c != '\0') {
        printf("%c: %s\n", root->c, code);
    }
    print_huffman(root->left, strcat(code, "0"));
    print_huffman(root->right, strcat(code, "1"));
}

int main() {
    int n;
    char s[100];
    int freq[256];
    node *root = NULL;

    printf("Enter the string: ");
    scanf("%s", s);

    for (int i = 0; i < 256; i++) {
        freq[i] = 0;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            root = insert_node(root, create_node(i, freq[i]));
        }
    }

    char code[100];
    print_huffman(root, code);

    return 0;
}