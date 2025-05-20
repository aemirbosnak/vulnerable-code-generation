//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum size for the input expression
#define MAX_EXPR_SIZE 256

// Function prototypes
void displayMenu();
double performCalculation(const char *expression);
void clearInputBuffer();
int precedence(char operator);
double applyOperator(double a, double b, char operator);

int main() {
    char expression[MAX_EXPR_SIZE];
    double result;

    printf("Welcome to the Magical Scientific Calculator!\n");
    
    while (1) {
        displayMenu();
        printf("Enter an expression to calculate (or type 'exit' to quit):\n");
        fgets(expression, MAX_EXPR_SIZE, stdin);
        
        // Check if the user wants to exit
        if (strncmp(expression, "exit", 4) == 0) {
            printf("Thank you for using the Magical Scientific Calculator!\n");
            break;
        }
        
        result = performCalculation(expression);
        printf("Result: %.6lf\n\n", result);
    }
    return 0;
}

void displayMenu() {
    printf("\n=====================\n");
    printf(" Magical Calculator\n");
    printf("=====================\n");
    printf("Available operations:\n");
    printf(" +  : Addition\n");
    printf(" -  : Subtraction\n");
    printf(" *  : Multiplication\n");
    printf(" /  : Division\n");
    printf(" ^  : Power\n");
    printf(" sin: Sine (in radians)\n");
    printf(" cos: Cosine (in radians)\n");
    printf(" tan: Tangent (in radians)\n");
    printf("=====================\n");
}

double performCalculation(const char *expression) {
    double stack[100];
    char opStack[100];
    int stackTop = -1, opTop = -1;
    char *token = strtok(expression, " \n");
    
    while (token != NULL) {
        if (isdigit(token[0])) {
            stack[++stackTop] = atof(token);
        } else if (strcmp(token, "sin") == 0 || strcmp(token, "cos") == 0 || strcmp(token, "tan") == 0) {
            token = strtok(NULL, " \n");
            double angle = atof(token); // get the number after the function
            if (strcmp(token - 1, "sin") == 0)
                stack[++stackTop] = sin(angle);
            else if (strcmp(token - 1, "cos") == 0)
                stack[++stackTop] = cos(angle);
            else if (strcmp(token - 1, "tan") == 0)
                stack[++stackTop] = tan(angle);
        } else {
            // Handle operators
            while (opTop != -1 && precedence(opStack[opTop]) >= precedence(token[0])) {
                double b = stack[stackTop--];
                double a = stack[stackTop--];
                char operator = opStack[opTop--];
                stack[++stackTop] = applyOperator(a, b, operator);
            }
            opStack[++opTop] = token[0];
        }
        token = strtok(NULL, " \n");
    }
    
    // Process remaining operators in the stack
    while (opTop != -1) {
        double b = stack[stackTop--];
        double a = stack[stackTop--];
        char operator = opStack[opTop--];
        stack[++stackTop] = applyOperator(a, b, operator);
    }

    return stack[stackTop];
}

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

double applyOperator(double a, double b, char operator) {
    switch (operator) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b != 0) {
                return a / b;
            } else {
                printf("Error: Division by zero!\n");
                exit(EXIT_FAILURE);
            }
        case '^':
            return pow(a, b);
        default:
            printf("Error: Unknown operator %c\n", operator);
            exit(EXIT_FAILURE);
    }
    return 0;
}

void clearInputBuffer() {
    while (getchar() != '\n');
}