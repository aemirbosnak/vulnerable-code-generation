//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INT 2147483647
#define MAGIC_NUMBER 42

int main() {
    int num1, num2, result;
    char operation;

    printf("Welcome to the Arithmetic Puzzle!\n");

    // Step 1: Enter the first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Step 2: Enter the second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Step 3: Enter the operation
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Step 4: Perform the operation
    if (operation == '+') {
        result = num1 + num2;
    } else if (operation == '-') {
        result = num1 - num2;
    } else if (operation == '*') {
        result = num1 * num2;
    } else if (operation == '/') {
        result = num1 / num2;
    } else {
        result = -1;
    }

    // Step 5: Check for magic numbers
    if (result == MAGIC_NUMBER) {
        printf("Congratulations! You found the magic number %d!\n", MAGIC_NUMBER);
    } else {
        printf("Too bad, the magic number is %d. Better luck next time!\n", MAGIC_NUMBER);
    }

    // Step 6: Print the result
    printf("The result of %d %s %d is %d\n", num1, operation, num2, result);

    return 0;
}