//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUMBERS 100
#define MAX_OPERATIONS 100

int main() {
    int num_operations = 0;
    int numbers[MAX_NUMBERS];
    char operations[MAX_OPERATIONS];
    int i, j, res;
    double operand1, operand2;

    // Get the number of operations from the user
    printf("Enter the number of operations: ");
    scanf("%d", &num_operations);

    // Get the numbers and operations from the user
    printf("Enter the numbers and operations (separated by spaces):\n");
    for (i = 0; i < num_operations; i++) {
        scanf("%s", &operations[i]);
        if (operations[i] == '+' || operations[i] == '-' || operations[i] == '*' || operations[i] == '/') {
            printf("Enter the operands for %c:\n", operations[i]);
            scanf("%lf %lf", &operand1, &operand2);
            switch (operations[i]) {
                case '+':
                    res = operand1 + operand2;
                    break;
                case '-':
                    res = operand1 - operand2;
                    break;
                case '*':
                    res = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }
                    res = operand1 / operand2;
                    break;
                default:
                    printf("Error: Invalid operation\n");
                    exit(1);
            }
            printf("Result: %.2lf\n", res);
        } else {
            printf("Error: Invalid operation\n");
            exit(1);
        }
    }

    return 0;
}