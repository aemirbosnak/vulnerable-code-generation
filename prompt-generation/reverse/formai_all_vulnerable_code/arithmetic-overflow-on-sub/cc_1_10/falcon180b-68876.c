//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, result;
    char operation;

    printf("Welcome to the Future of Arithmetic!\n");

    while (1) {
        printf("Enter the first number: ");
        scanf("%d", &num1);

        printf("Enter the second number: ");
        scanf("%d", &num2);

        printf("Enter the operation (+, -, *, /): ");
        scanf(" %c", &operation);

        switch (operation) {
            case '+':
                result = num1 + num2;
                printf("The result is %d.\n", result);
                break;
            case '-':
                result = num1 - num2;
                printf("The result is %d.\n", result);
                break;
            case '*':
                result = num1 * num2;
                printf("The result is %d.\n", result);
                break;
            case '/':
                if (num2 == 0) {
                    printf("Error: Division by zero.\n");
                } else {
                    result = num1 / num2;
                    printf("The result is %d.\n", result);
                }
                break;
            default:
                printf("Invalid operation. Please try again.\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &operation);

        if (operation == 'n' || operation == 'N') {
            printf("Exiting program...\n");
            break;
        }
    }

    return 0;
}