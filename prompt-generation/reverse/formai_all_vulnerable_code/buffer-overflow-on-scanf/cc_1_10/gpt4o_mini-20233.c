//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

/* Function to calculate factorial of a number using recursion */
unsigned long long factorial(int n) {
    // Base case
    if (n <= 1) return 1;
    // Recursive case
    return n * factorial(n - 1);
}

/* Function to print Fibonacci series up to n numbers */
void fibonacci(int n, int a, int b) {
    if (n <= 0) return;
    printf("%d ", a);
    fibonacci(n - 1, b, a + b);
}

/* Function to reverse a string recursively */
void reverse(char *str, int start, int end) {
    if (start >= end) return;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverse(str, start + 1, end - 1);
}

/* Function to perform binary search recursively */
int binary_search(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        
        // Return the index if the element is found
        if (arr[mid] == target) return mid;
        
        // If element is smaller than mid, look in left half
        if (arr[mid] > target) return binary_search(arr, left, mid - 1, target);
        
        // Else look in right half
        return binary_search(arr, mid + 1, right, target);
    }
    return -1; // Element not found
}

/* Function to find the greatest common divisor using recursion */
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

/* Function to display prime numbers up to n */
void print_primes(int n, int p) {
    if (p > n) return;
    int is_prime = 1;
    for (int i = 2; i <= p / 2; i++) {
        if (p % i == 0) {
            is_prime = 0;
            break;
        }
    }
    if (is_prime && p > 1) printf("%d ", p);
    print_primes(n, p + 1);
}

int main() {
    int choice;
    printf("Welcome to the Recursive Wonderland!\n");
    printf("1. Calculate Factorial\n");
    printf("2. Generate Fibonacci Series\n");
    printf("3. Reverse a String\n");
    printf("4. Binary Search\n");
    printf("5. Find GCD\n");
    printf("6. Print Prime Numbers\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int num;
        printf("Enter a number to calculate its factorial: ");
        scanf("%d", &num);
        printf("Factorial of %d is %llu\n", num, factorial(num));
    } else if (choice == 2) {
        int n;
        printf("Enter the number of Fibonacci terms to generate: ");
        scanf("%d", &n);
        printf("Fibonacci Series: ");
        fibonacci(n, 0, 1);
        printf("\n");
    } else if (choice == 3) {
        char str[100];
        printf("Enter a string to reverse: ");
        scanf("%s", str);
        int len = 0;
        while (str[len] != '\0') len++;
        reverse(str, 0, len - 1);
        printf("Reversed string: %s\n", str);
    } else if (choice == 4) {
        int arr[100], n, target;
        printf("Enter number of elements in array: ");
        scanf("%d", &n);
        printf("Enter elements of the array: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        printf("Enter the element to find: ");
        scanf("%d", &target);
        int result = binary_search(arr, 0, n - 1, target);
        if (result == -1) {
            printf("Element not found in array.\n");
        } else {
            printf("Element found at index: %d\n", result);
        }
    } else if (choice == 5) {
        int a, b;
        printf("Enter two numbers to find their GCD: ");
        scanf("%d %d", &a, &b);
        printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
    } else if (choice == 6) {
        int n;
        printf("Enter the limit to print prime numbers: ");
        scanf("%d", &n);
        printf("Prime Numbers: ");
        print_primes(n, 1);
        printf("\n");
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}