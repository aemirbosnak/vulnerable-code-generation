//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to calculate the nth Fibonacci number recursively
int fibonacci(int n) {
    if (n <= 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to reverse a string recursively
void reverseString(char *str, int start, int end) {
    if (start >= end)
        return;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseString(str, start + 1, end - 1);
}

// Function to calculate factorial recursively
int factorial(int n) {
    if (n < 0) return -1; // Error case for negative integers
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

// Function to print the elements of an array recursively
void printArray(int arr[], int size, int index) {
    if (index == size)
        return;
    printf("%d ", arr[index]);
    printArray(arr, size, index + 1);
}

// Function to calculate the sum of digits of a number recursively
int sumOfDigits(int n) {
    if (n < 10)
        return n;
    return (n % 10) + sumOfDigits(n / 10);
}

// Function to check if a number is prime recursively
int isPrime(int n, int divisor) {
    if (n <= 1) return 0; // Not prime
    if (divisor * divisor > n) return 1; // Is prime
    if (n % divisor == 0) return 0; // Not prime
    return isPrime(n, divisor + 1); // Check the next divisor
}

// Function to generate the first n terms of the arithmetic series recursively
void generateArithmeticSeries(int a, int d, int n, int currentTerm) {
    if (currentTerm > n)
        return;
    printf("%d ", a + (currentTerm - 1) * d);
    generateArithmeticSeries(a, d, n, currentTerm + 1);
}

int main() {
    int choice, n, a, d;
    char str[MAX_SIZE];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Fibonacci series\n");
        printf("2. Reverse a string\n");
        printf("3. Calculate factorial\n");
        printf("4. Print array\n");
        printf("5. Sum of digits\n");
        printf("6. Prime check\n");
        printf("7. Generate arithmetic series\n");
        printf("8. Exit\n");
        printf("Choose an option (1-8): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of terms: ");
                scanf("%d", &n);
                printf("Fibonacci series: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", fibonacci(i));
                }
                printf("\n");
                break;

            case 2:
                printf("Enter a string: ");
                scanf("%s", str);
                reverseString(str, 0, strlen(str) - 1);
                printf("Reversed string: %s\n", str);
                break;

            case 3:
                printf("Enter a number: ");
                scanf("%d", &n);
                int fact = factorial(n);
                if (fact == -1)
                    printf("Factorial is not defined for negative numbers.\n");
                else
                    printf("Factorial of %d is %d\n", n, fact);
                break;

            case 4:
                printf("Enter array size: ");
                scanf("%d", &n);
                int arr[MAX_SIZE];
                printf("Enter %d elements: ", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                printf("Array elements: ");
                printArray(arr, n, 0);
                printf("\n");
                break;

            case 5:
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Sum of digits: %d\n", sumOfDigits(n));
                break;

            case 6:
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("%d is %sprime\n", n, isPrime(n, 2) ? "" : "not ");
                break;

            case 7:
                printf("Enter first term (a): ");
                scanf("%d", &a);
                printf("Enter common difference (d): ");
                scanf("%d", &d);
                printf("Enter number of terms (n): ");
                scanf("%d", &n);
                printf("Arithmetic series: ");
                generateArithmeticSeries(a, d, n, 1);
                printf("\n");
                break;

            case 8:
                printf("Exiting the program.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}