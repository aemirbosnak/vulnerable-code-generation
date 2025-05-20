//Gemma-7B DATASET v1.0 Category: Binary search trees ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_SIZE 1000

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

int insert(Node* node, char data) {
    if (node == NULL) {
        node = (Node*)malloc(sizeof(Node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    } else if (data < node->data) {
        return insert(node->left, data);
    } else {
        return insert(node->right, data);
    }
}

char search(Node* node, char data) {
    if (node == NULL) {
        return 'N';
    } else if (node->data == data) {
        return 'Y';
    } else if (data < node->data) {
        return search(node->left, data);
    } else {
        return search(node->right, data);
    }
}

int main() {
    Node* root = NULL;
    insert(root, 'A');
    insert(root, 'B');
    insert(root, 'C');
    insert(root, 'D');
    insert(root, 'E');

    char data;
    printf("Enter data: ");
    scanf("%c", &data);

    char result = search(root, data);

    if (result == 'Y') {
        printf("Data found.\n");
    } else {
        printf("Data not found.\n");
    }

    return 0;
}