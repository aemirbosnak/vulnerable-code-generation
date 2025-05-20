//Falcon-180B DATASET v1.0 Category: Error handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a valid integer
int isInteger(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n;
    char input[100];

    // Prompt user for input
    printf("Enter a non-negative integer: ");
    scanf("%s", input);

    // Check if input is a valid integer
    if (!isInteger(input)) {
        printf("Error: Input must be a non-negative integer.\n");
        return 1;
    }

    // Convert input to integer
    n = atoi(input);

    // Check if input is non-negative
    if (n < 0) {
        printf("Error: Input must be a non-negative integer.\n");
        return 1;
    }

    // Calculate factorial of input
    int result = factorial(n);

    // Display result
    printf("The factorial of %d is %d.\n", n, result);

    return 0;
}