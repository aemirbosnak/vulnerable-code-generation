//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: genius
/*
 * C Data structures visualization example program
 * Written in a genius style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
    struct node *tail;
};

struct tree {
    int value;
    struct tree *left;
    struct tree *right;
};

// Functions
void insert_list(struct list *list, int value) {
    struct node *node = malloc(sizeof(struct node));
    node->value = value;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

void print_list(struct list *list) {
    struct node *node = list->head;
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}

void insert_tree(struct tree *tree, int value) {
    if (tree->value == NULL) {
        tree->value = value;
        tree->left = NULL;
        tree->right = NULL;
    } else {
        if (value < tree->value) {
            if (tree->left == NULL) {
                tree->left = malloc(sizeof(struct tree));
                tree->left->value = value;
                tree->left->left = NULL;
                tree->left->right = NULL;
            } else {
                insert_tree(tree->left, value);
            }
        } else {
            if (tree->right == NULL) {
                tree->right = malloc(sizeof(struct tree));
                tree->right->value = value;
                tree->right->left = NULL;
                tree->right->right = NULL;
            } else {
                insert_tree(tree->right, value);
            }
        }
    }
}

void print_tree(struct tree *tree) {
    if (tree->left != NULL) {
        print_tree(tree->left);
    }
    printf("%d ", tree->value);
    if (tree->right != NULL) {
        print_tree(tree->right);
    }
}

int main() {
    struct list list;
    list.head = NULL;
    list.tail = NULL;

    for (int i = 0; i < 5; i++) {
        insert_list(&list, i);
    }
    print_list(&list);

    struct tree tree;
    tree.value = 5;
    tree.left = NULL;
    tree.right = NULL;

    for (int i = 0; i < 5; i++) {
        insert_tree(&tree, i);
    }
    print_tree(&tree);

    return 0;
}