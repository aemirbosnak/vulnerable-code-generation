//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAB_SIZE 4
#define MAX_LINE_LENGTH 1024
#define ARRAY_SIZE 10
#define ELEMENT_SIZE sizeof(int)
#define BLOCK_SIZE (1024 / (2 * sizeof(int) + TAB_SIZE))

typedef struct block {
    int key;
    int index;
    struct block *next;
} Block;

void print_tab(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d%s", arr[i], i != size - 1 ? "\t" : "");
    }
    printf("\n");
}

void c_search(int *arr, int size, int target) {
    int low = 0, high = size - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == target) {
            printf("Element found at index %d.\n", mid);
            return;
        }

        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Element not found.\n");
}

void create_array(int **arr, int *size) {
    *arr = (int *)calloc(ARRAY_SIZE, ELEMENT_SIZE);
    if (*arr == NULL) {
        perror("Memory allocation failed.");
        exit(EXIT_FAILURE);
    }

    *size = ARRAY_SIZE;
}

void populate_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 50;
    }
}

void display_array(int *arr, int size) {
    printf("Array elements:\n");
    print_tab(arr, size);
}

int main(void) {
    int *arr;
    int size;
    int target;

    create_array(&arr, &size);
    populate_array(arr, size);
    display_array(arr, size);

    printf("Enter the target element to search: ");
    scanf("%d", &target);

    c_search(arr, size, target);

    free(arr);

    return EXIT_SUCCESS;
}