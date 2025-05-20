//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 50

// A Huffman tree node
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

// A Min Heap: collection of min-heap (or Huffman tree) nodes
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
};

// Function to create a new Huffman tree node
struct MinHeapNode* newNode(char data, unsigned freq) {
    struct MinHeapNode* node =
        (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Function to create a new min heap with given capacity
struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap =
        (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array =
        (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// Function to swap two nodes of min heap
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Function to heapify min heap
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size &&
        minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size &&
        minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to check if size of heap is 1 or not
int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Function to extract minimum value node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

// Function to insert a new node to min heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

// Function to build min heap
void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Function to print an array of size n
void printArr(int arr[], int n) {
    int i;

    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);

    printf("\n");
}

// Function to check if node is leaf node
int isLeaf(struct MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

// Function to create a min heap of capacity equal to size and insert all character of data[] in min heap.
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    int i;
    struct MinHeap* minHeap = createMinHeap(size);

    for (i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

// Function to build Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap)) {

        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

// Function to print Huffman codes from the root of Huffman Tree.
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
        printArr(arr, top);
    }
}

// Function to perform Huffman Compression and Decompression
void huffman_coding(char* str) {
    int i, freq[256] = { 0 }, len = strlen(str);
    char data[256];

    for (i = 0; i < len; i++)
        freq[str[i]]++;

    int j = 0;
    for (i = 0; i < 256; i++)
        if (freq[i] != 0) {
            data[j] = i;
            j++;
        }

    struct MinHeapNode* root = buildHuffmanTree(data, freq, j);

    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);

    printf("\n");

    // Encoding part
    printf("Encoded Output: ");
    for (i = 0; i < len; i++) {
        for (j = 0; j < j; j++)
            if (str[i] == data[j]) {
                printArr(arr[j], top);
                break;
            }
    }

    printf("\n");

    // Decoding part
    printf("Decoded Output: ");
    struct MinHeapNode* temp = root;
    for (i = 0; i < len; i++) {
        if (str[i] == '0')
            temp = temp->left;
        else
            temp = temp->right;

        if (isLeaf(temp)) {
            printf("%c", temp->data);
            temp = root;
        }
    }
}

// Driver program to test above functions
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]%*c", str);

    printf("\nHuffman Coding:\n\n");
    huffman_coding(str);

    return 0;
}