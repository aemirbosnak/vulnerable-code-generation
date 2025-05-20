//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: all-encompassing
#include <stdio.h>

// Function to calculate the factorial of a number recursively
unsigned long long factorial(int n) {
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 0;
    } else if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to find the nth Fibonacci number recursively
int fibonacci(int n) {
    if (n < 0) {
        printf("Fibonacci is not defined for negative numbers.\n");
        return -1;
    } else if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to reverse a string recursively
void reverseString(char str[], int start, int end) {
    if (start >= end) {
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseString(str, start + 1, end - 1);
}

// Function to calculate the power of a number recursively
double power(double base, int exp) {
    if (exp < 0) {
        return 1 / power(base, -exp);
    } else if (exp == 0) {
        return 1;
    } else {
        return base * power(base, exp - 1);
    }
}

// Helper function to print all subsets of a set
void printSubsets(int arr[], int subset[], int n, int index, int subsetIndex) {
    if (index == n) {
        // Print subset
        printf("{ ");
        for (int i = 0; i < subsetIndex; i++) {
            printf("%d ", subset[i]);
        }
        printf("}\n");
        return;
    }

    // Include the current element
    subset[subsetIndex] = arr[index];
    printSubsets(arr, subset, n, index + 1, subsetIndex + 1);

    // Exclude the current element
    printSubsets(arr, subset, n, index + 1, subsetIndex);
}

// Main function
int main() {
    int num;
    
    // Factorial example
    printf("Enter a non-negative integer for factorial: ");
    scanf("%d", &num);
    printf("Factorial of %d is %llu\n", num, factorial(num));
    
    // Fibonacci example
    printf("Enter the position of Fibonacci sequence (>= 0): ");
    scanf("%d", &num);
    printf("Fibonacci number at position %d is %d\n", num, fibonacci(num));

    // String reversal example
    char str[100];
    printf("Enter a string to reverse: ");
    scanf("%s", str);
    reverseString(str, 0, strlen(str) - 1);
    printf("Reversed string: %s\n", str);

    // Power example
    double base;
    int exp;
    printf("Enter a base and an exponent (separated by space): ");
    scanf("%lf %d", &base, &exp);
    printf("%.2lf raised to the power of %d is %.2lf\n", base, exp, power(base, exp));

    // Subset example
    int n;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int subset[n];
    printf("All subsets are:\n");
    printSubsets(arr, subset, n, 0, 0);
    
    return 0;
}