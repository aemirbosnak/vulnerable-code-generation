//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100
#define MAX_CODE_LEN 512

struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode* left, * right;
};

struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

struct MinHeapNode* nodeToMinHeapNode(char data, unsigned freq) {
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

void swapNodes(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct MinHeap* minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    if (smallest != index) {
        swapNodes(&minHeap->array[smallest], &minHeap->array[index]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    minHeap->size++;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

int isLeaf(struct MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; i++)
        minHeap->array[i] = nodeToMinHeapNode(data[i], freq[i]);
    minHeap->size = size;
    for (int i = (minHeap->size - 2) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
    return minHeap;
}

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = nodeToMinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printCodes(struct MinHeapNode* root, int arr[], int top, int* codesMap) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1, codesMap);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1, codesMap);
    }
    if (isLeaf(root)) {
        codesMap[(int)root->data] = top;
    }
}

void HuffmanCodes(char data[], int freq[], int size, int* codesMap) {
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top, codesMap);
}

void encode(char data[], int frequency[], int size, char* inputString) {
    int codesMap[256] = { 0 };
    HuffmanCodes(data, frequency, size, codesMap);
    char encodedString[MAX_CODE_LEN] = { 0 };
    int length = strlen(inputString);
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < codesMap[(int)inputString[i]]; j++) {
            strcat(encodedString, "1");
        }
        strcat(encodedString, "0");
    }
    printf("Encoded Huffman string: %s\n", encodedString);
}

void decode(char data[], int frequency[], int size, char* encodedString) {
    int codesMap[256] = { 0 };
    HuffmanCodes(data, frequency, size, codesMap);
    char decodedString[MAX_CODE_LEN] = { 0 };
    int length = strlen(encodedString);
    int i = 0, j = 0;
    while (i < length) {
        struct MinHeapNode* temp = buildHuffmanTree(data, frequency, size);
        while (!isLeaf(temp)) {
            if (encodedString[i] == '0') {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
            i++;
        }
        decodedString[j] = temp->data;
        j++;
    }
    printf("Decoded Huffman string: %s\n", decodedString);
}

int main() {
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);
    char inputString[MAX_CODE_LEN];
    printf("Enter a string to encode using Huffman coding: ");
    scanf("%[^\n]s", inputString);
    encode(data, freq, size, inputString);
    printf("Enter a string to decode using Huffman coding: ");
    scanf(" %[^\n]s", inputString);
    decode(data, freq, size, inputString);
    return 0;
}