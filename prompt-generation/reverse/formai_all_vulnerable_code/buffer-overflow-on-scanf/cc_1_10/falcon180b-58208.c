//Falcon-180B DATASET v1.0 Category: Error handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to print an error message and exit
void error(const char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}

// Function to check if a string is a valid integer
int is_int(const char* str) {
    for (int i = 0; str[i]!= '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert a string to an integer
int str_to_int(const char* str) {
    return atoi(str);
}

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to calculate the nth prime number
int prime(int n) {
    if (n <= 1) {
        error("Invalid input: n must be greater than 1");
    }
    int count = 0;
    int num = 2;
    while (count < n) {
        if (is_prime(num)) {
            count++;
        }
        num++;
    }
    return num - 1;
}

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    char input[100];
    printf("Enter a number: ");
    scanf("%s", input);
    if (!is_int(input)) {
        error("Invalid input: n must be an integer");
    }
    n = str_to_int(input);
    int result = 0;
    switch (n) {
        case 0:
            result = factorial(n);
            break;
        case 1:
            result = fibonacci(n);
            break;
        default:
            result = prime(n);
            break;
    }
    printf("Result: %d\n", result);
    return 0;
}