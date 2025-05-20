//Code Llama-13B DATASET v1.0 Category: Sorting ; Style: rigorous
// Rigorous C Sorting Example Program

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int value;
    int index;
} Element;

Element *create_array(int size) {
    Element *arr = (Element *)malloc(sizeof(Element) * size);
    for (int i = 0; i < size; i++) {
        arr[i].value = rand() % 100;
        arr[i].index = i;
    }
    return arr;
}

void print_array(Element *arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].value);
    }
    printf("]\n");
}

void insertion_sort(Element *arr, int size) {
    for (int i = 1; i < size; i++) {
        int j = i - 1;
        while (j >= 0 && arr[j].value > arr[j + 1].value) {
            int temp = arr[j].value;
            arr[j].value = arr[j + 1].value;
            arr[j + 1].value = temp;
            j--;
        }
    }
}

int main() {
    srand(time(NULL));

    Element *arr = create_array(MAX_SIZE);
    print_array(arr, MAX_SIZE);

    insertion_sort(arr, MAX_SIZE);

    print_array(arr, MAX_SIZE);

    free(arr);

    return 0;
}