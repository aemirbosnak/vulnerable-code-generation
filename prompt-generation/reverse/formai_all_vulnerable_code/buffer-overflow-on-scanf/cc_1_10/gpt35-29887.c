//FormAI DATASET v1.0 Category: Educational ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    // Declare variables
    int num1, num2, sum;
    
    // Prompt user to input two numbers
    printf("Enter number 1: ");
    scanf("%d", &num1);
    
    printf("Enter number 2: ");
    scanf("%d", &num2);
    
    // Add the two numbers
    sum = num1 + num2;
    
    // Print the result
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    
    // Check if the sum is even or odd
    if (sum % 2 == 0) {
        // If it is even
        printf("%d is even\n", sum);
    } else {
        // If it is odd
        printf("%d is odd\n", sum);
    }
    
    // Reverse the digits of the sum
    int reverse = 0;
    while (sum > 0) {
        int digit = sum % 10;
        reverse = reverse * 10 + digit;
        sum /= 10;
    }
    
    // Print the reversed digits
    printf("The reversed sum is %d\n", reverse);
    
    // Check if the reversed number is prime or not
    int isPrime = 1;
    for (int i = 2; i <= reverse / 2; ++i) {
        if (reverse % i == 0) {
            isPrime = 0;
            break;
        }
    }
    
    // Print the result
    if (isPrime == 1) {
        printf("%d is a prime number", reverse);
    } else {
        printf("%d is not a prime number", reverse);
    }
    
    return 0;
}