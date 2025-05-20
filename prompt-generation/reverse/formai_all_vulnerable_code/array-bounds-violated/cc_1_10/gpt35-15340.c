//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SYMBOL_LIMIT 256

typedef struct node Node;
struct node {
    Node* left;
    Node* right;
    int value;
    int code[SYMBOL_LIMIT];
};

Node* create_node() {
    Node* node = (Node*) malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    return node;
}

void generate_codes(Node* node, int* code, int depth) {
    if(node->left != NULL) {
        code[depth] = 0;
        generate_codes(node->left, code, depth + 1);
    }
    if(node->right != NULL) {
        code[depth] = 1;
        generate_codes(node->right, code, depth + 1);
    }
    if(node->left == NULL && node->right == NULL) {
        memcpy(node->code, code, sizeof(int) * depth);
    }
}

int compare_nodes(const void* a, const void* b) {
    return (*((Node* const*) a))->value - (*((Node* const*) b))->value;
}

void huffman_encode(const char* input_file_path, const char* output_file_path) {
    // Read file and count character appearances:
    FILE* input_file = fopen(input_file_path, "r");
    int symbol_count[SYMBOL_LIMIT] = { 0 };
    char symbol = fgetc(input_file);
    while(symbol != EOF) {
        ++symbol_count[(int) symbol];
        symbol = fgetc(input_file);
    }
    fclose(input_file);
    // Create nodes for each symbol:
    Node* symbols[SYMBOL_LIMIT];
    for(int symbol = 0; symbol < SYMBOL_LIMIT; ++symbol) {
        if(symbol_count[symbol] > 0) {
            Node* node = create_node();
            node->value = symbol_count[symbol];
            symbols[symbol] = node;
        }
        else {
            symbols[symbol] = NULL;
        }
    }
    // Create huffman tree:
    int symbol_count_total = 0;
    for(int symbol = 0; symbol < SYMBOL_LIMIT; ++symbol) {
        if(symbols[symbol] != NULL) {
            ++symbol_count_total;
        }
    }
    Node** nodes = (Node**) malloc(sizeof(Node*) * symbol_count_total);
    for(int i = 0, j = 0; i < SYMBOL_LIMIT; ++i) {
        if(symbols[i] != NULL) {
            nodes[j++] = symbols[i];
        }
    }
    while(symbol_count_total > 1) {
        qsort(nodes, symbol_count_total, sizeof(Node*), compare_nodes);
        Node* node = create_node();
        node->value = nodes[0]->value + nodes[1]->value;
        node->left = nodes[0];
        node->right = nodes[1];
        nodes[0] = node;
        --symbol_count_total;
        for(int i = 1; i < symbol_count_total; ++i) {
            nodes[i] = nodes[i + 1];
        }
    }
    // Generate codes:
    int code[SYMBOL_LIMIT] = { 0 };
    generate_codes(nodes[0], code, 0);
    // Write codes to file:
    input_file = fopen(input_file_path, "r");
    FILE* output_file = fopen(output_file_path, "wb");
    symbol = fgetc(input_file);
    int bit_index = 7;
    int buf = 0;
    while(symbol != EOF) {
        int* symbol_code = symbols[(int) symbol]->code;
        for(int i = 0; symbol_code[i] != -1; ++i) {
            buf |= symbol_code[i] << bit_index;
            if(bit_index == 0) {
                fputc(buf, output_file);
                buf = 0;
                bit_index = 7;
            }
            else {
                --bit_index;
            }
        }
        symbol = fgetc(input_file);
    }
    if(bit_index != 7) {
        fputc(buf, output_file);
    }
    fclose(input_file);
    fclose(output_file);
    // Free memory:
    for(int i = 0; i < SYMBOL_LIMIT; ++i) {
        free(symbols[i]);
    }
    free(nodes);
}

void huffman_decode(const char* input_file_path, const char* output_file_path) {
    // Read file and count bits:
    FILE* input_file = fopen(input_file_path, "rb");
    int symbol_count[2] = { 0 };
    int bit = fgetc(input_file);
    while(bit != EOF) {
        ++symbol_count[bit];
        bit = fgetc(input_file);
    }
    fclose(input_file);
    // Create huffman tree:
    Node* node = create_node();
    node->left = create_node();
    node->right = create_node();
    node->left->value = symbol_count[0];
    node->right->value = symbol_count[1];
    // Generate codes:
    int code[SYMBOL_LIMIT] = { 0 };
    generate_codes(node, code, 0);
    // Decode file:
    input_file = fopen(input_file_path, "rb");
    FILE* output_file = fopen(output_file_path, "w");
    Node* current_node = node;
    bit = fgetc(input_file);
    while(bit != EOF) {
        for(int i = 7; i >= 0; --i) {
            if(current_node->left == NULL && current_node->right == NULL) {
                fputc(current_node->value, output_file);
                current_node = node;
            }
            if((bit >> i) & 1) {
                current_node = current_node->right;
            }
            else {
                current_node = current_node->left;
            }
        }
        bit = fgetc(input_file);
    }
    fclose(input_file);
    fclose(output_file);
    // Free memory:
    free(node->left);
    free(node->right);
    free(node);
}

int main() {
    huffman_encode("input.txt", "output.bin");
    huffman_decode("output.bin", "output.txt");
    printf("Done!\n");
    return 0;
}