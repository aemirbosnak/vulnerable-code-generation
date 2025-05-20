//Code Llama-13B DATASET v1.0 Category: Syntax parsing ; Style: surrealist
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    struct Node {
        char* value;
        struct Node* left;
        struct Node* right;
    };

    struct Node* create_node(char* value) {
        struct Node* node = malloc(sizeof(struct Node));
        node->value = value;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    void print_node(struct Node* node) {
        printf("%s\n", node->value);
    }

    struct Node* insert(struct Node* node, char* value) {
        if (node == NULL) {
            return create_node(value);
        }

        if (strcmp(node->value, value) == 0) {
            return node;
        }

        if (strcmp(node->value, value) > 0) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }

        return node;
    }

    int main() {
        struct Node* root = NULL;
        root = insert(root, "apple");
        root = insert(root, "banana");
        root = insert(root, "cherry");
        root = insert(root, "date");
        root = insert(root, "elephant");
        root = insert(root, "fruit");
        root = insert(root, "grapes");
        root = insert(root, "orange");
        root = insert(root, "pear");
        root = insert(root, "pineapple");
        root = insert(root, "strawberry");
        root = insert(root, "watermelon");

        print_node(root);
        return 0;
    }