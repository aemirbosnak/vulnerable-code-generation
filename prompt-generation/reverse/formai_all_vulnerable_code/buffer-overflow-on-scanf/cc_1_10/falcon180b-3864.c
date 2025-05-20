//Falcon-180B DATASET v1.0 Category: Recursive ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Define a function to print the digits of a number in reverse order
void print_reverse(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    int remainder = n % 10;
    print_reverse(n / 10);
    printf("%d", remainder);
}

// Define a recursive function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Define a recursive function to calculate the Fibonacci sequence
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Define a recursive function to calculate the sum of the digits of a number
int digit_sum(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + digit_sum(n / 10);
}

// Define a recursive function to calculate the nth prime number
int nth_prime(int n) {
    int count = 0;
    int num = 2; // Start with the first prime number
    while (count < n) {
        if (is_prime(num)) {
            count++;
        }
        num++;
    }
    return num - 1;
}

// Define a recursive function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Call the recursive functions and print the results
    printf("The digits of %d in reverse order are: ", num);
    print_reverse(num);
    printf("\n");
    printf("The factorial of %d is: %d\n", num, factorial(num));
    printf("The %dth Fibonacci number is: %d\n", num, fibonacci(num));
    printf("The sum of the digits of %d is: %d\n", num, digit_sum(num));
    printf("The %dth prime number is: %d\n", num, nth_prime(num));
    printf("Is %d prime? %s\n", num, is_prime(num)? "Yes" : "No");

    return 0;
}