//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000000

int main() {

    int i, j, k;
    int *array1, *array2, *result;
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Array size too large.\n");
        return 1;
    }

    array1 = (int *) malloc(size * sizeof(int));
    array2 = (int *) malloc(size * sizeof(int));
    result = (int *) malloc(size * sizeof(int));

    for (i = 0; i < size; i++) {
        array1[i] = rand() % 100;
        array2[i] = rand() % 100;
    }

    for (i = 0; i < size; i++) {
        result[i] = array1[i] * array2[i];
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            for (k = 0; k < size; k++) {
                result[i] += result[j] * result[k];
            }
        }
    }

    for (i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }

    free(array1);
    free(array2);
    free(result);

    return 0;
}