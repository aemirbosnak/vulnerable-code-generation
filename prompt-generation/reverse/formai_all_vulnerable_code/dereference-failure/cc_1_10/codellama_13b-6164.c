//Code Llama-13B DATASET v1.0 Category: Syntax parsing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a syntax node
typedef struct Node {
    int type; // 0 for operator, 1 for operand
    char value[10];
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node *create_node(int type, char *value) {
    Node *node = malloc(sizeof(Node));
    node->type = type;
    strcpy(node->value, value);
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to parse a syntax tree from a string
Node *parse(char *str) {
    Node *root = create_node(0, str[0]);
    char *start = str + 1;
    char *end = str + strlen(str) - 1;
    while (start <= end) {
        if (*start == '(') {
            root->left = parse(start + 1);
        } else if (*start == ')') {
            root->right = parse(start + 1);
        } else {
            root->right = create_node(1, start);
        }
        start++;
    }
    return root;
}

// Function to print a syntax tree
void print_tree(Node *root) {
    if (root == NULL) {
        return;
    }
    if (root->type == 0) {
        printf("%s", root->value);
    } else {
        printf("%s", root->value);
    }
    print_tree(root->left);
    print_tree(root->right);
}

int main() {
    char str[] = "(a+b)*c";
    Node *root = parse(str);
    print_tree(root);
    return 0;
}