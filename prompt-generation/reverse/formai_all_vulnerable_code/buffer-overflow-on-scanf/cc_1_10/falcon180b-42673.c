//Falcon-180B DATASET v1.0 Category: Recursive ; Style: multivariable
#include <stdio.h>

// Recursive function to calculate the factorial of a number
long long int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

// Recursive function to calculate the sum of even numbers in an array
long long int sumEven(int arr[], int n) {
    if (n == 0)
        return 0;
    else if (arr[n-1] % 2 == 0)
        return arr[n-1] + sumEven(arr, n-1);
    else
        return sumEven(arr, n-1);
}

// Recursive function to calculate the product of odd numbers in an array
long long int productOdd(int arr[], int n) {
    if (n == 0)
        return 1;
    else if (arr[n-1] % 2!= 0)
        return arr[n-1] * productOdd(arr, n-1);
    else
        return productOdd(arr, n-1);
}

// Recursive function to calculate the sum of odd numbers in an array
long long int sumOdd(int arr[], int n) {
    if (n == 0)
        return 0;
    else if (arr[n-1] % 2!= 0)
        return arr[n-1] + sumOdd(arr, n-1);
    else
        return sumOdd(arr, n-1);
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate and print the factorial of the last element
    printf("Factorial of the last element: %lld\n", factorial(arr[n-1]));

    // Calculate and print the sum of even numbers in the array
    printf("Sum of even numbers in the array: %lld\n", sumEven(arr, n));

    // Calculate and print the product of odd numbers in the array
    printf("Product of odd numbers in the array: %lld\n", productOdd(arr, n));

    // Calculate and print the sum of odd numbers in the array
    printf("Sum of odd numbers in the array: %lld\n", sumOdd(arr, n));

    return 0;
}