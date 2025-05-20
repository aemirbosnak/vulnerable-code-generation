//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 100
#define MIN_VALUE -1000
#define MAX_VALUE 1000

int main() {
    int num1, num2, sum;
    char operation;
    printf("Welcome to the Intelligent Arithmetic Program!\n");

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
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
        if (num2 == 0) {
            printf("Error: cannot divide by zero!\n");
            return 1;
        }
        sum = num1 / num2;
    } else {
        printf("Invalid operation. Please try again.\n");
        return 1;
    }

    // Print the result
    printf("The result of %d %c %d is %d\n", num1, operation, num2, sum);

    // Get the user's feedback
    printf("Was this computation intelligent enough for you? (y/n): ");
    char feedback;
    scanf(" %c", &feedback);

    // If the user is satisfied, print a clever message
    if (feedback == 'y') {
        printf("Intelligent arithmetic is not just a dream, it's a reality! 😉\n");
    }

    return 0;
}