//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the parse tree
struct node {
    char *value;
    struct node *left;
    struct node *right;
};

// Function to create a new parse tree node
struct node *new_node(char *value) {
    struct node *node = malloc(sizeof(struct node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to parse a string into a parse tree
struct node *parse(char *string) {
    // Create a stack of nodes
    struct node **stack = malloc(sizeof(struct node *) * 100);
    int stack_top = -1;

    // Tokenize the string
    char *tokens[100];
    int token_count = 0;
    char *token = strtok(string, " ");
    while (token != NULL) {
        tokens[token_count++] = token;
        token = strtok(NULL, " ");
    }

    // Parse the tokens
    for (int i = 0; i < token_count; i++) {
        if (strcmp(tokens[i], "+") == 0 || strcmp(tokens[i], "-") == 0 || strcmp(tokens[i], "*") == 0 || strcmp(tokens[i], "/") == 0) {
            // Create a new node for the operator
            struct node *node = new_node(tokens[i]);

            // Pop the top two nodes from the stack
            struct node *right = stack[stack_top--];
            struct node *left = stack[stack_top--];

            // Set the left and right children of the operator node
            node->left = left;
            node->right = right;

            // Push the operator node onto the stack
            stack[++stack_top] = node;
        } else {
            // Create a new node for the operand
            struct node *node = new_node(tokens[i]);

            // Push the operand node onto the stack
            stack[++stack_top] = node;
        }
    }

    // Return the root of the parse tree
    return stack[stack_top];
}

// Function to print the parse tree
void print_tree(struct node *root) {
    if (root == NULL) {
        return;
    }

    printf("%s", root->value);

    if (root->left != NULL) {
        printf(" (");
        print_tree(root->left);
        printf(")");
    }

    if (root->right != NULL) {
        printf(" (");
        print_tree(root->right);
        printf(")");
    }
}

// Function to evaluate the parse tree
int evaluate(struct node *root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return atoi(root->value);
    }

    int left = evaluate(root->left);
    int right = evaluate(root->right);

    if (strcmp(root->value, "+") == 0) {
        return left + right;
    } else if (strcmp(root->value, "-") == 0) {
        return left - right;
    } else if (strcmp(root->value, "*") == 0) {
        return left * right;
    } else if (strcmp(root->value, "/") == 0) {
        return left / right;
    } else {
        return 0;
    }
}

// Main function
int main() {
    // Get the input string
    char string[100];
    printf("Enter a mathematical expression: ");
    scanf("%s", string);

    // Parse the string into a parse tree
    struct node *root = parse(string);

    // Print the parse tree
    printf("Parse tree:\n");
    print_tree(root);
    printf("\n");

    // Evaluate the parse tree
    int result = evaluate(root);

    // Print the result
    printf("Result: %d\n", result);

    return 0;
}