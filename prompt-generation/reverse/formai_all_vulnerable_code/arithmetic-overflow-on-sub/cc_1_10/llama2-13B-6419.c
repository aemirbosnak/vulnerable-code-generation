//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100000
#define MIN_NUM 1

// Function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the nth fibonacci number
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to calculate the greatest common divisor of two numbers
int gcd(int a, int b) {
    while (a != 0) {
        b = a;
        a = b;
    }
    return b;
}

// Function to calculate the sum of the digits of a given number
int sum_digits(int num) {
    int sum = 0;
    while (num != 0) {
        sum = (sum * 10) + (num % 10);
        num /= 10;
    }
    return sum;
}

int main() {
    int num1, num2, sum, gcd_result;
    char str[50];

    // Input the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Input the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Calculate the sum of the two numbers
    sum = num1 + num2;

    // Calculate the greatest common divisor of the two numbers
    gcd_result = gcd(num1, num2);

    // Calculate the sum of the digits of the two numbers
    sum_digits(num1);
    sum_digits(num2);

    // Print the results
    printf("The sum of the two numbers is: %d\n", sum);
    printf("The greatest common divisor of the two numbers is: %d\n", gcd_result);
    printf("The sum of the digits of the first number is: %d\n", sum_digits(num1));
    printf("The sum of the digits of the second number is: %d\n", sum_digits(num2));

    // Output the time taken to execute the program
    clock_t start_time, end_time;
    double time_taken;
    start_time = clock();
    end_time = clock();
    time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken to execute the program: %f seconds\n", time_taken);

    return 0;
}