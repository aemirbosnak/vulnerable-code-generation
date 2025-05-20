//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} element;

void create(element arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        arr[i].data = rand() % 1000;
        arr[i].index = -1;
    }
}

void display(element arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

void swap(element *a, element *b) {
    element temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(element arr[], int size) {
    int i, j, min_index;
    for (i = 0; i < size - 1; i++) {
        min_index = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j].data < arr[min_index].data) {
                min_index = j;
            }
        }
        swap(&arr[i], &arr[min_index]);
    }
}

void search(element arr[], int size, int target) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i].data == target) {
            arr[i].index = i;
            break;
        }
    }
}

void main() {
    int size, target;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    element arr[MAX_SIZE];
    create(arr, size);
    display(arr, size);
    printf("Enter the element to search: ");
    scanf("%d", &target);
    search(arr, size, target);
    printf("The index of the element is: %d\n", arr[target - 1].index);
}