//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define THRESHOLD 20

// Function to calculate factorial with paranoia checks
unsigned long long paranoidFactorial(int n) {
    // Check if the input number is valid
    if (n < 0) {
        printf("Danger! Negative input: %d. This could lead to a bad recursion spiral!\n", n);
        exit(EXIT_FAILURE);
    }

    if (n > THRESHOLD) {
        printf("Warning! Input too large: %d. Are you sure you want to proceed?\n", n);
        printf("You might want to back away before the recursion deeply entrenches you!\n");
        exit(EXIT_FAILURE);
    }

    // Base case
    if (n == 0) {
        printf("No enemy shall pass! Factorial of 0 is 1.\n");
        return 1;
    }

    // Recursive step with paranoia message
    printf("Calculating factorial of %d. Are you sure this is safe?\n", n);
    unsigned long long result = n * paranoidFactorial(n - 1);

    // Post recursion check
    if (result < n) {
        printf("Critical error! Result overflow detected! Exiting for safety...\n");
        exit(EXIT_FAILURE);
    }

    printf("Finished calculating factorial for %d. Result is %llu.\n", n, result);
    return result;
}

int main() {
    int number;
    
    // Input loop with fear of the unknown
    while (1) {
        printf("Enter a number to calculate its factorial (0 to %d): ", THRESHOLD);
        if (scanf("%d", &number) != 1) {
            printf("Suspicious input detected! Only integers are allowed. Please try again.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        if (number < 0) {
            printf("Alarming! You cannot enter negative numbers! Try again.\n");
            continue;
        }
        
        if (number > THRESHOLD) {
            printf("Caution! Your number exceeds the safe calculation limit. Choose wisely!\n");
            continue;
        }
        
        break; // Valid input, we can proceed to calculate
    }

    printf("Proceeding with trepidation to compute factorial of %d...\n", number);
    unsigned long long factorial = paranoidFactorial(number);
    
    printf("The factorial of %d is %llu. This knowledge comes with great power, handle with care!\n", number, factorial);
    return 0;
}