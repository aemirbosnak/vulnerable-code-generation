//Falcon-180B DATASET v1.0 Category: Error handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a string is a valid integer
bool isInteger(char* str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

// Function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    int i;
    for (i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num;
    char input[100];

    // Prompt user for input
    printf("Enter a positive integer: ");
    scanf("%s", input);

    // Check if input is a valid integer
    if (!isInteger(input)) {
        printf("Error: Input must be a positive integer.\n");
        return 1;
    }

    // Convert input to integer
    num = atoi(input);

    // Check if input is a positive integer
    if (num <= 0) {
        printf("Error: Input must be a positive integer.\n");
        return 1;
    }

    // Calculate factorial and display result
    int result = factorial(num);
    printf("The factorial of %d is %d.\n", num, result);

    return 0;
}