//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void generate_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000000;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int size) {
    int *buckets[MAX_SIZE];
    int bucket_size = (int) ceil((double) size / MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++) {
        buckets[i] = malloc(bucket_size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / bucket_size;
        int bucket_offset = arr[i] % bucket_size;
        buckets[bucket_index][bucket_offset] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < bucket_size; j++) {
            if (buckets[i][j]!= 0) {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    generate_array(arr, size);
    printf("Unsorted array: ");
    print_array(arr, size);

    bucket_sort(arr, size);
    printf("Sorted array: ");
    print_array(arr, size);

    return 0;
}