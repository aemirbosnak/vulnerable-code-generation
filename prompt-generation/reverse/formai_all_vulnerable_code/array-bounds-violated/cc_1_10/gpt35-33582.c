//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TREE_HT 100

int char_count[256] = {0};//counting the frequency of each character in the input file

typedef struct node{
    char data;//represents character value
    unsigned freq;//represents frequency of the character
    struct node *left, *right;
}node;

typedef struct min_heap{
    unsigned size;
    unsigned capacity;
    node **arr;
}min_heap;

node* newNode(char data, unsigned freq){//function to create a new node with given character value and frequency
    node* temp = (node*)malloc(sizeof(node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

min_heap* createHeap(unsigned capacity){//function to create a new min heap
    min_heap* heap = (min_heap*)malloc(sizeof(min_heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->arr = (node**)malloc(heap->capacity * sizeof(node*));
    return heap;
}

void swap(node **a, node **b){//function to swap nodes a and b
    node *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(min_heap* heap, int index){//function to make sure that the heap property is maintained
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < heap->size && heap->arr[left]->freq < heap->arr[smallest]->freq)
        smallest = left;

    if(right < heap->size && heap->arr[right]->freq < heap->arr[smallest]->freq)
        smallest = right;

    if(smallest != index){
        swap(&heap->arr[smallest], &heap->arr[index]);
        minHeapify(heap, smallest);
    }
}

bool isSizeOne(min_heap* heap){//function to check if size of heap is 1
    return (heap->size == 1);
}

node* extractMin(min_heap* heap){//function to extract minimum value node from min heap
    node* temp = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    --heap->size;
    minHeapify(heap, 0);
    return temp;
}

void insert(min_heap* heap, node* newNode){//function to insert a new node into the min heap
    ++heap->size;
    int i = heap->size - 1;
    while(i && newNode->freq < heap->arr[(i - 1)/2]->freq){
        heap->arr[i] = heap->arr[(i - 1)/2];
        i = (i - 1)/2;
    }
    heap->arr[i] = newNode;
}

void buildHeap(min_heap* heap){//function to build the min heap
    int n = heap->size - 1;
    int i;
    for(i = (n - 1)/2; i >= 0; --i)
        minHeapify(heap, i);
}

void printArr(int arr[], int n){//function to print the array of binary codes
    int i;
    for(i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

bool isLeaf(node* root){//function to check if a node is a leaf
    return !(root->left) && !(root->right);
}

min_heap* createAndBuild(min_heap* heap){//function to create and build a min heap from the character frequencies
    int i, n = 0;
    for(i = 0; i < 256; ++i){
        if(char_count[i] != 0)
            ++n;
    }
    heap = createHeap(n);
    for(i = 0; i < 256; ++i){
        if(char_count[i] != 0)
            heap->arr[heap->size++] = newNode(i, char_count[i]);
    }
    buildHeap(heap);
    return heap;
}

node* buildHuffmanTree(){//function to build the Huffman tree
    min_heap* heap = NULL;
    heap = createAndBuild(heap);
    while(!isSizeOne(heap)){
        node *left = extractMin(heap);
        node *right = extractMin(heap);
        node *temp = newNode('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        insert(heap, temp);
    }
    return extractMin(heap);
}

void printCodes(node* root, int arr[], int top){//recursive function to print the Huffman codes for each character
    if(root->left){
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if(root->right){
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if(isLeaf(root)){
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}

void readInputFile(char *filename){//function to read the input file and count the frequency of each character
    FILE *fp = fopen(filename, "r");
    int c;
    if(fp){
        while((c = getc(fp)) != EOF)
            ++char_count[c];
        fclose(fp);
    }
}

void writeFile(char *filename, char **code, char *c){//function to write the compressed output to file
    FILE *fp = fopen(filename, "w");
    if(fp){
        while(*c){
            fprintf(fp, "%s", code[(int)(*c)]);
            ++c;
        }
        fclose(fp);
    }
}

void encodeData(char *filename){//function to encode the input data using Huffman codes
    int arr[MAX_TREE_HT], top = 0;
    char *code[256];
    memset(code, 0, sizeof(code));
    node* root = buildHuffmanTree();
    printCodes(root, arr, top);
    int i;
    for(i = 0; i < 256; ++i){
        if(char_count[i] != 0){
            int n = strlen(code[i]) + 1;
            char *temp = (char*)malloc(n * sizeof(char));
            strncpy(temp, code[i], n);
            temp[n - 1] = '\0';
            code[i] = temp;
        }
    }
    char *c = NULL;
    int s = 0;
    FILE *fp = fopen(filename, "r");
    if(fp){
        fseek(fp, 0, SEEK_END);
        s = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        c = (char*)malloc(sizeof(char) * (s + 1));
        fread(c, 1, s, fp);
        fclose(fp);
        int n = strlen(c);
        for(i = 0; i < n; ++i){
            if(char_count[(int)c[i]] != 0)
                ;
            else{
                printf("\nInput file is not valid for Huffman coding\n");
                exit(1);
            }
        }
        writeFile("output.txt", code, c);
        printf("\nOutput file written succesfully\n");
    }
}

int main(){
    char* filename = "input.txt";
    readInputFile(filename);
    encodeData(filename);
    return 0;
}