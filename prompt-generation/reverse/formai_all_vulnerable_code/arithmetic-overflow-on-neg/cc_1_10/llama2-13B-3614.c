//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, result;
    char operation;

    // Welcome message
    printf("Welcome to the Invasive Math Exercise!\n");

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user (e.g., +, -, *, /)
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform the operation
    if (operation == '+') {
        result = num1 + num2;
    } else if (operation == '-') {
        result = num1 - num2;
    } else if (operation == '*') {
        result = num1 * num2;
    } else if (operation == '/') {
        result = num1 / num2;
    } else {
        result = -1; // invalid operation
    }

    // Check if the result is equal to MAGIC_NUMBER
    if (result == MAGIC_NUMBER) {
        printf("Congratulations! You got the Magic Number!\n");
    } else {
        printf("Boo! You didn't get the Magic Number :(\n");
    }

    // Randomly change the result
    if (rand() % 2) {
        result = -result;
    }

    // Print the result
    printf("The result is: %d\n", result);

    // Wait for the user to press a key
    getchar();

    return 0;
}