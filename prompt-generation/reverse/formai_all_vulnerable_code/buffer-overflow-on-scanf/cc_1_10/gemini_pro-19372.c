//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our cheerful syntax tree node
typedef struct node {
    char* data;
    struct node* left;
    struct node* right;
} node_t;

// Function to create a new node
node_t* create_node(char* data) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->data = strdup(data);
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to parse a C expression
node_t* parse_expression(char* expr) {
    if (strlen(expr) == 0) {
        return NULL;
    }

    // Check if the expression is a number
    if (isdigit(expr[0])) {
        return create_node(expr);
    }

    // Check if the expression is a variable
    if (isalpha(expr[0])) {
        return create_node(expr);
    }

    // Check if the expression is a parenthesized expression
    if (expr[0] == '(' && expr[strlen(expr) - 1] == ')') {
        return parse_expression(expr + 1);
    }

    // Check if the expression is a binary operator
    char* op = strstr(expr, "+");
    if (op != NULL) {
        node_t* left_node = parse_expression(expr);
        node_t* right_node = parse_expression(op + 1);
        node_t* new_node = create_node("+");
        new_node->left = left_node;
        new_node->right = right_node;
        return new_node;
    }

    op = strstr(expr, "-");
    if (op != NULL) {
        node_t* left_node = parse_expression(expr);
        node_t* right_node = parse_expression(op + 1);
        node_t* new_node = create_node("-");
        new_node->left = left_node;
        new_node->right = right_node;
        return new_node;
    }

    op = strstr(expr, "*");
    if (op != NULL) {
        node_t* left_node = parse_expression(expr);
        node_t* right_node = parse_expression(op + 1);
        node_t* new_node = create_node("*");
        new_node->left = left_node;
        new_node->right = right_node;
        return new_node;
    }

    op = strstr(expr, "/");
    if (op != NULL) {
        node_t* left_node = parse_expression(expr);
        node_t* right_node = parse_expression(op + 1);
        node_t* new_node = create_node("/");
        new_node->left = left_node;
        new_node->right = right_node;
        return new_node;
    }

    // If the expression is not valid, return NULL
    return NULL;
}

// Function to print the syntax tree
void print_syntax_tree(node_t* root) {
    if (root == NULL) {
        return;
    }

    printf("%s\n", root->data);
    print_syntax_tree(root->left);
    print_syntax_tree(root->right);
}

// Function to free the syntax tree
void free_syntax_tree(node_t* root) {
    if (root == NULL) {
        return;
    }

    free(root->data);
    free_syntax_tree(root->left);
    free_syntax_tree(root->right);
    free(root);
}

int main() {
    // Get the expression from the user
    char expr[100];
    printf("Enter an expression: ");
    scanf("%s", expr);

    // Parse the expression
    node_t* root = parse_expression(expr);

    // Print the syntax tree
    printf("Syntax tree:\n");
    print_syntax_tree(root);

    // Free the syntax tree
    free_syntax_tree(root);

    return 0;
}