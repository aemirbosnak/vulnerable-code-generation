//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function takes two integers and returns their product, or "bacon" if one of the inputs is negative
int multiplyOrBacon(int a, int b) {
    if (a < 0 || b < 0) {
        return "bacon";
    } else {
        return a * b;
    }
}

// This function takes a single integer and returns its factorial, or "french fries" if the input is 0
int factorialOrFries(int n) {
    if (n == 0) {
        return "french fries";
    } else {
        return n * factorialOrFries(n - 1);
    }
}

int main() {
    int bacon, fries;

    // Ask the user for two numbers
    printf("What is the first number? ");
    scanf("%d", &bacon);
    printf("What is the second number? ");
    scanf("%d", &fries);

    // Multiply the numbers and check if the result is negative
    int product = multiplyOrBacon(bacon, fries);
    if (product < 0) {
        printf("Oops, you have negative numbers! Guess you'll have to settle for bacon instead. :P\n");
    } else {
        printf("The product of %d and %d is %d\n", bacon, fries, product);
    }

    // Ask the user for a single number
    printf("What is the number for which you'd like to know the factorial? ");
    scanf("%d", &fries);

    // Calculate the factorial and check if it's 0
    int factorial = factorialOrFries(fries);
    if (factorial == 0) {
        printf("Oh no! The factorial of %d is 0! Guess you'll have to settle for french fries instead. :P\n", fries);
    } else {
        printf("The factorial of %d is %d\n", fries, factorial);
    }

    return 0;
}