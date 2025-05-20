//FormAI DATASET v1.0 Category: Browser Plugin ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This is a hilarious C Browser Plugin Example Program that will surely make everyone laugh! */

/* Let's start defining the necessary functions. */

/* function to add two numbers */
int add(int a, int b) {
    return a + b;
}

/* function to subtract two numbers */
int subtract(int a, int b) {
    return a - b;
}

/* function to multiply two numbers */
int multiply(int a, int b) {
    return a * b;
}

/* function to divide two numbers */
int divide(int a, int b) {
    if (b == 0) {
        printf("Oops! Division by zero is undefined.\n");
        exit(0);
    }
    return a / b;
}

/* function to calculate factorial of a number */
long long factorial(int n) {
    if (n < 0) {
        printf("Oops! Factorial of negative numbers is undefined.\n");
        exit(0);
    }
    long long result = 1;
    for (int i=1; i<=n; i++) {
        result *= i;
    }
    return result;
}

/* function to reverse a string */
char* reverse(char* str) {
    int len = strlen(str);
    char* reversed_str = (char*)malloc(len + 1);
    for (int i=0; i<len; i++) {
        reversed_str[i] = str[len - i - 1];
    }
    reversed_str[len] = '\0';
    return reversed_str;
}

/* Now, let's define the main function. */

int main() {
    printf("Welcome to the Hilarious C Browser Plugin Example Program!\n");
    printf("Enter two numbers to perform some calculations (addition, subtraction, multiplication, and division):\n");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("Great! Now, let's perform some calculations:\n");
    printf("a + b = %d\n", add(a, b));
    printf("a - b = %d\n", subtract(a, b));
    printf("a * b = %d\n", multiply(a, b));
    printf("a / b = %d\n", divide(a, b));
    printf("Time for some extra fun! Enter a number to calculate its factorial:\n");
    int n;
    scanf("%d", &n);
    printf("%d! = %lld\n", n, factorial(n));
    printf("Enter a string to reverse:\n");
    char str[100];
    scanf("%s", str);
    char* reversed_str = reverse(str);
    printf("Reversed string: %s\n", reversed_str);
    free(reversed_str);
    printf("That's it for today! Hope you enjoyed the show!\n");
    return 0;
}