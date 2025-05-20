//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: surprised
#include <stdio.h>

/* Surprise! This program calculates the factorial of a number using recursion,
   but wait, it does more! It explores the whimsical world of imaginary numbers. 
   Can you believe it? Let's dive into this mathematical mystery. */

/* Function: calculate_factorial
   This function takes an integer n and recursively calculates its factorial.
   Surprise, the factorial of 0 is 1, by definition! */
int calculate_factorial(int n) {
    if (n < 0) {
        printf("Oops! Factorial is not defined for negative numbers.\n");
        return -1; // Indicator for error
    }
    if (n == 0) {
        return 1; // Base case: 0! = 1
    }
    return n * calculate_factorial(n - 1);
}

/* Function: calculate_imaginary_factorial
   What if we could calculate the 'imaginary factorial'? 
   This function mimics the idea for imaginary units. */
void calculate_imaginary_factorial(int n) {
    if (n < 0) {
        printf("Surprisingly, we can't calculate factorials for negative imaginary numbers!\n");
        return;
    }

    if (n == 0) {
        printf("An imaginary surprise! The imaginary factorial of 0 is still 1! 🎉\n");
        return;
    }

    printf("Calculating imaginary factorial for i^%d...\n", n);
    for (int i = 1; i <= n; i++) {
        printf("i^%d ", i);
        if (i % 2 == 0) {
            printf("= -1 ");
        } else {
            printf("= i ");
        }
        printf("\n");
    }
}

/* Function: main
   This is where the magic begins! */
int main() {
    int num;

    printf("🎉 Welcome to the Surprise Factorial Program! 🎉\n");
    printf("Please enter a non-negative integer to calculate its factorial: ");
    scanf("%d", &num);

    int factorial_result = calculate_factorial(num);
    if (factorial_result != -1) {
        printf("The factorial of %d is: %d\n", num, factorial_result);
    }

    printf("\nNow, let's have some fun with imaginary numbers!\n");
    printf("How many powers of 'i' would you like to explore? ");
    scanf("%d", &num);
    calculate_imaginary_factorial(num);

    printf("Whoa! What an amazing journey into the world of numbers!\n");
    printf("Remember, mathematics is full of surprises. Keep exploring! 🎈\n");
    
    return 0; // Surprise! Program ended successfully!
}