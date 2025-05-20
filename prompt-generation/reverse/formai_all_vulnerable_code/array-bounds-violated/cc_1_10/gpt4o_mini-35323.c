//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100
#define MAX_CHAR 256

// Structure for a node in the Huffman tree
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

// Structure for the Min Heap
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
};

// Function declarations
struct MinHeapNode* createNode(char data, unsigned freq);
struct MinHeap* createMinHeap(unsigned capacity);
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode);
void minHeapify(struct MinHeap* minHeap, int idx);
struct MinHeapNode* extractMin(struct MinHeap* minHeap);
int isLeaf(struct MinHeapNode* root);
void buildHuffmanTree(char data[], int freq[], int size);
void printCodes(struct MinHeapNode* root, int arr[], int top);
void HuffmanCoding(char* inputFile, char* outputFile);
void decodeHuffman(struct MinHeapNode* root, char* binaryString);

// Function to create a new Min Heap Node
struct MinHeapNode* createNode(char data, unsigned freq) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Function to create a Min Heap
struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// Function to insert a new node into Min Heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    minHeap->size++;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Function to min-heapify a subtree
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx, left = 2 * idx + 1, right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) {
        smallest = right;
    }
    if (smallest != idx) {
        struct MinHeapNode* temp = minHeap->array[smallest];
        minHeap->array[smallest] = minHeap->array[idx];
        minHeap->array[idx] = temp;
        minHeapify(minHeap, smallest);
    }
}

// Function to extract the minimum value node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to check if a node is a leaf
int isLeaf(struct MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

// Function to build the Huffman tree
void buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i) {
        insertMinHeap(minHeap, createNode(data[i], freq[i]));
    }
    while (minHeap->size != 1) {
        struct MinHeapNode* left = extractMin(minHeap);
        struct MinHeapNode* right = extractMin(minHeap);
        struct MinHeapNode* top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    printCodes(minHeap->array[0], (int[MAX_TREE_HT]){0}, 0);
}

// Function to print the codes recursively
void printCodes(struct MinHeapNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Function to Huffman encode the content of a file
void HuffmanCoding(char* inputFile, char* outputFile) {
    // File handling logic goes here
    // read characters and their frequencies from input file
    // For demonstration, we will use a static frequency array
    char data[MAX_CHAR];
    int freq[MAX_CHAR] = {0}; // Frequency array
    
    FILE *fp = fopen(inputFile, "r");
    if (!fp) {
        printf("Could not open file %s\n", inputFile);
        exit(1);
    }
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        freq[ch]++;
    }
    fclose(fp);

    int size = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i]) {
            data[size] = (char)i;
            size++;
        }
    }
    buildHuffmanTree(data, freq, size);
}

// Function to decode the binary string using Huffman tree
void decodeHuffman(struct MinHeapNode* root, char* binaryString) {
    struct MinHeapNode* currentNode = root;
    for (int i = 0; binaryString[i]; i++) {
        if (binaryString[i] == '0') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
        if (isLeaf(currentNode)) {
            printf("%c", currentNode->data);
            currentNode = root;
        }
    }
    printf("\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    HuffmanCoding(argv[1], argv[2]);
    // Implement decoding logic here if needed
    return 0;
}