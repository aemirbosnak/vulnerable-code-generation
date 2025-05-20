//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

typedef struct node {
    char ch;
    int freq;
    struct node *left, *right;
} node;

node *newNode(char ch, int freq) {
    node *temp = (node *)malloc(sizeof(node));
    temp->ch = ch;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

void printCodes(node *root, char codes[], int top) {
    if (root == NULL)
        return;

    if (root->freq > 0) {
        printCodes(root->left, codes, top + 1);
        if (root->left == NULL) {
            printf("%c : %s\n", root->ch, codes);
            codes[top] = '\0';
        }
        printCodes(root->right, codes, top + 1);
    }
}

void HuffmanCoding() {
    int freq[MAX_CHAR];
    node *left, *right, *top;
    char codes[MAX_CHAR][10];
    int i, len;

    printf("Enter the string: ");
    char str[100];
    scanf("%s", str);

    memset(freq, 0, sizeof(freq));
    for (i = 0; str[i] != '\0'; i++)
        freq[str[i]]++;

    node *heap[MAX_CHAR];
    for (i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0)
            heap[i] = newNode(i, freq[i]);
    }

    while (heap[0] && heap[MAX_CHAR - 1]) {
        len = 0;
        left = heap[0];
        right = heap[MAX_CHAR - 1];
        top = newNode('\0', left->freq + right->freq);
        top->left = left;
        top->right = right;

        for (i = 0; i < MAX_CHAR; i++)
            if (heap[i] != NULL && heap[i]->freq > 0) {
                heap[len++] = heap[i];
                heap[i] = NULL;
            }

        if (len < MAX_CHAR - 1) {
            heap[len++] = top;
        }
    }

    printCodes(heap[0], "", 0);
}

int main() {
    printf("Compiled without any errors!\n");
    HuffmanCoding();
    return 0;
}