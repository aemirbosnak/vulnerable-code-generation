//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

void print_data(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i, j;
    char str[100];
    double arr[100];
    int size = 0;
    int *start, *end, *tmp;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    start = (int *)malloc(n * sizeof(int));
    end = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        printf("Enter the element at position %d: ", i);
        scanf("%d", &arr[i]);
        size++;
    }

    for (i = 0; i < n; i++) {
        printf("Enter the starting position of the sub-array at position %d: ", i);
        scanf("%d", &start[i]);
        printf("Enter the ending position of the sub-array at position %d: ", i);
        scanf("%d", &end[i]);
        tmp = (int *)malloc((end[i] - start[i] + 1) * sizeof(int));
        for (j = start[i]; j <= end[i]; j++) {
            tmp[j - start[i]] = arr[j];
        }
        size += end[i] - start[i] + 1;
    }

    printf("The original array is: ");
    print_data(arr, n);
    printf("\n");

    printf("The sub-arrays are: ");
    print_data(start, n);
    printf("\n");

    free(start);
    free(end);
    free(tmp);
    return 0;
}