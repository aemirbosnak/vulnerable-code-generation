//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int choice, num1, num2, result;
    char operation;

    printf("Welcome to the Shocking Arithmetic Calculator\n");
    printf("Enter 1 for addition\n");
    printf("Enter 2 for subtraction\n");
    printf("Enter 3 for multiplication\n");
    printf("Enter 4 for division\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter two numbers to add: ");
        scanf("%d %d", &num1, &num2);
        result = num1 + num2;
        printf("The result is: %d\n", result);
    }
    else if (choice == 2) {
        printf("Enter two numbers to subtract: ");
        scanf("%d %d", &num1, &num2);
        result = num1 - num2;
        printf("The result is: %d\n", result);
    }
    else if (choice == 3) {
        printf("Enter two numbers to multiply: ");
        scanf("%d %d", &num1, &num2);
        result = num1 * num2;
        printf("The result is: %d\n", result);
    }
    else if (choice == 4) {
        printf("Enter two numbers to divide: ");
        scanf("%d %d", &num1, &num2);
        if (num2 == 0) {
            printf("Error: Division by zero is not allowed!\n");
        }
        else {
            result = num1 / num2;
            printf("The result is: %d\n", result);
        }
    }
    else {
        printf("Invalid choice! Please enter a valid choice.\n");
    }

    return 0;
}