//FormAI DATASET v1.0 Category: Compression algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum size of the input file
#define MAX_FILE_SIZE 1024

// Define the character frequency table size
#define CHAR_FREQUENCY_TABLE_SIZE 256

// Define the node structure for the Huffman tree
struct huffman_node {
    unsigned char data;
    unsigned int frequency;
    struct huffman_node *left, *right;
};

// Function to create a new node for the Huffman tree
struct huffman_node* create_node(unsigned char data, unsigned int frequency) {
    struct huffman_node* node = (struct huffman_node*) malloc(sizeof(struct huffman_node));
    node->data = data;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

// Function to compare two Huffman nodes
int compare_nodes(const void* a, const void* b) {
    struct huffman_node** node1 = (struct huffman_node**) a;
    struct huffman_node** node2 = (struct huffman_node**) b;
    return (*node1)->frequency - (*node2)->frequency;
}

// Function to build the Huffman tree
struct huffman_node* build_huffman_tree(unsigned int* frequency_table) {
    // Create an array of Huffman nodes
    struct huffman_node* nodes[CHAR_FREQUENCY_TABLE_SIZE];
    int node_count = 0;
    for (int i = 0; i < CHAR_FREQUENCY_TABLE_SIZE; i++) {
        if (frequency_table[i] > 0) {
            nodes[node_count++] = create_node((unsigned char) i, frequency_table[i]);
        }
    }

    // Build the Huffman tree
    while (node_count > 1) {
        // Sort the nodes by frequency in ascending order
        qsort(nodes, node_count, sizeof(struct huffman_node*), compare_nodes);

        // Create a new parent node with the two smallest frequency nodes
        struct huffman_node* parent = create_node(0, nodes[0]->frequency + nodes[1]->frequency);
        parent->left = nodes[0];
        parent->right = nodes[1];

        // Remove the two smallest frequency nodes and add the parent node
        nodes[0] = parent;
        nodes[1] = nodes[--node_count];
        nodes[node_count] = NULL;
    }

    // Return the root node of the Huffman tree
    return nodes[0];
}

// Function to encode the input file using the Huffman tree
void encode_huffman_file(FILE* input_file, FILE* output_file, struct huffman_node* root_node, unsigned int* frequency_table) {
    // Write the frequency table to the output file
    fwrite(frequency_table, sizeof(unsigned int), CHAR_FREQUENCY_TABLE_SIZE, output_file);

    // Write the encoded data to the output file
    unsigned char buffer = 0;
    int bit_count = 0;
    int byte_count = 0;
    int character;
    while ((character = getc(input_file)) != EOF) {
        // Traverse the Huffman tree to find the encoding for the character
        struct huffman_node* node = root_node;
        while (node->left != NULL && node->right != NULL) {
            if (character & (1 << bit_count)) {
                node = node->right;
            } else {
                node = node->left;
            }
            if (++bit_count == 8) {
                bit_count = 0;
                buffer |= (node == root_node ? 0 : 1) << byte_count++;
                if (byte_count == sizeof(buffer)) {
                    fwrite(&buffer, sizeof(unsigned char), 1, output_file);
                    byte_count = 0;
                    buffer = 0;
                }
            }
        }

        // Update the frequency count for the character
        frequency_table[character]++;
    }

    // Write the final byte to the output file
    if (byte_count > 0) {
        fwrite(&buffer, sizeof(unsigned char), 1, output_file);
    }
}

// Function to decode the input file using the Huffman tree
void decode_huffman_file(FILE* input_file, FILE* output_file, struct huffman_node* root_node) {
    // Read the frequency table from the input file
    unsigned int frequency_table[CHAR_FREQUENCY_TABLE_SIZE] = {0};
    fread(frequency_table, sizeof(unsigned int), CHAR_FREQUENCY_TABLE_SIZE, input_file);

    // Rebuild the Huffman tree using the frequency table
    struct huffman_node* node_stack[MAX_FILE_SIZE];
    int stack_count = 0;
    node_stack[stack_count++] = root_node;
    while (stack_count > 0) {
        struct huffman_node* node = node_stack[--stack_count];
        if (node->left == NULL && node->right == NULL) {
            node->frequency = frequency_table[node->data];
        } else {
            node_stack[stack_count++] = node->left;
            node_stack[stack_count++] = node->right;
        }
    }
    root_node = build_huffman_tree(frequency_table);

    // Read the encoded data from the input file and write the decoded data to the output file
    struct huffman_node* node = root_node;
    int bit_count = 0;
    int character;
    while ((character = getc(input_file)) != EOF) {
        for (int i = 0; i < 8; i++) {
            if (character & (1 << i)) {
                node = node->right;
            } else {
                node = node->left;
            }
            if (node->left == NULL && node->right == NULL) {
                fwrite(&node->data, sizeof(unsigned char), 1, output_file);
                node = root_node;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s [e|d] <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    // Open the input and output files
    FILE* input_file = fopen(argv[2], "rb");
    FILE* output_file = fopen(argv[3], "wb");
    if (input_file == NULL || output_file == NULL) {
        fprintf(stderr, "Error: Unable to open input/output file\n");
        return 1;
    }

    // Create the character frequency table
    unsigned int frequency_table[CHAR_FREQUENCY_TABLE_SIZE] = {0};
    int character;
    while ((character = getc(input_file)) != EOF) {
        frequency_table[character]++;
    }
    rewind(input_file);

    // Build the Huffman tree
    struct huffman_node* root_node = build_huffman_tree(frequency_table);

    // Encode or decode the input file based on the command-line argument
    if (strcmp(argv[1], "e") == 0) {
        encode_huffman_file(input_file, output_file, root_node, frequency_table);
    } else if (strcmp(argv[1], "d") == 0) {
        decode_huffman_file(input_file, output_file, root_node);
    } else {
        fprintf(stderr, "Error: Invalid command-line argument\n");
        return 1;
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}