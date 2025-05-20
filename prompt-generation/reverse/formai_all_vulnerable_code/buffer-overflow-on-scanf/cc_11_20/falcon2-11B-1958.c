//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, k, max_val, min_val;
    int array[100], sorted[100];
    int size = 0;

    srand(time(NULL));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    max_val = array[0];
    min_val = array[0];
    for (i = 1; i < n; i++) {
        if (array[i] > max_val) {
            max_val = array[i];
        }
        if (array[i] < min_val) {
            min_val = array[i];
        }
    }

    for (i = 0; i < n; i++) {
        if (array[i] > max_val) {
            k = max_val;
            max_val = array[i];
        }
        if (array[i] < min_val) {
            k = min_val;
            min_val = array[i];
        }
    }

    printf("Max value: %d\n", max_val);
    printf("Min value: %d\n", min_val);

    for (i = 0; i < n; i++) {
        for (j = 0; j < (max_val - min_val) + 1; j++) {
            sorted[j] = 0;
        }
        for (j = 0; j < n; j++) {
            if (array[j] >= min_val && array[j] <= max_val) {
                sorted[array[j] - min_val]++;
            }
        }

        size = 0;
        for (j = 0; j < (max_val - min_val) + 1; j++) {
            if (sorted[j]!= 0) {
                for (k = 0; k < sorted[j]; k++) {
                    array[size++] = j + min_val;
                }
            }
        }

        printf("Sorted array: ");
        for (j = 0; j < size; j++) {
            printf("%d ", array[j]);
        }
        printf("\n");
    }

    return 0;
}