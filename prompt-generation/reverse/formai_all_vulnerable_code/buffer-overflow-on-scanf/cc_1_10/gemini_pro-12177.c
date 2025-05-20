//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the sum of digits of a number
int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Function to calculate the product of digits of a number
int productOfDigits(int num) {
    int product = 1;
    while (num > 0) {
        product *= num % 10;
        num /= 10;
    }
    return product;
}

// Function to check if a number is a palindrome
int isPalindrome(int num) {
    int reversedNum = 0, originalNum = num;
    while (num > 0) {
        reversedNum = reversedNum * 10 + num % 10;
        num /= 10;
    }
    return reversedNum == originalNum;
}

// Function to calculate the greatest common divisor (GCD) of two numbers using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the least common multiple (LCM) of two numbers using the formula LCM(a, b) = (a * b) / GCD(a, b)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Function to calculate the factorial of a number
int factorial(int num) {
    int factorial = 1;
    for (int i = 1; i <= num; i++) {
        factorial *= i;
    }
    return factorial;
}

// Function to calculate the nth Fibonacci number using the recursive formula F(n) = F(n-1) + F(n-2)
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("The sum of digits of %d is: %d\n", num, sumOfDigits(num));
    printf("The product of digits of %d is: %d\n", num, productOfDigits(num));
    printf("Is %d a palindrome? %s\n", num, isPalindrome(num) ? "Yes" : "No");
    printf("The GCD of %d and 15 is: %d\n", num, gcd(num, 15));
    printf("The LCM of %d and 15 is: %d\n", num, lcm(num, 15));
    printf("The factorial of %d is: %d\n", num, factorial(num));
    printf("The %dth Fibonacci number is: %d\n", num, fibonacci(num));

    return 0;
}