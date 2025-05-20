//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in a Huffman tree
typedef struct node {
    char ch;
    int freq;
    struct node *left, *right;
} node;

// A structure to store a Huffman tree
typedef struct huffmanTree {
    node *root;
} huffmanTree;

// A structure to store a set of characters and their frequencies
typedef struct charFreq {
    char ch;
    int freq;
} charFreq;

// A comparison function for sorting characters by frequency
int compareCharFreq(const void *a, const void *b) {
    charFreq *cf1 = (charFreq *)a;
    charFreq *cf2 = (charFreq *)b;
    return cf1->freq - cf2->freq;
}

// A function to create a new node in a Huffman tree
node *newNode(char ch, int freq) {
    node *new = malloc(sizeof(node));
    new->ch = ch;
    new->freq = freq;
    new->left = new->right = NULL;
    return new;
}

// A function to create a Huffman tree from a set of characters and their frequencies
huffmanTree *createHuffmanTree(charFreq *charFreqs, int numChars) {
    // Sort the characters by frequency
    qsort(charFreqs, numChars, sizeof(charFreq), compareCharFreq);

    // Create a priority queue to store the nodes in the tree
    node **queue = malloc(numChars * sizeof(node *));
    int front = 0, rear = 0;

    // Add the first two nodes to the queue
    queue[rear++] = newNode(charFreqs[0].ch, charFreqs[0].freq);
    queue[rear++] = newNode(charFreqs[1].ch, charFreqs[1].freq);

    // While there are more than one node in the queue, merge the two nodes with the lowest frequencies
    while (rear - front > 1) {
        // Remove the two nodes with the lowest frequencies from the queue
        node *left = queue[front++];
        node *right = queue[front++];

        // Create a new node with the combined frequency of the two nodes
        node *new = newNode(' ', left->freq + right->freq);
        new->left = left;
        new->right = right;

        // Add the new node to the queue
        int i;
        for (i = rear; i > 0 && new->freq < queue[i - 1]->freq; i--) {
            queue[i] = queue[i - 1];
        }
        queue[i] = new;
        rear++;
    }

    // Create a new Huffman tree and set the root to the only node in the queue
    huffmanTree *tree = malloc(sizeof(huffmanTree));
    tree->root = queue[front];

    // Free the memory allocated for the queue
    free(queue);

    return tree;
}

// A function to print the Huffman codes for a set of characters
void printHuffmanCodes(huffmanTree *tree, char *code, int codeLen) {
    if (tree->root == NULL) {
        return;
    }

    if (tree->root->ch != ' ') {
        printf("%c: %s\n", tree->root->ch, code);
    }

    // Recursively print the Huffman codes for the left and right subtrees
    code[codeLen] = '0';
    printHuffmanCodes(tree->root->left, code, codeLen + 1);

    code[codeLen] = '1';
    printHuffmanCodes(tree->root->right, code, codeLen + 1);
}

// A function to encode a string using a Huffman tree
char *huffmanEncode(huffmanTree *tree, char *str) {
    int strLen = strlen(str);
    char *encodedStr = malloc(strLen * sizeof(char) * 8);

    int codeLen = 0;
    char code[100];

    for (int i = 0; i < strLen; i++) {
        node *curr = tree->root;

        // Find the Huffman code for the current character
        while (curr->ch != str[i]) {
            code[codeLen++] = curr->ch == '0' ? '0' : '1';
            curr = curr->ch == '0' ? curr->left : curr->right;
        }

        // Append the Huffman code to the encoded string
        strcat(encodedStr, code);

        // Reset the code length for the next character
        codeLen = 0;
    }

    return encodedStr;
}

// A function to decode a string using a Huffman tree
char *huffmanDecode(huffmanTree *tree, char *encodedStr) {
    int encodedStrLen = strlen(encodedStr);
    char *decodedStr = malloc(encodedStrLen);

    int codeLen = 0;
    node *curr = tree->root;

    for (int i = 0; i < encodedStrLen; i++) {
        // Traverse the Huffman tree until a leaf node is reached
        while (curr->left != NULL && curr->right != NULL) {
            curr = encodedStr[i] == '0' ? curr->left : curr->right;
        }

        // Append the character to the decoded string
        decodedStr[codeLen++] = curr->ch;

        // Reset the current node to the root of the tree
        curr = tree->root;
    }

    return decodedStr;
}

int main() {
    // Create a set of characters and their frequencies
    charFreq charFreqs[] = {
        {'a', 5},
        {'b', 2},
        {'c', 3},
        {'d', 4},
        {'e', 1},
    };

    int numChars = sizeof(charFreqs) / sizeof(charFreq);

    // Create a Huffman tree from the set of characters and their frequencies
    huffmanTree *tree = createHuffmanTree(charFreqs, numChars);

    // Print the Huffman codes for the set of characters
    printf("Huffman Codes:\n");
    char code[100];
    printHuffmanCodes(tree, code, 0);

    // Encode a string using the Huffman tree
    char *encodedStr = huffmanEncode(tree, "abcabc");
    printf("\nEncoded String: %s\n", encodedStr);

    // Decode the encoded string using the Huffman tree
    char *decodedStr = huffmanDecode(tree, encodedStr);
    printf("\nDecoded String: %s\n", decodedStr);

    // Free the memory allocated for the Huffman tree and the encoded string
    free(tree);
    free(encodedStr);
    free(decodedStr);

    return 0;
}