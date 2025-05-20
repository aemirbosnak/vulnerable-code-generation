//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 256

typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

Node *newNode(char ch, int freq) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

void encode(Node *root, char *code, int len) {
    if (root == NULL)
        return;

    if (!root->left) {
        code[len] = '\0';
        printf("%c : %s\n", root->ch, code);
    }

    encode(root->left, code, len + 1);
    encode(root->right, code, len + 1);
}

int main() {
    int i, n;
    char ch[MAX_CHAR];
    int freq[MAX_CHAR];

    printf("Enter the number of characters : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter character %d : ", i + 1);
        scanf(" %c", &ch[i]);
        printf("Enter frequency of character %c : ", ch[i]);
        scanf("%d", &freq[i]);
    }

    Node *left[n], *right[n], *root = NULL;

    for (i = 0; i < n; i++) {
        left[i] = newNode(ch[i], freq[i]);
        if (i < n - 1 && freq[i] < freq[i + 1]) {
            root = left[i];
            continue;
        }

        if (root == NULL) {
            root = left[i];
            continue;
        }

        while (root != NULL) {
            if (freq[i] < root->freq) {
                if (root->left == NULL) {
                    root->left = left[i];
                    break;
                }
                left[i] = root;
                root = NULL;
            } else {
                right[i] = left[i];
                left[i] = root;
                root = NULL;

                if (root == NULL) {
                    root = newNode('\0', 0);
                    root->left = right[i];
                    root->right = left[i];
                }
            }
        }
    }

    char code[MAX_CHAR];
    encode(root, code, 0);

    return 0;
}