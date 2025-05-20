//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// define the Huffman tree struct
typedef struct HuffmanNode
{
    char c;
    int freq;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

// define the Huffman heap struct
typedef struct HuffmanHeap
{
    int size;
    int capacity;
    HuffmanNode **array;
} HuffmanHeap;

// function to create a new Huffman node
HuffmanNode *newHuffmanNode(char c, int freq)
{
    HuffmanNode *node = (HuffmanNode *)malloc(sizeof(HuffmanNode));
    node->c = c;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// function to swap two Huffman nodes
void swapHuffmanNode(HuffmanNode **a, HuffmanNode **b)
{
    HuffmanNode *temp = *a;
    *a = *b;
    *b = temp;
}

// function to create a new Huffman heap
HuffmanHeap *newHuffmanHeap(int capacity)
{
    HuffmanHeap *heap = (HuffmanHeap *)malloc(sizeof(HuffmanHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (HuffmanNode **)malloc(capacity * sizeof(HuffmanNode *));
    return heap;
}

// function to check if the Huffman heap is empty
int isEmptyHuffmanHeap(HuffmanHeap *heap)
{
    return heap->size == 0;
}

// function to get the parent index of a Huffman node
int getParentIndex(int i)
{
    return (i - 1) / 2;
}

// function to get the left child index of a Huffman node
int getLeftChildIndex(int i)
{
    return 2 * i + 1;
}

// function to get the right child index of a Huffman node
int getRightChildIndex(int i)
{
    return 2 * i + 2;
}

// function to insert a Huffman node into a Huffman heap
void insertHuffmanNode(HuffmanHeap *heap, HuffmanNode *node)
{
    if (heap->size == heap->capacity)
    {
        printf("Error: Huffman heap is full!\n");
        return;
    }
    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = node;

    while (i != 0 && heap->array[getParentIndex(i)]->freq > heap->array[i]->freq)
    {
        swapHuffmanNode(&heap->array[i], &heap->array[getParentIndex(i)]);
        i = getParentIndex(i);
    }
}

// function to get the minimum node in a Huffman heap
HuffmanNode *getMinHuffmanNode(HuffmanHeap *heap)
{
    return heap->array[0];
}

// function to remove the minimum node in a Huffman heap
HuffmanNode *removeMinHuffmanNode(HuffmanHeap *heap)
{
    if (isEmptyHuffmanHeap(heap))
    {
        printf("Error: Huffman heap is empty!");
        return NULL;
    }
    if (heap->size == 1)
    {
        heap->size--;
        return heap->array[0];
    }
    HuffmanNode *minNode = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;

    int i = 0;
    int smallest;
    while (1)
    {
        int leftChildIndex = getLeftChildIndex(i);
        int rightChildIndex = getRightChildIndex(i);
        smallest = i;
        if (leftChildIndex < heap->size && heap->array[leftChildIndex]->freq < heap->array[smallest]->freq)
        {
            smallest = leftChildIndex;
        }
        if (rightChildIndex < heap->size && heap->array[rightChildIndex]->freq < heap->array[smallest]->freq)
        {
            smallest = rightChildIndex;
        }
        if (smallest != i)
        {
            swapHuffmanNode(&heap->array[i], &heap->array[smallest]);
            i = smallest;
        }
        else
        {
            break;
        }
    }
    return minNode;
}

// function to build a Huffman tree from a given string
HuffmanNode *buildHuffmanTree(char *str)
{
    int freq[256] = {0};
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        freq[(int)str[i]]++;
    }

    HuffmanHeap *heap = newHuffmanHeap(256);
    for (i = 0; i < 256; i++)
    {
        if (freq[i] > 0)
        {
            insertHuffmanNode(heap, newHuffmanNode((char)i, freq[i]));
        }
    }

    while (heap->size > 1)
    {
        HuffmanNode *left = removeMinHuffmanNode(heap);
        HuffmanNode *right = removeMinHuffmanNode(heap);
        HuffmanNode *node = newHuffmanNode('\0', left->freq + right->freq);
        node->left = left;
        node->right = right;
        insertHuffmanNode(heap, node);
    }

    return removeMinHuffmanNode(heap);
}

// function to print the Huffman codes for each character in a Huffman tree
void printHuffmanCodes(HuffmanNode *node, char *s, int top)
{
    if (node->left)
    {
        s[top] = '0';
        printHuffmanCodes(node->left, s, top + 1);
    }

    if (node->right)
    {
        s[top] = '1';
        printHuffmanCodes(node->right, s, top + 1);
    }

    if (node->left == NULL && node->right == NULL)
    {
        printf("%c: %s\n", node->c, s);
    }
}

// main function
int main()
{
    char str[100];
    printf("Enter a string to encode with Huffman coding: ");
    scanf("%[^\n]s", str);

    HuffmanNode *root = buildHuffmanTree(str);

    char s[100];
    int top = 0;
    printf("Huffman coding:\n");
    printHuffmanCodes(root, s, top);

    return 0;
}