//Falcon-180B DATASET v1.0 Category: Recursive ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Function to print the list
void printList(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to swap elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the list
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to perform quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Function to generate a random list
void generateList(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

int main() {
    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);

    int arr[size];
    generateList(arr, size);

    printf("Unsorted list:\n");
    printList(arr, size);

    quicksort(arr, 0, size - 1);

    printf("Sorted list:\n");
    printList(arr, size);

    return 0;
}