//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TREE_HT 100

typedef struct tNode {
    char data;
    unsigned freq;
    struct tNode *left, *right;
} TreeNode;

typedef struct minHeap {
    unsigned size;
    unsigned capacity;
    TreeNode **array;
} MinHeap;

typedef struct huffCode {
    char c;
    char bits[MAX_TREE_HT];
} HuffCode;

// Create a new TreeNode
TreeNode* newTreeNode(char data, unsigned freq) {
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Create a new min heap
MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*) malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (TreeNode**) malloc(minHeap->capacity * sizeof(TreeNode*));
    return minHeap;
}

// Swap two TreeNodes
void swapTreeNode(TreeNode** a, TreeNode** b) {
    TreeNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify a subtree with the given root
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx) {
        swapTreeNode(&minHeap->array[idx], &minHeap->array[smallest]);
        minHeapify(minHeap, smallest);
    }
}

// Check if the passed MinHeap is of size 1
int isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Extracts the minimum node from min heap
TreeNode* extractMin(MinHeap* minHeap) {
    TreeNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert a TreeNode to the min heap
void insertMinHeap(MinHeap* minHeap, TreeNode* TNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && TNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = TNode;
}

// Build a min heap and return the root
TreeNode* buildMinHeap(char data[], int freq[], int size) {
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newTreeNode(data[i], freq[i]);
    minHeap->size = size;
    for (int i = (minHeap->size - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
    while (!isSizeOne(minHeap)) {
        TreeNode *left = extractMin(minHeap);
        TreeNode *right = extractMin(minHeap);
        TreeNode *node = newTreeNode('$', left->freq + right->freq);
        node->left = left;
        node->right = right;
        insertMinHeap(minHeap, node);
    }
    return extractMin(minHeap);
}

// Encoding functions
void printHuffCode(HuffCode huffCodes[], int size) {
    printf("\nHuffman Codes:\n");
    for (int i = 0; i < size; ++i) {
        printf("%c -> %s\n", huffCodes[i].c, huffCodes[i].bits);
    }
}

void storeHuffCode(TreeNode* root, char code[], int top, HuffCode huffCodes[]) {
    if (root->left) {
        code[top] = '0';
        storeHuffCode(root->left, code, top + 1, huffCodes);
    }
    if (root->right) {
        code[top] = '1';
        storeHuffCode(root->right, code, top + 1, huffCodes);
    }
    if (!root->left && !root->right) {
        int index = root->data;
        huffCodes[index].c = root->data;
        strcpy(huffCodes[index].bits, code);
    }
}

// Huffman coding function
void huffmanCode(char data[], int freq[], int size) {
    TreeNode* root = buildMinHeap(data, freq, size);
    char code[MAX_TREE_HT];
    int top = 0;
    HuffCode huffCodes[MAX_TREE_HT];
    storeHuffCode(root, code, top, huffCodes);
    printHuffCode(huffCodes, size);
}

int main() {
    printf("Welcome to my Huffman Coding algorithm implementation in C!\n");
    printf("Enter the number of characters: ");
    int size;
    scanf("%d", &size);
    char data[size];
    int freq[size];
    printf("Enter your characters and their frequencies:\n");
    for (int i = 0; i < size; i++) {
        printf("Character %d: ", i+1);
        scanf(" %c", &data[i]);
        printf("Frequency: ");
        scanf("%d", &freq[i]);
    }
    huffmanCode(data, freq, size);
    printf("\nThanks for using my program! Have a great day :)");
    return 0;
}