//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void main() {
    int num1, num2, operator, choice;
    float result;

    system("cls");

    // Display calculator banner
    printf("_______________________\n");
    printf("           CALCULATOR\n");
    printf("_______________________\n");

    // Get the first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the operator
    printf("Enter the operator (+, -, *, /): ");
    scanf("%d", &operator);

    // Get the second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Calculate the result
    switch (operator) {
        case 1:
            result = (float)num1 + (float)num2;
            break;
        case 2:
            result = (float)num1 - (float)num2;
            break;
        case 3:
            result = (float)num1 * (float)num2;
            break;
        case 4:
            result = (float)num1 / (float)num2;
            break;
        default:
            printf("Invalid operator.\n");
            return;
    }

    // Display the result
    printf("The result is: %.2f\n", result);

    // Get the user's choice
    printf("Do you want to continue? (Y/N): ");
    scanf("%d", &choice);

    // If the user wants to continue, start the program again
    if (choice == 1) {
        main();
    }

    return;
}