//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the factorial of a number
long long int factorial(int n) {
    long long int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the nth Fibonacci number
long long int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    long long int first = 0, second = 1, next = 0;
    for (int i = 2; i <= n; i++) {
        next = first + second;
        first = second;
        second = next;
    }
    return next;
}

int main() {
    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Factorial\n2. Fibonacci\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a number: ");
                int num;
                scanf("%d", &num);
                printf("Factorial of %d is %lld\n", num, factorial(num));
                break;
            case 2:
                printf("Enter a number: ");
                int n;
                scanf("%d", &n);
                printf("The %dth Fibonacci number is %lld\n", n, fibonacci(n));
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);
    return 0;
}