//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

typedef struct {
    int data;
    char shape;
} Element;

void print_array(Element arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d%c", arr[i].data, arr[i].shape);
    }
    printf("\n");
}

void generate_shapes(Element arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        arr[i].shape = (i % 3 == 0) ? 'S' : (i % 3 == 1) ? 'T' : 'U';
    }
}

void bubble_sort(Element arr[], int size) {
    int i, j, swap;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j].data > arr[j + 1].data) {
                swap = arr[j].data;
                arr[j].data = arr[j + 1].data;
                arr[j + 1].data = swap;
                char temp = arr[j].shape;
                arr[j].shape = arr[j + 1].shape;
                arr[j + 1].shape = temp;
            }
        }
    }
}

int main() {
    Element arr[MAX];
    int i, n;
    clock_t start, end;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    generate_shapes(arr, n);
    print_array(arr, n);

    start = clock();
    bubble_sort(arr, n);
    end = clock();

    printf("Sorted array:\n");
    print_array(arr, n);
    printf("Time taken: %.10fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}