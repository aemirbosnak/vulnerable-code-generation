//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_SYMBOLS 256

typedef struct {
    char symbol;
    int frequency;
    struct node* left;
    struct node* right;
} HuffmanNode;

typedef struct {
    HuffmanNode* root;
    int num_symbols;
} HuffmanTree;

HuffmanNode* create_node(char symbol, int frequency) {
    HuffmanNode* node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    node->symbol = symbol;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int compare_nodes(const void* a, const void* b) {
    HuffmanNode* node1 = *(HuffmanNode**)a;
    HuffmanNode* node2 = *(HuffmanNode**)b;
    return node1->frequency - node2->frequency;
}

void build_tree(HuffmanTree* tree, int num_symbols) {
    HuffmanNode** nodes = (HuffmanNode**)malloc(sizeof(HuffmanNode*) * num_symbols);
    for (int i = 0; i < num_symbols; i++) {
        nodes[i] = create_node('a' + i, 0);
    }
    for (int i = 0; i < num_symbols; i++) {
        scanf("%d", &nodes[i]->frequency);
    }
    qsort(nodes, num_symbols, sizeof(HuffmanNode*), compare_nodes);
    HuffmanNode* root = NULL;
    for (int i = num_symbols - 1; i > 0; i--) {
        HuffmanNode* left = nodes[i];
        HuffmanNode* right = nodes[i - 1];
        HuffmanNode* parent = create_node('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        root = parent;
    }
    tree->root = root;
    tree->num_symbols = num_symbols;
}

void generate_codes(HuffmanNode* node, char* code, int code_length) {
    if (node == NULL) {
        return;
    }
    if (node->left == NULL && node->right == NULL) {
        printf("%c -> %s\n", node->symbol, code);
    }
    code_length++;
    generate_codes(node->left, code, code_length);
    generate_codes(node->right, code, code_length);
}

void generate_huffman_codes(HuffmanTree* tree) {
    char code[MAX_SYMBOLS];
    generate_codes(tree->root, code, 0);
}

int main() {
    int num_symbols;
    scanf("%d", &num_symbols);
    HuffmanTree tree = {NULL, 0};
    build_tree(&tree, num_symbols);
    printf("Huffman codes:\n");
    generate_huffman_codes(&tree);
    return 0;
}