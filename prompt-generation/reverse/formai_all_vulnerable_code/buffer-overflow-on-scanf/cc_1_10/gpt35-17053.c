//FormAI DATASET v1.0 Category: Recursive ; Style: portable
#include <stdio.h>

int factorial(int n) {
    if(n == 1 || n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int fibonacci(int n) {
    if(n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}

int main() {
    int choice, n, a, b;
    printf("Enter your choice: \n1. Factorial\n2. Fibonacci\n3. GCD (Greatest Common Divisor)\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1: {
            printf("Enter a number to find its factorial: ");
            scanf("%d", &n);
            printf("Factorial of %d is %d\n", n, factorial(n));
            break;
        }
        case 2: {
            printf("Enter a number to find its nth term of Fibonacci series: ");
            scanf("%d", &n);
            printf("The %dth term of Fibonacci series is %d\n", n, fibonacci(n));
            break;
        }
        case 3: {
            printf("Enter two numbers to find their GCD: ");
            scanf("%d %d", &a, &b);
            printf("The GCD of %d and %d is %d\n", a, b, gcd(a, b));
            break;
        }
        default: {
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}