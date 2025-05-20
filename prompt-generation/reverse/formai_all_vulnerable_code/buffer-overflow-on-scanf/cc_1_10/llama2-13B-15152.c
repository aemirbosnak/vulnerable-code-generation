//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 1000000
#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, difference, product, quotient, remainder;
    char operation[10];

    printf("Welcome to the Safe Arithmetic Program! \n");

    // Ask the user for the first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Ask the user for the operation
    printf("Enter the operation (+, -, *, /): ");
    fgets(operation, 10, stdin);

    // Parse the operation
    if (strcmp(operation, "+") == 0) {
        // Perform addition
        printf("Enter the second number: ");
        scanf("%d", &num2);
        sum = num1 + num2;
    } else if (strcmp(operation, "-") == 0) {
        // Perform subtraction
        printf("Enter the second number: ");
        scanf("%d", &num2);
        difference = num1 - num2;
    } else if (strcmp(operation, "*") == 0) {
        // Perform multiplication
        printf("Enter the second number: ");
        scanf("%d", &num2);
        product = num1 * num2;
    } else if (strcmp(operation, "/") == 0) {
        // Perform division
        printf("Enter the second number: ");
        scanf("%d", &num2);
        quotient = num1 / num2;
        remainder = num1 % num2;
    } else {
        printf("Invalid operation! Please try again.\n");
        return 1;
    }

    // Print the result
    printf("Result: %d\n", sum);

    // Check if the user wants to play again
    printf("Do you want to play again? (y/n): ");
    char answer;
    scanf(" %c", &answer);

    if (answer == 'y') {
        // Start the program again
        main();
    } else {
        printf("Goodbye! \n");
        return 0;
    }

    return 0;
}