//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Donald Knuth
#include <stdio.h>

#define MAX_ARRAY_SIZE 1000000

int array[MAX_ARRAY_SIZE];

void initialize_array() {
    int i;
    for (i = 0; i < MAX_ARRAY_SIZE; i++) {
        array[i] = i;
    }
}

void print_array() {
    int i;
    for (i = 0; i < MAX_ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int i, j, k, n, step, sum;

    printf("Enter the number of elements to be processed: ");
    scanf("%d", &n);

    if (n > MAX_ARRAY_SIZE) {
        printf("Error: Array size is too large.\n");
        return 1;
    }

    initialize_array();

    printf("Original array:\n");
    print_array();

    sum = 0;
    for (i = 0; i < n; i++) {
        sum += array[i];
    }

    printf("Sum of array elements: %d\n", sum);

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    printf("Sorted array:\n");
    print_array();

    return 0;
}