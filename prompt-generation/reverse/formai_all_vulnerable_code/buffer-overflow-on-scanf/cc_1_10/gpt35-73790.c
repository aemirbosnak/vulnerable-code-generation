//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define CHAR_COUNT 128

typedef struct Node {
    char character;
    int count;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct HuffmanTree {
    Node *root;
} HuffmanTree;

typedef struct Code {
    int binary_code;
    int bits;
} Code;

Node *create_node(char character, int count, Node *left, Node *right) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->character = character;
    node->count = count;
    node->left = left;
    node->right = right;
    return node;
}

HuffmanTree *create_huffman_tree(char *text) {
    int char_counts[CHAR_COUNT] = { 0 };
    int i;

    for (i = 0; i < strlen(text); i++) {
        char_counts[text[i]]++;
    }

    Node *node_queue[CHAR_COUNT] = { NULL };
    int node_queue_count = 0;
    for (i = 0; i < CHAR_COUNT; i++) {
        if (char_counts[i] > 0) {
            node_queue[node_queue_count++] = create_node(i, char_counts[i], NULL, NULL);
        }
    }
    while (node_queue_count > 1) {
        Node *first_node = node_queue[0];
        Node *second_node = node_queue[1];
        node_queue_count--;
        if (node_queue_count > 0) {
            memmove(&node_queue[0], &node_queue[1], node_queue_count * sizeof(Node *));
        }
        Node *new_node = create_node('\0', first_node->count + second_node->count, first_node, second_node);
        int j = node_queue_count - 1;
        for (; j >= 0; j--) {
            if (node_queue[j]->count >= new_node->count) {
                break;
            }
            node_queue[j + 1] = node_queue[j];
        }
        node_queue[j + 1] = new_node;
        node_queue_count++;
    }

    HuffmanTree *tree = (HuffmanTree *)malloc(sizeof(HuffmanTree));
    tree->root = node_queue[0];
    return tree;
}

Code *generate_huffman_codes_helper(Node *node, int binary_code, int bits) {
    if (node->left == NULL && node->right == NULL) {
        Code *code = (Code *)malloc(sizeof(Code));
        code->binary_code = binary_code;
        code->bits = bits;
        return code;
    }

    Code *codes[2] = { NULL };
    codes[0] = generate_huffman_codes_helper(node->left, (binary_code << 1) | 0, bits + 1);
    codes[1] = generate_huffman_codes_helper(node->right, (binary_code << 1) | 1, bits + 1);

    Code *merged_codes = (Code *)malloc(2 * sizeof(Code));
    merged_codes[0] = *codes[0];
    merged_codes[1] = *codes[1];

    free(codes[0]);
    free(codes[1]);
    return merged_codes;
}

Code *generate_huffman_codes(HuffmanTree *tree) {
    return generate_huffman_codes_helper(tree->root, 0, 0);
}

void encode_text(HuffmanTree *tree, Code *huffman_codes, char *text) {
    int i;
    printf("Encoded Text: ");
    for (i = 0; i < strlen(text); i++) {
        int ascii_value = (int)text[i];
        Code code = huffman_codes[ascii_value];
        int j;
        for (j = code.bits - 1; j >= 0; j--) {
            printf("%c", (code.binary_code & (1 << j)) ? '1' : '0');
        }
    }
    printf("\n");
}

int main() {
    char text[100];
    printf("Enter text to encode: ");
    scanf("%[^\n]s", text);
    getchar();

    HuffmanTree *tree = create_huffman_tree(text);
    Code *huffman_codes = generate_huffman_codes(tree);

    int i;
    for (i = 0; i < CHAR_COUNT; i++) {
        if (huffman_codes[i].bits > 0) {
            printf("'%c'   -> %d\n", (char)i, huffman_codes[i].binary_code);
        }
    }

    encode_text(tree, huffman_codes, text);
    
    free(huffman_codes);
    free(tree);
    return 0;
}