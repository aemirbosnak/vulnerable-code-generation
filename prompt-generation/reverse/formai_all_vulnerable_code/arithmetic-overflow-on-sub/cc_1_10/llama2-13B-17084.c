//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100
#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum;
    char operation;

    printf("Welcome to the Calm Arithmetic Program!\n");

    // Ask the user for the first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Ask the user for the second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Ask the user for the operation
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform the operation
    if (operation == '+') {
        sum = num1 + num2;
    } else if (operation == '-') {
        sum = num1 - num2;
    } else if (operation == '*') {
        sum = num1 * num2;
    } else if (operation == '/') {
        sum = num1 / num2;
    } else {
        printf("Invalid operation! Please try again.\n");
        return 1;
    }

    // Print the result
    printf("The result of %d + %d is %d\n", num1, num2, sum);

    // Add some magic to the program
    if (sum == MAGIC_NUMBER) {
        printf("Congratulations! You have found the secret magic number!\n");
    }

    return 0;
}