//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100000
#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum;
    char op;

    printf("Welcome to the Arithmetic Puzzle!\n");

    // Initialize variables
    num1 = 0;
    num2 = 0;
    sum = 0;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user (using a single character)
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
        sum = -1;
    }

    // Check for magic number
    if (sum == MAGIC_NUMBER) {
        printf("Congratulations! You found the magic number!\n");
    } else {
        printf("Better luck next time...\n");
    }

    // Print the result
    printf("The result of %d + %d is %d\n", num1, num2, sum);

    return 0;
}