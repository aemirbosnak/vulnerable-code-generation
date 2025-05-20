//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100

int main() {
    int num1, num2, sum;
    char op;

    // Ask the user for the first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Ask the user for the second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Ask the user for the operation
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    // Perform the operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        sum = num1 - num2;
    } else if (op == '*') {
        sum = num1 * num2;
    } else if (op == '/') {
        sum = num1 / num2;
    } else {
        printf("Invalid operation. Please try again.\n");
        return 1;
    }

    // Print the result
    printf("The result of %d + %d is %d\n", num1, num2, sum);

    // Ask the user if they want to play again
    printf("Do you want to play again? (y/n): ");
    char answer;
    scanf(" %c", &answer);

    if (answer == 'y') {
        main();
    } else {
        printf("Goodbye! \n");
    }

    return 0;
}