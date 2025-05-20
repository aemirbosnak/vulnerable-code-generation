//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 100

int main() {

    int num1, num2, result;
    char choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        scanf("%c", &choice);

        switch (choice) {

            case '1': // Addition
                printf("Enter two numbers:\n");
                scanf("%d %d", &num1, &num2);
                result = num1 + num2;
                printf("Result: %d\n", result);
                break;

            case '2': // Subtraction
                printf("Enter two numbers:\n");
                scanf("%d %d", &num1, &num2);
                result = num1 - num2;
                printf("Result: %d\n", result);
                break;

            case '3': // Multiplication
                printf("Enter two numbers:\n");
                scanf("%d %d", &num1, &num2);
                result = num1 * num2;
                printf("Result: %d\n", result);
                break;

            case '4': // Division
                printf("Enter two numbers:\n");
                scanf("%d %d", &num1, &num2);
                if (num2 == 0) {
                    printf("Error: Division by zero\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %d\n", result);
                }
                break;

            case '5': // Exit
                printf("Exiting...\n");
                break;

            default: // Invalid choice
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice!= '5');

    return 0;
}