//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 100
#define MAX_BUCKETS 10

// Function to generate random numbers between min and max
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array into buckets
void partition(int arr[], int n, int buckets[]) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        j = rand_int(0, MAX_BUCKETS - 1);
        while (buckets[j] == MAX_ELEMENTS) {
            j = rand_int(0, MAX_BUCKETS - 1);
        }
        buckets[j]++;
        arr[i] = rand_int(0, MAX_ELEMENTS - 1);
    }
}

// Function to sort the elements in the array using bucket sort
void bucket_sort(int arr[], int n, int buckets[]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX_BUCKETS; j++) {
            if (arr[i] >= j * MAX_ELEMENTS && arr[i] < (j + 1) * MAX_ELEMENTS) {
                buckets[j]--;
                swap(&arr[i], &arr[--n]);
                break;
            }
        }
    }
}

// Function to print the sorted array
void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int i, n, buckets[MAX_BUCKETS] = {0};
    srand(time(NULL));
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    int arr[MAX_ELEMENTS];
    partition(arr, n, buckets);
    printf("Original array:\n");
    print_array(arr, n);
    bucket_sort(arr, n, buckets);
    printf("Sorted array:\n");
    print_array(arr, n);
    return 0;
}