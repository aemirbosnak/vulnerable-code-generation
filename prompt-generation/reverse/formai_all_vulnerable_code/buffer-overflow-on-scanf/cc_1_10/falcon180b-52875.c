//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} Element;

void swap(Element *a, Element *b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Element arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].data > arr[j + 1].data) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void insert(Element arr[], int n, int data) {
    int i;
    Element newElement = {data, n};
    for (i = n - 1; i >= 0 && arr[i].data > data; i--) {
        arr[i + 1] = arr[i];
    }
    arr[i + 1] = newElement;
}

int main() {
    Element arr[MAX_SIZE];
    int n = 0, data;

    printf("Enter the elements to be sorted:\n");
    while (n < MAX_SIZE) {
        scanf("%d", &data);
        insert(arr, n, data);
        n++;
    }

    bubbleSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i].data);
    }

    return 0;
}