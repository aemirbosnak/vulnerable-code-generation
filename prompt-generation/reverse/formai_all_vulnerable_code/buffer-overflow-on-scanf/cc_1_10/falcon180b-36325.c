//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_RANGE 1000

void generate_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_RANGE;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int size) {
    int bucket_size = MAX_RANGE / size;
    int *buckets[MAX_SIZE];

    for (int i = 0; i < size; i++) {
        int index = arr[i] / bucket_size;
        if (buckets[index] == NULL) {
            buckets[index] = malloc(sizeof(int) * (size + 1));
        }
        int *ptr = buckets[index];
        while (*ptr!= -1) {
            ptr++;
        }
        *ptr = arr[i];
    }

    int j = 0;
    for (int i = 0; i < size; i++) {
        arr[i] = buckets[arr[i] / bucket_size][j++];
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    generate_array(arr, size);
    printf("Unsorted array:\n");
    print_array(arr, size);

    clock_t start = clock();
    bucket_sort(arr, size);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    print_array(arr, size);
    printf("Time taken: %lf seconds\n", time_taken);

    return 0;
}