//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000
#define MIN_SIZE 10

int main() {
    int size, i, j;
    char *str;
    double *arr;

    printf("Enter the size of the array (between %d and %d): ", MIN_SIZE, MAX_SIZE);
    scanf("%d", &size);

    if (size < MIN_SIZE || size > MAX_SIZE) {
        printf("Invalid size. Exiting.\n");
        exit(1);
    }

    str = (char *) malloc(size * sizeof(char));
    arr = (double *) malloc(size * sizeof(double));

    if (str == NULL || arr == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }

    printf("Enter %d strings:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%s", str + i * (MAX_SIZE + 1));
    }

    printf("Enter %d numbers:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%lf", arr + i);
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i == j) {
                continue;
            }

            if (strcmp(str + i * (MAX_SIZE + 1), str + j * (MAX_SIZE + 1)) == 0) {
                printf("%s and %s are equal.\n", str + i * (MAX_SIZE + 1), str + j * (MAX_SIZE + 1));
            } else if (arr[i] > arr[j]) {
                printf("%s is greater than %s.\n", str + i * (MAX_SIZE + 1), str + j * (MAX_SIZE + 1));
            } else {
                printf("%s is less than %s.\n", str + i * (MAX_SIZE + 1), str + j * (MAX_SIZE + 1));
            }
        }
    }

    free(str);
    free(arr);

    return 0;
}