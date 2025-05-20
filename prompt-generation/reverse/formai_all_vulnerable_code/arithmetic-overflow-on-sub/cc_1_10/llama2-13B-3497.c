//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, result;
    char op;

    printf("Welcome to the Puzzling Math Exercise! \n");

    // Part 1: Guess the Magic Number
    printf("The magic number is: ");
    scanf("%d", &num1);
    if (num1 == MAGIC_NUMBER) {
        printf("Congratulations! You guessed it right! \n");
    } else {
        printf("Oh no! You didn't guess it right... \n");
    }

    // Part 2: Perform Math Operations
    printf("Now, perform the following math operations: \n");

    do {
        printf("Enter the first number: ");
        scanf("%d", &num1);
        printf("Enter the second number: ");
        scanf("%d", &num2);
        printf("Enter the operation (+, -, *, /): ");
        scanf(" %c", &op);

        if (op == '+') {
            result = num1 + num2;
        } else if (op == '-') {
            result = num1 - num2;
        } else if (op == '*') {
            result = num1 * num2;
        } else if (op == '/') {
            result = num1 / num2;
        } else {
            printf("Invalid operation. Try again! \n");
        }

        printf("Result: %d \n", result);
    } while (result != MAGIC_NUMBER);

    printf("Congratulations! You solved the puzzle! \n");
    return 0;
}