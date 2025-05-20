//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 256

typedef struct node {
    int frequency;
    char symbol;
    struct node *left, *right;
} node_t;

typedef struct tree {
    node_t *root;
} tree_t;

void insert_node(tree_t *tree, node_t *node) {
    if (tree->root == NULL) {
        tree->root = node;
        return;
    }

    node_t *current = tree->root;
    node_t *parent = NULL;

    while (current != NULL) {
        parent = current;

        if (node->frequency < current->frequency) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (node->frequency < parent->frequency) {
        parent->left = node;
    } else {
        parent->right = node;
    }
}

void build_tree(tree_t *tree, int frequencies[], char symbols[]) {
    for (int i = 0; i < MAX_SYMBOLS; i++) {
        if (frequencies[i] > 0) {
            node_t *node = malloc(sizeof(node_t));
            node->frequency = frequencies[i];
            node->symbol = symbols[i];
            node->left = NULL;
            node->right = NULL;
            insert_node(tree, node);
        }
    }
}

void print_tree(tree_t *tree, char code[]) {
    if (tree->root == NULL) {
        return;
    }

    print_tree(tree->root->left, strcat(code, "0"));
    printf("%c: %s\n", tree->root->symbol, code);
    print_tree(tree->root->right, strcat(code, "1"));
}

void encode(tree_t *tree, char *input, char *output) {
    int input_length = strlen(input);
    int output_length = 0;

    for (int i = 0; i < input_length; i++) {
        node_t *current = tree->root;

        while (current != NULL) {
            if (current->symbol == input[i]) {
                output[output_length++] = '0' + current->frequency;
                break;
            }

            if (current->left != NULL && current->left->frequency < current->right->frequency) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
    }

    output[output_length] = '\0';
}

void decode(tree_t *tree, char *input, char *output) {
    int input_length = strlen(input);
    int output_length = 0;

    node_t *current = tree->root;

    for (int i = 0; i < input_length; i++) {
        if (input[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->left == NULL && current->right == NULL) {
            output[output_length++] = current->symbol;
            current = tree->root;
        }
    }

    output[output_length] = '\0';
}

int main() {
    int frequencies[MAX_SYMBOLS] = {0};
    char symbols[MAX_SYMBOLS];
    int symbol_count = 0;

    // Get the input string from the user.
    char input[100];
    printf("Enter the input string: ");
    scanf("%s", input);

    // Calculate the frequencies of each symbol in the input string.
    for (int i = 0; i < strlen(input); i++) {
        frequencies[input[i]]++;
    }

    // Find the unique symbols in the input string.
    for (int i = 0; i < MAX_SYMBOLS; i++) {
        if (frequencies[i] > 0) {
            symbols[symbol_count++] = i;
        }
    }

    // Build the Huffman tree.
    tree_t tree;
    tree.root = NULL;
    build_tree(&tree, frequencies, symbols);

    // Print the Huffman tree.
    printf("Huffman Tree:\n");
    print_tree(&tree, "");

    // Encode the input string using the Huffman tree.
    char output[100];
    encode(&tree, input, output);

    // Print the encoded string.
    printf("Encoded String:\n");
    printf("%s\n", output);

    // Decode the encoded string using the Huffman tree.
    char decoded[100];
    decode(&tree, output, decoded);

    // Print the decoded string.
    printf("Decoded String:\n");
    printf("%s\n", decoded);

    return 0;
}