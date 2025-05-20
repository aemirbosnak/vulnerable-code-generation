//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct {
    int data;
    int feather;
} Bird;

void swapBirds(Bird *a, Bird *b) {
    Bird temp = *a;
    *a = *b;
    *b = temp;
}

int partitionBirds(Bird birds[], int low, int high) {
    int pivot = birds[high].feather;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (birds[j].feather < pivot) {
            i++;
            swapBirds(&birds[i], &birds[j]);
        }
    }
    swapBirds(&birds[i + 1], &birds[high]);
    return (i + 1);
}

void sortBirds(Bird birds[], int low, int high) {
    if (low < high) {
        int pi = partitionBirds(birds, low, high);
        sortBirds(birds, low, pi - 1);
        sortBirds(birds, pi + 1, high);
    }
}

int main() {
    Bird birds[SIZE];

    printf("Enter 100 integers and their corresponding feathers:\n");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d%d", &birds[i].data, &birds[i].feather);
    }

    printf("Unsorted array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Data: %d, Feather: %d\n", birds[i].data, birds[i].feather);
    }

    sortBirds(birds, 0, SIZE - 1);

    printf("\nSorted array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Data: %d, Feather: %d\n", birds[i].data, birds[i].feather);
    }

    return 0;
}