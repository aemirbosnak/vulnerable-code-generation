//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char ch;
    int freq;
    struct node *left, *right;
} node;

node *create_node(char ch, int freq) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->ch = ch;
    new_node->freq = freq;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *insert_node(node *root, node *new_node) {
    if (root == NULL) {
        root = new_node;
        return root;
    }
    if (new_node->freq < root->freq) {
        root->left = insert_node(root->left, new_node);
    } else {
        root->right = insert_node(root->right, new_node);
    }
    return root;
}

void create_huffman_tree(node **root, char *str) {
    int freq[256] = {0};
    for (int i = 0; i < strlen(str); i++) {
        freq[str[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            *root = insert_node(*root, create_node(i, freq[i]));
        }
    }
}

void print_huffman_code(node *root, char *code) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->ch, code);
        return;
    }
    print_huffman_code(root->left, strcat(code, "0"));
    print_huffman_code(root->right, strcat(code, "1"));
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);
    node *root = NULL;
    create_huffman_tree(&root, str);
    char code[100] = "";
    print_huffman_code(root, code);
    return 0;
}