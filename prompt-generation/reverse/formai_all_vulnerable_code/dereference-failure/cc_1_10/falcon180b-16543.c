//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000000

typedef struct {
    int *data;
    int size;
} Array;

void create_array(Array *arr, int size) {
    arr->data = (int *)malloc(sizeof(int) * size);
    arr->size = size;
}

void destroy_array(Array *arr) {
    free(arr->data);
}

void fill_array(Array *arr, int value) {
    int i;
    for (i = 0; i < arr->size; i++) {
        arr->data[i] = value;
    }
}

void print_array(Array *arr) {
    int i;
    for (i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

void bubble_sort(Array *arr) {
    int i, j;
    int temp;
    for (i = 0; i < arr->size - 1; i++) {
        for (j = 0; j < arr->size - i - 1; j++) {
            if (arr->data[j] > arr->data[j + 1]) {
                temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
            }
        }
    }
}

int main() {
    Array arr;
    int i, choice;

    create_array(&arr, MAX_SIZE);
    fill_array(&arr, 0);

    while (1) {
        printf("\n");
        printf("1. Fill array with random numbers\n");
        printf("2. Bubble sort\n");
        printf("3. Print array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            srand(time(NULL));
            for (i = 0; i < arr.size; i++) {
                arr.data[i] = rand() % 100;
            }
            printf("Array filled with random numbers.\n");
            break;

        case 2:
            bubble_sort(&arr);
            printf("Array sorted.\n");
            break;

        case 3:
            print_array(&arr);
            break;

        case 4:
            destroy_array(&arr);
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}