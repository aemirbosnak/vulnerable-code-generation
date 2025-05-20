//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to find the factorial of a given number
int factorial(int num) {
    if (num > 1)
        return num * factorial(num - 1);
    else
        return 1;
}

// Function to find the Fibonacci sequence up to a given number
void fibonacci(int num) {
    int t1 = 0, t2 = 1, next;
    printf("%d %d ", t1, t2);

    while (next <= num) {
        next = t1 + t2;
        printf("%d ", next);
        t1 = t2;
        t2 = next;
    }
    printf("\n");
}

// Function to calculate the maximum value of an array
int max_array(int arr[], int size) {
    if (size <= 0)
        return arr[0];
    else
        return (size > 1 && arr[size - 1] > arr[max_array(arr, size - 1)]) ? arr[size - 1] : arr[max_array(arr, size - 1)];
}

// Function to merge two subarrays
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
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
}

// Function to merge sort an array
void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int arr[MAX_SIZE];
    int n, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements in the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Factorial of %d is %d\n", n, factorial(n));
    fibonacci(n + 5);
    printf("Maximum value in the array is %d\n", max_array(arr, n));

    merge_sort(arr, 0, n - 1);

    printf("Sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}