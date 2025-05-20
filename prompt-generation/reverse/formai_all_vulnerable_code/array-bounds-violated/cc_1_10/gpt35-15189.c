//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int freq;
    char symbol;
    struct node *left;
    struct node *right;
} node;

node *createNode(int freq, char symbol, node *left, node *right) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->freq = freq;
    newNode->symbol = symbol;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

int isLeaf(node *root) {
    return !(root->left) && !(root->right);
}

void printCodes(node *root, char *code, int top) {
    if (root->left) {
        code[top] = '0';
        printCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = '1';
        printCodes(root->right, code, top + 1);
    }
    if (isLeaf(root)) {
        code[top] = '\0';
        printf("%c: %s\n", root->symbol, code);
    }
}

void encode(char *input, char *output, node *root) {
    FILE *in = fopen(input, "r");
    FILE *out = fopen(output, "w");

    char symbol, c;
    while ((symbol = fgetc(in)) != EOF) {
        node *temp = root;
        while (!isLeaf(temp)) {
            c = fgetc(in);
            if (c == '0') temp = temp->left;
            else temp = temp->right;
        }
        fprintf(out, "%s", &temp->symbol);
    }

    fclose(in);
    fclose(out);
}

void decode(char *input, char *output, node *root) {
    FILE *in = fopen(input, "r");
    FILE *out = fopen(output, "w");

    char symbol, c;
    node *temp = root;
    while ((symbol = fgetc(in)) != EOF) {
        if (symbol == '0') temp = temp->left;
        else temp = temp->right;

        if (isLeaf(temp)) {
            fprintf(out, "%c", temp->symbol);
            temp = root;
        }
    }

    fclose(in);
    fclose(out);
}

void huffman(char *input, char *output) {
    FILE *in = fopen(input, "r");

    int freq[256] = {0};
    char symbol;
    while ((symbol = fgetc(in)) != EOF) {
        freq[symbol]++;
    }

    node *heap[256] = {NULL};
    int heapSize = 0;

    for (int i = 0; i < 256; i++) {
        if (freq[i]) {
            node *newNode = createNode(freq[i], i, NULL, NULL);
            heap[heapSize] = newNode;
            heapSize++;
        }
    }

    while (heapSize > 1) {
        node *left = heap[heapSize - 1];
        node *right = heap[heapSize - 2];
        node *newNode = createNode(left->freq + right->freq, '\0', left, right);
        heap[heapSize - 2] = newNode;
        heapSize--;
        for(int i=heapSize-2; i>=0; i--){
            if(heap[i]->freq < heap[i+1]->freq)
                break;
            node *temp = heap[i];
            heap[i] = heap[i+1];
            heap[i+1] = temp;
        }
    }

    node *root = heap[0];

    char code[256] = {0};
    printCodes(root, code, 0);

    encode(input, output, root);
    decode(output, input, root);

    fclose(in);
}

int main() {
    char input[] = "input.txt";
    char output[] = "output.txt";

    huffman(input, output);

    return 0;
}