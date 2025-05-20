//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Custom data type for nodes in the Huffman tree
typedef struct Node {
    int frequency;  // Frequency of the character represented by the node
    unsigned char character;  // Character represented by the node (optional)
    struct Node *left;  // Left child node
    struct Node *right;  // Right child node
} Node;

// Global array to store the character frequencies
int characterFrequencies[256] = {0};

// Function to create a new node with the given frequency and character
Node *newNode(int frequency, unsigned char character) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->frequency = frequency;
    node->character = character;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to compare two nodes based on their frequencies
int compareNodes(const void *a, const void *b) {
    const Node *node1 = (const Node *)a;
    const Node *node2 = (const Node *)b;
    return node1->frequency - node2->frequency;
}

// Function to build the Huffman tree
Node *buildHuffmanTree() {
    // Create a priority queue to store the nodes
    Node *queue[256];
    int queueSize = 0;

    // Insert the nodes into the priority queue based on their frequencies
    for (int i = 0; i < 256; i++) {
        if (characterFrequencies[i] > 0) {
            queue[queueSize++] = newNode(characterFrequencies[i], i);
        }
    }
    qsort(queue, queueSize, sizeof(Node *), compareNodes);

    // Build the Huffman tree
    while (queueSize > 1) {
        // Extract the two nodes with the lowest frequencies
        Node *node1 = queue[0];
        Node *node2 = queue[1];
        queue[0] = queue[queueSize - 1];
        queueSize--;
        qsort(queue, queueSize, sizeof(Node *), compareNodes);

        // Create a new node with the combined frequency and make it the parent of the two extracted nodes
        Node *parentNode = newNode(node1->frequency + node2->frequency, 0);
        parentNode->left = node1;
        parentNode->right = node2;

        // Insert the new node into the priority queue
        queue[queueSize++] = parentNode;
        qsort(queue, queueSize, sizeof(Node *), compareNodes);
    }

    // Return the root of the Huffman tree
    return queue[0];
}

// Function to perform a depth-first traversal of the Huffman tree and generate the codewords
void generateCodewords(Node *node, unsigned char *codeword, int codewordLength) {
    if (node->left == NULL && node->right == NULL) {
        // If the node is a leaf, print the codeword
        printf("%c: %s\n", node->character, codeword);
    } else {
        // If the node is not a leaf, recursively traverse the left and right subtrees

        // Add a '0' to the codeword for the left subtree
        codeword[codewordLength] = '0';
        generateCodewords(node->left, codeword, codewordLength + 1);

        // Add a '1' to the codeword for the right subtree
        codeword[codewordLength] = '1';
        generateCodewords(node->right, codeword, codewordLength + 1);
    }
}

int main() {
    // Read the input string
    char inputString[256];
    printf("Enter the input string: ");
    scanf("%s", inputString);

    // Calculate the frequency of each character in the input string
    for (int i = 0; inputString[i] != '\0'; i++) {
        characterFrequencies[inputString[i]]++;
    }

    // Build the Huffman tree
    Node *root = buildHuffmanTree();

    // Generate the codewords for each character
    unsigned char codeword[256];
    generateCodewords(root, codeword, 0);

    return 0;
}