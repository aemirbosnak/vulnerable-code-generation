//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the Fibonacci sequence up to a given number of terms
void fibonacci(int n) {
    int first = 0, second = 1, next = 0;
    printf("Fibonacci sequence up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", first);
        next = first + second;
        first = second;
        second = next;
    }
}

// Function to calculate the sum of even numbers in an array
int sumEven(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }
    return sum;
}

// Function to calculate the product of odd numbers in an array
int productOdd(int arr[], int size) {
    int product = 1;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2!= 0) {
            product *= arr[i];
        }
    }
    return product;
}

// Function to calculate the average of an array of numbers
double average(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double) sum / size;
}

int main() {
    int n;
    printf("Enter the number of terms for the Fibonacci sequence: ");
    scanf("%d", &n);
    fibonacci(n);

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = sumEven(arr, 10);
    printf("The sum of even numbers in the array is: %d\n", sum);

    int product = productOdd(arr, 10);
    printf("The product of odd numbers in the array is: %d\n", product);

    double avg = average(arr, 10);
    printf("The average of the array is: %.2f\n", avg);

    return 0;
}