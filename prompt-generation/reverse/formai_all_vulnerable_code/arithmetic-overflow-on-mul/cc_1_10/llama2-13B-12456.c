//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER 100000

int main() {
    int num1, num2, sum;
    char op;

    printf("Welcome to Arithmattack!\n");

    // Initialize variables
    num1 = 0;
    num2 = 0;
    sum = 0;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    // Perform the operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        sum = num1 - num2;
    } else if (op == '*') {
        sum = num1 * num2;
    } else if (op == '/') {
        sum = num1 / num2;
    }

    // Print the result
    printf("The result is: %d\n", sum);

    // Check if the result is a prime number
    if (sum > 1 && isprime(sum)) {
        printf("The result is a prime number!\n");
    } else {
        printf("The result is not a prime number.\n");
    }

    return 0;
}

// Function to check if a number is prime
int isprime(int num) {
    int i;

    if (num <= 1) {
        return 0;
    }

    for (i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}