//Falcon-180B DATASET v1.0 Category: Educational ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int main() {
    int size;
    int *array;
    int sum = 0;
    int count = 0;

    // ask user for array size
    printf("Enter array size: ");
    scanf("%d", &size);

    // check if size is within bounds
    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    // allocate memory for array
    array = (int *)malloc(size * sizeof(int));

    // check if memory was successfully allocated
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // ask user for array elements
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
        sum += array[i];
    }

    // calculate average
    if (size > 0) {
        count = size;
    } else {
        count = 1;
    }
    double avg = (double)sum / count;

    // print results
    printf("Array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avg);

    // free memory allocated for array
    free(array);

    return 0;
}