//FormAI DATASET v1.0 Category: Image compression ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXELS 65535
#define SYMBOLS 256

// Node structure for Huffman tree
struct node {
    int value;
    unsigned freq;
    struct node *left, *right;
};

// Priority queue
struct pqueue {
    int size;
    int capacity;
    struct node** elements;
};

// Function to create a new node
struct node* newNode (int value, unsigned freq) {
    struct node* temp =
        (struct node*) malloc(sizeof(struct node));
    temp->left = temp->right = NULL;
    temp->value = value;
    temp->freq = freq;
    return temp;
}

// Function to create a priority queue
struct pqueue* createPQueue (int capacity) {
    struct pqueue* pQ =
        (struct pqueue*) malloc(sizeof(struct pqueue));
    pQ->size = 0;
    pQ->capacity = capacity;
    pQ->elements =
        (struct node**) malloc(pQ->capacity * sizeof(struct node*));
    return pQ;
}

// Function to swap two nodes
void swapNodes (struct node** x, struct node** y) {
    struct node* temp = *x;
    *x = *y;
    *y = temp;
}

// Function to heapify subtree
void heapify (struct pqueue* pQ, int index) {
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    if (left <
        pQ->size && pQ->elements[left]->freq <
        pQ->elements[smallest]->freq)
        smallest = left;
    if (right <
        pQ->size && pQ->elements[right]->freq <
        pQ->elements[smallest]->freq)
        smallest = right;
    if (smallest != index) {
        swapNodes(&pQ->elements[smallest], &pQ->elements[index]);
        heapify(pQ, smallest);
    }
}

// Function to check if the priority queue is empty
int isEmpty (struct pqueue* pQ) {
    return pQ->size == 0;
}

// Function to fetch the root node of the priority queue
struct node* dequeue (struct pqueue* pQ) {
    struct node* temp = pQ->elements[0];
    pQ->elements[0] = pQ->elements[pQ->size - 1];
    --pQ->size;
    heapify(pQ, 0);
    return temp;
}

// Function to insert a node into the priority queue
void enqueue (struct pqueue* pQ, struct node* node) {
    ++pQ->size;
    int i = pQ->size - 1;
    while (i && node->freq < pQ->elements[(i-1)/2]->freq) {
        pQ->elements[i] = pQ->elements[(i-1)/2];
        i = (i-1)/2;
    }
    pQ->elements[i] = node;
}

// Function to build the Huffman tree
struct node* buildHuffmanTree (unsigned freq[], int size) {
    struct node* left, *right, *top;
    struct pqueue* pQ = createPQueue(size);
    for (int i = 0; i < size; ++i)
        enqueue(pQ, newNode(i, freq[i]));
    while (pQ->size != 1) {
        left = dequeue(pQ);
        right = dequeue(pQ);
        top = newNode(SYMBOLS, left->freq + right->freq);
        top->left = left;
        top->right = right;
        enqueue(pQ, top);
    }
    return dequeue(pQ);
}

// Function to print the Huffman codes
void printHuffmanCodes (struct node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }
    if (root->value != SYMBOLS) {
        printf("%d ", root->value);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Function to compress an image using Huffman coding
void compressImage (FILE* inputfile, FILE* outputfile) {
    int symbolCount[SYMBOLS] = { 0 };
    int pixelCount = 0;
    unsigned char pixel[MAX_PIXELS];
    int c = getc(inputfile);
    while (c != EOF) {
        ++symbolCount[c];
        pixel[pixelCount] = c;
        ++pixelCount;
        c = getc(inputfile);
    }
    pixel[pixelCount] = '\0';
    fseek(inputfile, 0L, SEEK_SET);
    struct node* root = buildHuffmanTree(symbolCount, SYMBOLS);
    int arr[MAX_PIXELS], top = 0;
    printHuffmanCodes(root, arr, top);
    unsigned char code = 0;
    int bitPos = 7;
    c = getc(inputfile);
    while (c != EOF) {
        struct node* temp = root;
        while (temp->left || temp->right) {
            if (c == '0')
                temp = temp->left;
            else if (c == '1')
                temp = temp->right;
            else {
                printf("Unexpected character: %c\n", c);
                exit(1);
            }
            if (!temp) {
                printf("Decoding error!\n");
                exit(1);
            }
            if (temp->left == NULL && temp->right == NULL) {
                for (int i = 0; i < top; ++i) {
                    if (arr[i] == 0)
                        code &= ~(1 << bitPos);
                    else
                        code |= (1 << bitPos);
                    --bitPos;
                    if (bitPos < 0) {
                        fputc(code, outputfile);
                        code = 0;
                        bitPos = 7;
                    }
                }
                break;
            }
            c = getc(inputfile);
        }
    }
    if (bitPos >= 0) {
        fputc(code, outputfile);
        code = 0;
        bitPos = 7;
    }
    fclose(inputfile);
    fclose(outputfile);
}

int main () {
    FILE *inputfile, *outputfile;
    inputfile = fopen("input.bmp", "rb");
    if (inputfile == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }
    outputfile = fopen("output.cic", "wb");
    if (outputfile == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }
    compressImage(inputfile, outputfile);
    return 0;
}