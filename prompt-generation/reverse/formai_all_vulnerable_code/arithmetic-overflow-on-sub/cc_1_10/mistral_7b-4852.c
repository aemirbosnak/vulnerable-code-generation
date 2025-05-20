//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50

void generateArray(int *arr) {
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }
}

void printArray(int *arr) {
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[N], i, j;
    clock_t start, end;

    srand(time(NULL));
    start = clock();
    generateArray(arr);
    end = clock();

    printf("Generated Array in %.6f seconds:\n", (float)(end - start) / CLOCKS_PER_SEC);
    printArray(arr);

    start = clock();

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    end = clock();

    printf("Sorted Array in %.6f seconds:\n", (float)(end - start) / CLOCKS_PER_SEC);
    printArray(arr);

    return 0;
}