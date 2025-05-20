//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char chr;
    int freq;
    struct Node *left, *right;
} Node;

Node *newNode(char chr, int freq) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->chr = chr;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

void swap(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(Node **arr, int size, int i) {
    int min = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && arr[left]->freq < arr[min]->freq)
        min = left;
    if (right < size && arr[right]->freq < arr[min]->freq)
        min = right;
    if (min != i) {
        swap(&arr[min], &arr[i]);
        minHeapify(arr, size, min);
    }
}

Node *buildMinHeap(Node **arr, int size) {
    int i;
    for (i = size / 2 - 1; i >= 0; i--)
        minHeapify(arr, size, i);
    return arr[0];
}

Node *buildHuffmanTree(Node **arr, int size) {
    Node *left, *right, *top;
    while (size != 1) {
        left = buildMinHeap(arr, size--);
        right = buildMinHeap(arr, size--);
        top = newNode('-', left->freq + right->freq);
        top->left = left;
        top->right = right;
        arr[size++] = top;
    }
    return arr[0];
}

void printCodes(Node *root, char *code, int top) {
    if (root->left) {
        code[top] = '0';
        printCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = '1';
        printCodes(root->right, code, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: %s\n", root->chr, code);
    }
}

void huffmanCoding(char *str, int n) {
    int i;
    int *freq = (int *)calloc(256, sizeof(int));
    for (i = 0; i < n; i++)
        freq[str[i]]++;
    Node **arr = (Node **)malloc(sizeof(Node *) * 256);
    int size = 0;
    for (i = 0; i < 256; i++)
        if (freq[i])
            arr[size++] = newNode(i, freq[i]);
    Node *root = buildHuffmanTree(arr, size);
    char code[n];
    printCodes(root, code, 0);
}

int main() {
    char str[] = "Hello world";
    int n = strlen(str);
    huffmanCoding(str, n);
    return 0;
}