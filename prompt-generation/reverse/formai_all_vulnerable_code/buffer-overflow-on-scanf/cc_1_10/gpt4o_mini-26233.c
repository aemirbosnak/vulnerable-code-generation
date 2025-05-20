//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Function prototype declarations
int factorial(int n);
int fibonacci(int n);
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod);
void printArray(int arr[], int size);
void mergeSort(int arr[], int left, int right);
void swap(int* a, int* b);

// Function to compute factorial of a number using recursion
int factorial(int n) {
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return -1;
    }
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

// Function to compute nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n < 0) {
        printf("Fibonacci is not defined for negative numbers.\n");
        return -1;
    }
    return (n == 0) ? 0 : (n == 1) ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to implement Tower of Hanoi using recursion
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to merge two subarrays in sorted order
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Function to perform merge sort using recursion
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Main function
int main() {
    int number;

    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &number);
    printf("Factorial of %d is %d\n", number, factorial(number));

    printf("Enter a number to find its Fibonacci value: ");
    scanf("%d", &number);
    printf("Fibonacci of %d is %d\n", number, fibonacci(number));

    printf("Number of disks for Tower of Hanoi: ");
    scanf("%d", &number);
    printf("The moves involved in Tower of Hanoi are:\n");
    towerOfHanoi(number, 'A', 'C', 'B');

    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array: \n");
    printArray(arr, arr_size);
    mergeSort(arr, 0, arr_size - 1);
    printf("Sorted array: \n");
    printArray(arr, arr_size);

    return 0;
}