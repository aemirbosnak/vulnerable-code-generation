//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Recursive function to calculate factorial of a number
long long factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

// Recursive function to calculate Fibonacci series up to n terms
void fibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm;

    for (int i = 0; i < n; i++) {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
}

// Recursive function to calculate sum of even numbers in an array
int sumEven(int arr[], int size) {
    if (size == 0)
        return 0;
    else if (arr[0] % 2 == 0)
        return arr[0] + sumEven(arr + 1, size - 1);
    else
        return sumEven(arr + 1, size);
}

int main() {
    int n;

    // Example 1: Calculate factorial using recursion
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n);
    printf("Factorial of %d is %lld\n", n, factorial(n));

    // Example 2: Print Fibonacci series up to n terms
    int terms;
    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &terms);
    fibonacci(terms);
    printf("\n");

    // Example 3: Calculate sum of even numbers in an array using recursion
    int arr[100], size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Sum of even numbers in the array is %d\n", sumEven(arr, size));

    return 0;
}