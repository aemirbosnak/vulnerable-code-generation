//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: Ada Lovelace
#include <stdio.h>

// Function to calculate the factorial of a number
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to print the Fibonacci series up to n terms
void printFibonacci(int n) {
    static int a = 0, b = 1, count = 0;

    if (count < n) {
        printf("%d ", a);
        count++;
        int next = a + b;
        a = b;
        b = next;
        printFibonacci(n);
    }
}

// Function to calculate the power using recursion
double power(double base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else if (exponent < 0) {
        return 1 / power(base, -exponent);
    } else {
        return base * power(base, exponent - 1);
    }
}

// Function to reverse a string using recursion
void reverseString(char str[], int s, int e) {
    if (s >= e) {
        return; // Base case: if start index crosses end index
    }
    // Swap characters
    char temp = str[s];
    str[s] = str[e];
    str[e] = temp;
    reverseString(str, s + 1, e - 1);
}

// Function to find the greatest common divisor (GCD) using recursion
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to generate a series of triangular numbers
void triangularNumbers(int n, int current) {
    if (current > n) {
        return; // Base case: stop when current exceeds n
    }
    int triangularNumber = (current * (current + 1)) / 2;
    printf("Triangular Number %d: %d\n", current, triangularNumber);
    triangularNumbers(n, current + 1);
}

// Main function where execution begins
int main() {
    int choice, n;

    printf("Choose a function:\n");
    printf("1. Factorial\n");
    printf("2. Fibonacci Series\n");
    printf("3. Power Calculation\n");
    printf("4. Reverse String\n");
    printf("5. GCD Calculation\n");
    printf("6. Triangular Numbers\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a number for factorial calculation: ");
            scanf("%d", &n);
            printf("Factorial of %d is %llu\n", n, factorial(n));
            break;
        case 2:
            printf("Enter the number of terms in Fibonacci series: ");
            scanf("%d", &n);
            printf("Fibonacci series up to %d terms: ", n);
            printFibonacci(n);
            printf("\n");
            break;
        case 3:
            {
                double base;
                printf("Enter base and exponent separated by space: ");
                scanf("%lf %d", &base, &n);
                printf("%lf raised to the power of %d is %lf\n", base, n, power(base, n));
            }
            break;
        case 4:
            {
                char str[100];
                printf("Enter a string to reverse: ");
                scanf("%s", str);
                int len = 0;
                while (str[len] != '\0') {
                    len++;
                }
                reverseString(str, 0, len - 1);
                printf("Reversed String: %s\n", str);
            }
            break;
        case 5:
            {
                int a, b;
                printf("Enter two numbers to find their GCD: ");
                scanf("%d %d", &a, &b);
                printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
            }
            break;
        case 6:
            printf("Enter the number of triangular numbers to generate: ");
            scanf("%d", &n);
            triangularNumbers(n, 1);
            break;
        default:
            printf("Invalid choice! Please run the program again.\n");
            break;
    }

    return 0;
}