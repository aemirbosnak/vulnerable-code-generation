//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HEIGHT 1000
#define MAX_CHARS 256
#define MAX_CODE_LEN 16

struct node {
    int freq;
    char ch;
    int code;
    struct node *left, *right;
};

struct node *create_node(int freq, char ch, int code_len) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->freq = freq;
    new_node->ch = ch;
    new_node->code = 0;
    new_node->left = new_node->right = NULL;
    return new_node;
}

struct node *create_tree(char *text, int text_len) {
    struct node *root = NULL;
    int i;
    for (i = 0; i < text_len; i++) {
        if (text[i] == '\n')
            continue;
        struct node *new_node = root;
        while (new_node!= NULL) {
            if (new_node->ch == text[i]) {
                new_node->freq++;
                break;
            } else if (new_node->ch < text[i]) {
                new_node = new_node->right;
            } else {
                new_node = new_node->left;
            }
        }
        if (new_node == NULL) {
            new_node = create_node(1, text[i], 0);
            if (root == NULL) {
                root = new_node;
            } else {
                struct node *curr_node = root;
                while (curr_node->right!= NULL) {
                    curr_node = curr_node->right;
                }
                curr_node->right = new_node;
            }
        }
    }
    return root;
}

void encode_huffman(struct node *root, char *text, int text_len, FILE *fp) {
    int i;
    for (i = 0; i < text_len; i++) {
        fputc(root->code, fp);
        root = root->left;
        while (root->right!= NULL) {
            root = root->right;
        }
    }
}

void decode_huffman(struct node *root, FILE *fp) {
    int code, i;
    while (fgetc(fp)!= EOF) {
        code = 0;
        while (root->left!= NULL && root->left->freq <= code) {
            root = root->left;
        }
        while (root->right!= NULL && root->right->freq <= code) {
            root = root->right;
        }
        if (root->left!= NULL) {
            printf("%c", root->left->ch);
            root = root->left;
        } else {
            printf("%c", root->ch);
            root = root->right;
        }
    }
}

int main() {
    char text[MAX_CHARS];
    int text_len;
    struct node *root;
    FILE *fp;

    printf("Enter the text to be compressed: ");
    scanf("%s", text);
    text_len = strlen(text);

    root = create_tree(text, text_len);
    encode_huffman(root, text, text_len, fp);

    printf("Compressed text written to file.\n");

    return 0;
}