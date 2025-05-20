//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

typedef struct node {
    char data;
    int freq;
    struct node* left;
    struct node* right;
} Node;

typedef struct tree {
    Node* root;
} Tree;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->freq = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Tree* tree, char str[]) {
    int n = strlen(str);
    Node* currentNode = tree->root;
    for (int i = 0; i < n; i++) {
        if (isalpha(str[i])) {
            char ch = tolower(str[i]);
            if (currentNode->left == NULL) {
                currentNode->left = createNode(ch);
            } else if (currentNode->right == NULL) {
                currentNode->right = createNode(ch);
            } else if (currentNode->left!= NULL && currentNode->right!= NULL) {
                if (ch < currentNode->left->data) {
                    currentNode->left = createNode(ch);
                } else {
                    currentNode->right = createNode(ch);
                }
            }
        }
    }
}

void inorder(Node* node) {
    if (node!= NULL) {
        inorder(node->left);
        printf("%c %d\n", node->data, node->freq);
        inorder(node->right);
    }
}

void deleteTree(Node* root) {
    if (root!= NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    Tree tree;
    tree.root = NULL;
    insert(&tree, str);
    printf("Inorder traversal of the Huffman tree:\n");
    inorder(tree.root);
    return 0;
}