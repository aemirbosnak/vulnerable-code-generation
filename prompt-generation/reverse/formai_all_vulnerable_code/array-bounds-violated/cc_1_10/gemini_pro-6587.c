//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our jolly Huffman tree node
typedef struct Node {
    int frequency;
    char character;
    struct Node *left, *right;
} Node;

// Head honcho of the Huffman tree
Node *root = NULL;

// Let's create a node for our tree
Node *createNode(int frequency, char character) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->frequency = frequency;
    newNode->character = character;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build the Huffman tree. Prepare yourself for a mind-boggling dance!
Node *buildTree(char *message) {
    int frequencies[256] = {0}; // Array to keep track of character frequencies
    int messageLength = strlen(message); // Message length - the size of our dance floor

    // Step 1: Find out how often each character shows up
    for (int i = 0; i < messageLength; i++) {
        frequencies[message[i]]++;
    }

    // Step 2: Get the party started! Create the initial forest
    for (int i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            root = createNode(frequencies[i], i);
        }
    }

    // Step 3: The merging of the trees
    while (root->left && root->right) { 
        Node *leftChild = root->left;
        Node *rightChild = root->right;

        // Find the two trees with the lowest frequencies
        Node *min1 = leftChild;
        Node *min2 = rightChild;
        while (min1->left != NULL) {
            min1 = min1->left;
        }
        while (min2->left != NULL) {
            min2 = min2->left;
        }

        // Create a new parent node to unite them in harmony
        Node *parentNode = createNode(min1->frequency + min2->frequency, 0);
        parentNode->left = min1;
        parentNode->right = min2;

        // Replace the left and right children
        if (leftChild->frequency <= rightChild->frequency) {
            root->left = parentNode;
            root = root->left;
        }
        else {
            root->right = parentNode;
            root = root->right;
        }
    }

    return root;
}

// Time to assign codes! Let's give each character a unique bit pattern
void assignCodes(Node *root, char *codes, int index) {
    if (root->left) {
        codes[index] = '0';
        assignCodes(root->left, codes, index + 1);
    }
    if (root->right) {
        codes[index] = '1';
        assignCodes(root->right, codes, index + 1);
    }
    if (!root->left && !root->right) {
        codes[index] = '\0';
    }
}

// Convert our message into a sequence of bits
char *encodeMessage(char *message, char *codes) {
    int messageLength = strlen(message);
    int encodedLength = 0;
    char *encodedMessage = (char *)malloc(encodedLength * sizeof(char));

    for (int i = 0; i < messageLength; i++) {
        strcat(encodedMessage, codes + message[i]);
        encodedLength += strlen(codes + message[i]);
    }

    return encodedMessage;
}

// Decode the message! Let's dance backwards to recover our original text
char *decodeMessage(char *encodedMessage, Node *root) {
    int encodedLength = strlen(encodedMessage);
    char *decodedMessage = (char *)malloc(encodedLength * sizeof(char));
    decodedMessage[encodedLength] = '\0';

    Node *currentNode = root;
    int index = 0;

    for (int i = 0; i < encodedLength; i++) {
        if (encodedMessage[i] == '0') {
            currentNode = currentNode->left;
        }
        else {
            currentNode = currentNode->right;
        }

        if (!currentNode->left && !currentNode->right) {
            decodedMessage[index++] = currentNode->character;
            currentNode = root;
        }
    }

    return decodedMessage;
}

int main() {
    // Get a message worthy of coding from the user
    char message[100];
    printf("Enter your secret message: ");
    fgets(message, sizeof(message), stdin);

    // Build our Huffman tree - the backbone of our code
    Node *huffmanTree = buildTree(message);

    // Assign codes to each character, making communication more efficient
    char codes[256] = {0};
    assignCodes(huffmanTree, codes, 0);

    // Encode the message, transforming it into a series of 0s and 1s
    char *encodedMessage = encodeMessage(message, codes);
    printf("Encoded message: %s\n", encodedMessage);

    // Decode the encoded message, bringing it back to its original form
    char *decodedMessage = decodeMessage(encodedMessage, huffmanTree);
    printf("Decoded message: %s\n", decodedMessage);

    return 0;
}