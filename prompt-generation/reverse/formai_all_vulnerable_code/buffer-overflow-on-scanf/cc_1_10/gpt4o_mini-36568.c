//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayMenu() {
    printf("Welcome to the Math Game!\n");
    printf("1. Play\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

void performArithmetic(int num1, int num2) {
    int result;
    char operator;
    int operation = rand() % 4; // Randomly choose an operation (0-3)

    switch (operation) {
        case 0:
            operator = '+';
            result = num1 + num2;
            printf("%d %c %d = %d\n", num1, operator, num2, result);
            break;
        case 1:
            operator = '-';
            result = num1 - num2;
            printf("%d %c %d = %d\n", num1, operator, num2, result);
            break;
        case 2:
            operator = '*';
            result = num1 * num2;
            printf("%d %c %d = %d\n", num1, operator, num2, result);
            break;
        case 3:
            if (num2 != 0) {
                operator = '/';
                result = num1 / num2;
                printf("%d %c %d = %d\n", num1, operator, num2, result);
            } else {
                operator = '/';
                printf("Error! Division by zero is undefined.\n");
            }
            break;
    }
}

int main() {
    int option = 0;
    int num1, num2;

    // Seed the random number generator
    srand(time(NULL));

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the first number: ");
                scanf("%d", &num1);
                printf("Enter the second number: ");
                scanf("%d", &num2);
                performArithmetic(num1, num2);
                break;
            case 2:
                printf("Thank you for playing! Goodbye!\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}