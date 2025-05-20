//FormAI DATASET v1.0 Category: Compression algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int frequency[256];

typedef struct node {
    char ch;
    unsigned int freq;
    struct node *left, *right;
} node;

node* newNode(char ch, unsigned int freq) {
    node* n = (node*) malloc(sizeof(node));
    n->left = n->right = NULL;
    n->ch = ch;
    n->freq = freq;
    
    return n;
}

void countFrequency(FILE *f) {
    int c;
    while((c = fgetc(f)) != EOF) {
        frequency[c]++;
    }
}

void buildMinHeap(node **minHeap, int *size) {
    for(int i=0; i<256; i++) {
        if(frequency[i] != 0) {
            minHeap[*size] = newNode((char) i, frequency[i]);
            (*size)++;
        }
    }
}

void buildHuffmanTree(node **minHeap, int *size) {
    while(*size > 1) {
        node *n1 = minHeap[0];
        node *n2 = minHeap[1];
        node *parent = newNode('~', n1->freq + n2->freq);
        parent->left = n1;
        parent->right = n2;
        
        minHeap[0] = parent;
        (*size)--;
        for(int i=1; i<*size; i++) {
            minHeap[i] = minHeap[i+1];
        }
        
        int j = *size - 1;
        while(j > 0 && minHeap[j]->freq < minHeap[j-1]->freq) {
            node *temp = minHeap[j-1];
            minHeap[j-1] = minHeap[j];
            minHeap[j] = temp;
            j--;
        }
        
        minHeap[*size - 1] = parent;
    }
}

void encode(node *root, char *code, int level, char *encoded[]) {
    if(root->left) {
        code[level] = '0';
        encode(root->left, code, level+1, encoded);
    }
    
    if(root->right) {
        code[level] = '1';
        encode(root->right, code, level+1, encoded);
    }
    
    if(!root->left && !root->right) {
        code[level] = '\0';
        char *s = (char*) malloc(sizeof(char) * (level+1));
        strcpy(s, code);
        encoded[root->ch] = s;
    }
}

int main() {
    char inputFileName[20], outputFileName[20], tempFileName[20];
    printf("Enter the file name: ");
    scanf("%s", inputFileName);
    
    FILE *inFile = fopen(inputFileName, "rb");
    if(!inFile) {
        printf("Error opening file");
        return 1;
    }
    
    countFrequency(inFile);
    fclose(inFile);
    
    node *minHeap[256] = {NULL};
    int size = 0;
    buildMinHeap(minHeap, &size);
    
    buildHuffmanTree(minHeap, &size);
    
    char code[256] = {'\0'};
    char *encoded[256] = {NULL};
    encode(minHeap[0], code, 0, encoded);
    
    FILE *tempFile = tmpfile();
    FILE *outputFile = fopen("output.bin", "wb");
    FILE *lookupTable = fopen("lookup.bin", "wb");
    
    unsigned long long fileSize = 0;
    inFile = fopen(inputFileName, "rb");
    while(!feof(inFile)) {
        int c = fgetc(inFile);
        if(!feof(inFile)) {
            fileSize++;
            fwrite(encoded[c], sizeof(char), strlen(encoded[c]), tempFile);
        }
    }
    
    fclose(inFile);
    rewind(tempFile);
    
    fwrite(&fileSize, sizeof(unsigned long long), 1, outputFile);
    
    while(!feof(tempFile)) {
        char buffer[255] = {'\0'};
        int bytesRead = fread(buffer, sizeof(char), 255, tempFile);
        if(bytesRead > 0) {
            fwrite(buffer, sizeof(char), bytesRead, outputFile);
        }
    }
    
    for(int i=0; i<256; i++) {
        if(encoded[i] != NULL) {
            int len = strlen(encoded[i]);
            fwrite(&i, sizeof(char), 1, lookupTable);
            fwrite(&len, sizeof(int), 1, lookupTable);
            fwrite(encoded[i], sizeof(char), len, lookupTable);
        }
    }
    
    fclose(tempFile);
    fclose(outputFile);
    fclose(lookupTable);
    
    printf("%s compressed to output.bin", inputFileName);
    return 0;
}