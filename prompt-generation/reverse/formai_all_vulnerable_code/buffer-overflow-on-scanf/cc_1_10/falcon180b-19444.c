//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_SEARCH 10
#define MAX_NUMBERS 10

typedef struct {
    int data[MAX_SIZE];
    int size;
} Array;

void initialize(Array *array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array->data[i] = rand() % MAX_NUMBERS;
    }
    array->size = size;
}

void printArray(Array array) {
    for (int i = 0; i < array.size; i++) {
        printf("%d ", array.data[i]);
    }
    printf("\n");
}

int search(Array array, int target, int *index) {
    for (int i = 0; i < array.size; i++) {
        if (array.data[i] == target) {
            *index = i;
            return 1;
        }
    }
    return 0;
}

int main() {
    Array array;
    int target, index;

    printf("Enter the size of the array: ");
    scanf("%d", &array.size);

    initialize(&array, array.size);
    printArray(array);

    printf("Enter the target number to search for: ");
    scanf("%d", &target);

    if (search(array, target, &index)) {
        printf("Found target number at index %d\n", index);
    } else {
        printf("Target number not found\n");
    }

    return 0;
}