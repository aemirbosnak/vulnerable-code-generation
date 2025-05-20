//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, product, square, cube;
    char operation[10];

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user (e.g. +, -, x, /)
    printf("Enter the operation (+, -, x, /): ");
    scanf("%s", operation);

    // Perform the operation
    if (strcmp(operation, "+") == 0) {
        sum = num1 + num2;
    } else if (strcmp(operation, "-") == 0) {
        sum = num1 - num2;
    } else if (strcmp(operation, "*") == 0) {
        product = num1 * num2;
    } else if (strcmp(operation, "/") == 0) {
        if (num2 == 0) {
            printf("Error: division by zero!\n");
            return 1;
        }
        cube = num1 / num2;
    } else {
        printf("Invalid operation. Please try again.\n");
        return 1;
    }

    // Print the result
    printf("Result: %d\n", sum);

    // Generate a random number between 1 and 10
    srand(time(NULL));
    int random = rand() % 10 + 1;

    // Check if the result is equal to the magic number
    if (sum == MAGIC_NUMBER) {
        printf("Congratulations! You have found the magic number %d!\n", MAGIC_NUMBER);
    } else {
        printf("Too bad, the result is not the magic number %d.\n", MAGIC_NUMBER);
    }

    return 0;
}