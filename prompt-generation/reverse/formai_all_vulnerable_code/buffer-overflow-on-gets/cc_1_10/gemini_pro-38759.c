//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the syntax tree nodes
typedef struct Node {
    char* value;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new node
Node* createNode(char* value) {
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Parse the input string
Node* parse(char* input) {
    // Create a stack to store the nodes
    Node** stack = malloc(sizeof(Node*) * 100);
    int stackSize = 0;

    // Tokenize the input string
    char* token = strtok(input, " ");

    // Parse the tokens
    while (token != NULL) {
        // If the token is an operator, create a new node
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            Node* node = createNode(token);
            node->right = stack[stackSize - 1];
            stackSize--;
            node->left = stack[stackSize - 1];
            stackSize--;
            stack[stackSize++] = node;
        }
        // If the token is a number, create a new node
        else {
            Node* node = createNode(token);
            stack[stackSize++] = node;
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Return the root node of the syntax tree
    return stack[stackSize - 1];
}

// Evaluate the syntax tree
int evaluate(Node* root) {
    // If the node is an operator, evaluate the left and right subtrees and perform the operation
    if (strcmp(root->value, "+") == 0) {
        return evaluate(root->left) + evaluate(root->right);
    } else if (strcmp(root->value, "-") == 0) {
        return evaluate(root->left) - evaluate(root->right);
    } else if (strcmp(root->value, "*") == 0) {
        return evaluate(root->left) * evaluate(root->right);
    } else if (strcmp(root->value, "/") == 0) {
        return evaluate(root->left) / evaluate(root->right);
    }
    // If the node is a number, return the value
    else {
        return atoi(root->value);
    }
}

// Main function
int main() {
    // Get the input string from the user
    char input[100];
    printf("Enter an expression: ");
    gets(input);

    // Parse the input string
    Node* root = parse(input);

    // Evaluate the syntax tree
    int result = evaluate(root);

    // Print the result
    printf("The result is: %d\n", result);

    return 0;
}