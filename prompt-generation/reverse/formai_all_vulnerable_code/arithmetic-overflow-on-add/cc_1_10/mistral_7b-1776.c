//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100

typedef struct {
    int value;
    int shock_level;
} Element;

void generate_shock(Element* arr, int idx) {
    srand(time(NULL) + idx);
    arr[idx].shock_level = rand() % 10 + 1;
}

void print_array(Element* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Element %d: value=%d, shock_level=%d\n", i, arr[i].value, arr[i].shock_level);
    }
}

void shocked_swap(Element* arr, int i, int j) {
    if (arr[i].shock_level > arr[j].shock_level) {
        Element temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void shocked_sort(Element* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            shocked_swap(arr, i, j);
        }
    }
}

int main() {
    Element arr[MAX_SIZE];

    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i].value = i;
        generate_shock(arr, i);
    }

    print_array(arr, MAX_SIZE);
    printf("Before sorting:\n");

    shocked_sort(arr, MAX_SIZE);

    print_array(arr, MAX_SIZE);
    printf("After sorting:\n");

    return 0;
}