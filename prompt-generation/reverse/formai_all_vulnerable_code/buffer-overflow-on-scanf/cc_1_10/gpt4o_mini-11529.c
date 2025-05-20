//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: genius
#include <stdio.h>

#define MAX_SIZE 100

// Function prototype declarations
void readArray(int arr[], int size);
void printArray(int arr[], int size);
int recursiveSum(int arr[], int size);
int findMax(int arr[], int size);
int factorial(int n);
int fibonacci(int n);

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the number of elements in the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if(size <= 0 || size > MAX_SIZE) {
        printf("Invalid size. Please run the program again with a valid size.\n");
        return 1;
    }

    readArray(arr, size);
    
    printf("The elements of the array are: ");
    printArray(arr, size);

    int sum = recursiveSum(arr, size);
    printf("Sum of array elements: %d\n", sum);

    int max = findMax(arr, size);
    printf("Maximum element in the array: %d\n", max);

    int num;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);
    if(num < 0) {
        printf("Factorial not defined for negative numbers.\n");
    } else {
        int fact = factorial(num);
        printf("Factorial of %d: %d\n", num, fact);
    }

    printf("Enter a number to find its Fibonacci value: ");
    scanf("%d", &num);
    if(num < 0) {
        printf("Fibonacci not defined for negative numbers.\n");
    } else {
        int fib = fibonacci(num);
        printf("Fibonacci of %d: %d\n", num, fib);
    }

    return 0;
}

// Recursive function to read an array
void readArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Recursive function to print an array
void printArray(int arr[], int size) {
    if(size > 0) {
        printf("%d ", arr[0]);
        printArray(arr + 1, size - 1);
    } else {
        printf("\n");
    }
}

// Recursive function to calculate the sum of elements in an array
int recursiveSum(int arr[], int size) {
    if(size == 0) {
        return 0;
    } else {
        return arr[0] + recursiveSum(arr + 1, size - 1);
    }
}

// Recursive function to find the maximum element in an array
int findMax(int arr[], int size) {
    if(size == 1) {
        return arr[0];
    }
    int maxOfRest = findMax(arr + 1, size - 1);
    return (arr[0] > maxOfRest) ? arr[0] : maxOfRest;
}

// Recursive function to calculate factorial
int factorial(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Recursive function to calculate Fibonacci numbers
int fibonacci(int n) {
    if(n == 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}