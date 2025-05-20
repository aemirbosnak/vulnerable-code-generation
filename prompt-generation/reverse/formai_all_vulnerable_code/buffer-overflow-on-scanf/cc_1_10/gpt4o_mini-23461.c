//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_EXPRESSION_LENGTH 100

typedef struct {
    double value;
    char operator;
} Operand;

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

double perform_operation(double a, double b, char operator) {
    switch (operator) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                printf("Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
            return a / b;
        case '^': return pow(a, b);
        default:
            printf("Error: Unknown operator %c\n", operator);
            exit(EXIT_FAILURE);
    }
}

double evaluate_expression(const char *expression) {
    Operand values[MAX_EXPRESSION_LENGTH];
    char operators[MAX_EXPRESSION_LENGTH];
    int value_top = -1, operator_top = -1;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == ' ') continue; // Ignore spaces

        if (isdigit(expression[i])) {
            double value = 0;
            while (isdigit(expression[i])) {
                value = (value * 10) + (expression[i] - '0');
                i++;
            }
            values[++value_top].value = value;
            i--; // to counter the extra increment in the loop
        } else {
            while (operator_top != -1 &&
                   precedence(operators[operator_top]) >= precedence(expression[i])) {
                double b = values[value_top--].value;
                double a = values[value_top--].value;
                char op = operators[operator_top--];
                values[++value_top].value = perform_operation(a, b, op);
            }
            operators[++operator_top] = expression[i];
        }
    }

    while (operator_top != -1) {
        double b = values[value_top--].value;
        double a = values[value_top--].value;
        char op = operators[operator_top--];
        values[++value_top].value = perform_operation(a, b, op);
    }

    return values[value_top].value;
}

void clear_buffer() {
    while (getchar() != '\n');
}

void display_menu() {
    printf("\nScientific Calculator\n");
    printf("1. Evaluate Expression\n");
    printf("2. Exit\n");
}

int main() {
    char expression[MAX_EXPRESSION_LENGTH];
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        clear_buffer(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter expression: ");
                fgets(expression, MAX_EXPRESSION_LENGTH, stdin);
                expression[strcspn(expression, "\n")] = 0; // Remove trailing newline
                double result = evaluate_expression(expression);
                printf("Result: %.2f\n", result);
                break;
            case 2:
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}