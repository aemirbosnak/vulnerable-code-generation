//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INTEGER 1000000
#define MAX_STRLEN 100

// A smart arithmetic program that can handle various math operations
// and also provides some intelligent responses

int main() {
    int num1, num2, sum, diff, mult, div, mod;
    char op;
    char str[MAX_STRLEN];
    char *p;
    long long int result;

    // Initialize variables and get the first two numbers from the user
    printf("Welcome to the Intelligent Arithmetic Program!\n");
    printf("Please enter the first number: ");
    scanf("%d", &num1);
    printf("Please enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
    printf("Now, please enter the operation you want to perform (add, subtract, multiply, divide, or mod): ");
    scanf(" %c", &op);

    // Perform the operation
    switch (op) {
        case '+':
            sum = num1 + num2;
            break;
        case '-':
            diff = num1 - num2;
            break;
        case '*':
            mult = num1 * num2;
            break;
        case '/':
            div = num1 / num2;
            break;
        case '%':
            mod = num1 % num2;
            break;
        default:
            printf("Invalid operation! Please try again.\n");
            return 0;
    }

    // Print the result
    printf("Result: %d\n", sum);

    // Check if the result is a prime number
    if (isprime(sum)) {
        printf("Hey, that's a prime number! Congratulations!\n");
    }

    // Check if the result is a perfect square
    if (isperfectsquare(sum)) {
        printf("Wow, that's a perfect square! You must be a math whiz!\n");
    }

    // Check if the result is a power of 2
    if (ispowerof2(sum)) {
        printf("Impressive! That's a power of 2. You're a math genius!\n");
    }

    // Check if the result is a palindrome
    if (ispalindrome(sum)) {
        printf("Amazing! That's a palindrome. You're a math ninja!\n");
    }

    // Check if the result is a Armstrong number
    if (isarmstrong(sum)) {
        printf("Incredible! That's an Armstrong number. You're a math master!\n");
    }

    // Check if the result is a Fibonacci number
    if (isfibonacci(sum)) {
        printf("Congratulations! That's a Fibonacci number. You're a math prodigy!\n");
    }

    // Print the result in words
    printf("The result is: %ld\n", result);

    // Print the result in a more intelligent way
    p = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    sprintf(p, "%lld", result);
    printf("The result is: %s\n", p);

    // Free the memory
    free(p);

    return 0;
}

// Function to check if a number is prime
int isprime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a number is a perfect square
int isperfectsquare(int num) {
    int square = num * num;
    return square == num;
}

// Function to check if a number is a power of 2
int ispowerof2(int num) {
    return num > 0 && (num & (num - 1)) == 0;
}

// Function to check if a number is a palindrome
int ispalindrome(int num) {
    int rev = 0;
    while (num != 0) {
        rev = (rev * 10) + (num % 10);
        num /= 10;
    }
    return rev == num;
}

// Function to check if a number is an Armstrong number
int isarmstrong(int num) {
    if (num <= 1) {
        return 0;
    }
    int a = num, b = 1, c = 1;
    while (c < num) {
        a = (a * b) % num;
        b = c;
        c = (a * c) % num;
    }
    return c == 1;
}

// Function to check if a number is a Fibonacci number
int isfibonacci(int num) {
    if (num <= 1) {
        return 0;
    }
    int prev = 0, curr = 1, next = 1;
    while (curr < num) {
        prev = curr;
        curr = next;
        next = (prev + curr) % num;
    }
    return curr == num;
}