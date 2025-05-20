//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_SYMBOLS 256
#define MAX_CHARS 100000
#define NODE_SIZE 256

typedef struct node {
    int freq;
    char ch;
    struct node *left;
    struct node *right;
} Node;

typedef struct tree {
    Node *root;
} Tree;

void init_tree(Tree *tree) {
    tree->root = NULL;
}

Node* create_node(char ch, int freq) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->freq = freq;
    node->ch = ch;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert_node(Node **root, char ch, int freq) {
    if (*root == NULL) {
        *root = create_node(ch, freq);
    } else if (freq > (*root)->freq) {
        Node *temp = *root;
        *root = create_node(ch, freq);
        (*root)->left = temp;
    } else {
        if (freq < (*root)->freq) {
            insert_node(&(*root)->left, ch, freq);
        } else {
            insert_node(&(*root)->right, ch, freq);
        }
    }
}

void print_tree(Node *root, char *code, int *code_len) {
    if (root == NULL) {
        return;
    }

    print_tree(root->left, code, code_len);

    if (root->freq > 0) {
        code[*code_len] = root->ch;
        (*code_len)++;
    }

    print_tree(root->right, code, code_len);
}

void build_tree(Tree *tree, char *text, int text_len) {
    init_tree(tree);

    int i;
    for (i = 0; i < text_len; i++) {
        if (isalpha(text[i])) {
            insert_node(&(tree->root), tolower(text[i]), 1);
        }
    }
}

void encode_text(Tree *tree, char *text, int text_len, FILE *fp) {
    char code[MAX_SYMBOLS];
    int code_len = 0;

    print_tree(tree->root, code, &code_len);

    int i;
    for (i = 0; i < text_len; i++) {
        if (isalpha(text[i])) {
            fprintf(fp, "%c", code[tolower(text[i]) - 'a']);
        } else {
            fprintf(fp, "%c", text[i]);
        }
    }
}

void decode_text(Tree *tree, FILE *fp) {
    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            printf("%c", ch);
        } else {
            printf("%c", ch);
        }
    }
}

int main() {
    char text[MAX_CHARS];
    fgets(text, MAX_CHARS, stdin);
    int text_len = strlen(text);

    Tree tree;
    build_tree(&tree, text, text_len);

    FILE *fp = fopen("output.txt", "w");
    encode_text(&tree, text, text_len, fp);
    fclose(fp);

    fp = fopen("output.txt", "r");
    decode_text(&tree, fp);
    fclose(fp);

    return 0;
}