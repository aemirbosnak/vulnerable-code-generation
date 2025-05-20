//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: funny
#include <stddef.h>
#include <stdio.h>

// Declaring a struct to represent a syntax tree node
typedef struct syntax_tree_node {
    char *type;
    struct syntax_tree_node *left;
    struct syntax_tree_node *right;
} syntax_tree_node;

// Function to handle an integer literal
syntax_tree_node *handle_integer_literal(char *input) {
    // Allocating memory for the syntax tree node
    syntax_tree_node *node = malloc(sizeof(syntax_tree_node));
    
    // Setting the type of the node to "integer_literal"
    node->type = "integer_literal";
    
    // Setting the left and right children of the node to NULL
    node->left = NULL;
    node->right = NULL;
    
    // Returning the syntax tree node
    return node;
}

// Function to handle a binary operator
syntax_tree_node *handle_binary_operator(char *input) {
    // Allocating memory for the syntax tree node
    syntax_tree_node *node = malloc(sizeof(syntax_tree_node));
    
    // Setting the type of the node to "binary_operator"
    node->type = "binary_operator";
    
    // Setting the left and right children of the node to NULL
    node->left = NULL;
    node->right = NULL;
    
    // Returning the syntax tree node
    return node;
}

// Function to handle a unary operator
syntax_tree_node *handle_unary_operator(char *input) {
    // Allocating memory for the syntax tree node
    syntax_tree_node *node = malloc(sizeof(syntax_tree_node));
    
    // Setting the type of the node to "unary_operator"
    node->type = "unary_operator";
    
    // Setting the left and right children of the node to NULL
    node->left = NULL;
    node->right = NULL;
    
    // Returning the syntax tree node
    return node;
}

// Function to parse the input string and return the root of the syntax tree
syntax_tree_node *parse_input(char *input) {
    // Initializing the current position in the input string
    size_t position = 0;
    
    // Skipping any leading whitespace
    while (input[position] == ' ') {
        position++;
    }
    
    // Checking if the input string is empty
    if (input[position] == '\0') {
        return NULL;
    }
    
    // Checking if the input string starts with an integer literal
    if (isdigit(input[position])) {
        return handle_integer_literal(input + position);
    }
    
    // Checking if the input string starts with a binary operator
    else if (input[position] == '+' || input[position] == '-' || input[position] == '*' || input[position] == '/') {
        return handle_binary_operator(input + position);
    }
    
    // Checking if the input string starts with a unary operator
    else if (input[position] == '-' || input[position] == '!') {
        return handle_unary_operator(input + position);
    }
    
    // If the input string does not start with any of the expected characters, then it is invalid
    else {
        printf("Invalid input string: %s\n", input);
        return NULL;
    }
}

// Function to print the syntax tree in a human-readable format
void print_syntax_tree(syntax_tree_node *root) {
    // If the root node is NULL, then the syntax tree is empty
    if (root == NULL) {
        return;
    }
    
    // Printing the type of the root node
    printf("%s", root->type);
    
    // If the root node is an integer literal, then printing its value
    if (strcmp(root->type, "integer_literal") == 0) {
        printf(" (%d)", atoi(root->type));
    }
    
    // If the root node is a binary operator, then printing its left and right children
    else if (strcmp(root->type, "binary_operator") == 0) {
        printf(" (");
        print_syntax_tree(root->left);
        printf(" %s ", root->type);
        print_syntax_tree(root->right);
        printf(")");
    }
    
    // If the root node is a unary operator, then printing its child
    else if (strcmp(root->type, "unary_operator") == 0) {
        printf(" (%s", root->type);
        print_syntax_tree(root->left);
        printf(")");
    }
}

// Main function
int main(void) {
    // Getting the input string from the user
    char input[100];
    printf("Enter an arithmetic expression: ");
    scanf("%s", input);
    
    // Parsing the input string and getting the root of the syntax tree
    syntax_tree_node *root = parse_input(input);
    
    // Checking if the input string is valid
    if (root == NULL) {
        return 1;
    }
    
    // Printing the syntax tree
    printf("Syntax tree:\n");
    print_syntax_tree(root);
    printf("\n");
    
    // Freeing the memory allocated for the syntax tree
    free(root);
    
    return 0;
}