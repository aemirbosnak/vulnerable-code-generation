//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

// Node for Huffman Tree
typedef struct node {
    char character;
    int frequency;
    struct node * left, * right;
} Node;

// Comparison function for sorting the nodes by frequency
int compare(const void * a, const void * b) {
    return ((Node *) a)->frequency - ((Node *) b)->frequency;
}

// Function to create a new node
Node * create_node(char character, int frequency) {
    Node * new_node = (Node *) malloc(sizeof(Node));
    new_node->character = character;
    new_node->frequency = frequency;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Function to create a Huffman tree
Node * create_huffman_tree(char * input, int length) {
    // Create an array of nodes, each representing a unique character in the input
    Node * nodes[length];
    for (int i = 0; i < length; i++) {
        nodes[i] = create_node(input[i], 1);
    }

    // Sort the nodes by frequency
    qsort(nodes, length, sizeof(Node *), compare);

    // Create a Huffman tree by combining the nodes with the lowest frequencies
    while (length > 1) {
        Node * left = nodes[0];
        Node * right = nodes[1];

        // Create a new node representing the combined frequency of the left and right nodes
        Node * parent = create_node('\0', left->frequency + right->frequency);

        // Set the left and right children of the parent node
        parent->left = left;
        parent->right = right;

        // Remove the left and right nodes from the array of nodes
        nodes[0] = nodes[length - 1];
        length--;

        // Insert the parent node into the array of nodes
        nodes[length] = parent;

        // Sort the nodes by frequency
        qsort(nodes, length, sizeof(Node *), compare);
    }

    // Return the root of the Huffman tree
    return nodes[0];
}

// Function to generate Huffman codes for each character
void generate_huffman_codes(Node * root, char * codes[], int length) {
    // If the node is a leaf node, assign the Huffman code to the corresponding character
    if (root->left == NULL && root->right == NULL) {
        codes[root->character - 'A'] = malloc(length + 1);
        strcpy(codes[root->character - 'A'], "");
        return;
    }

    // Generate Huffman codes for the left and right subtrees
    generate_huffman_codes(root->left, codes, length + 1);
    generate_huffman_codes(root->right, codes, length + 1);

    // Append '0' to the Huffman codes for the left subtree
    for (int i = 0; i < length; i++) {
        if (codes[root->left->character - 'A'] != NULL) {
            codes[root->left->character - 'A'][i] = '0';
        }
    }

    // Append '1' to the Huffman codes for the right subtree
    for (int i = 0; i < length; i++) {
        if (codes[root->right->character - 'A'] != NULL) {
            codes[root->right->character - 'A'][i] = '1';
        }
    }
}

// Function to encode the input string using the Huffman codes
char * encode(char * input, char * codes[], int length) {
    char * encoded_string = malloc(length * 8 + 1);
    int index = 0;

    for (int i = 0; i < length; i++) {
        char * code = codes[input[i] - 'A'];
        for (int j = 0; j < strlen(code); j++) {
            encoded_string[index++] = code[j];
        }
    }

    encoded_string[index] = '\0';
    return encoded_string;
}

// Function to decode the encoded string using the Huffman tree
char * decode(char * encoded_string, Node * root, int length) {
    char * decoded_string = malloc(length + 1);
    int index = 0;

    Node * current = root;
    for (int i = 0; i < length; i++) {
        if (encoded_string[i] == '0') {
            current = current->left;
        } else if (encoded_string[i] == '1') {
            current = current->right;
        }

        // If the current node is a leaf node, add the character to the decoded string
        if (current->left == NULL && current->right == NULL) {
            decoded_string[index++] = current->character;
            current = root;
        }
    }

    decoded_string[index] = '\0';
    return decoded_string;
}

// Function to print the Huffman codes
void print_huffman_codes(char * codes[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%c: %s\n", i + 'A', codes[i]);
    }
}

// Main function
int main() {
    // Get the input string
    char input[100];
    printf("Enter the input string: ");
    scanf("%s", &input);

    // Get the length of the input string
    int length = strlen(input);

    // Create a Huffman tree
    Node * root = create_huffman_tree(input, length);

    // Generate Huffman codes for each character
    char * codes[length];
    generate_huffman_codes(root, codes, 0);

    // Print the Huffman codes
    printf("\nHuffman Codes:\n");
    print_huffman_codes(codes, length);

    // Encode the input string using the Huffman codes
    char * encoded_string = encode(input, codes, length);

    // Print the encoded string
    printf("\nEncoded String: %s\n", encoded_string);

    // Decode the encoded string using the Huffman tree
    char * decoded_string = decode(encoded_string, root, length);

    // Print the decoded string
    printf("\nDecoded String: %s\n", decoded_string);

    return 0;
}