//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
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
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int *bucket = (int *) malloc(range * sizeof(int));

    for (int i = 0; i < range; i++) {
        bucket[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        bucket[arr[i] - min]++;
    }

    for (int i = 0; i < range; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            arr[j * range + i + min] = i + min;
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *) malloc(size * sizeof(int));

    generate_array(arr, size);
    print_array(arr, size);

    bucket_sort(arr, size);
    printf("Sorted array: ");
    print_array(arr, size);

    free(arr);
    return 0;
}