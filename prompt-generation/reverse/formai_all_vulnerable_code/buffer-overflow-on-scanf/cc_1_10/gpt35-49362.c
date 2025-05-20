//FormAI DATASET v1.0 Category: Arithmetic ; Style: creative
#include <stdio.h>

// Function to check if a number is prime
int isPrime(int num) {
    int i;

    // 1 is not a prime number
    if (num == 1) {
        return 0;
    }

    // Check if num is divisible by any number other than itself and 1
    for (i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    // If no other number divides num, then it is a prime number
    return 1;
}

// Function to calculate the factorial of a number
int factorial(int num) {
    int i;
    int result = 1;

    // Calculate the factorial of num
    for (i = num; i > 1; i--) {
        result *= i;
    }

    return result;
}

int main() {
    int num, choice, result;

    printf("Welcome to the MathBot! What do you want to do today?\n");
    printf("1. Check if a number is prime\n");
    printf("2. Calculate the factorial of a number\n");

    // Take user input
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    // Branch based on user choice
    if (choice == 1) {
        // Check if a number is prime
        printf("Enter a number: ");
        scanf("%d", &num);

        if (isPrime(num)) {
            printf("%d is a prime number.\n", num);
        } else {
            printf("%d is not a prime number.\n", num);
        }
    } else if (choice == 2) {
        // Calculate the factorial of a number
        printf("Enter a number: ");
        scanf("%d", &num);

        result = factorial(num);
        printf("%d! = %d\n", num, result);
    } else {
        printf("Invalid choice. Please select option 1 or 2.\n");
    }

    printf("Thank you for using MathBot!\n");

    return 0;
}