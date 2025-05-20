//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define a struct for the syntax tree
typedef struct {
    int data;
    struct node* left;
    struct node* right;
} node;

// Function to create a new node
node* newNode(int data) {
    node* new = (node*) malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

// Function to print the syntax tree
void printTree(node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    printTree(root->left);
    printTree(root->right);
}

// Function to evaluate the syntax tree
int evaluate(node* root) {
    if (root == NULL) {
        return 0;
    }
    switch (root->data) {
        case '+':
            return evaluate(root->left) + evaluate(root->right);
        case '-':
            return evaluate(root->left) - evaluate(root->right);
        case '*':
            return evaluate(root->left) * evaluate(root->right);
        case '/':
            return evaluate(root->left) / evaluate(root->right);
        default:
            return root->data;
    }
}

// Function to parse the input string
node* parse(char* input) {
    int i = 0;
    node* root = NULL;
    while (input[i]!= '\0') {
        if (isdigit(input[i])) {
            int num = input[i] - '0';
            root = newNode(num);
            i++;
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            node* left = parse(input + i + 1);
            root = newNode(input[i]);
            root->left = left;
            i += 2;
        } else {
            printf("Invalid input\n");
            exit(1);
        }
    }
    return root;
}

int main() {
    char input[100];
    printf("Enter a C syntax expression: ");
    scanf("%s", input);
    node* root = parse(input);
    printf("Syntax tree:\n");
    printTree(root);
    printf("\nEvaluation result: %d\n", evaluate(root));
    return 0;
}