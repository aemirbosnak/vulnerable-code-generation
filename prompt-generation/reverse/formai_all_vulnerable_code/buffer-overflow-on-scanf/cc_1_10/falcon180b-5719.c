//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MAX_CHARS 256

typedef struct node {
    char ch;
    int freq;
    struct node *left;
    struct node *right;
} node;

node *create_node(char ch, int freq) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->ch = ch;
    newnode->freq = freq;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node *insert_node(node *root, char ch, int freq) {
    if (root == NULL) {
        return create_node(ch, freq);
    }
    if (freq < root->freq) {
        root->left = insert_node(root->left, ch, freq);
    } else {
        root->right = insert_node(root->right, ch, freq);
    }
    return root;
}

void build_tree(char *text, int n, node **root) {
    int i;
    for (i = 0; i < n; i++) {
        text[i] -= 'A';
        text[i] = (text[i] >= 0)? text[i] : text[i] + 26;
        (*root) = insert_node((*root), text[i], 1);
    }
}

void encode_message(node *root, char *message, int n, FILE *output_file) {
    int i = 0;
    while (i < n) {
        if (root->left == NULL && root->right == NULL) {
            fprintf(output_file, "%c", root->ch);
            i++;
        } else {
            if (message[i] == '0') {
                root = root->left;
            } else {
                root = root->right;
            }
            i++;
        }
    }
}

int main() {
    char text[MAX_CHARS];
    int n, i;
    printf("Enter the message to compress: ");
    scanf("%s", text);
    n = strlen(text);
    node *root = NULL;
    build_tree(text, n, &root);
    FILE *output_file = fopen("compressed_message.txt", "w");
    encode_message(root, text, n, output_file);
    fclose(output_file);
    printf("Compressed message saved in compressed_message.txt\n");
    return 0;
}