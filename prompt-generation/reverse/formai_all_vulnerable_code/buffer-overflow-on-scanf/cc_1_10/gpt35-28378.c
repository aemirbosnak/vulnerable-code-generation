//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10    // Number of buckets
#define MAX_VAL 100       // Maximum value to be sorted

/* Function to generate random integers */
int rand_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

/* Function to print the bucket array */
void print_buckets(int buckets[]) {
    int i;
    for(i = 0; i < BUCKET_SIZE; i++) {
        printf("%d ", buckets[i]);
    }
    printf("\n");
}

/* Recursive function to perform bucket sort */
void bucket_sort(int arr[], int n, int max_val) {
    // Create an array of buckets
    int buckets[BUCKET_SIZE] = {0};
    int i, j;
    
    // Assign each element of the array to a bucket
    for(i = 0; i < n; i++) {
        buckets[arr[i] * BUCKET_SIZE / (max_val + 1)]++;
    }
    
    // Recursively sort each bucket
    for(i = 0; i < BUCKET_SIZE; i++) {
        if(buckets[i] > 0) {
            int bucket_arr[buckets[i]];
            int k = 0;
            for(j = 0; j < n; j++) {
                if(arr[j] * BUCKET_SIZE / (max_val + 1) == i) {
                    bucket_arr[k++] = arr[j];
                }
            }
            bucket_sort(bucket_arr, buckets[i], max_val);
            for(j = 0; j < buckets[i]; j++) {
                arr[i * buckets[i] + j] = bucket_arr[j];
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Original array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Call bucket_sort and print the sorted array
    bucket_sort(arr, n, MAX_VAL);
    printf("Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}