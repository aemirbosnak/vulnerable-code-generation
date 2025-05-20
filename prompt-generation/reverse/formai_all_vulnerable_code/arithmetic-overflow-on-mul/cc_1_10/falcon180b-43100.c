//Falcon-180B DATASET v1.0 Category: Error handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to check if a string is a valid integer
int isInteger(char *str) {
    int i = 0;
    while (str[i]!= '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to calculate the factorial of a number
int factorial(int num) {
    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

// Function to handle errors and print error messages
void error(char *msg) {
    printf("Error: %s\n", msg);
    exit(1);
}

// Main function
int main() {
    int n;
    char input[MAX_SIZE];

    // Prompt user for input
    printf("Enter a number: ");
    fgets(input, MAX_SIZE, stdin);

    // Convert input to integer
    n = atoi(input);

    // Check if input is a valid integer
    if (!isInteger(input)) {
        error("Invalid input. Please enter a valid integer.");
    }

    // Check if input is negative
    if (n < 0) {
        error("Input must be a non-negative integer.");
    }

    // Calculate factorial and print result
    int result = factorial(n);
    printf("The factorial of %d is %d.\n", n, result);

    return 0;
}