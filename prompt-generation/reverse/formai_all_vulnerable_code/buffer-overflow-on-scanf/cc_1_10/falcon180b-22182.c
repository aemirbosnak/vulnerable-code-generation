//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int ch;
    int freq;
    struct node *left;
    struct node *right;
} node;

node *createNode(int ch, int freq) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->ch = ch;
    newnode->freq = freq;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node *insert(node *root, int ch) {
    if (root == NULL) {
        root = createNode(ch, 1);
        return root;
    }

    if (ch < root->ch)
        root->left = insert(root->left, ch);
    else if (ch > root->ch)
        root->right = insert(root->right, ch);

    return root;
}

void encode(node *root, char *str, FILE *fp) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        fprintf(fp, "%c", root->ch);
        return;
    }

    encode(root->left, str, fp);
    encode(root->right, str, fp);
}

void decode(node *root, char *str, FILE *fp) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        fprintf(fp, "%c", root->ch);
        return;
    }

    decode(root->left, str, fp);
    decode(root->right, str, fp);
}

void huffman(char *str, FILE *fp) {
    int freq[256] = { 0 };
    int i, n = strlen(str);
    node *root = NULL;

    for (i = 0; i < n; i++) {
        freq[str[i]]++;
    }

    for (i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            root = insert(root, i);
        }
    }

    encode(root, str, fp);
}

int main() {
    char str[100];
    FILE *fp;

    printf("Enter the input string: ");
    scanf("%s", str);

    fp = fopen("output.txt", "wb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    huffman(str, fp);

    fclose(fp);
    printf("Compression completed.\n");

    return 0;
}