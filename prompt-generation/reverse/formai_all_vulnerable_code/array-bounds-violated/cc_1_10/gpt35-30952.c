//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 256

typedef struct node {
    unsigned char value;
    unsigned int freq;
    struct node *left, *right;
} Node;

// Global variables
int freq[MAX_SIZE] = {0};
Node *heap[MAX_SIZE];
unsigned char encoding[MAX_SIZE][MAX_SIZE] = {0};
int size = 0;
int numSymbols = 0;

// Create a new node for a character with given frequency
Node* newNode(unsigned char value, unsigned int freq) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Swap nodes in the heap array
void swap(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify the array starting at index i
void heapify(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left]->freq < heap[smallest]->freq) {
        smallest = left;
    }

    if (right < size && heap[right]->freq < heap[smallest]->freq) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

// Insert a new node into the heap
void insert(Node* node) {
    size++;
    int i = size-1;
    while (i > 0 && heap[(i-1)/2]->freq > node->freq) {
        heap[i] = heap[(i-1)/2];
        i = (i-1)/2;
    }
    heap[i] = node;
}

// Build a Huffman tree from the character frequencies
Node* buildTree() {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (freq[i] > 0) {
            insert(newNode(i, freq[i]));
            numSymbols++;
        }
    }

    while (size != 1) {
        Node* a = heap[0];
        swap(&heap[0], &heap[size-1]);
        size--;
        heapify(0);

        Node* b = heap[0];
        swap(&heap[0], &heap[size-1]);
        size--;
        heapify(0);

        Node* c = newNode('$', a->freq + b->freq);
        c->left = a;
        c->right = b;

        insert(c);
    }

    return heap[0];
}

// Traverse the Huffman tree to generate the encodings for each symbol
void generateEncodings(Node* ptr, char* prefix, int prefixSize) {
    if (ptr->left == NULL && ptr->right == NULL) {
        strncpy(encoding[ptr->value], prefix, prefixSize);
        return;
    }
    if (ptr->left != NULL) {
        char leftPrefix[MAX_SIZE];
        strncpy(leftPrefix, prefix, prefixSize);
        leftPrefix[prefixSize] = '0';
        generateEncodings(ptr->left, leftPrefix, prefixSize+1);
    }
    if (ptr->right != NULL) {
        char rightPrefix[MAX_SIZE];
        strncpy(rightPrefix, prefix, prefixSize);
        rightPrefix[prefixSize] = '1';
        generateEncodings(ptr->right, rightPrefix, prefixSize+1);
    }
}

// Print the encodings
void printEncodings() {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (freq[i] > 0) {
            printf("%c: ", i);
            for (int j = 0; j < MAX_SIZE; j++) {
                if (encoding[i][j] != '\0') {
                    printf("%c", encoding[i][j]);
                }
            }
            printf("\n");
        }
    }
}

int main() {
    char msg[MAX_SIZE];

    printf("Enter a message to encode: ");
    fgets(msg, MAX_SIZE, stdin);

    // Calculate character frequencies
    int len = strlen(msg);
    for (int i = 0; i < len; i++) {
        freq[(int) msg[i]]++;
    }

    // Build Huffman tree and generate encodings
    Node* root = buildTree();
    char prefix[MAX_SIZE] = {0};
    generateEncodings(root, prefix, 0);

    // Print the encodings
    printf("Encodings:\n");
    printEncodings();

    // Encode the message using the generated encodings
    printf("Encoded message:\n");
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (encoding[(int) msg[i]][j] != '\0') {
                printf("%c", encoding[(int) msg[i]][j]);
            } else {
                break;
            }
        }
    }
    printf("\n");

    // Encode the message using the generated encodings
    printf("Decoded message:\n");
    Node* ptr = root;
    for (int i = 0; i < len; i++) {
        if (msg[i] == '0') {
            ptr = ptr->left;
        } else {
            ptr = ptr->right;
        }
        if (ptr->left == NULL && ptr->right == NULL) {
            printf("%c", ptr->value);
            ptr = root;
        }
    }
    printf("\n");

    return 0;
}