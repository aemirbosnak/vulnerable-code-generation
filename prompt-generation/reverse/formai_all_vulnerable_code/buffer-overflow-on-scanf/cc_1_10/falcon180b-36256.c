//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: funny
/* Bucket Sort Implementation */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000

int main() {
    int i, j, n, range;
    int *array;

    srand(time(NULL)); // Seed for random numbers

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    array = (int *)malloc(n * sizeof(int));

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    range = MAX_RANGE / n; // Range of each bucket

    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (array[i] >= j * range && array[i] < (j + 1) * range) {
                printf("Inserting %d into bucket %d\n", array[i], j);
                break;
            }
        }
    }

    for (i = 0; i < MAX_SIZE; i++) {
        printf("Bucket %d: ", i);
        for (j = 0; j < n; j++) {
            if (array[j] >= i * range && array[j] < (i + 1) * range) {
                printf("%d ", array[j]);
            }
        }
        printf("\n");
    }

    free(array);

    return 0;
}