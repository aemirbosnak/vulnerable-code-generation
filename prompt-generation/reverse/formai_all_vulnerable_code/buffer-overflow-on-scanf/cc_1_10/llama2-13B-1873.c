//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum;
    char operation;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user (e.g. +, -, *, /)
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform the operation
    switch (operation) {
        case '+':
            sum = num1 + num2;
            break;
        case '-':
            sum = num1 - num2;
            break;
        case '*':
            sum = num1 * num2;
            break;
        case '/':
            sum = num1 / num2;
            break;
        default:
            sum = 0;
            break;
    }

    // Print the result
    printf("The result of %d %c %d is %d\n", num1, operation, num2, sum);

    // Generate a random number between 1 and 10
    int random_number = (rand() % 10) + 1;

    // Check if the result of the operation is equal to the random number
    if (sum == random_number) {
        printf("Congratulations! You have won the magic prize!\n");
    } else {
        printf("Better luck next time...\n");
    }

    return 0;
}