//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void generate_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int size) {
    int *buckets[MAX_SIZE] = {0};
    int max_val = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    int bucket_size = max_val / size;
    for (int i = 0; i < size; i++) {
        int bucket_idx = arr[i] / bucket_size;
        buckets[bucket_idx]++;
    }
    int bucket_start = 0;
    for (int i = 0; i < size; i++) {
        int bucket_idx = arr[i] / bucket_size;
        for (int j = 0; j < buckets[bucket_idx]; j++) {
            arr[bucket_start++] = i;
        }
        buckets[bucket_idx] = 0;
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    generate_array(arr, size);
    printf("Unsorted array: ");
    print_array(arr, size);

    bucket_sort(arr, size);
    printf("Sorted array: ");
    print_array(arr, size);

    return 0;
}