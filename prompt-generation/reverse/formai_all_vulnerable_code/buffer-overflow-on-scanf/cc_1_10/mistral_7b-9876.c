//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 10

typedef struct {
    int key;
    char name[20];
} Element;

void swap(Element* a, Element* b) {
    Element temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int binarySearch(Element arr[], int l, int r, int key) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid].key == key)
            return mid;

        if (arr[mid].key < key)
            l = mid + 1;

        else
            r = mid - 1;
    }

    return -1;
}

void selectionSort(Element arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j].key < arr[min_idx].key) {
                min_idx = j;
            }
        }

        swap(&arr[min_idx], &arr[i]);
    }
}

void linearSearch(Element arr[], int n, int key) {
    int i;

    for (i = 0; i < n; i++) {
        if (arr[i].key == key) {
            printf("Element %s with key %d found at position %d.\n", arr[i].name, arr[i].key, i + 1);
            return;
        }
    }

    printf("Element %d not found in the array.\n", key);
}

void createArray(Element arr[]) {
    int i;

    srand(time(NULL));

    for (i = 0; i < SIZE; i++) {
        arr[i].key = rand() % 50 + 1;
        sprintf(arr[i].name, "Element %d", i + 1);
    }

    selectionSort(arr, SIZE);
}

int main() {
    Element arr[SIZE];
    int key, pos;

    createArray(arr);

    printf("Unsorted array:\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%s : %d\n", arr[i].name, arr[i].key);
    }

    printf("\nEnter the key to search: ");
    scanf("%d", &key);

    pos = binarySearch(arr, 0, SIZE - 1, key);

    if (pos != -1) {
        printf("\nBinary search algorithm: Element %s with key %d found at position %d.\n", arr[pos].name, arr[pos].key, pos + 1);
    } else {
        linearSearch(arr, SIZE, key);
    }

    return 0;
}