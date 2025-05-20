//Code Llama-13B DATASET v1.0 Category: Huffman Coding Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256

typedef struct Node {
    char ch;
    int freq;
    struct Node *left;
    struct Node *right;
} Node;

void print_huffman_tree(Node *root) {
    if (root == NULL) {
        return;
    }

    if (root->left != NULL) {
        print_huffman_tree(root->left);
    }

    if (root->right != NULL) {
        print_huffman_tree(root->right);
    }

    printf("%c: %d\n", root->ch, root->freq);
}

Node* build_huffman_tree(int freq[], int n) {
    Node *nodes[n];

    for (int i = 0; i < n; i++) {
        nodes[i] = (Node *)malloc(sizeof(Node));
        nodes[i]->ch = i;
        nodes[i]->freq = freq[i];
        nodes[i]->left = NULL;
        nodes[i]->right = NULL;
    }

    while (n > 1) {
        Node *min1 = NULL;
        Node *min2 = NULL;

        for (int i = 0; i < n; i++) {
            if (min1 == NULL || nodes[i]->freq < min1->freq) {
                min1 = nodes[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (min2 == NULL || nodes[i]->freq < min2->freq) {
                min2 = nodes[i];
            }
        }

        Node *parent = (Node *)malloc(sizeof(Node));
        parent->ch = 0;
        parent->freq = min1->freq + min2->freq;
        parent->left = min1;
        parent->right = min2;

        nodes[n] = parent;
        n++;
    }

    return nodes[0];
}

int main() {
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int n = sizeof(freq) / sizeof(freq[0]);

    Node *root = build_huffman_tree(freq, n);

    print_huffman_tree(root);

    return 0;
}