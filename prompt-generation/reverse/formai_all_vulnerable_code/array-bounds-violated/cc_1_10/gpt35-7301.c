//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_LENGTH 10000

// Define a frequency table struct to hold the count of each character
typedef struct frequency_table {
    char character;
    int count;
} FrequencyTable;

// Define a node struct for the Huffman tree
typedef struct huffman_node {
    char character;
    int count;
    struct huffman_node *left;
    struct huffman_node *right;
} HuffmanNode;

// Define a function to create a frequency table from an input string
FrequencyTable *create_frequency_table(char *input) {
    
    // Initialize an array to keep track of the character frequencies
    int frequency_count[256] = {0};
    
    // Loop through the input string and count the frequency of each character
    for (int i = 0; input[i] != '\0'; i++) {
        frequency_count[(int)input[i]]++;
    }
    
    // Allocate space for the frequency table array
    FrequencyTable *freq_table = malloc(sizeof(FrequencyTable) * 256);
    
    // Loop through the frequency count array and add each character and count to the frequency table
    int j = 0;
    for (int i = 0; i < 256; i++) {
        if (frequency_count[i] > 0) {
            freq_table[j].character = (char)i;
            freq_table[j].count = frequency_count[i];
            j++;
        }
    }
    
    // Resize the frequency table array to conserve memory
    freq_table = realloc(freq_table, sizeof(FrequencyTable) * j);
    
    return freq_table;
}

// Define a function to create a new Huffman node
HuffmanNode *create_huffman_node(char character, int count) {
    HuffmanNode *new_node = malloc(sizeof(HuffmanNode));
    new_node->character = character;
    new_node->count = count;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Define a function to find the two smallest nodes in a Huffman tree node array
void find_smallest_nodes(HuffmanNode **tree_nodes, int num_nodes, int *smallest_node_index, int *second_smallest_node_index) {
    // Initialize the smallest and second smallest nodes to the first two nodes in the array
    *smallest_node_index = 0;
    *second_smallest_node_index = 1;
    // Loop through the remaining nodes in the array and compare the counts to find the smallest and second smallest nodes
    for (int i = 1; i < num_nodes; i++) {
        if (tree_nodes[i]->count < tree_nodes[*smallest_node_index]->count) {
            *second_smallest_node_index = *smallest_node_index;
            *smallest_node_index = i;
        } else if (tree_nodes[i]->count < tree_nodes[*second_smallest_node_index]->count) {
            *second_smallest_node_index = i;
        }
    }
}

// Define a function to build a Huffman tree from a frequency table
HuffmanNode *build_huffman_tree(FrequencyTable *freq_table, int num_chars) {
    
    // Create an array to hold the Huffman Tree Nodes
    HuffmanNode **tree_nodes = malloc(sizeof(HuffmanNode*)*num_chars);
    
    // Convert the frequency table into individual trees
    for(int i = 0; i < num_chars; i++) {
        tree_nodes[i] = create_huffman_node(freq_table[i].character, freq_table[i].count);
    }
    
    // Loop through the array of Huffman Tree Nodes while joining the two nodes with the smallest counts
    int smallest_node_index, second_smallest_node_index;
    for(int i = 0; i < num_chars - 1; i++) {
        
        // Find the two smallest nodes
        find_smallest_nodes(tree_nodes, num_chars-i, &smallest_node_index, &second_smallest_node_index);
        
        // Create a new parent node and set its count to the sum of the two smallest nodes' counts
        HuffmanNode *parent_node = create_huffman_node('*', (tree_nodes[smallest_node_index]->count + tree_nodes[second_smallest_node_index]->count));
        
        // Set the new parent node's left and right children to the two smallest nodes
        parent_node->left = tree_nodes[smallest_node_index];
        parent_node->right = tree_nodes[second_smallest_node_index];
        
        // Replace the smallest node with the new parent node
        tree_nodes[smallest_node_index] = parent_node;
        
        // Shift the remaining nodes in the array over to remove the second smallest node
        for(int j = second_smallest_node_index; j < num_chars - i - 2; j++) {
            tree_nodes[j] = tree_nodes[j+1];
        }
    }
    
    // Return the root node of the completed Huffman tree
    HuffmanNode *root_node = tree_nodes[0];
    free(tree_nodes);
    return root_node;
}

// Define a function to recursively traverse the Huffman tree to generate the codes for each character
void generate_character_codes(HuffmanNode *node, char *code, char *codes[]) {
    if (node->left == NULL && node->right == NULL) {
        codes[(int)node->character] = code;
    } else {
        char *left_code = malloc(strlen(code) + 2);
        snprintf(left_code, strlen(code) + 2, "%s0", code);
        generate_character_codes(node->left, left_code, codes);
        char *right_code = malloc(strlen(code) + 2);
        snprintf(right_code, strlen(code) + 2, "%s1", code);
        generate_character_codes(node->right, right_code, codes);
    }
}

/* Define the main Huffman coding function that takes in a string input and returns the Huffman encoded string */
char *huffman_encode(char *input) {
    
    // Create a frequency table from the input string
    FrequencyTable *freq_table = create_frequency_table(input);
    
    // Build a Huffman tree from the frequency table
    int num_chars = strlen(input);
    HuffmanNode *huffman_tree = build_huffman_tree(freq_table, num_chars);
    
    // Generate the Huffman codes for each character in the input string
    char **codes = malloc(sizeof(char*) * 256);
    generate_character_codes(huffman_tree, "", codes);
    
    // Encode the input string using the Huffman codes
    int output_len = 0;
    char *output = calloc((num_chars*8), sizeof(char)); // Initialize the output string to be the length of the input string times the maximum number of bits needed for a character
    for (int i = 0; input[i] != '\0'; i++) {
        char *code = codes[(int)input[i]];
        strcat(output, code);
        output_len += strlen(code);
    }
    
    // Free memory allocated for the Huffman Tree nodes and frequency table
    free(huffman_tree);
    free(freq_table);
    
    // Free the memory allocated for the Huffman codes array
    for (int i = 0; i < 256; i++) {
        if (codes[i] != NULL) {
            free(codes[i]);
        }
    }
    free(codes);
    
    return output;
}

/* Example usage */
int main() {
    char input[MAX_LENGTH];
    printf("Please enter a string to encode with Huffman coding: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline character from fgets input
    
    char *encoded_string = huffman_encode(input);
    printf("Encoded string: %s\n", encoded_string);
    free(encoded_string);
    
    return 0;
}