//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a macro for clearing the console
#define cls cls() system("clear")

// Define a structure for a calculator operand
typedef struct Operand {
    int number;
    char operator;
} Operand;

// Define a function to compare two operands
int compare_operands(Operand a, Operand b) {
    return a.number - b.number;
}

// Define a function to evaluate an expression
double evaluate_expression(Operand *operands, int num_operands) {
    double result = operands[0].number;
    for (int i = 1; i < num_operands; i++) {
        switch (operands[i].operator) {
            case '+':
                result += operands[i].number;
                break;
            case '-':
                result -= operands[i].number;
                break;
            case '*':
                result *= operands[i].number;
                break;
            case '/':
                result /= operands[i].number;
                break;
            case '^':
                result = pow(result, operands[i].number);
                break;
            default:
                break;
        }
    }
    return result;
}

int main() {
    // Create an array of operands
    Operand operands[10];

    // Get the number of operands
    int num_operands = 0;

    // Get the operator and number for each operand
    char operator;
    int number;

    // Loop until the user enters an operator
    printf("Enter an operator (+, -, *, /, ^): ");
    scanf("%c", &operator);

    // While the operator is not equal to '#' (end of input), add an operand
    while (operator != '#') {
        // Get the number for the operand
        printf("Enter the number for the operand: ");
        scanf("%d", &number);

        // Create an operand
        operands[num_operands].number = number;
        operands[num_operands].operator = operator;

        // Increment the number of operands
        num_operands++;

        // Get the next operator
        printf("Enter an operator (+, -, *, /, ^): ");
        scanf("%c", &operator);
    }

    // Evaluate the expression
    double result = evaluate_expression(operands, num_operands);

    // Print the result
    printf("The result of the expression is: %.2lf\n", result);

    return 0;
}