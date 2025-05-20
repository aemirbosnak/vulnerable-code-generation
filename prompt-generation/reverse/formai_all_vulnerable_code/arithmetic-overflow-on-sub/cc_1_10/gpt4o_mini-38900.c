//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: satisfied
#include <stdio.h>

// Function to calculate factorial of a number recursively
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to calculate Fibonacci number recursively
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to recursively reverse a string
void reverseString(char str[], int start, int end) {
    if (start >= end) {
        return;
    }
    // Swap characters
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseString(str, start + 1, end - 1);
}

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to find the lowest common multiple (LCM)
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// Function to generate prime numbers using recursion
void genPrimes(int n, int num, int *primes) {
    if (num > n) {
        return;
    }
    
    int isPrime = 1;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            isPrime = 0;
            break;
        }
    }
    
    if (isPrime && num > 1) {
        primes[(*primes)++] = num;
    }
    
    genPrimes(n, num + 1, primes);
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, n;

    while (1) {
        printf("Choose an option:\n");
        printf("1. Calculate Factorial\n");
        printf("2. Find Fibonacci Number\n");
        printf("3. Reverse a String\n");
        printf("4. Calculate GCD\n");
        printf("5. Calculate LCM\n");
        printf("6. Generate Prime Numbers\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a positive integer: ");
                scanf("%d", &n);
                printf("Factorial of %d is %llu\n", n, factorial(n));
                break;
            case 2:
                printf("Enter a positive integer: ");
                scanf("%d", &n);
                printf("Fibonacci number %d is %d\n", n, fibonacci(n));
                break;
            case 3: {
                char str[100];
                printf("Enter a string: ");
                scanf("%s", str);
                int len = 0;
                while (str[len] != '\0') {
                    len++;
                }
                reverseString(str, 0, len - 1);
                printf("Reversed string is: %s\n", str);
                break;
            }
            case 4:
                printf("Enter two integers: ");
                int a, b;
                scanf("%d %d", &a, &b);
                printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
                break;
            case 5:
                printf("Enter two integers: ");
                scanf("%d %d", &a, &b);
                printf("LCM of %d and %d is %d\n", a, b, lcm(a, b));
                break;
            case 6: {
                printf("Enter the upper limit up to which you want prime numbers: ");
                scanf("%d", &n);
                int primes[100] = {0};
                int count = 0;
                genPrimes(n, 2, &count);
                printf("Prime numbers up to %d are: ", n);
                printArray(primes, count);
                break;
            }
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}