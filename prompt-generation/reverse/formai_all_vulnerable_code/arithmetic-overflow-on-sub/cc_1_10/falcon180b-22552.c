//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int id;
    int size;
    int position;
} Process;

void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) {
    Process *processA = (Process*)a;
    Process *processB = (Process*)b;

    if (processA->size > processB->size) {
        return -1;
    } else if (processA->size < processB->size) {
        return 1;
    } else {
        return 0;
    }
}

void printArray(Process *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i].id);
    }
    printf("\n");
}

int main() {
    Process *array = (Process*)malloc(MAX_SIZE * sizeof(Process));
    int size = 0;
    int availableSpace = MAX_SIZE;

    while (true) {
        printf("Enter process ID and size (enter -1 to stop): ");
        int id;
        scanf("%d", &id);

        if (id == -1) {
            break;
        }

        printf("Enter process size: ");
        int size;
        scanf("%d", &size);

        if (availableSpace >= size) {
            array[size].id = id;
            array[size].size = size;
            array[size].position = availableSpace;

            availableSpace -= size;
            size++;
        } else {
            printf("Not enough space for process %d\n", id);
        }
    }

    qsort(array, size, sizeof(Process), compare);

    printf("Initial array:\n");
    printArray(array, size);

    int currentPosition = 0;

    for (int i = 0; i < size; i++) {
        if (array[i].size <= availableSpace) {
            availableSpace -= array[i].size;
            array[i].position = currentPosition;
            currentPosition += array[i].size;
        } else {
            printf("Not enough space for process %d\n", array[i].id);
        }
    }

    printf("\nFinal array:\n");
    printArray(array, size);

    free(array);
    return 0;
}