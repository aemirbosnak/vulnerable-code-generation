//FormAI DATASET v1.0 Category: Recursive ; Style: recursive
#include<stdio.h>

// Define a recursive function to print Fibonacci series up to n terms
void fibonacci_series(int n) {
    static int n1 = 0, n2 = 1, n3 = 0;
    
    if (n > 0) {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        printf("%d ", n3);
        fibonacci_series(n - 1);
    }
}

// Define a recursive function to return factorial of a given number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Define a recursive function to calculate GCD of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    // Print Fibonacci series up to n terms
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    if (n <= 0) { // Validation check
        printf("Invalid input! Number of terms should be greater than 0.\n");
        return 0;
    }
    printf("Fibonacci series up to %d terms: 0 1 ", n);
    fibonacci_series(n - 2);
    printf("\n");
    
    // Calculate factorial of a given number
    int num;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);
    if (num < 0) { // Validation check
        printf("Invalid input! Factorial of a negative number does not exist.\n");
        return 0;
    }
    int fact = factorial(num);
    printf("Factorial of %d is %d.\n", num, fact);
    
    // Calculate GCD of two numbers
    int a, b;
    printf("Enter two numbers to find their GCD: ");
    scanf("%d %d", &a, &b);
    if (a < 0 || b < 0) { // Validation check
        printf("Invalid input! GCD of negative numbers does not exist.\n");
        return 0;
    }
    int gcd_num = gcd(a, b);
    printf("GCD of %d and %d is %d.\n", a, b, gcd_num);
    
    return 0;
}