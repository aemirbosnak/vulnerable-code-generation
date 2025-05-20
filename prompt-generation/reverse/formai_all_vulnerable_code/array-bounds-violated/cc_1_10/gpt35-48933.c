//FormAI DATASET v1.0 Category: Syntax parsing ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct syntax_tree {
    char* value;
    struct syntax_tree* left;
    struct syntax_tree* right;
} SyntaxTree;

void print_tree(SyntaxTree* root, int indent) {
    if (root == NULL)
        return;

    print_tree(root->right, indent + 4);
    printf("%*s%s\n", indent, "", root->value);
    print_tree(root->left, indent + 4);
}

SyntaxTree* new_node(char* value) {
    SyntaxTree* node = (SyntaxTree*) malloc(sizeof(SyntaxTree));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

SyntaxTree* parse_expression(char** tokens);
SyntaxTree* parse_term(char** tokens);
SyntaxTree* parse_factor(char** tokens);
SyntaxTree* parse_number(char** tokens);

SyntaxTree* parse_expression(char** tokens) {
    SyntaxTree* term = parse_term(tokens);

    while (*tokens && (**tokens == '+' || **tokens == '-')) {
        char* op = *tokens++;
        SyntaxTree* right = parse_term(tokens);

        SyntaxTree* op_node = new_node(op);
        op_node->left = term;
        op_node->right = right;

        term = op_node;
    }

    return term;
}

SyntaxTree* parse_term(char** tokens) {
    SyntaxTree* factor = parse_factor(tokens);

    while (*tokens && (**tokens == '*' || **tokens == '/')) {
        char* op = *tokens++;
        SyntaxTree* right = parse_factor(tokens);

        SyntaxTree* op_node = new_node(op);
        op_node->left = factor;
        op_node->right = right;

        factor = op_node;
    }

    return factor;
}

SyntaxTree* parse_factor(char** tokens) {
    if (**tokens == '(') {
        *tokens++;
        SyntaxTree* expr = parse_expression(tokens);
        *tokens++;
        return expr;
    }

    if (isdigit(**tokens))
        return parse_number(tokens);

    fprintf(stderr, "Invalid factor: %s\n", *tokens);
    exit(1);
}

SyntaxTree* parse_number(char** tokens) {
    char* num_str = *tokens++;
    while (*tokens && isdigit(**tokens))
        num_str = strcat(num_str, *tokens++);
    return new_node(num_str);
}

SyntaxTree* parse(char** tokens) {
    return parse_expression(tokens);
}

int main() {
    printf("Enter an expression to parse: ");
    char input[512];
    fgets(input, 512, stdin);
    input[strlen(input) - 1] = '\0';

    char* tokens[512];
    int index = 0;
    char* token = strtok(input, " ");
    while (token) {
        tokens[index++] = token;
        token = strtok(NULL, " ");
    }
    tokens[index] = NULL;

    SyntaxTree* root = parse(tokens);
    printf("\nParsed expression tree:\n");
    print_tree(root, 0);

    return 0;
}