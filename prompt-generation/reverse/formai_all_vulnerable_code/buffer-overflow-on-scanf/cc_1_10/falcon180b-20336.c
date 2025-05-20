//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000
#define MAX_RANGE 1000000

void generate_random_array(int arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_RANGE;
    }
}

void bucket_sort(int arr[], int size) {
    int *buckets = malloc(MAX_SIZE * sizeof(int));
    for (int i = 0; i < MAX_SIZE; i++) {
        buckets[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / (MAX_RANGE / MAX_SIZE);
        buckets[bucket_index]++;
    }

    int curr_index = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[curr_index++] = i * (MAX_RANGE / MAX_SIZE) + MAX_RANGE / MAX_SIZE;
        }
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;
    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    generate_random_array(arr, size);

    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, size);

    printf("After sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}