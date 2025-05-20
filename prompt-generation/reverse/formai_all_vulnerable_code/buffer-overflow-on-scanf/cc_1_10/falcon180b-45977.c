//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_RANGE 1000

void create_array(int arr[], int size, int range) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % range;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int size, int range) {
    int *buckets[MAX_RANGE];
    for (int i = 0; i < MAX_RANGE; i++) {
        buckets[i] = malloc(sizeof(int) * size);
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / range;
        int bucket_offset = arr[i] % range;
        buckets[bucket_index][bucket_offset] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < MAX_RANGE; i++) {
        for (int j = 0; j < size; j++) {
            if (buckets[i][j]!= 0) {
                arr[index] = buckets[i][j];
                index++;
            }
        }
    }
}

int main() {
    int size, range;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the range of the array: ");
    scanf("%d", &range);

    int arr[size];

    create_array(arr, size, range);

    printf("Before sorting:\n");
    print_array(arr, size);

    bucket_sort(arr, size, range);

    printf("After sorting:\n");
    print_array(arr, size);

    return 0;
}