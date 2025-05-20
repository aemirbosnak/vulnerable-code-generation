//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 32

void decimalToBinary(int n, char *binaryRepresentation) {
    if (n < 0) {
        fprintf(stderr, "Error: Negative numbers are not supported in binary conversion.\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        binaryRepresentation[i] = (n % 2) ? '1' : '0';
        n /= 2;
    }
    binaryRepresentation[MAX_BITS] = '\0';  // Null-terminate the string
}

void printBinaryRepresentation(const char *binaryRepresentation) {
    int leadingZero = 1; // Flag to skip leading zeros
    for (int i = 0; i < MAX_BITS; i++) {
        if (binaryRepresentation[i] == '1') {
            leadingZero = 0;
        }
        if (!leadingZero) {
            printf("%c", binaryRepresentation[i]);
        }
    }
    if (leadingZero) {
        printf("0"); // If all bits are zero
    }
    printf("\n");
}

void getUserInput(int *number) {
    printf("Enter a non-negative integer: ");
    while (scanf("%d", number) != 1 || *number < 0) {
        while (getchar() != '\n'); // Clear the input buffer
        printf("Invalid input. Please enter a non-negative integer: ");
    }
}

int main() {
    int number;
    char binaryRepresentation[MAX_BITS + 1]; // +1 for the null terminator

    getUserInput(&number);

    decimalToBinary(number, binaryRepresentation);
    
    printf("The binary representation of %d is: ", number);
    printBinaryRepresentation(binaryRepresentation);

    return 0;
}