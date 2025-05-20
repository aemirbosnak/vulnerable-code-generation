//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include <stdio.h>

#define SIZE 10

// Function to set a specific bit of an integer
void setBit(int *num, int bit) {
    *num |= (1 << bit);
}

// Function to clear a specific bit of an integer
void clearBit(int *num, int bit) {
    *num &= ~(1 << bit);
}

// Function to toggle a specific bit of an integer
void toggleBit(int *num, int bit) {
    *num ^= (1 << bit);
}

// Function to check if a specific bit of an integer is set
int checkBit(int num, int bit) {
    return (num & (1 << bit)) != 0;
}

// Recursive function to apply bitwise operations on an array
void processArray(int *arr, int index, int size, int operation, int bit) {
    // Base case
    if (index >= size) {
        return;
    }

    switch (operation) {
        case 1: // Set bit
            setBit(&arr[index], bit);
            printf("Set bit %d in element %d: %d\n", bit, index, arr[index]);
            break;
        case 2: // Clear bit
            clearBit(&arr[index], bit);
            printf("Cleared bit %d in element %d: %d\n", bit, index, arr[index]);
            break;
        case 3: // Toggle bit
            toggleBit(&arr[index], bit);
            printf("Toggled bit %d in element %d: %d\n", bit, index, arr[index]);
            break;
        case 4: // Check bit
            printf("Element %d - Bit %d is %s\n", index, bit, checkBit(arr[index], bit) ? "set" : "not set");
            break;
        default:
            printf("Invalid operation\n");
    }

    // Recursive call
    processArray(arr, index + 1, size, operation, bit);
}

int main() {
    int arr[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int bitPosition;
    int operation;

    printf("Initial array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Set bit operation
    printf("\nChoose a bit position to set (0-31): ");
    scanf("%d", &bitPosition);
    operation = 1;
    printf("Applying operation to set bit %d...\n", bitPosition);
    processArray(arr, 0, SIZE, operation, bitPosition);

    // Clear bit operation
    printf("\nChoose a bit position to clear (0-31): ");
    scanf("%d", &bitPosition);
    operation = 2;
    printf("Applying operation to clear bit %d...\n", bitPosition);
    processArray(arr, 0, SIZE, operation, bitPosition);

    // Toggle bit operation
    printf("\nChoose a bit position to toggle (0-31): ");
    scanf("%d", &bitPosition);
    operation = 3;
    printf("Applying operation to toggle bit %d...\n", bitPosition);
    processArray(arr, 0, SIZE, operation, bitPosition);

    // Check bit operation
    printf("\nChoose a bit position to check (0-31): ");
    scanf("%d", &bitPosition);
    operation = 4;
    printf("Applying operation to check bit %d...\n", bitPosition);
    processArray(arr, 0, SIZE, operation, bitPosition);

    return 0;
}