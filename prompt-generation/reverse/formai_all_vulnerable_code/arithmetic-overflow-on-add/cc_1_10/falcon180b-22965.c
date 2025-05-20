//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

// Function to generate a random number between 0 and max-1
int rand_num(int max) {
    return rand() % max;
}

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array into buckets
void partition(int arr[], int n, int max_val) {
    int i;
    int* buckets = (int*)malloc(max_val * sizeof(int));
    for (i = 0; i < max_val; i++) {
        buckets[i] = 0;
    }
    for (i = 0; i < n; i++) {
        buckets[arr[i]]++;
    }
    int j = 0;
    for (i = 0; i < max_val; i++) {
        while (buckets[i] > 0) {
            arr[j++] = i;
            buckets[i]--;
        }
    }
    free(buckets);
}

// Function to perform bucket sort
void bucket_sort(int arr[], int n) {
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    partition(arr, n, max_val);
    for (int i = 0; i < n; i++) {
        if (arr[i]!= i) {
            swap(&arr[i], &arr[arr[i]]);
        }
    }
}

int main() {
    srand(time(NULL));
    int n = rand_num(MAX_SIZE);
    int arr[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        arr[i] = rand_num(MAX_SIZE);
    }
    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucket_sort(arr, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}