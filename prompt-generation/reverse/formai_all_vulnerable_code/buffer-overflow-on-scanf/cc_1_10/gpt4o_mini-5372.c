//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

void printPattern(int n, int i) {
    if (i > n) return; // Base case
    for (int j = 1; j <= i; j++) {
        printf("*"); // Print stars
    }
    printf("\n");
    printPattern(n, i + 1); // Recursive call
}

void reversePattern(int n, int i) {
    if (i < 1) return; // Base case
    for (int j = 1; j <= i; j++) {
        printf("*"); // Print stars
    }
    printf("\n");
    reversePattern(n, i - 1); // Recursive call
}

void printNumbers(int n, int i) {
    if (i > n) return; // Base case
    printf("%d ", i); // Print numbers
    printNumbers(n, i + 1); // Recursive call
}

void reverseNumbers(int n, int i) {
    if (i < 1) return; // Base case
    printf("%d ", i); // Print numbers
    reverseNumbers(n, i - 1); // Recursive call
}

void fibonacci(int a, int b, int n) {
    if (n <= 0) return; // Base case
    printf("%d ", a); // Print Fibonacci number
    fibonacci(b, a + b, n - 1); // Recursive call
}

void countdown(int n) {
    if (n < 1) {
        printf("Lift off!\n"); // Base case
        return;
    }
    printf("%d...\n", n); // Print countdown
    countdown(n - 1); // Recursive call
}

int power(int base, int exp) {
    if (exp == 0) return 1; // Base case
    return base * power(base, exp - 1); // Recursive definition
}

int factorial(int n) {
    if (n <= 1) return 1; // Base case
    return n * factorial(n - 1); // Recursive definition
}

int main() {
    int choice, n;

    printf("Welcome to the recursive functions program!\n");
    printf("Choose an option:\n");
    printf("1. Print Pattern\n");
    printf("2. Reverse Pattern\n");
    printf("3. Print Numbers\n");
    printf("4. Reverse Numbers\n");
    printf("5. Fibonacci Sequence\n");
    printf("6. Countdown\n");
    printf("7. Power\n");
    printf("8. Factorial\n");
    
    while (1) {
        printf("Enter your choice (1-8, or 0 to exit): ");
        scanf("%d", &choice);
        if (choice == 0) break;

        switch (choice) {
            case 1:
                printf("Enter the height of the pattern: ");
                scanf("%d", &n);
                printPattern(n, 1); 
                break;
            case 2:
                printf("Enter the height of the reverse pattern: ");
                scanf("%d", &n);
                reversePattern(n, n); 
                break;
            case 3:
                printf("Enter the number of integers to print: ");
                scanf("%d", &n);
                printNumbers(n, 1); 
                break;
            case 4:
                printf("Enter the number of integers to reverse print: ");
                scanf("%d", &n);
                reverseNumbers(n, n);
                break;
            case 5:
                printf("Enter the number of Fibonacci numbers to generate: ");
                scanf("%d", &n);
                printf("Fibonacci Series: ");
                fibonacci(0, 1, n);
                printf("\n");
                break;
            case 6:
                printf("Enter a number for countdown: ");
                scanf("%d", &n);
                countdown(n);
                break;
            case 7:
                printf("Enter base and exponent: ");
                int base, exp;
                scanf("%d %d", &base, &exp);
                printf("%d raised to the power of %d is %d\n", base, exp, power(base, exp));
                break;
            case 8:
                printf("Enter a number to compute factorial: ");
                scanf("%d", &n);
                printf("Factorial of %d is %d\n", n, factorial(n));
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    printf("Thank you for using the recursive functions program!\n");
    return 0;
}