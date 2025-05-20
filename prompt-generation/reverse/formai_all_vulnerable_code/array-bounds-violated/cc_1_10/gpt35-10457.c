//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct HuffmanNode
{
    char value;
    int freq;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

typedef struct MinHeapNode
{
    HuffmanNode *huffNode;
    struct MinHeapNode *left;
    struct MinHeapNode *right;
} MinHeapNode;

void decode(HuffmanNode *root, char *str)
{
    HuffmanNode *temp = root;
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '0')
            temp = temp->left;
        else
            temp = temp->right;

        if (temp->left == NULL && temp->right == NULL)
        {
            printf("%c", temp->value);
            temp = root;
        }
    }
}

void encode(HuffmanNode *root, char *str, char *code, int index)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        printf("%c: %s\n", root->value, code);
        str[index] = root->value;
        str[index + 1] = '\0';
        return;
    }

    code[index] = '0';
    encode(root->left, str, code, index + 1);

    code[index] = '1';
    encode(root->right, str, code, index + 1);
}

MinHeapNode *createMinHeapNode(HuffmanNode *huffNode)
{
    MinHeapNode *minHeapNode = (MinHeapNode *)malloc(sizeof(MinHeapNode));
    minHeapNode->huffNode = huffNode;
    minHeapNode->left = NULL;
    minHeapNode->right = NULL;

    return minHeapNode;
}

void swapMinHeapNodes(MinHeapNode **a, MinHeapNode **b)
{
    MinHeapNode *temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeapNode *minHeapNodes[], int heapSize, int index)
{
    int smallest = index;
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;

    if (leftChildIndex < heapSize && minHeapNodes[leftChildIndex]->huffNode->freq < minHeapNodes[smallest]->huffNode->freq)
        smallest = leftChildIndex;

    if (rightChildIndex < heapSize && minHeapNodes[rightChildIndex]->huffNode->freq < minHeapNodes[smallest]->huffNode->freq)
        smallest = rightChildIndex;

    if (smallest != index)
    {
        swapMinHeapNodes(&minHeapNodes[index], &minHeapNodes[smallest]);
        minHeapify(minHeapNodes, heapSize, smallest);
    }
}

int isSizeOne(int heapSize)
{
    return (heapSize == 1);
}

MinHeapNode *extractMin(MinHeapNode *minHeapNodes[], int *heapSize)
{
    MinHeapNode *temp = minHeapNodes[0];
    minHeapNodes[0] = minHeapNodes[*heapSize - 1];
    minHeapify(minHeapNodes, --(*heapSize), 0);
    return temp;
}

void insertMinHeapNode(MinHeapNode *minHeapNodes[], int *heapSize, MinHeapNode *minHeapNode)
{
    (*heapSize)++;
    int index = *heapSize - 1;
    minHeapNodes[index] = minHeapNode;

    while (index != 0 && minHeapNodes[(index - 1) / 2]->huffNode->freq > minHeapNodes[index]->huffNode->freq)
    {
        swapMinHeapNodes(&minHeapNodes[(index - 1) / 2], &minHeapNodes[index]);
        index = (index - 1) / 2;
    }
}

int isLeaf(HuffmanNode *root)
{
    return !(root->left) && !(root->right);
}

MinHeapNode *buildMinHeap(HuffmanNode *huffNodes[], int numHuffNodes)
{
    MinHeapNode *minHeapNodes[numHuffNodes];
    int i;
    for (i = 0; i < numHuffNodes; i++)
        minHeapNodes[i] = createMinHeapNode(huffNodes[i]);

    int heapSize = numHuffNodes;

    while (!isSizeOne(heapSize))
    {
        MinHeapNode *minHeapNode1 = extractMin(minHeapNodes, &heapSize);
        MinHeapNode *minHeapNode2 = extractMin(minHeapNodes, &heapSize);

        HuffmanNode *tempHuffNode = (HuffmanNode *)malloc(sizeof(HuffmanNode));
        tempHuffNode->value = '#';
        tempHuffNode->freq = minHeapNode1->huffNode->freq + minHeapNode2->huffNode->freq;
        tempHuffNode->left = minHeapNode1->huffNode;
        tempHuffNode->right = minHeapNode2->huffNode;

        MinHeapNode *tempMinHeapNode = createMinHeapNode(tempHuffNode);
        insertMinHeapNode(minHeapNodes, &heapSize, tempMinHeapNode);
    }

    return extractMin(minHeapNodes, &heapSize);
}

void huffmanEncode(char *str)
{
    int freq[256] = {0};

    int i;
    for (i = 0; str[i] != '\0'; i++)
        freq[(int)str[i]]++;

    HuffmanNode *huffNodes[256];
    int numHuffNodes = 0;
    for (i = 0; i < 256; i++)
    {
        if (freq[i] != 0)
        {
            HuffmanNode *tempHuffNode = (HuffmanNode *)malloc(sizeof(HuffmanNode));
            tempHuffNode->value = (char)i;
            tempHuffNode->freq = freq[i];
            tempHuffNode->left = NULL;
            tempHuffNode->right = NULL;
            huffNodes[numHuffNodes++] = tempHuffNode;
        }
    }

    MinHeapNode *rootMinHeapNode = buildMinHeap(huffNodes, numHuffNodes);

    char code[256];
    encode(rootMinHeapNode->huffNode, str, code, 0);
}

int main()
{
    char str[256];
    printf("Enter a string to encode:\n");
    scanf("%s", str);

    huffmanEncode(str);

    return 0;
}