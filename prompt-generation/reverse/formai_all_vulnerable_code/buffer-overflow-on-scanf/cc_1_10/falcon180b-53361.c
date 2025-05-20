//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bitwise_operations(int arr[], int size) {
    int i, j, k;

    // Set all bits to 1
    for (i = 0; i < size; i++) {
        arr[i] = ~0;
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Check if a number is a power of 2
    for (i = 0; i < size; i++) {
        if ((arr[i] & (arr[i] - 1)) == 0) {
            printf("%d is a power of 2\n", arr[i]);
        } else {
            printf("%d is not a power of 2\n", arr[i]);
        }
    }

    // Swap two numbers without using a temporary variable
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                arr[j] ^= arr[j + 1];
                arr[j + 1] ^= arr[j];
                arr[j] ^= arr[j + 1];
            }
        }
    }

    // Count the number of set bits in each number
    for (i = 0; i < size; i++) {
        for (j = 0, k = 1; j < 32; j++, k <<= 1) {
            if (arr[i] & k) {
                printf("%d has %d set bit(s)\n", arr[i], j + 1);
                break;
            }
        }
    }

    // Clear the least significant bit
    for (i = 0; i < size; i++) {
        arr[i] &= ~1;
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    bitwise_operations(arr, size);

    return 0;
}