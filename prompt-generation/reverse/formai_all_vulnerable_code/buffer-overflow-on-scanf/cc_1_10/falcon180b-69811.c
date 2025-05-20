//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

void generate_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int size) {
    int max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int bucket_size = max_val / size;
    int *buckets[MAX_SIZE];

    for (int i = 0; i < MAX_SIZE; i++) {
        buckets[i] = (int *)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / bucket_size;
        buckets[bucket_index][--size] = arr[i];
    }

    int j = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int k = 0; k < size; k++) {
            arr[j++] = buckets[i][k];
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    generate_array(arr, size);

    printf("Original array: ");
    print_array(arr, size);

    bucket_sort(arr, size);

    printf("Sorted array: ");
    print_array(arr, size);

    return 0;
}