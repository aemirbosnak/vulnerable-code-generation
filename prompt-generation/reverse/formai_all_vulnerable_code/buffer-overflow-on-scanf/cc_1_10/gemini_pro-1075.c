//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Define the maximum number of characters in the input string
#define MAX_CHAR 256

// Structure to store the frequency of each character
typedef struct {
    char character;
    int frequency;
} Frequency;

// Structure to store a node in the Huffman tree
typedef struct Node {
    char character;
    int frequency;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node in the Huffman tree
Node* create_node(char character, int frequency) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to compare two nodes based on their frequency
int compare_nodes(const void *a, const void *b) {
    const Node *node1 = (const Node*) a;
    const Node *node2 = (const Node*) b;
    return node1->frequency - node2->frequency;
}

// Function to build the Huffman tree
Node* build_huffman_tree(Frequency frequencies[], int size) {
    // Create a priority queue to store the nodes
    Node *queue[size];
    for (int i = 0; i < size; i++) {
        queue[i] = create_node(frequencies[i].character, frequencies[i].frequency);
    }

    // Sort the nodes by frequency
    qsort(queue, size, sizeof(Node*), compare_nodes);

    // Build the Huffman tree
    while (size > 1) {
        // Remove the two nodes with the lowest frequency
        Node *node1 = queue[0];
        Node *node2 = queue[1];
        queue[0] = queue[size - 1];
        size--;

        // Create a new node with the combined frequency
        Node *parent = create_node('\0', node1->frequency + node2->frequency);
        parent->left = node1;
        parent->right = node2;

        // Insert the new node into the queue
        queue[0] = parent;

        // Sort the nodes by frequency
        qsort(queue, size, sizeof(Node*), compare_nodes);
    }

    // Return the root of the Huffman tree
    return queue[0];
}

// Function to generate the Huffman codes
void generate_huffman_codes(Node *root, char code[], int top) {
    // If the node is a leaf, assign the code to the character
    if (root->left == NULL && root->right == NULL) {
        code[top] = '\0';
        printf("%c: %s\n", root->character, code);
        return;
    }

    // If the node is not a leaf, traverse the left and right subtrees
    code[top] = '0';
    generate_huffman_codes(root->left, code, top + 1);
    code[top] = '1';
    generate_huffman_codes(root->right, code, top + 1);
}

// Function to encode the input string using the Huffman codes
char* encode_string(const char *input, char huffman_codes[][MAX_CHAR]) {
    int size = strlen(input);
    char *encoded_string = (char*) malloc(size * sizeof(char));
    int top = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < MAX_CHAR; j++) {
            if (input[i] == huffman_codes[j][0]) {
                for (int k = 1; huffman_codes[j][k] != '\0'; k++) {
                    encoded_string[top++] = huffman_codes[j][k];
                }
                break;
            }
        }
    }

    encoded_string[top] = '\0';
    return encoded_string;
}

// Function to decode the encoded string using the Huffman codes
char* decode_string(const char *encoded, Node *root) {
    int size = strlen(encoded);
    char *decoded_string = (char*) malloc(size * sizeof(char));
    int top = 0;

    Node *current = root;
    for (int i = 0; i < size; i++) {
        if (encoded[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->left == NULL && current->right == NULL) {
            decoded_string[top++] = current->character;
            current = root;
        }
    }

    decoded_string[top] = '\0';
    return decoded_string;
}

int main() {
    // Get the input string
    char input[100];
    printf("Enter the input string: ");
    scanf("%s", input);

    // Calculate the frequency of each character
    Frequency frequencies[MAX_CHAR];
    for (int i = 0; i < MAX_CHAR; i++) {
        frequencies[i].character = i;
        frequencies[i].frequency = 0;
    }
    for (int i = 0; input[i] != '\0'; i++) {
        frequencies[input[i]].frequency++;
    }

    // Build the Huffman tree
    Node *root = build_huffman_tree(frequencies, MAX_CHAR);

    // Generate the Huffman codes
    char huffman_codes[MAX_CHAR][MAX_CHAR];
    generate_huffman_codes(root, "", 0);

    // Encode the input string
    char *encoded_string = encode_string(input, huffman_codes);
    printf("Encoded string: %s\n", encoded_string);

    // Decode the encoded string
    char *decoded_string = decode_string(encoded_string, root);
    printf("Decoded string: %s\n", decoded_string);

    return 0;
}