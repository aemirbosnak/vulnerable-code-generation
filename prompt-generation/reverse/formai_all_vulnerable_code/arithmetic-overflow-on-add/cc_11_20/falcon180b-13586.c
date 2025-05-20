//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operation, result;
    char choice;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the first number from the user
    printf("Enter the first number: ");
    if (scanf("%d", &num1)!= 1) {
        printf("Invalid input!\n");
        return 1;
    }

    // Get the second number from the user
    printf("Enter the second number: ");
    if (scanf("%d", &num2)!= 1) {
        printf("Invalid input!\n");
        return 1;
    }

    // Get the operation from the user
    printf("Enter the operation (+, -, *, /): ");
    if (scanf(" %c", &operation)!= 1) {
        printf("Invalid input!\n");
        return 1;
    }

    // Perform the operation and print the result
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
                printf("Division by zero is not allowed!\n");
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            printf("Invalid operation!\n");
            return 1;
    }

    printf("The result is: %d\n", result);

    // Ask the user if they want to perform another operation
    printf("Do you want to perform another operation? (y/n): ");
    if (scanf(" %c", &choice)!= 1) {
        printf("Invalid input!\n");
        return 1;
    }

    // Repeat the program if the user wants to
    while (choice == 'y' || choice == 'Y') {
        main();
        printf("Do you want to perform another operation? (y/n): ");
        if (scanf(" %c", &choice)!= 1) {
            printf("Invalid input!\n");
            return 1;
        }
    }

    return 0;
}