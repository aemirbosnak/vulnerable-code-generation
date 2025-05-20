//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
} Array;

void init(Array *arr) {
    arr->data = (int *)malloc(MAX_SIZE * sizeof(int));
    arr->size = 0;
}

void push(Array *arr, int value) {
    if (arr->size >= MAX_SIZE) {
        printf("Error: Array is full.\n");
        return;
    }
    arr->data[arr->size++] = value;
}

int pop(Array *arr) {
    if (arr->size == 0) {
        printf("Error: Array is empty.\n");
        return -1;
    }
    return arr->data[--arr->size];
}

int peek(Array *arr, int index) {
    if (index >= arr->size || index < 0) {
        printf("Error: Invalid index.\n");
        return -1;
    }
    return arr->data[index];
}

void print(Array *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Array arr;
    init(&arr);

    for (int i = 0; i < 10; i++) {
        int value = rand() % 100;
        push(&arr, value);
        printf("Pushed %d\n", value);
    }

    print(&arr);

    int sum = 0;
    for (int i = 0; i < arr.size; i++) {
        sum += arr.data[i];
    }
    printf("Sum of elements: %d\n", sum);

    int max = arr.data[0];
    for (int i = 1; i < arr.size; i++) {
        if (arr.data[i] > max) {
            max = arr.data[i];
        }
    }
    printf("Maximum element: %d\n", max);

    int min = arr.data[0];
    for (int i = 1; i < arr.size; i++) {
        if (arr.data[i] < min) {
            min = arr.data[i];
        }
    }
    printf("Minimum element: %d\n", min);

    for (int i = 0; i < 5; i++) {
        int index = rand() % arr.size;
        printf("Popped %d\n", pop(&arr));
        arr.data[index] = rand() % 100;
        push(&arr, arr.data[index]);
        printf("Pushed %d\n", arr.data[index]);
    }

    print(&arr);

    return 0;
}