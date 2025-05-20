//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

//Function to perform bucket sort
void bucketSort(int arr[], int n, int max) {
    int bucket[max];
    int i, j;

    for (i = 0; i < max; i++)
        bucket[i] = 0;

    for (i = 0; i < n; i++)
        bucket[arr[i]]++;

    for (i = 0; i < max; i++) {
        for (j = 0; j < bucket[i]; j++) {
            arr[j + i * max] = i;
        }
    }
}

//Function to generate a random array of integers
void generateArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

//Main function
int main() {
    int n, max;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    generateArray(arr, n);

    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    bucketSort(arr, n, max);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}