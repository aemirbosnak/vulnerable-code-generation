//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bubbleSort(int arr[], int n);
void printArray(int arr[], int size);
void fibonacci(int arr[], int n);

int main() {
    int i, n, arr1[MAX_SIZE], arr2[MAX_SIZE], fib_num;

    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    bubbleSort(arr1, n);
    printf("Sorted array: ");
    printArray(arr1, n);

    fib_num = arr1[n-1];
    printf("\nFibonacci sequence up to %d: ", fib_num);
    fibonacci(arr2, fib_num);
    printArray(arr2, fib_num);

    return 0;
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;

    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    int i;

    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void fibonacci(int arr[], int n) {
    int i, first = 0, second = 1, next;

    arr[0] = 0;
    arr[1] = 1;

    for(i = 2; i < n; i++) {
        next = first + second;
        arr[i] = next;
        first = second;
        second = next;
    }
}