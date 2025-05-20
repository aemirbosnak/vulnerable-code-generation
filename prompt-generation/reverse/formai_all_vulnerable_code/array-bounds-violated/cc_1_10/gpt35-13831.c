//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Struct for the nodes of Huffman tree
struct Node {
    char character;
    int frequency;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

// Struct for the Huffman tree
struct HuffmanTree {
    Node* root;
};

typedef struct HuffmanTree HuffmanTree;

// Struct for a single Huffman code
struct HuffmanCode {
    char character;
    char* code;
};

typedef struct HuffmanCode HuffmanCode;

// Helper function to create a new node
Node* newNode (char c, int freq) {
    Node* temp = (Node*) malloc (sizeof(Node));
    temp->left = temp->right = NULL;
    temp->character = c;
    temp->frequency = freq;
    return temp;
}

// Helper function for heapify
void heapify (Node** heap, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && heap[l]->frequency > heap[largest]->frequency) {
        largest = l;
    }
    if (r < n && heap[r]->frequency > heap[largest]->frequency) {
        largest = r;
    }
    if (largest != i) {
        Node* temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapify(heap, n, largest);
    }
}

// Helper function for building a heap
void buildHeap (Node** heap, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(heap, n, i);
    }
}

// Helper function for removing the root of the heap
Node* removeRoot (Node** heap, int* n) {
    Node* root = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    heapify(heap, *n, 0);
    return root;
}

// Helper function for inserting a node into the heap
void insertIntoHeap (Node** heap, int* n, Node* node) {
    (*n)++;
    int i = (*n) - 1;
    while (i > 0 && heap[(i - 1) / 2]->frequency < node->frequency) {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = node;
}

// Helper function for traversing the tree and generating codes
void generateCodes (Node* node, char* code, int len, HuffmanCode* codes, int* numCodes) {
    if (!node) {
        return;
    }
    if (node->character != '\0') {
        codes[*numCodes].character = node->character;
        codes[*numCodes].code = (char*) malloc (len + 1);
        for (int i = 0; i < len; i++) {
            codes[*numCodes].code[i] = code[i];
        }
        codes[*numCodes].code[len] = '\0';
        (*numCodes)++;
    }
    else {
        code[len] = '0';
        generateCodes(node->left, code, len+1, codes, numCodes);
        code[len] = '1';
        generateCodes(node->right, code, len+1, codes, numCodes);
    }
}

HuffmanTree* buildHuffmanTree (char* str) {
    int freq[128] = {0};
    for (int i = 0; str[i]; i++) {
        freq[(int) str[i]]++;
    }
    Node** heap = (Node**) malloc (128 * sizeof(Node*));
    int n = 0;
    for (int i = 0; i < 128; i++) {
        if (freq[i]) {
            insertIntoHeap(heap, &n, newNode((char) i, freq[i]));
        }
    }
    while (n > 1) {
        Node* left = removeRoot(heap, &n);
        Node* right = removeRoot(heap, &n);
        Node* node = newNode('\0', left->frequency + right->frequency);
        node->left = left;
        node->right = right;
        insertIntoHeap(heap, &n, node);
    }
    HuffmanTree* tree = (HuffmanTree*) malloc (sizeof(HuffmanTree));
    tree->root = heap[0];
    free(heap);
    return tree;
}

HuffmanCode* generateHuffmanCodes (HuffmanTree* tree, int* numCodes) {
    char code[128];
    HuffmanCode* codes = (HuffmanCode*) malloc (128 * sizeof(HuffmanCode));
    *numCodes = 0;
    generateCodes(tree->root, code, 0, codes, numCodes);
    return codes;
}

int main () {
    printf("Enter a string to encode: ");
    char str[1000];
    fgets(str, 1000, stdin);
    HuffmanTree* tree = buildHuffmanTree(str);
    int numCodes;
    HuffmanCode* codes = generateHuffmanCodes(tree, &numCodes);
    printf("Huffman codes generated:\n");
    for (int i = 0; i < numCodes; i++) {
        printf("Character: %c, Code: %s\n", codes[i].character, codes[i].code);
    }
    return 0;
}