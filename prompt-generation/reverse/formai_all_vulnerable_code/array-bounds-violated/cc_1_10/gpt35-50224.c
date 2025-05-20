//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_LEN 1000

// Define the maximum number of unique characters in the input string
#define MAX_CHARS 256

// Define the structure for the Huffman code used
struct HuffmanCode {
    int frequency;                  // Frequency of the character
    char character;                 // Character represented by the Huffman code
    struct HuffmanCode* left;       // Pointer to the left child node
    struct HuffmanCode* right;      // Pointer to the right child node
};

// Function to create a new Huffman code node with the given character and frequency
struct HuffmanCode* newHuffmanNode(int frequency, char character) {
    struct HuffmanCode* node = (struct HuffmanCode*) malloc(sizeof(struct HuffmanCode));
    node->frequency = frequency;
    node->character = character;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to compare two Huffman codes based on frequency
int cmpHuffmanCodes(const void* a, const void* b) {
    struct HuffmanCode* h1 = (struct HuffmanCode*) a;
    struct HuffmanCode* h2 = (struct HuffmanCode*) b;
    return h1->frequency - h2->frequency;
}

// Function to print the Huffman codes for each character in the input string
void printHuffmanCodes(struct HuffmanCode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top+1);
    }
    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top+1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->character);
        for (int i=0; i<top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Function to generate Huffman codes for the characters in the input string
void generateHuffmanCodes(char* input) {
    int freq[MAX_CHARS] = {0};             // Array to store the frequency of each character
    int n = strlen(input);                 // Length of the input string
    for (int i=0; i<n; i++) {
        freq[(int) input[i]]++;
    }
    struct HuffmanCode* queue[MAX_CHARS];  // Priority queue to hold Huffman code tree nodes
    int front = 0, rear = 0;
    for (int i=0; i<MAX_CHARS; i++) {
        if (freq[i] != 0) {
            queue[rear++] = newHuffmanNode(freq[i], (char) i);
        }
    }
    qsort(queue, rear, sizeof(queue[0]), cmpHuffmanCodes);
    while (rear-front > 1) {                // Build Huffman code tree
        struct HuffmanCode* node1 = queue[front++];
        struct HuffmanCode* node2 = queue[front++];
        struct HuffmanCode* parent = newHuffmanNode(node1->frequency + node2->frequency, '-');
        parent->left = node1;
        parent->right = node2;
        queue[rear++] = parent;
        qsort(queue+front, rear-front, sizeof(queue[0]), cmpHuffmanCodes);
    }
    int arr[MAX_CHARS] = {0};               // Array to store the Huffman code for each character
    printHuffmanCodes(queue[front], arr, 0);    // Print the Huffman codes
}

// Main function to run the Huffman code generation program
int main() {
    char input[MAX_LEN];
    printf("Enter the input string: ");
    fgets(input, MAX_LEN, stdin);
    generateHuffmanCodes(input);
    return 0;
}