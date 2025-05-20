//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
};

typedef struct node* Node;

Node insert(Node root, int key) {
    if (root == NULL) {
        root = (Node)malloc(sizeof(struct node));
        root->key = key;
        root->left = NULL;
        root->right = NULL;
        return root;
    } else {
        if (key < root->key)
            root->left = insert(root->left, key);
        else if (key > root->key)
            root->right = insert(root->right, key);
        return root;
    }
}

void print_tree(Node root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->key);
    print_tree(root->right);
}

int main() {
    Node root = NULL;
    int key;
    while (1) {
        printf("Enter key to insert into the tree (0 to quit): ");
        scanf("%d", &key);
        if (key == 0)
            break;
        root = insert(root, key);
    }
    printf("The tree is: \n");
    print_tree(root);
    return 0;
}