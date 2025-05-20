//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char ch;
    int freq;
    struct node *left;
    struct node *right;
} node;

node* create_node(char ch, int freq) {
    node* new_node = (node*) malloc(sizeof(node));
    if (!new_node) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->ch = ch;
    new_node->freq = freq;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* insert_node(node* root, char ch, int freq) {
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

void encode(node* root, char* str, FILE* fp) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        fprintf(fp, "%c %d\n", root->ch, root->freq);
        return;
    }
    encode(root->left, str, fp);
    encode(root->right, str, fp);
}

void decode(node* root, FILE* fp) {
    char ch;
    int freq;
    while (fscanf(fp, "%c %d", &ch, &freq)!= EOF) {
        root = insert_node(root, ch, freq);
    }
}

int main() {
    char filename[MAX_SIZE];
    printf("Enter the input file name: ");
    scanf("%s", filename);
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found\n");
        exit(0);
    }
    char ch;
    int freq = 0;
    node* root = NULL;
    while ((ch = fgetc(fp))!= EOF) {
        freq++;
        root = insert_node(root, ch, freq);
    }
    fclose(fp);
    encode(root, "", stdout);
    printf("\n");
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("File not found\n");
        exit(0);
    }
    decode(root, fp);
    fclose(fp);
    return 0;
}