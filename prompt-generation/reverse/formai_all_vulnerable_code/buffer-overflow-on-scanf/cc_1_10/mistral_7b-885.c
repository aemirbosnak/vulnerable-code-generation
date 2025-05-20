//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int memory_id;
    int love_level;
} Memory;

void swap(Memory* a, Memory* b) {
    Memory temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Memory arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].love_level > arr[j + 1].love_level) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    Memory memories[MAX];
    int n;

    printf("Enter number of memories:\n");
    scanf("%d", &n);

    printf("\nEnter memory ID and its love level:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &memories[i].memory_id, &memories[i].love_level);
    }

    printf("\nMemories before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("Memory %d has a love level of %d\n", memories[i].memory_id, memories[i].love_level);
    }

    bubbleSort(memories, n);

    printf("\nMemories after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("Memory %d has a love level of %d\n", memories[i].memory_id, memories[i].love_level);
    }

    return 0;
}