//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the Huffman tree
struct Node {
    char character;
    int frequency;
    struct Node *left;
    struct Node *right;
};

// A min-heap to store the nodes
struct MinHeap {
    int size;
    struct Node **elements;
};

// Create a new node
struct Node *newNode(char character, int frequency) {
    struct Node *node = malloc(sizeof(struct Node));
    node->character = character;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

// Create a new min-heap
struct MinHeap *createMinHeap(int capacity) {
    struct MinHeap *minHeap = malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->elements = malloc(sizeof(struct Node *) * capacity);
    return minHeap;
}

// Insert a node into the min-heap
void insertMinHeap(struct MinHeap *minHeap, struct Node *node) {
    minHeap->elements[minHeap->size++] = node;
    int i = minHeap->size - 1;
    while (i > 0 && minHeap->elements[i]->frequency < minHeap->elements[(i - 1) / 2]->frequency) {
        struct Node *temp = minHeap->elements[i];
        minHeap->elements[i] = minHeap->elements[(i - 1) / 2];
        minHeap->elements[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Extract the minimum node from the min-heap
struct Node *extractMin(struct MinHeap *minHeap) {
    struct Node *root = minHeap->elements[0];
    minHeap->elements[0] = minHeap->elements[minHeap->size - 1];
    minHeap->size--;
    int i = 0;
    while (i < minHeap->size / 2) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < minHeap->size && minHeap->elements[left]->frequency < minHeap->elements[smallest]->frequency) {
            smallest = left;
        }
        if (right < minHeap->size && minHeap->elements[right]->frequency < minHeap->elements[smallest]->frequency) {
            smallest = right;
        }
        if (smallest != i) {
            struct Node *temp = minHeap->elements[i];
            minHeap->elements[i] = minHeap->elements[smallest];
            minHeap->elements[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
    }
    return root;
}

// Build the Huffman tree from the min-heap
struct Node *buildHuffmanTree(struct MinHeap *minHeap) {
    struct Node *left, *right, *top;
    while (minHeap->size > 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode(' ', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// Print the codes of all the characters
void printCodes(struct Node *root, char *code, int top) {
    if (root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->character, code);
        return;
    }
    code[top] = '0';
    printCodes(root->left, code, top + 1);
    code[top] = '1';
    printCodes(root->right, code, top + 1);
}

// Compute the frequency of each character in the string
int *computeFrequency(char *str) {
    int *frequency = calloc(256, sizeof(int));
    while (*str != '\0') {
        frequency[*str++]++;
    }
    return frequency;
}

// Encode the string using Huffman coding
char *encode(char *str, struct Node *root) {
    int size = strlen(str);
    char *encoded = malloc(sizeof(char) * size * 8);
    int top = 0;
    for (int i = 0; i < size; i++) {
        struct Node *node = root;
        while (node->left != NULL && node->right != NULL) {
            if (str[i] == node->left->character) {
                node = node->left;
                encoded[top++] = '0';
            } else {
                node = node->right;
                encoded[top++] = '1';
            }
        }
    }
    encoded[top] = '\0';
    return encoded;
}

// Decode the string using Huffman coding
char *decode(char *encoded, struct Node *root) {
    int size = strlen(encoded);
    char *decoded = malloc(sizeof(char) * size);
    struct Node *node = root;
    int top = 0;
    for (int i = 0; i < size; i++) {
        if (encoded[i] == '0') {
            node = node->left;
        } else {
            node = node->right;
        }
        if (node->left == NULL && node->right == NULL) {
            decoded[top++] = node->character;
            node = root;
        }
    }
    decoded[top] = '\0';
    return decoded;
}

int main() {
    char *str = "The quick brown fox jumps over the lazy dog.";
    int *frequency = computeFrequency(str);
    struct MinHeap *minHeap = createMinHeap(256);
    for (int i = 0; i < 256; i++) {
        if (frequency[i] != 0) {
            insertMinHeap(minHeap, newNode(i, frequency[i]));
        }
    }
    struct Node *root = buildHuffmanTree(minHeap);
    char code[256];
    printCodes(root, code, 0);
    char *encoded = encode(str, root);
    char *decoded = decode(encoded, root);
    printf("Original string: %s\n", str);
    printf("Encoded string: %s\n", encoded);
    printf("Decoded string: %s\n", decoded);
    return 0;
}