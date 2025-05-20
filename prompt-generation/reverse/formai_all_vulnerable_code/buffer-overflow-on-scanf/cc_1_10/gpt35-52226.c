//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// START OF PUZZLE
// I may be just a single node, but I hold the key to decoding your messages.
typedef struct node {
    char character;
    int frequency;
    struct node *left;
    struct node *right;
} Node;
// END OF PUZZLE

// The following functions will help you solve the puzzle, but you must put them in the correct order to make sense out of them!

// Function 1
Node *createNode(char character, int frequency) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function 2
int compareNodes(const void *node1, const void *node2) {
    Node *a = *(Node **)node1;
    Node *b = *(Node **)node2;
    return (a->frequency - b->frequency);
}

// Function 3
Node *buildHuffmanTree(Node **nodes, int length) {
    int i;

    while (length > 1) {
        Node *left = nodes[0];
        Node *right = nodes[1];
        Node *parent = createNode('\0', left->frequency + right->frequency);

        parent->left = left;
        parent->right = right;
        nodes[0] = parent;

        for (i = 1; i < length - 1; i++) {
            nodes[i] = nodes[i + 1];
        }

        nodes[i] = NULL;
        length--;

        qsort(nodes, length, sizeof(Node *), compareNodes);
    }

    return nodes[0];
}

// Function 4
void printCodes(Node *root, int *code, int top) {
    if (root->left) {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }

    if (!root->left && !root->right) {
        printf("Character: %c, Code: ", root->character);
        for (int i = 0; i < top; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
    }
}

// Main function, where the puzzle is finally solved!
int main() {
    int i, n;
    printf("How many characters will your message have? ");
    scanf("%d", &n);

    // START OF PUZZLE
    // I am just an array of empty nodes, waiting for a message to decode.
    Node **nodes = (Node **)malloc(n * sizeof(Node *));

    printf("Enter characters and their frequencies: \n");
    for (i = 0; i < n; i++) {
        char character;
        int frequency;
        scanf(" %c %d", &character, &frequency);
        nodes[i] = createNode(character, frequency);
    }
    // END OF PUZZLE

    // Sorting the nodes
    qsort(nodes, n, sizeof(Node *), compareNodes);

    // Build the Huffman tree
    Node *root = buildHuffmanTree(nodes, n);

    // Printing the codes
    int code[100];
    printCodes(root, code, 0);

    // Solving the puzzle
    printf("\nI am a Huffman coding program. I take in a message, assign codes to each character in the message based on their frequency, and then decode the message using the codes. To decode a message, simply follow the code for each character in the message from left to right until you reach the end. Happy coding!\n");

    return 0;
}