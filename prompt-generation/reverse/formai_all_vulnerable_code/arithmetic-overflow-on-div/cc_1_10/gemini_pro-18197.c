//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: beginner-friendly
#include <stdio.h>

int main() {
    // Declare variables
    int num1, num2, sum, difference, product, quotient, remainder;

    // Get input from the user
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Perform arithmetic operations
    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    quotient = num1 / num2;
    remainder = num1 % num2;

    // Print the results
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", difference);
    printf("Product: %d\n", product);
    printf("Quotient: %d\n", quotient);
    printf("Remainder: %d\n", remainder);

    // Calculate the average of the two numbers
    float average = (float)(num1 + num2) / 2;
    printf("Average: %.2f\n", average);

    // Check if the first number is greater than the second number
    if (num1 > num2) {
        printf("%d is greater than %d\n", num1, num2);
    } else if (num1 < num2) {
        printf("%d is less than %d\n", num1, num2);
    } else {
        printf("%d is equal to %d\n", num1, num2);
    }

    // Check if the first number is even or odd
    if (num1 % 2 == 0) {
        printf("%d is even\n", num1);
    } else {
        printf("%d is odd\n", num1);
    }

    // Check if the second number is divisible by 3
    if (num2 % 3 == 0) {
        printf("%d is divisible by 3\n", num2);
    } else {
        printf("%d is not divisible by 3\n", num2);
    }

    return 0;
}