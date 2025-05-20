//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, n;
    int *arr;
    srand(time(0));
    printf("Enter the size of array: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory could not be allocated\n");
        exit(0);
    }
    printf("Enter the elements of array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of K: ");
    scanf("%d", &k);
    printf("The original array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < 8; j++) {
            if ((arr[i] >> j) & 1) {
                printf("%d ", (1 << j));
            }
        }
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        arr[i] ^= k;
    }
    printf("The new array after XORing with K is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < 8; j++) {
            if ((arr[i] >> j) & 1) {
                printf("%d ", (1 << j));
            }
        }
    }
    printf("\n");
    free(arr);
    return 0;
}