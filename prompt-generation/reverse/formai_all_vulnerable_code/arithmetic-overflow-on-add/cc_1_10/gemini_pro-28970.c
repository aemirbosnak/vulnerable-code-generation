//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the input string
#define MAX_SIZE 100

// Define the Huffman coding tree node
typedef struct node {
    int data;
    int freq;
    struct node *left;
    struct node *right;
} node;

// Define the Huffman coding table
typedef struct table {
    int code;
    int len;
} table;

// Function to create a new Huffman coding node
node* create_node(int data, int freq) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->freq = freq;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to compare two Huffman coding nodes based on their frequencies
int compare(const void *a, const void *b) {
    node *x = *(node**)a;
    node *y = *(node**)b;
    return x->freq - y->freq;
}

// Function to build a Huffman coding tree
node* build_tree(int freq[], int size) {
    // Create a priority queue of Huffman coding nodes
    node** pq = (node**)malloc(sizeof(node*) * size);
    int pq_size = 0;

    // Initialize the priority queue with the individual characters
    for (int i = 0; i < size; i++) {
        if (freq[i] > 0) {
            pq[pq_size++] = create_node(i, freq[i]);
        }
    }

    // Build the Huffman coding tree
    while (pq_size > 1) {
        // Sort the priority queue by frequencies
        qsort(pq, pq_size, sizeof(node*), compare);

        // Extract the two nodes with the lowest frequencies
        node *left = pq[0];
        node *right = pq[1];

        // Create a new node with the combined frequency
        node *parent = create_node(0, left->freq + right->freq);

        // Set the left and right children of the new node
        parent->left = left;
        parent->right = right;

        // Remove the two nodes from the priority queue
        pq[0] = pq[pq_size - 1];
        pq_size--;

        // Insert the new node into the priority queue
        pq[pq_size++] = parent;
    }

    // Return the root of the Huffman coding tree
    return pq[0];
}

// Function to generate the Huffman coding table
void generate_table(node* root, table* table, int code, int len) {
    if (root->left == NULL && root->right == NULL) {
        // If the node is a leaf, set the code and length in the table
        table[root->data].code = code;
        table[root->data].len = len;
        return;
    }

    // If the node is not a leaf, recursively generate the codes for its children
    generate_table(root->left, table, code << 1, len + 1);
    generate_table(root->right, table, (code << 1) | 1, len + 1);
}

// Function to compress the input string using Huffman coding
char* compress(char* input, int freq[], table* table, int size) {
    // Calculate the total length of the compressed string
    int compressed_len = 0;
    for (int i = 0; i < size; i++) {
        compressed_len += freq[i] * table[i].len;
    }

    // Allocate memory for the compressed string
    char* compressed = (char*)malloc(compressed_len + 1);

    // Initialize the compressed string
    int index = 0;

    // Compress the input string using Huffman coding
    for (int i = 0; i < size; i++) {
        if (freq[i] > 0) {
            for (int j = 0; j < freq[i]; j++) {
                for (int k = 0; k < table[i].len; k++) {
                    compressed[index++] = (table[i].code >> k) & 1 ? '1' : '0';
                }
            }
        }
    }

    // Terminate the compressed string
    compressed[index] = '\0';

    // Return the compressed string
    return compressed;
}

// Function to decompress the compressed string using Huffman coding
char* decompress(char* compressed, node* root, int size) {
    // Allocate memory for the decompressed string
    char* decompressed = (char*)malloc(size + 1);

    // Initialize the decompressed string
    int index = 0;

    // Decompress the compressed string using Huffman coding
    node* current = root;
    for (int i = 0; i < strlen(compressed); i++) {
        if (compressed[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->left == NULL && current->right == NULL) {
            decompressed[index++] = current->data;
            current = root;
        }
    }

    // Terminate the decompressed string
    decompressed[index] = '\0';

    // Return the decompressed string
    return decompressed;
}

// Main function
int main() {
    // Initialize the input string
    char input[] = "Hello world";

    // Calculate the frequencies of the characters in the input string
    int freq[MAX_SIZE] = {0};
    for (int i = 0; i < strlen(input); i++) {
        freq[input[i]]++;
    }

    // Build the Huffman coding tree
    node* root = build_tree(freq, MAX_SIZE);

    // Generate the Huffman coding table
    table table[MAX_SIZE];
    generate_table(root, table, 0, 0);

    // Compress the input string using Huffman coding
    char* compressed = compress(input, freq, table, MAX_SIZE);

    // Print the compressed string
    printf("Compressed string: %s\n", compressed);

    // Decompress the compressed string using Huffman coding
    char* decompressed = decompress(compressed, root, strlen(input));

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}