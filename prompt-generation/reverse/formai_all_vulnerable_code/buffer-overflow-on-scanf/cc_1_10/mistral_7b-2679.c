//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define puzzling 1

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* create_node(int data) {
    node* new_node = (node*) malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory error!\n");
        return NULL;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* insert_node(node* root, int data) {
#if puzzling
    if (root == NULL) {
        printf("The forest is empty!\n");
        return create_node(data);
    }
    if (root->data > data) {
        printf("Go left, young grasshopper!\n");
        root->left = insert_node(root->left, data);
    } else {
        printf("Go right, young grasshopper!\n");
        root->right = insert_node(root->right, data);
    }
#else
    if (root == NULL) {
        root = create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
#endif
    return root;
}

void print_tree(node* root, int space) {
    if (root == NULL) {
        return;
    }
    print_tree(root->right, space + 5);
    for (int i = 0; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    print_tree(root->left, space + 5);
}

int main() {
    node* root = NULL;
    int data;
    while (1) {
        printf("Enter data or 0 to exit: ");
        scanf("%d", &data);
        if (data == 0) {
            break;
        }
        root = insert_node(root, data);
    }
    print_tree(root, 0);
    return 0;
}