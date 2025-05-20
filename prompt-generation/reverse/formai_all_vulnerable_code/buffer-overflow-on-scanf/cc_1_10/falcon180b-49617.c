//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int arr_size, i, j, count = 0;
    int *arr;
    int *bucket[MAX_SIZE];

    printf("Enter the size of the array: ");
    scanf("%d", &arr_size);

    arr = (int *)malloc(arr_size * sizeof(int));

    printf("Enter the elements of the array: ");
    for (i = 0; i < arr_size; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize the buckets with -1
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *)malloc(MAX_SIZE * sizeof(int));
        for (j = 0; j < MAX_SIZE; j++) {
            bucket[i][j] = -1;
        }
    }

    // Insert elements into the buckets
    for (i = 0; i < arr_size; i++) {
        int index = arr[i] % MAX_SIZE;
        if (bucket[index][count] == -1) {
            bucket[index][count] = arr[i];
            count++;
        } else {
            printf("Bucket is full.\n");
            exit(0);
        }
    }

    // Sort the buckets
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < count; j++) {
            printf("%d ", bucket[i][j]);
        }
        printf("\n");
    }

    return 0;
}