//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 50
#define MAX_TREE_NODES 26

struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

struct MinHeapNode* createNode(char data, unsigned freq) {
    struct MinHeapNode* node = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));

    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;

    return node;
}

struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));

    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**) malloc(minHeap->capacity * sizeof(struct MinHeapNode*));

    return minHeap;
}

void swapNodes(struct MinHeapNode** node1, struct MinHeapNode** node2) {
    struct MinHeapNode* temp = *node1;
    *node1 = *node2;
    *node2 = temp;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) {
        smallest = right;
    }

    if (smallest != idx) {
        swapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* node) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = node;
}

void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }
}

void printCodes(struct MinHeapNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        int i;

        for (i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }

        printf("\n");
    }
}

void HuffmanCodes(char data[], int freq[], int size, struct MinHeapNode* root) {
    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i) {
        minHeap->array[i] = createNode(data[i], freq[i]);
    }

    minHeap->size = size;
    buildMinHeap(minHeap);

    while (!isSizeOne(minHeap)) {
        struct MinHeapNode* left = extractMin(minHeap);
        struct MinHeapNode* right = extractMin(minHeap);

        struct MinHeapNode* node = createNode('$', left->freq + right->freq);
        node->left = left;
        node->right = right;

        insertMinHeap(minHeap, node);
    }

    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

int main() {
    char data[MAX_TREE_NODES];
    int freq[MAX_TREE_NODES];
    int ch, i, j, k, size;

    printf("Enter number of characters: ");
    scanf("%d", &size);

    printf("Enter characters and their frequencies: \n");

    for (i = 0, j = 0, k = 0; i < size; ++i) {
        scanf(" %c %d", &ch, &freq[i]);
        data[i] = ch;
    }

    struct MinHeapNode* root = createNode('$', 0);
    HuffmanCodes(data, freq, size, root);
    return 0;
}