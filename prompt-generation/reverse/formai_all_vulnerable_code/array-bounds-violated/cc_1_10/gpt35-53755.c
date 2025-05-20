//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

typedef struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
} MinHeapNode;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    MinHeapNode **array;
} MinHeap;

typedef struct HuffmanNode {
    char data;
    char *code;
    struct HuffmanNode *next;
} HuffmanNode;

typedef struct HuffmanList {
    HuffmanNode *first;
    HuffmanNode *last;
} HuffmanList;

MinHeapNode *newMinHeapNode(char data, unsigned freq);
MinHeap *createMinHeap(unsigned capacity);
void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b);
void minHeapify(MinHeap *minHeap, int);
int isSizeOne(MinHeap *minHeap);
MinHeapNode *extractMin(MinHeap *minHeap);
void insertMinHeap(MinHeap *minHeap, MinHeapNode *minHeapNode);
void buildMinHeap(MinHeap *minHeap);
void printArr(int arr[], int n, char data);
int isLeaf(MinHeapNode *root);
HuffmanList *newHuffmanList();
void insertHuffmanList(HuffmanList *list, char data, char *code);
void printHuffmanList(HuffmanList *list);
void encodeHuffman(MinHeapNode *root, HuffmanList *list, int arr[], int top);
void decodeHuffman(MinHeapNode *root, char *str);

int main() {
    char str[100], ch[2];
    unsigned charCount[256] = {0};
    int i;

    printf("Enter a string: ");
    scanf("%[^\n]%*c", str);

    for (i = 0; str[i]; i++) {
        charCount[str[i]]++;
    }

    MinHeap *minHeap = createMinHeap(256);

    for (i = 0; i < 256; i++) {
        if (charCount[i] > 0) {
            insertMinHeap(minHeap, newMinHeapNode(i, charCount[i]));
        }
    }

    while (!isSizeOne(minHeap)) {
        MinHeapNode *left = extractMin(minHeap);
        MinHeapNode *right = extractMin(minHeap);

        MinHeapNode *node = newMinHeapNode('$', left->freq + right->freq);

        node->left = left;
        node->right = right;

        insertMinHeap(minHeap, node);
    }

    MinHeapNode *root = extractMin(minHeap);

    HuffmanList *list = newHuffmanList();

    int arr[MAX_TREE_HT], top = 0;

    encodeHuffman(root, list, arr, top);

    printf("\nHuffman Codes:\n");
    printHuffmanList(list);

    printf("\nEncoded String: ");
    for (i = 0; str[i]; i++) {
        ch[0] = str[i];
        ch[1] = '\0';
        insertHuffmanList(list, str[i], NULL);
    }

    printf("\n");

    return 0;
}

MinHeapNode *newMinHeapNode(char data, unsigned freq) {
    MinHeapNode *node = (MinHeapNode *)malloc(sizeof(MinHeapNode));

    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;

    return node;
}

MinHeap *createMinHeap(unsigned capacity) {
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));

    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode **)malloc(minHeap->capacity * sizeof(MinHeapNode *));

    return minHeap;
}

void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b) {
    MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap *minHeap, int idx) {
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
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(MinHeap *minHeap) {
    return minHeap->size == 1;
}

MinHeapNode *extractMin(MinHeap *minHeap) {
    MinHeapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

void insertMinHeap(MinHeap *minHeap, MinHeapNode *minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(MinHeap *minHeap) {
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }
}

void printArr(int arr[], int n, char data) {
    printf("%c: ", data);
    int i;

    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }

    printf("\n");
}

int isLeaf(MinHeapNode *root) {
    return !(root->left) && !(root->right);
}

HuffmanList *newHuffmanList() {
    HuffmanList *list = (HuffmanList *)malloc(sizeof(HuffmanList));

    list->first = NULL;
    list->last = NULL;

    return list;
}

void insertHuffmanList(HuffmanList *list, char data, char *code) {
    HuffmanNode *node = (HuffmanNode *)malloc(sizeof(HuffmanNode));

    node->data = data;
    node->code = code;
    node->next = NULL;

    if (list->first == NULL && list->last == NULL) {
        list->first = list->last = node;
    } else {
        list->last->next = node;
        list->last = node;
    }
}

void printHuffmanList(HuffmanList *list) {
    HuffmanNode *current = list->first;

    while (current != NULL) {
        printf("%c: %s\n", current->data, current->code);
        current = current->next;
    }
}

void encodeHuffman(MinHeapNode *root, HuffmanList *list, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        encodeHuffman(root->left, list, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        encodeHuffman(root->right, list, arr, top + 1);
    }

    if (isLeaf(root)) {
        printf("%c: ", root->data);
        arr[top] = '\0';
        printArr(arr, top, root->data);

        insertHuffmanList(list, root->data, arr);
    }
}

void decodeHuffman(MinHeapNode *root, char *str) {
    MinHeapNode *current = root;

    int i;
    for (i = 0; str[i]; i++) {
        if (str[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (!current->left && !current->right) {
            printf("%c", current->data);
            current = root;
        }
    }

    printf("\n");
}