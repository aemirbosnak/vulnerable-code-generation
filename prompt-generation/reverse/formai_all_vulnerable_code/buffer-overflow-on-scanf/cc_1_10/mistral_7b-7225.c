//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

Node* newNode(char ch, int freq) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

void printCodes(Node* root, char str[]) {
    if (root == NULL)
        return;

    if (root->freq == 0)
        return;

    printCodes(root->left, str);

    printf("%c : %s\n", root->ch, str);
    str[root->freq] = '\0';

    printCodes(root->right, str);
}

int height(Node* node) {
    if (node == NULL)
        return 0;
    return (1 + max(height(node->left), height(node->right)));
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* buildHeap(Node** nodes, int size) {
    Node* heap = NULL;
    int i;

    for (i = 0; i < size; i++) {
        Node* temp = nodes[i];
        int pos = i;

        while (pos != 0 && nodes[pos / 2]->freq > temp->freq) {
            nodes[pos] = nodes[pos / 2];
            pos /= 2;
            nodes[pos] = temp;
        }

        heap = nodes[pos];
        nodes[pos] = temp;
    }

    return heap;
}

void huffmanCoding(char str[]) {
    int size = strlen(str);
    Node** nodes = (Node**)malloc(sizeof(Node*) * (size + 2));

    for (int i = 0; i < size; i++) {
        nodes[i] = newNode(str[i], 1);
    }

    Node* root = buildHeap(nodes, size + 1);

    while (root->left != NULL) {
        Node* temp = root;
        root = newNode('\0', root->freq + temp->freq);
        root->left = temp->left;
        root->right = temp->right;
    }

    char codes[256] = {'\0'};

    printCodes(root, "");

    free(nodes);
}

int main() {
    char str[100];
    printf("Enter a string : ");
    scanf("%s", str);

    huffmanCoding(str);

    return 0;
}