//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000 // Maximum size of the input array

typedef struct {
    int key;
    int value;
} Pair;

Pair *createArray(int size) {
    Pair *array = (Pair *)malloc(size * sizeof(Pair));
    if (array == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    return array;
}

void destroyArray(Pair *array) {
    free(array);
}

int compare(const void *a, const void *b) {
    Pair *pair1 = (Pair *)a;
    Pair *pair2 = (Pair *)b;
    return pair1->key - pair2->key;
}

void printArray(Pair *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d %d\n", array[i].key, array[i].value);
    }
}

int binarySearch(Pair *array, int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (array[mid].key == key) {
            return mid;
        } else if (array[mid].key < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Key not found
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    Pair *array = createArray(size);

    printf("Enter the elements in the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d %d", &array[i].key, &array[i].value);
    }

    qsort(array, size, sizeof(Pair), compare);

    int searchKey;
    printf("Enter the key to search: ");
    scanf("%d", &searchKey);

    int index = binarySearch(array, size, searchKey);

    if (index == -1) {
        printf("Key not found\n");
    } else {
        printf("Key found at index %d\n", index);
    }

    destroyArray(array);
    return 0;
}