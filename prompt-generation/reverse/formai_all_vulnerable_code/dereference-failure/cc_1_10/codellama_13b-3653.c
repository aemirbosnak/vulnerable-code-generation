//Code Llama-13B DATASET v1.0 Category: Huffman Coding Implementation ; Style: energetic
// Huffman Coding Implementation in C
// By: [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 32

typedef struct node {
    char data;
    int frequency;
    struct node *left;
    struct node *right;
} node;

node *create_node(char data, int frequency) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->frequency = frequency;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void build_huffman_tree(node **root, char *data, int *frequency, int size) {
    for (int i = 0; i < size; i++) {
        node *new_node = create_node(data[i], frequency[i]);
        if (*root == NULL) {
            *root = new_node;
        } else {
            node *temp = *root;
            while (temp != NULL) {
                if (temp->frequency > new_node->frequency) {
                    if (temp->left == NULL) {
                        temp->left = new_node;
                        break;
                    } else {
                        temp = temp->left;
                    }
                } else {
                    if (temp->right == NULL) {
                        temp->right = new_node;
                        break;
                    } else {
                        temp = temp->right;
                    }
                }
            }
        }
    }
}

void print_huffman_codes(node *root, char *data, int *frequency, int size, char *code) {
    if (root == NULL) {
        return;
    }
    if (root->data != '\0') {
        printf("%c: %s\n", root->data, code);
    }
    print_huffman_codes(root->left, data, frequency, size, code);
    print_huffman_codes(root->right, data, frequency, size, code);
}

void huffman_encode(char *data, int *frequency, int size, char *output) {
    node *root = NULL;
    build_huffman_tree(&root, data, frequency, size);
    char code[MAX_CODE_LENGTH];
    memset(code, '\0', MAX_CODE_LENGTH);
    print_huffman_codes(root, data, frequency, size, code);
    free(root);
}

int main() {
    char data[] = "hello world";
    int frequency[13] = {8, 4, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1};
    int size = sizeof(data) / sizeof(data[0]);
    char output[MAX_CODE_LENGTH];
    huffman_encode(data, frequency, size, output);
    printf("Encoded data: %s\n", output);
    return 0;
}