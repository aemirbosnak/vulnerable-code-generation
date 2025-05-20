//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum size of the input string
#define MAX_STRING_SIZE 100

// Node structure for the Huffman tree
typedef struct node {
    char character;
    int frequency;
    struct node *left;
    struct node *right;
} node;

// Function to create a new node
node *create_node(char character, int frequency) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->character = character;
    new_node->frequency = frequency;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a node into the priority queue
void insert_node(node **priority_queue, node *new_node) {
    int i;
    for (i = 0; i < 256; i++) {
        if (priority_queue[i] == NULL || priority_queue[i]->frequency > new_node->frequency) {
            break;
        }
    }
    for (int j = 255; j > i; j--) {
        priority_queue[j] = priority_queue[j - 1];
    }
    priority_queue[i] = new_node;
}

// Function to create a Huffman tree
node *create_huffman_tree(char *input_string) {
    // Create a priority queue to store the nodes
    node *priority_queue[256];
    for (int i = 0; i < 256; i++) {
        priority_queue[i] = NULL;
    }

    // Count the frequency of each character in the input string
    int character_frequencies[256];
    for (int i = 0; input_string[i] != '\0'; i++) {
        character_frequencies[input_string[i]]++;
    }

    // Insert the nodes into the priority queue
    for (int i = 0; i < 256; i++) {
        if (character_frequencies[i] > 0) {
            insert_node(priority_queue, create_node(i, character_frequencies[i]));
        }
    }

    // While there are more than one node in the priority queue
    while (priority_queue[1] != NULL) {
        // Remove the two nodes with the lowest frequencies
        node *left_node = priority_queue[0];
        node *right_node = priority_queue[1];
        priority_queue[0] = priority_queue[255];
        priority_queue[1] = NULL;
        priority_queue[255] = NULL;

        // Create a new node with the combined frequency of the two removed nodes
        node *new_node = create_node(' ', left_node->frequency + right_node->frequency);
        new_node->left = left_node;
        new_node->right = right_node;

        // Insert the new node into the priority queue
        insert_node(priority_queue, new_node);
    }

    // Return the root of the Huffman tree
    return priority_queue[0];
}

// Function to generate the Huffman codes
void generate_huffman_codes(node *root, char *codes[], int *code_lengths) {
    if (root->left == NULL && root->right == NULL) {
        codes[root->character] = malloc(sizeof(char) * (code_lengths[root->character] + 1));
        strcpy(codes[root->character], "");
        return;
    }

    if (root->left != NULL) {
        code_lengths[root->left->character] = code_lengths[root->character] + 1;
        codes[root->left->character] = malloc(sizeof(char) * (code_lengths[root->left->character] + 1));
        strcpy(codes[root->left->character], codes[root->character]);
        strcat(codes[root->left->character], "0");
        generate_huffman_codes(root->left, codes, code_lengths);
    }

    if (root->right != NULL) {
        code_lengths[root->right->character] = code_lengths[root->character] + 1;
        codes[root->right->character] = malloc(sizeof(char) * (code_lengths[root->right->character] + 1));
        strcpy(codes[root->right->character], codes[root->character]);
        strcat(codes[root->right->character], "1");
        generate_huffman_codes(root->right, codes, code_lengths);
    }
}

// Function to encode the input string using the Huffman codes
char *encode_string(char *input_string, char *codes[]) {
    int encoded_string_length = 0;
    for (int i = 0; input_string[i] != '\0'; i++) {
        encoded_string_length += strlen(codes[input_string[i]]);
    }

    char *encoded_string = malloc(sizeof(char) * (encoded_string_length + 1));
    int encoded_string_index = 0;
    for (int i = 0; input_string[i] != '\0'; i++) {
        strcat(encoded_string, codes[input_string[i]]);
        encoded_string_index += strlen(codes[input_string[i]]);
    }

    return encoded_string;
}

// Function to decode the encoded string using the Huffman tree
char *decode_string(char *encoded_string, node *root) {
    int decoded_string_length = strlen(encoded_string);
    char *decoded_string = malloc(sizeof(char) * (decoded_string_length + 1));
    int decoded_string_index = 0;

    node *current_node = root;
    for (int i = 0; i < decoded_string_length; i++) {
        if (encoded_string[i] == '0') {
            current_node = current_node->left;
        } else if (encoded_string[i] == '1') {
            current_node = current_node->right;
        }

        if (current_node->left == NULL && current_node->right == NULL) {
            decoded_string[decoded_string_index] = current_node->character;
            decoded_string_index++;
            current_node = root;
        }
    }

    return decoded_string;
}

int main() {
    // Get the input string from the user
    char input_string[MAX_STRING_SIZE];
    printf("Enter the string to be compressed: ");
    scanf("%s", input_string);

    // Create the Huffman tree
    node *root = create_huffman_tree(input_string);

    // Generate the Huffman codes
    char *codes[256];
    int code_lengths[256];
    for (int i = 0; i < 256; i++) {
        codes[i] = NULL;
        code_lengths[i] = 0;
    }
    generate_huffman_codes(root, codes, code_lengths);

    // Encode the input string using the Huffman codes
    char *encoded_string = encode_string(input_string, codes);

    // Decode the encoded string using the Huffman tree
    char *decoded_string = decode_string(encoded_string, root);

    // Print the original, encoded, and decoded strings
    printf("Original string: %s\n", input_string);
    printf("Encoded string: %s\n", encoded_string);
    printf("Decoded string: %s\n", decoded_string);

    // Free the allocated memory
    for (int i = 0; i < 256; i++) {
        if (codes[i] != NULL) {
            free(codes[i]);
        }
    }
    free(encoded_string);
    free(decoded_string);
    free(root);

    return 0;
}