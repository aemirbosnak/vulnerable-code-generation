//FormAI DATASET v1.0 Category: Recursive ; Style: standalone
#include<stdio.h>

int fact(int n) {
    if(n == 0)
        return 1;
    else
        return n*fact(n-1);
}

int fibonacci(int n) {
    if(n <= 1)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int power(int base, int exp) {
    if(exp == 0)
        return 1;
    else
        return base * power(base, exp-1);
}

int gcd(int x, int y) {
    if(y == 0)
        return x;
    else
        return gcd(y, x%y);
}

int main() {
    int choice, n, base, exponent, x, y;

    while(1) {
        printf("\n=======================================\n");
        printf("               RECURSION                \n");
        printf("=======================================\n");
        printf("1. Factorial of a number \n");
        printf("2. nth Fibonacci number \n");
        printf("3. Power of a number\n");
        printf("4. GCD of two numbers \n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the number: ");
                scanf("%d", &n);
                printf("\nFactorial of %d is %d\n", n, fact(n));
                break;
            case 2:
                printf("\nEnter the number: ");
                scanf("%d", &n);
                printf("\n%dth Fibonacci number is %d\n", n, fibonacci(n));
                break;
            case 3:
                printf("\nEnter the base: ");
                scanf("%d", &base);
                printf("Enter the exponent: ");
                scanf("%d", &exponent);
                printf("\n%d^%d is %d\n", base, exponent, power(base, exponent));
                break;
            case 4:
                printf("\nEnter the first number: ");
                scanf("%d", &x);
                printf("Enter the second number: ");
                scanf("%d", &y);
                printf("\nGCD of %d and %d is %d\n", x, y, gcd(x, y));
                break;
            case 5:
                printf("\nExiting program.\n");
                return 0;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}