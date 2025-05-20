//FormAI DATASET v1.0 Category: Recursive ; Style: scalable
#include <stdio.h>

// A recursive function to print all numbers from 1 to n
void printNumbers(int n) {
    if (n > 0) {
        printNumbers(n-1);
        printf("%d ", n);
    }
}

// A recursive function to calculate factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

// A recursive function to calculate fibonacci series up to nth term
int fibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// A recursive function to calculate the sum of digits of a number
int sumOfDigits(int n) {
    if (n == 0) {
        return 0;
    } else {
        return (n % 10) + sumOfDigits(n/10);
    }
}

int main() {
    int choice, n;
    do {
        printf("\nChoose an operation to perform:\n");
        printf("1. Print numbers from 1 to n\n");
        printf("2. Calculate factorial of a number\n");
        printf("3. Generate fibonacci series up to nth term\n");
        printf("4. Calculate sum of digits of a number\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value of n: ");
                scanf("%d", &n);
                printf("Numbers from 1 to %d: ", n);
                printNumbers(n);
                printf("\n");
                break;
            case 2:
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Factorial of %d is %d\n", n, factorial(n));
                break;
            case 3:
                printf("Enter value of n: ");
                scanf("%d", &n);
                printf("Fibonacci series up to %d terms: ", n);
                for (int i = 1; i <= n; i++) {
                    printf("%d ", fibonacci(i));
                }
                printf("\n");
                break;
            case 4:
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Sum of digits of %d is %d\n", n, sumOfDigits(n));
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice != 5);
    return 0;
}