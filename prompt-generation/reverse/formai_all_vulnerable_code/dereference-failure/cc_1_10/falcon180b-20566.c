//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Function to generate random integers between min and max
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print an array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform bucket sort
void bucket_sort(int arr[], int n) {
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int bucket_size = max_val / n;
    int *buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = malloc(MAX_SIZE * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] >= i * bucket_size && arr[j] < (i + 1) * bucket_size) {
                buckets[i][j] = arr[j];
            }
        }
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (buckets[i][j]!= 0) {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

// Function to generate an array of random integers
void generate_array(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand_int(0, 100);
    }
}

int main() {
    int n = rand() % 10 + 1;
    int arr[n];

    printf("Sherlock Holmes' Bucket Sort\n");
    printf("-----------------------------\n");

    generate_array(arr, n);
    print_array(arr, n);

    bucket_sort(arr, n);
    print_array(arr, n);

    return 0;
}