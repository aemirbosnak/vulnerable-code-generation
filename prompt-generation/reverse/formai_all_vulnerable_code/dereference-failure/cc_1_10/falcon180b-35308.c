//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_VALUE 100

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

struct node *insert_node(struct node *root, int data) {
    if (root == NULL) {
        root = create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }

    return root;
}

int search_node(struct node *root, int data) {
    if (root == NULL) {
        return 0;
    } else if (data == root->data) {
        return 1;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

int count_nodes(struct node *root) {
    int count = 0;

    if (root!= NULL) {
        count = 1;
        count += count_nodes(root->left);
        count += count_nodes(root->right);
    }

    return count;
}

int main() {
    srand(time(NULL));

    struct node *root = NULL;
    int i, data;

    for (i = 0; i < MAX_NODES; i++) {
        data = rand() % MAX_VALUE;
        root = insert_node(root, data);
    }

    printf("Number of nodes in the tree: %d\n", count_nodes(root));

    int search_data = rand() % MAX_VALUE;
    int found = search_node(root, search_data);

    if (found) {
        printf("Element %d found in the tree\n", search_data);
    } else {
        printf("Element %d not found in the tree\n", search_data);
    }

    return 0;
}