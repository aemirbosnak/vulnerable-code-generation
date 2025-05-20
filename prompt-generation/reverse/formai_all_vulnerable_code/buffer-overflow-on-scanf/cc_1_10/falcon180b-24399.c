//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void print_binary(int num) {
    int i = 0;
    while (num > 0) {
        printf("%d", num & 1);
        num >>= 1;
        i++;
        if (i == 8) {
            printf("\n");
            i = 0;
        }
    }
}

int main() {
    int arr[MAX_SIZE];
    int n, i, j;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < 8; j++) {
            int bit = (arr[i] >> j) & 1;
            printf("%d ", bit);
        }
        printf("\n");
    }

    printf("\n");

    for (i = 0; i < n; i++) {
        arr[i] = ~arr[i];
    }

    printf("Array with all bits flipped:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    for (i = 0; i < n; i++) {
        int bit_count = 0;
        int mask = 1;
        while (mask!= 0) {
            if (arr[i] & mask) {
                bit_count++;
            }
            mask <<= 1;
        }
        printf("%d has %d bits set.\n", arr[i], bit_count);
    }

    return 0;
}