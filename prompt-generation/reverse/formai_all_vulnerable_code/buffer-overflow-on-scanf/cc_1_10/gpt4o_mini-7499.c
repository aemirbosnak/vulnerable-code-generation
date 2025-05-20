//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: surprised
#include <stdio.h>

// Function to calculate Factorial
unsigned long long factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to print a surprise message based on input number
void surpriseMessage(int num) {
    if (num == 5) {
        printf("Surprise! You've reached the magical number 5!\n");
    } else if (num == 10) {
        printf("Wow! 10 is such a round number!\n");
    } else if (num == 15) {
        printf("Did you just guess it? 15 is awesome!\n");
    } else {
        printf("Continuing our journey through the numbers...\n");
    }
}

// Function to print a pyramid of numbers
void printPyramid(int n) {
    if (n == 0) {
        return;
    }
    printPyramid(n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", n);
    }
    printf("\n");
}

// Main function to execute the program
int main() {
    int number;

    printf("Welcome to the Factorial and Surprise Generator!\n");
    printf("Please enter a positive integer: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Cannot compute factorial of a negative number!\n");
        return 1;
    }

    // Factorial calculation
    unsigned long long fact = factorial(number);
    printf("The factorial of %d is: %llu\n", number, fact);

    // Generate Surprise Messages
    surpriseMessage(number);

    // Print number pyramid
    printf("Here's a pyramid of numbers up to %d:\n", number);
    printPyramid(number);

    printf("Thank you for using the Factorial and Surprise Generator!\n");
    return 0;
}