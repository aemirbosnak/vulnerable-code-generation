//Code Llama-13B DATASET v1.0 Category: Huffman Coding Implementation ; Style: standalone
/* Huffman Coding Implementation in C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure to represent a node in the Huffman tree */
typedef struct node {
    int freq;
    char symbol;
    struct node *left;
    struct node *right;
} Node;

/* Function to create a new node with the given frequency and symbol */
Node* newNode(int freq, char symbol) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->freq = freq;
    node->symbol = symbol;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Function to create a Huffman tree from the given array of characters */
Node* createHuffmanTree(char arr[], int size) {
    int i;
    Node* tree[size];

    /* Create a leaf node for each unique character and add it to the tree */
    for (i = 0; i < size; i++) {
        tree[i] = newNode(1, arr[i]);
    }

    /* Create a min-heap of all the nodes */
    int minHeap = 0;
    while (minHeap < size - 1) {
        /* Find the two nodes with the minimum frequency */
        int min1 = 0, min2 = 0;
        for (i = 1; i < size; i++) {
            if (tree[i]->freq < tree[min1]->freq) {
                min1 = i;
            }
        }
        for (i = 1; i < size; i++) {
            if (tree[i]->freq < tree[min2]->freq && i != min1) {
                min2 = i;
            }
        }

        /* Create a new node with the minimum frequency and add it to the tree */
        tree[minHeap] = newNode(tree[min1]->freq + tree[min2]->freq, ' ');
        tree[minHeap]->left = tree[min1];
        tree[minHeap]->right = tree[min2];
        minHeap++;
    }

    return tree[0];
}

/* Function to encode a string using the Huffman tree */
void encode(Node* root, char str[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        /* Find the current character in the tree and its corresponding code */
        Node* curr = root;
        char code[100];
        int j = 0;
        while (curr != NULL) {
            if (curr->symbol == str[i]) {
                code[j] = curr->symbol;
                j++;
                break;
            } else if (curr->left != NULL && curr->right != NULL) {
                if (curr->left->symbol == str[i]) {
                    code[j] = '0';
                    j++;
                    curr = curr->left;
                } else if (curr->right->symbol == str[i]) {
                    code[j] = '1';
                    j++;
                    curr = curr->right;
                } else {
                    curr = NULL;
                }
            } else {
                curr = NULL;
            }
        }

        /* Print the code for the current character */
        printf("%s", code);
    }
    printf("\n");
}

/* Function to decode a string using the Huffman tree */
void decode(Node* root, char code[]) {
    Node* curr = root;
    int i = 0;
    while (i < strlen(code)) {
        /* Find the current character in the tree */
        if (code[i] == '0') {
            curr = curr->left;
        } else if (code[i] == '1') {
            curr = curr->right;
        } else {
            break;
        }
        i++;
    }

    /* Print the decoded string */
    printf("%c\n", curr->symbol);
}

int main() {
    /* Test the Huffman coding implementation */
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node* root = createHuffmanTree(arr, size);
    char str[] = "hello world";
    encode(root, str, strlen(str));
    decode(root, "0110010101101001001101111");
    return 0;
}