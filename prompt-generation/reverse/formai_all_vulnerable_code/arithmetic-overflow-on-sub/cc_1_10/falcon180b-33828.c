//Falcon-180B DATASET v1.0 Category: Recursive ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Function to print a string in reverse order
void reverseString(char* str) {
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
}

// Function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to find the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    reverseString(str);
    printf("\n");

    int n;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d\n", n, factorial(n));

    int m;
    printf("Enter a number to find its Fibonacci number: ");
    scanf("%d", &m);
    printf("Fibonacci number of %d is %d\n", m, fibonacci(m));

    return 0;
}