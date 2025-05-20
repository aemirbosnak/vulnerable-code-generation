//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int generateRandomNumber(int min, int max);
int calculateSum(int num1, int num2);
int calculateDifference(int num1, int num2);
int calculateProduct(int num1, int num2);
int calculateQuotient(int num1, int num2);

int main() {
    int num1, num2, choice;
    char operation;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate two random numbers between 1 and 100
    num1 = generateRandomNumber(1, 100);
    num2 = generateRandomNumber(1, 100);

    // Display the two random numbers
    printf("Random numbers: %d and %d\n", num1, num2);

    // Prompt the user to choose an operation
    printf("Choose an operation:\n");
    printf("a. Addition\n");
    printf("b. Subtraction\n");
    printf("c. Multiplication\n");
    printf("d. Division\n");
    scanf("%c", &operation);

    // Perform the selected operation
    switch (operation) {
        case 'a':
        case 'A':
            printf("The sum is: %d\n", calculateSum(num1, num2));
            break;
        case 'b':
        case 'B':
            printf("The difference is: %d\n", calculateDifference(num1, num2));
            break;
        case 'c':
        case 'C':
            printf("The product is: %d\n", calculateProduct(num1, num2));
            break;
        case 'd':
        case 'D':
            printf("The quotient is: %d\n", calculateQuotient(num1, num2));
            break;
        default:
            printf("Invalid operation.\n");
    }

    return 0;
}

// Function to generate a random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to calculate the sum of two numbers
int calculateSum(int num1, int num2) {
    return num1 + num2;
}

// Function to calculate the difference between two numbers
int calculateDifference(int num1, int num2) {
    return num1 - num2;
}

// Function to calculate the product of two numbers
int calculateProduct(int num1, int num2) {
    return num1 * num2;
}

// Function to calculate the quotient of two numbers
int calculateQuotient(int num1, int num2) {
    return num1 / num2;
}