//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_EXPR_LEN 100

// Function to evaluate an expression
double evaluate_expression(char* expression) {
    double result = 0;
    char* token = strtok(expression, " ");
    while (token!= NULL) {
        if (isdigit(token[0])) {
            result += atoi(token);
        } else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            result += evaluate_expression(token + 1);
        }
        token = strtok(NULL, " ");
    }
    return result;
}

// Function to print the menu
void print_menu() {
    printf("Scientific Calculator\n");
    printf("1. Enter an expression\n");
    printf("2. Evaluate an expression\n");
    printf("3. Exit\n");
}

// Function to get an expression from the user
char* get_expression() {
    char expression[MAX_EXPR_LEN];
    printf("Enter an expression: ");
    fgets(expression, MAX_EXPR_LEN, stdin);
    return strdup(expression);
}

int main() {
    char* expression = NULL;
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                expression = get_expression();
                printf("Expression: %s\n", expression);
                break;
            case 2:
                expression = get_expression();
                printf("Result: %.2f\n", evaluate_expression(expression));
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }

    } while (choice!= 3);

    return 0;
}