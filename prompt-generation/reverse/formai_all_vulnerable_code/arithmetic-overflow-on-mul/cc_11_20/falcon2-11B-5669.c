//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: future-proof
#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100

int main() {
    int num1, num2, result;
    char operation;
    int size = 0;

    while (1) {
        printf("Enter an operation (+, -, *, /): ");
        scanf(" %c", &operation);

        if (operation == '+' || operation == '-' || operation == '*' || operation == '/') {
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            switch (operation) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    if (num2 == 0) {
                        printf("Error: Division by zero\n");
                    } else {
                        result = num1 / num2;
                    }
                    break;
                default:
                    printf("Invalid operation\n");
            }
            printf("Result: %d\n", result);
        } else {
            printf("Invalid operation\n");
        }

        printf("Do you want to continue (Y/N): ");
        scanf(" %c", &operation);

        if (operation == 'N' || operation == 'n') {
            printf("Goodbye!\n");
            break;
        }
    }

    return 0;
}