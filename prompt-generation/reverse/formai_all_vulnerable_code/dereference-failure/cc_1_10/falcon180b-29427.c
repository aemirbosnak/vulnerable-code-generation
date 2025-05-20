//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    int data;
    int index;
} Element;

void createBucket(Element *bucket, int size) {
    for (int i = 0; i < size; i++) {
        bucket[i].data = -1;
        bucket[i].index = -1;
    }
}

void insert(Element *bucket, int data, int size) {
    int index = data % size;
    if (bucket[index].data == -1) {
        bucket[index].data = data;
        bucket[index].index = 0;
    } else {
        int j = 0;
        while (j < SIZE && bucket[index].data!= data) {
            index = (index + 1) % SIZE;
            j++;
        }
        bucket[index].data = data;
        bucket[index].index = j;
    }
}

void sort(int *arr, int size) {
    Element *bucket = (Element *)malloc(sizeof(Element) * SIZE);
    createBucket(bucket, SIZE);

    int min = *arr;
    int max = *arr;

    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int range = max - min + 1;

    for (int i = 0; i < size; i++) {
        int index = (arr[i] - min) / range;
        insert(bucket, arr[i], SIZE);
    }

    int j = 0;
    for (int i = 0; i < SIZE; i++) {
        while (bucket[i].data!= -1) {
            int k = bucket[i].index;
            arr[j++] = bucket[i].data;
            bucket[i].data = -1;
            bucket[i].index = -1;
        }
    }

    free(bucket);
}

int main() {
    int arr[] = { 7, 3, 1, 2, 9, 8, 6, 5, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    sort(arr, size);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}