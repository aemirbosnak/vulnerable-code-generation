//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: standalone
#include <stdio.h>

// Function to find the greatest common divisor (GCD) using recursion
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to calculate the factorial of a number using recursion
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to calculate the nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to reverse a string using recursion
void reverseString(char str[], int start, int end) {
    if (start >= end) {
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseString(str, start + 1, end - 1);
}

// Function to print the steps of the Tower of Hanoi recursively
void towerOfHanoi(int n, char source, char helper, char target) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    towerOfHanoi(n - 1, source, target, helper);
    printf("Move disk %d from %c to %c\n", n, source, target);
    towerOfHanoi(n - 1, helper, source, target);
}

// Function to print patterns of stars recursively
void printStarPattern(int n, int i) {
    if (i > n) {
        return;
    }
    for (int j = 1; j <= i; j++) {
        printf("* ");
    }
    printf("\n");
    printStarPattern(n, i + 1);
}

// Main function to demonstrate recursion
int main() {
    int choice, num1, num2, n;
    char str[100];

    printf("Choose an option:\n");
    printf("1. GCD of two numbers\n");
    printf("2. Factorial of a number\n");
    printf("3. nth Fibonacci number\n");
    printf("4. Reverse a string\n");
    printf("5. Tower of Hanoi\n");
    printf("6. Print star pattern\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            printf("GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));
            break;
        case 2:
            printf("Enter a number: ");
            scanf("%d", &num1);
            printf("Factorial of %d is %d\n", num1, factorial(num1));
            break;
        case 3:
            printf("Enter n: ");
            scanf("%d", &n);
            printf("Fibonacci(%d) = %d\n", n, fibonacci(n));
            break;
        case 4:
            printf("Enter a string: ");
            scanf("%s", str);
            reverseString(str, 0, strlen(str) - 1);
            printf("Reversed string: %s\n", str);
            break;
        case 5:
            printf("Enter number of disks: ");
            scanf("%d", &n);
            printf("Steps to solve Tower of Hanoi with %d disks:\n", n);
            towerOfHanoi(n, 'A', 'B', 'C');
            break;
        case 6:
            printf("Enter number of lines for star pattern: ");
            scanf("%d", &n);
            printStarPattern(n, 1);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}