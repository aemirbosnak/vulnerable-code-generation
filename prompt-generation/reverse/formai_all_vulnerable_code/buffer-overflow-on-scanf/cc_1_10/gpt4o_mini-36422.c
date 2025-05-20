//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: funny
#include <stdio.h>

// This is a recursive function that calculates the factorial
long long int funny_factorial(int n) {
    // Check base case
    if (n < 0) {
        printf("Whoa there! Finding the factorial of a negative number? That's like trying to find Bigfoot! Not gonna happen!\n");
        return -1; // Factorial of negative numbers is undefined
    }
    
    if (n == 0) {
        // Factorial of zero, the ultimate paradox
        printf("0! = 1, because zero's just chillin' with nothing to do!\n");
        return 1;
    }
    
    printf("Calculating %d!... The suspense is killing me!\n", n);
    
    // Holy recursion! Call the function on (n - 1)
    long long int result = n * funny_factorial(n - 1);
    
    // Reveal the mystery of what (n-1)! equals
    printf("%d! = %d * %lld = %lld!\n", n, n, funny_factorial(n - 1), result);
    
    return result;
}

// Main function where all the magic happens
int main() {
    int number;

    printf("Welcome to the Fun-tastic Factorial Factory!\n");
    printf("Enter a non-negative integer to find its factorial: ");
    
    // Getting user input, and holding the breath!
    scanf("%d", &number);

    // Let's do this! But not if it's negative
    if (number >= 0) {
        printf("Calculating the factorial of %d...\n", number);
        long long int result = funny_factorial(number);
        if (result != -1) {
            printf("The factorial of %d is: %lld\n", number, result);
        }
    } else {
        printf("You entered a negative number! That's like requesting a swim in the desert!\n");
    }
    
    printf("Thank you for visiting the Fun-tastic Factorial Factory! Come again!\n");
    
    return 0;
}