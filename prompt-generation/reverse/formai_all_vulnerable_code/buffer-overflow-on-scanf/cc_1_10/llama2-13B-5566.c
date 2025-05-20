//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MIN_VALUE 1000000
#define MAX_VALUE 0

int main() {
    int num1, num2, sum;
    char op;

    printf("Welcome to the Invasive Math Game!\n");

    // Initialize variables
    num1 = (int)rand() % 100;
    num2 = (int)rand() % 100;
    sum = 0;

    // Get operation from user
    printf("Enter an operation (+, -, *, /): ");
    scanf("%c", &op);

    // Perform operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        sum = num1 - num2;
    } else if (op == '*') {
        sum = num1 * num2;
    } else if (op == '/') {
        sum = num1 / num2;
    }

    // Check for errors
    if (sum < MIN_VALUE || sum > MAX_VALUE) {
        printf("Error: result out of range. Try again!\n");
        return 1;
    }

    // Print result
    printf("Result: %d\n", sum);

    // Ask user for next operation
    printf("Do you want to continue? (y/n): ");
    scanf(" %c", &op);

    return 0;
}