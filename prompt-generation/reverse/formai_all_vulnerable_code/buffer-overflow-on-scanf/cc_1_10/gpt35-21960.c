//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_TREE_HT 100
 
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};
 
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
};
 
struct MinHeapNode* newNode(char data, unsigned freq)
{
    struct MinHeapNode* temp
        = (struct MinHeapNode*)malloc
(sizeof(struct MinHeapNode));
 
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
 
    return temp;
}
 
struct MinHeap* createMinHeap(unsigned capacity)
{
    struct MinHeap* minHeap
        = (struct MinHeap*)malloc(sizeof(struct MinHeap));
 
    minHeap->size = 0;
 
    minHeap->capacity = capacity;
 
    minHeap->array
        = (struct MinHeapNode**)malloc(minHeap->capacity
* sizeof(struct MinHeapNode*));
    return minHeap;
}
 
void swapMinHeapNode(struct MinHeapNode** a,
                     struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}
 
void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
 
    if (left < minHeap->size
        && minHeap->array[left]->freq
               < minHeap->array[smallest]->freq)
        smallest = left;
 
    if (right < minHeap->size
        && minHeap->array[right]->freq
               < minHeap->array[smallest]->freq)
        smallest = right;
 
    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest],
                        &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}
 
int isSizeOne(struct MinHeap* minHeap)
{
    return (minHeap->size == 1);
}
 
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0]
        = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}
 
void insertMinHeap(struct MinHeap* minHeap,
                   struct MinHeapNode* minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
 
    while (i
           && minHeapNode->freq
                  < minHeap->array[(i - 1) / 2]->freq) {
 
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
  
    minHeap->array[i] = minHeapNode;
}
 
void buildMinHeap(struct MinHeap* minHeap)
{
    int n = minHeap->size - 1;
    int i;
 
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}
 
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
 
    printf("\n");
}
 
int isLeaf(struct MinHeapNode* root)
{
    return !(root->left) && !(root->right);
}
 
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)
{
    struct MinHeap* minHeap = createMinHeap(size);
 
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
 
    minHeap->size = size;
    buildMinHeap(minHeap);
 
    return minHeap;
}
 
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)
{
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
 
void printCodes(struct MinHeapNode* root, int arr[], int top)
{
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
 
void HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
 
    int arr[MAX_TREE_HT], top = 0;
 
    printCodes(root, arr, top);
}
 
 
void compress(char* input, char* output)
{
    FILE* fptr1 = fopen(input, "r");
    FILE* fptr2 = fopen(output, "w");
    char c;
    int freq[128] = {0};
    while ((c = fgetc(fptr1)) != EOF)
        ++freq[c];
    char data[128];
    int i,j;
    for (i = j = 0; i < 128; ++i)
        if (freq[i] != 0)
            data[j++] = i;
    HuffmanCodes(data, freq, j);
    rewind(fptr1);
    char x,g = 0;
    int count;
    while ((c = fgetc(fptr1)) != EOF) {
        for (i = 0; data[i] != c; ++i);
        int arr[MAX_TREE_HT], top = 0;
        struct MinHeapNode* root = buildHuffmanTree(data, freq, j);
        struct MinHeapNode* temp = root;
        while (temp->data != c) {
            if (temp->left != NULL && strchr(data,temp->left->data)!= NULL) {
                temp = temp->left;
                arr[top++] = 0;
            } else {
                temp = temp->right;
                arr[top++] = 1;
            }
        }
        arr[top] = -1;
        for (i = top-1; i >= 0; --i) 
            if (arr[i] == 1) g |= (1 << (7 - count));
            else if (arr[i] == 0) g |= (0 << (7 - count));
            ++count;
            if (count == 8) {
                fputc(g, fptr2);
                count = 0, g = 0;
            }
    }
    if (count) {
        g |= 128 >> count;
        fputc(g, fptr2);
    }
    fclose(fptr1);
    fclose(fptr2);
}
 
void decompress(char* input, char* output)
{
    FILE *fptr1 = fopen(input,"r"),*fptr2 = fopen(output,"w");
    char data[128] = {0};
    int freq[128] = {0},j = 0;
    char c,x;
    while ((c = fgetc(fptr1)) != EOF) {
        for (int i = 0; i < 8; ++i) {
            x = (c >> (7-i))&1;
            if (x) freq[(int)data[j]]++;
            ++j;
            if (data[j-1] == -1) break;
        }
        if (data[j-1] == -1) break;
    }
    j = 0;
    for (int i = 0; i < 128; ++i)
        if (freq[i] != 0)
            data[j++] = i;
    HuffmanCodes(data, freq, j);
    struct MinHeapNode* root = buildHuffmanTree(data, freq, j);
    struct MinHeapNode* temp = root;
    while (1) {
        c = fgetc(fptr1);
        int i;
        for (i = 0; i < 8; ++i) {
            int x = (c >> 7 - i)&1;
            if (x) temp = temp->right;
            else temp = temp->left;
 
            if (isLeaf(temp)) {
                fputc(temp->data, fptr2);
                temp = root;
                if (temp == NULL) break;
            }
        }
        if (temp == NULL) break;
    }
    fclose(fptr1);
    fclose(fptr2);
}
 
int main()
{
    int choice;
    while (1) {
        printf("Enter choice: 1. compress 2. decompress 3. exit\n");
        scanf("%d",&choice);
        getchar();
        if (choice == 1) {
            char input[100];
            printf("Enter file path to compress : ");
            scanf("%[^\n]s",input);
            getchar();
            char output[100];
            printf("Enter file path to save compressed file : ");
            scanf("%[^\n]s",output);
            getchar();
            compress(input,output);
            printf("Compress Successfull!\n");
        } else if (choice == 2) {
            char input[100];
            printf("Enter file path to decompress : ");
            scanf("%[^\n]s",input);
            getchar();
            char output[100];
            printf("Enter file path to save decompressed file : ");
            scanf("%[^\n]s",output);
            getchar();
            decompress(input,output);
            printf("Decompress Successfull!\n");
        } else if (choice == 3) {
            exit(0);
        } else {
            printf("Invalid choice entered.\n");
        }
    }
    return 0;
}