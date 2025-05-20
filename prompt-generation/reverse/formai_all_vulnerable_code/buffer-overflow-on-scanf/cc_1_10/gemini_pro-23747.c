//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: cheerful
#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to print a happy face
void printHappyFace() {
    printf(":)");
}

// Function to print a sad face
void printSadFace() {
    printf(":(");
}

// Function to check if a number is even
int isEven(int n) {
    return n % 2 == 0;
}

// Function to check if a number is odd
int isOdd(int n) {
    return n % 2 != 0;
}

// Main function
int main() {
    int n;

    // Get a number from the user
    printf("Enter a number: ");
    scanf("%d", &n);

    // Check if the number is even or odd
    if (isEven(n)) {
        printf("%d is even\n", n);
        printHappyFace();
    } else if (isOdd(n)) {
        printf("%d is odd\n", n);
        printSadFace();
    }

    // Calculate the factorial of the number
    int factorialResult = factorial(n);
    printf("The factorial of %d is %d\n", n, factorialResult);

    return 0;
}