//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void convertToBinary(int num, int *binaryArray) {
    int index = 0;
    while (num > 0) {
        binaryArray[index] = num % 2; // Store remainder (bit)
        num = num / 2; // Divide number by 2
        index++;
    }
}

void printBinary(int *binaryArray, int size) {
    // Print in reverse order to display correct binary representation
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", binaryArray[i]);
    }
}

int main() {
    int number; // To store the decimal number
    int *binaryArray; // Pointer to store binary representation
    int size = 32; // Assuming a maximum of 32 bits for the binary number

    // Dynamically allocate memory for binaryArray
    binaryArray = (int*) malloc(size * sizeof(int));
    if (binaryArray == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1; // Exit program if memory allocation fails
    }

    // Initialize binaryArray to 0
    for (int i = 0; i < size; i++) {
        binaryArray[i] = 0;
    }

    // Input: Get a number from the user
    printf("Enter a decimal number: ");
    scanf("%d", &number);

    // Special case for zero
    if (number == 0) {
        printf("Binary representation of %d is: 0\n", number);
        free(binaryArray);
        return 0;
    }

    // Convert to binary
    convertToBinary(number, binaryArray);

    // Print binary representation
    printf("Binary representation of %d is: ", number);
    printBinary(binaryArray, size);

    printf("\n");

    // Free allocated memory
    free(binaryArray);
    return 0;
}