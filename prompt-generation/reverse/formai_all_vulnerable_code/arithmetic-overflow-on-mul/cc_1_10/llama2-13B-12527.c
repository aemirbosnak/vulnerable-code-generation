//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 1000000

int main() {
    int num1, num2, sum, diff, mult, div;
    char op;

    printf("Welcome to the Arithmetic Playground! \n");

    // Initialize variables
    num1 = 0;
    num2 = 0;
    sum = 0;
    diff = 0;
    mult = 0;
    div = 0;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    // Perform the operation
    switch (op) {
        case '+':
            sum = num1 + num2;
            break;
        case '-':
            diff = num1 - num2;
            break;
        case '*':
            mult = num1 * num2;
            break;
        case '/':
            div = num1 / num2;
            break;
        default:
            printf("Invalid operation! \n");
            return 0;
    }

    // Print the results
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    printf("The difference of %d and %d is %d\n", num1, num2, diff);
    printf("The product of %d and %d is %d\n", num1, num2, mult);
    printf("The quotient of %d and %d is %d\n", num1, num2, div);

    // Get the user's response
    printf("Do you want to play again? (y/n): ");
    char response[5];
    scanf(" %s", response);

    // End the program based on the user's response
    if (strcmp(response, "y") == 0) {
        main();
    } else {
        printf("Goodbye! \n");
        return 0;
    }

    return 0;
}