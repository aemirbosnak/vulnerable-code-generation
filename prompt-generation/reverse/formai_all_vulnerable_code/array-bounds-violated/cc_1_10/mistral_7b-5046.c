//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 30
#define MAX_HEIGHT 100

typedef struct {
    char name[MAX_NAME_LENGTH + 1];
    int height;
    int is_leaf;
    struct node *left, *right;
} node;

void set_node(node *node, char *name) {
    strcpy(node->name, name);
    node->height = 0;
    node->is_leaf = 1;
    node->left = NULL;
    node->right = NULL;
}

node *create_node(char *name) {
    node *new_node = (node *) malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Out of memory!\n");
        exit(EXIT_FAILURE);
    }
    set_node(new_node, name);
    return new_node;
}

node *insert(node *root, node *new_node) {
    if (root == NULL) {
        root = new_node;
        return root;
    }

    int cmp_result = strcmp(new_node->name, root->name);
    if (cmp_result < 0) {
        root->left = insert(root->left, new_node);
    } else if (cmp_result > 0) {
        root->right = insert(root->right, new_node);
    }

    root->height = 1 + MAX(height(root->left), height(root->right));
    return root;
}

int height(node *node) {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

int MAX(int a, int b) {
    return (a > b) ? a : b;
}

void print_node(node *node) {
    if (node == NULL) {
        printf("NULL");
        return;
    }

    printf("%s (h=%d)", node->name, node->height);
    if (!node->is_leaf) {
        printf(" [%d, %d]", height(node->left), height(node->right));
    }
}

void print_tree(node *root, int space) {
    if (root == NULL) {
        return;
    }

    print_tree(root->right, space + 5);
    printf("\n");
    for (int i = 0; i < space; i++) {
        putchar(' ');
    }
    print_node(root);
    print_tree(root->left, space + 5);
}

int main() {
    node *root = NULL;

    char names[MAX_HEIGHT][MAX_NAME_LENGTH + 1];
    int num_nodes = 10;

    for (int i = 0; i < num_nodes; i++) {
        printf("Enter node %d name: ", i + 1);
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strlen(names[i]) - 1] = '\0'; // Remove newline character

        node *new_node = create_node(names[i]);
        root = insert(root, new_node);
    }

    printf("\nTree:\n");
    print_tree(root, 0);

    free(root);

    return EXIT_SUCCESS;
}