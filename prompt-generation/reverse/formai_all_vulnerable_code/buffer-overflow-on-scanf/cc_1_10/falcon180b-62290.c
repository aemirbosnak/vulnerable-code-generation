//Falcon-180B DATASET v1.0 Category: Error handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// function to check if a string is a valid integer
int is_valid_integer(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// function to calculate the nth term of the Fibonacci series
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int fib_n_minus_1 = 0, fib_n_minus_2 = 1, fib_n = 0;
    for (int i = 2; i <= n; i++) {
        fib_n = fib_n_minus_1 + fib_n_minus_2;
        fib_n_minus_2 = fib_n_minus_1;
        fib_n_minus_1 = fib_n;
    }
    return fib_n;
}

int main() {
    char input[MAX_SIZE];
    int n, result;
    
    // prompt the user to enter a number
    printf("Enter a number: ");
    scanf("%s", input);
    
    // check if the input is a valid integer
    if (!is_valid_integer(input)) {
        printf("Error: Invalid input.\n");
        return 1;
    }
    
    // convert the input to an integer
    n = atoi(input);
    
    // check if the input is a valid nth term
    if (n < 0 || n > 100) {
        printf("Error: Invalid nth term.\n");
        return 1;
    }
    
    // calculate the nth term of the Fibonacci series
    result = fibonacci(n);
    
    // calculate the factorial of the nth term
    result *= factorial(n);
    
    // print the result
    printf("The %dth term of the Fibonacci series is %d.\n", n, result);
    
    return 0;
}