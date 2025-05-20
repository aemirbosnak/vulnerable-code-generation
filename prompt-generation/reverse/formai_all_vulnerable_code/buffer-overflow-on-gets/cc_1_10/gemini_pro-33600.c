//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char c;
    int f;
    struct node *l;
    struct node *r;
} node;

node *tree;

void build_tree(char *s) {
    int i, j, k;
    int n = strlen(s);
    int freq[256] = {0};

    for (i = 0; i < n; i++) {
        freq[s[i]]++;
    }

    node *q[n];
    int q_size = 0;

    for (i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            node *new_node = malloc(sizeof(node));
            new_node->c = i;
            new_node->f = freq[i];
            new_node->l = NULL;
            new_node->r = NULL;
            q[q_size++] = new_node;
        }
    }

    while (q_size > 1) {
        node *n1 = q[0];
        node *n2 = q[1];
        q[0] = q[q_size - 1];
        q_size--;
        node *new_node = malloc(sizeof(node));
        new_node->c = '\0';
        new_node->f = n1->f + n2->f;
        new_node->l = n1;
        new_node->r = n2;
        q[q_size++] = new_node;

        for (i = 0; i < q_size; i++) {
            for (j = 0; j < q_size - 1; j++) {
                if (q[j]->f > q[j + 1]->f) {
                    node *temp = q[j];
                    q[j] = q[j + 1];
                    q[j + 1] = temp;
                }
            }
        }
    }

    tree = q[0];
}

void print_code(node *root, char *code) {
    if (root->l == NULL && root->r == NULL) {
        printf("%c: %s\n", root->c, code);
        return;
    }

    print_code(root->l, strcat(code, "0"));
    print_code(root->r, strcat(code, "1"));
}

void encode(char *s, char *code) {
    int i, j, k;
    int n = strlen(s);
    char encoded[n + 1];

    for (i = 0; i < n; i++) {
        node *temp = tree;
        while (temp->l != NULL || temp->r != NULL) {
            if (s[i] == temp->c) {
                break;
            } else if (s[i] < temp->c) {
                temp = temp->l;
            } else {
                temp = temp->r;
            }
        }

        strcat(encoded, code);
    }

    printf("Encoded: %s\n", encoded);
}

void decode(char *encoded) {
    int i, j;
    int n = strlen(encoded);
    char decoded[n + 1];
    node *temp = tree;

    for (i = 0; i < n; i++) {
        if (encoded[i] == '0') {
            temp = temp->l;
        } else {
            temp = temp->r;
        }

        if (temp->l == NULL && temp->r == NULL) {
            decoded[i] = temp->c;
            temp = tree;
        }
    }

    printf("Decoded: %s\n", decoded);
}

int main() {
    char s[100];
    char code[100];

    printf("Enter a string to compress: ");
    gets(s);

    build_tree(s);
    print_code(tree, code);
    encode(s, code);
    decode(code);

    return 0;
}