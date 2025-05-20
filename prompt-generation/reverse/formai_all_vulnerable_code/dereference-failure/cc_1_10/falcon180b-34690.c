//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int size;
    struct node* left;
    struct node* right;
} node;

node* create_node() {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->size = 0;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(node* root, char* word) {
    int len = strlen(word);
    node* current_node = root;

    while (len > 0) {
        int index = word[0] - 'a';
        if (current_node->left == NULL) {
            current_node->left = create_node();
        }
        else if (current_node->right == NULL) {
            current_node->right = create_node();
        }

        if (index < 0 || index >= current_node->size) {
            current_node->size++;
        }

        current_node = (index < 0 || index >= current_node->size)? current_node->right : current_node->left;
        len--;
    }

    current_node->data[0] = '\0';
}

void inorder_traversal(node* root) {
    if (root == NULL)
        return;

    inorder_traversal(root->left);
    printf("%s ", root->data);
    inorder_traversal(root->right);
}

void main() {
    node* root = create_node();

    char* words[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon"};

    int i = 0;
    while (i < 10) {
        insert(root, words[i]);
        i++;
    }

    printf("In-order traversal of the BST is \n");
    inorder_traversal(root);
}