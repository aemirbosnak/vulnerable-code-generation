//Falcon-180B DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define SIZE 1000

int randint(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int compare(const void* a, const void* b) {
    int* ia = (int*)a;
    int* ib = (int*)b;
    return *ia - *ib;
}

int* generate_array(int size) {
    int* arr = malloc(size * sizeof(int));
    if(arr == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    for(int i = 0; i < size; i++) {
        arr[i] = randint(0, INT_MAX);
    }
    return arr;
}

void print_array(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int* arr, int size) {
    for(int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

int main() {
    srand(time(NULL));
    int* arr = generate_array(SIZE);
    print_array(arr, SIZE);
    selection_sort(arr, SIZE);
    print_array(arr, SIZE);
    free(arr);
    return 0;
}