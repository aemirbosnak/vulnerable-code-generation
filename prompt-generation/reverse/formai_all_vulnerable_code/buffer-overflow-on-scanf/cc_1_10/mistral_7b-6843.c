//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: Claude Shannon
#include <stdio.h>
#define SIZE 10

// Function to swap two elements
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bitwise XOR between two integers
int xor(int a, int b) {
    int result;
    result = a ^ b;
    return result;
}

// Function to check the sign of an integer
int sign(int num) {
    int mask = 1 << 31;
    return (num & mask) >> 31;
}

int main() {
    int arr[SIZE];
    int i, j, k;
    int temp1, temp2;

    printf("Enter %d integers:\n", SIZE);

    // Initialize array with user input
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    // Sorting the array using bitwise XOR and sign check
    for (i = 0; i < SIZE - 1; i++) {
        for (j = i + 1; j < SIZE; j++) {
            k = i;

            // Checking sign of first element
            if (sign(arr[i]) == -1) {
                if (sign(arr[j]) != -1) { // First element is negative and second is positive
                    swap(&arr[i], &arr[j]);
                }
            } else if (sign(arr[i]) == 0 && sign(arr[j]) == -1) { // First element is zero and second is negative
                swap(&arr[i], &arr[j]);
            } else if ((sign(arr[i]) == 0) && (sign(arr[j]) == 0)) { // Both are zero
                int xored = xor(arr[i], arr[j]);
                if ((xored & (1 << (sizeof(int) * 8 - 1))) != 0) { // Checking last bit
                    swap(&arr[i], &arr[j]);
                }
            }
        }
    }

    // Printing sorted array
    printf("\nSorted array: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}