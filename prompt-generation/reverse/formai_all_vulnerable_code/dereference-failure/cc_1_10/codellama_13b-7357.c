//Code Llama-13B DATASET v1.0 Category: Huffman Coding Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input file
#define MAX_SIZE 1024

// Define the Huffman tree structure
typedef struct {
    int freq;
    char c;
    struct node *left, *right;
} node;

// Function to create a new node
node *new_node(int freq, char c) {
    node *n = (node *)malloc(sizeof(node));
    n->freq = freq;
    n->c = c;
    n->left = n->right = NULL;
    return n;
}

// Function to build the Huffman tree
node *build_tree(int *freq, int n) {
    // Create a priority queue to store the nodes
    node *pq[n];
    for (int i = 0; i < n; i++) {
        pq[i] = new_node(freq[i], i);
    }

    // Build the Huffman tree
    while (n > 1) {
        // Find the two nodes with the minimum frequency
        node *left = pq[0], *right = pq[1];
        for (int i = 2; i < n; i++) {
            if (pq[i]->freq < left->freq) {
                left = pq[i];
            } else if (pq[i]->freq < right->freq) {
                right = pq[i];
            }
        }

        // Create a new node with the sum of the frequencies
        node *n = new_node(left->freq + right->freq, '\0');
        n->left = left;
        n->right = right;

        // Update the priority queue
        for (int i = 0; i < n; i++) {
            if (pq[i] == left || pq[i] == right) {
                pq[i] = n;
            }
        }

        // Decrement the number of nodes
        n--;
    }

    // Return the root node
    return pq[0];
}

// Function to encode the input string
void encode(node *root, char *input, char *output) {
    // Initialize the output string
    int i = 0;

    // Encode the input string
    while (*input != '\0') {
        // Traverse the Huffman tree
        node *n = root;
        while (n->c != *input) {
            if (*input < n->c) {
                n = n->left;
            } else {
                n = n->right;
            }
        }

        // Add the code to the output string
        if (n->c == *input) {
            output[i++] = n->c;
        }

        // Move to the next character
        input++;
    }

    // Add the null terminator
    output[i] = '\0';
}

// Function to decode the input string
void decode(node *root, char *input, char *output) {
    // Initialize the output string
    int i = 0;

    // Decode the input string
    while (*input != '\0') {
        // Traverse the Huffman tree
        node *n = root;
        while (n->c == '\0') {
            if (*input == '0') {
                n = n->left;
            } else {
                n = n->right;
            }
            input++;
        }

        // Add the decoded character to the output string
        output[i++] = n->c;
    }

    // Add the null terminator
    output[i] = '\0';
}

int main() {
    // Define the input and output strings
    char input[MAX_SIZE], output[MAX_SIZE];

    // Read the input string
    fgets(input, MAX_SIZE, stdin);

    // Build the Huffman tree
    int freq[26] = {0};
    for (int i = 0; i < strlen(input); i++) {
        freq[input[i] - 'a']++;
    }
    node *root = build_tree(freq, 26);

    // Encode the input string
    encode(root, input, output);
    printf("Encoded string: %s\n", output);

    // Decode the output string
    decode(root, output, input);
    printf("Decoded string: %s\n", input);

    return 0;
}