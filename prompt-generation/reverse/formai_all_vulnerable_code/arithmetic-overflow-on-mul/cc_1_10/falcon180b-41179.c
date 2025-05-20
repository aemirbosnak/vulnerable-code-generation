//Falcon-180B DATASET v1.0 Category: Error handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a valid integer
int is_valid_int(char* str) {
    int i;
    for(i=0; str[i]!='\0'; i++) {
        if(!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to calculate the factorial of a number
int factorial(int num) {
    int result = 1;
    int i;
    for(i=1; i<=num; i++) {
        result *= i;
    }
    return result;
}

// Function to handle errors
void error(char* message) {
    printf("Error: %s\n", message);
    exit(1);
}

// Main function
int main() {
    char input[100];
    int num;

    // Prompt user for input
    printf("Enter a positive integer: ");
    fgets(input, 100, stdin);

    // Check if input is a valid integer
    if(!is_valid_int(input)) {
        error("Invalid input. Please enter a positive integer.");
    }

    // Convert input to integer
    num = atoi(input);

    // Check if input is a positive integer
    if(num <= 0) {
        error("Input must be a positive integer.");
    }

    // Calculate factorial
    int result = factorial(num);

    // Print result
    printf("Factorial of %d is %d\n", num, result);

    return 0;
}