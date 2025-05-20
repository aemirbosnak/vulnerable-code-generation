//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int freq;
} item;

void swap(item* a, item* b) {
    item temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(item arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].freq < arr[j + 1].freq) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void printArray(item arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d %d\n", arr[i].data, arr[i].freq);
    }
}

int main() {
    int i, n;
    item arr[MAX_SIZE];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        arr[i].data = rand() % 100;
        arr[i].freq = 1;
    }

    bubbleSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}