//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, result, choice;
    char operation;
    float decimal1, decimal2;

    srand(time(NULL));
    printf("Welcome to the Arithmetic Puzzle Game!\n");
    printf("Choose your difficulty level:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You have chosen Easy mode.\n");
            break;
        case 2:
            printf("You have chosen Medium mode.\n");
            break;
        case 3:
            printf("You have chosen Hard mode.\n");
            break;
        default:
            printf("Invalid choice. Exiting program.\n");
            return 0;
    }

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    switch (operation) {
        case '+':
            result = num1 + num2;
            printf("Result: %d\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %d\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %d\n", result);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero.\n");
            } else {
                result = num1 / num2;
                printf("Result: %.2f\n", result);
            }
            break;
        default:
            printf("Invalid operation. Exiting program.\n");
            return 0;
    }

    return 0;
}