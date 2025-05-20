//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Node {
    char data;
    int freq;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char ch) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ch;
    newNode->freq = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, char ch) {
    if (root == NULL) {
        root = createNode(ch);
    } else if (root->data == ch) {
        root->freq++;
    } else if (ch < root->data) {
        root->left = insert(root->left, ch);
    } else {
        root->right = insert(root->right, ch);
    }

    return root;
}

void traverse(struct Node* root) {
    if (root == NULL) {
        return;
    }

    traverse(root->left);
    printf("%c %d\n", root->data, root->freq);
    traverse(root->right);
}

int main() {
    char input[MAX_SIZE];
    int i = 0;
    struct Node* root = NULL;

    printf("Enter a string:\n");
    scanf("%s", input);

    for (i = 0; i < strlen(input); i++) {
        root = insert(root, input[i]);
    }

    printf("Frequency of characters:\n");
    traverse(root);

    return 0;
}