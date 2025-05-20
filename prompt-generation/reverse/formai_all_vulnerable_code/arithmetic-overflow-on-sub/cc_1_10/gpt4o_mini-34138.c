//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void printFibonacci(int n);
int fibonacci(int n);
void printReverse(char *str, int index);
void reverseString(char *str, int start, int end);
int factorial(int n);
void printFactorial(int n);
void stringPermutations(char *str, int start, int end);
void swap(char *x, char *y);

int main() {
    int n, choice;

    printf("Choose an option:\n");
    printf("1. Print Fibonacci series\n");
    printf("2. Print Factorial of a number\n");
    printf("3. Reverse a string\n");
    printf("4. Print all permutations of a string\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the number of terms for Fibonacci series: ");
            scanf("%d", &n);
            printFibonacci(n);
            break;
        case 2:
            printf("Enter a number to find its factorial: ");
            scanf("%d", &n);
            printFactorial(n);
            break;
        case 3:
            printf("Enter a string to reverse: ");
            char str[100];
            scanf("%s", str);
            reverseString(str, 0, strlen(str) - 1);
            printf("Reversed string: %s\n", str);
            break;
        case 4:
            printf("Enter a string to print permutations: ");
            char permStr[100];
            scanf("%s", permStr);
            printf("Permutations of the string are:\n");
            stringPermutations(permStr, 0, strlen(permStr) - 1);
            break;
        default:
            printf("Invalid choice. Exiting...\n");
            break;
    }

    return 0;
}

void printFibonacci(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void printFactorial(int n) {
    printf("Factorial of %d is %d\n", n, factorial(n));
}

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

void reverseString(char *str, int start, int end) {
    if (start >= end) {
        return;
    }
    swap(&str[start], &str[end]);
    reverseString(str, start + 1, end - 1);
}

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void stringPermutations(char *str, int start, int end) {
    if (start == end) {
        printf("%s\n", str);
    } else {
        for (int i = start; i <= end; i++) {
            swap((str + start), (str + i));
            stringPermutations(str, start + 1, end);
            swap((str + start), (str + i)); // backtrack
        }
    }
}