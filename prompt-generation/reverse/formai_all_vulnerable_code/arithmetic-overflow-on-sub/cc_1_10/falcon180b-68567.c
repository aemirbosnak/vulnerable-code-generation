//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} Node;

void create(Node arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        arr[i].data = rand() % 100;
        arr[i].index = i;
    }
}

void display(Node arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

void bubbleSort(Node arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j].data > arr[j + 1].data) {
                temp = arr[j].data;
                arr[j].data = arr[j + 1].data;
                arr[j + 1].data = temp;

                temp = arr[j].index;
                arr[j].index = arr[j + 1].index;
                arr[j + 1].index = temp;
            }
        }
    }
}

void linearSearch(Node arr[], int size, int data) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i].data == data) {
            printf("Element %d found at index %d\n", data, arr[i].index);
            return;
        }
    }
    printf("Element %d not found\n", data);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    Node arr[MAX_SIZE];
    if (size > MAX_SIZE) {
        printf("Array size exceeds maximum limit\n");
        exit(0);
    }

    create(arr, size);
    display(arr, size);

    int data;
    printf("Enter the data to be searched: ");
    scanf("%d", &data);

    linearSearch(arr, size, data);

    bubbleSort(arr, size);
    display(arr, size);

    return 0;
}