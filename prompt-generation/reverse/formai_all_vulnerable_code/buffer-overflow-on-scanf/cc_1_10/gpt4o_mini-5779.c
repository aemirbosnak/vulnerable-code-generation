//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_BITS 32

// Function to display the binary representation of an integer.
void displayBits(unsigned int num) {
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        putchar((num & (1U << i)) ? '1' : '0');
        if (i % 4 == 0) putchar(' '); // Print space every 4 bits for readability
    }
    putchar('\n');
}

// Function to set a bit at a specific position.
unsigned int setBit(unsigned int num, int position) {
    if (position < 0 || position >= MAX_BITS) {
        fprintf(stderr, "Error: Position out of range.\n");
        exit(EXIT_FAILURE);
    }
    return num | (1U << position);
}

// Function to clear a bit at a specific position.
unsigned int clearBit(unsigned int num, int position) {
    if (position < 0 || position >= MAX_BITS) {
        fprintf(stderr, "Error: Position out of range.\n");
        exit(EXIT_FAILURE);
    }
    return num & ~(1U << position);
}

// Function to flip a bit at a specific position.
unsigned int flipBit(unsigned int num, int position) {
    if (position < 0 || position >= MAX_BITS) {
        fprintf(stderr, "Error: Position out of range.\n");
        exit(EXIT_FAILURE);
    }
    return num ^ (1U << position);
}

// Function to check if a bit at a specific position is set.
int isBitSet(unsigned int num, int position) {
    if (position < 0 || position >= MAX_BITS) {
        fprintf(stderr, "Error: Position out of range.\n");
        exit(EXIT_FAILURE);
    }
    return (num & (1U << position)) != 0;
}

// Main function to demonstrate bitwise operations.
int main() {
    unsigned int num = 0; // Initialize number to zero
    int choice = 0, position = 0;

    printf("Bitwise Operations Menu:\n");
    printf("1. Set a bit\n");
    printf("2. Clear a bit\n");
    printf("3. Flip a bit\n");
    printf("4. Check if a bit is set\n");
    printf("5. Display value in binary\n");
    printf("0. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Error: Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        if (choice == 0) {
            printf("Exiting program.\n");
            break;
        }

        if (choice < 1 || choice > 5) {
            fprintf(stderr, "Error: Please select a valid option (1-5).\n");
            continue;
        }

        printf("Enter the bit position (0-%d): ", MAX_BITS - 1);
        if (scanf("%d", &position) != 1) {
            fprintf(stderr, "Error: Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                num = setBit(num, position);
                printf("Set bit at position %d.\n", position);
                break;

            case 2:
                num = clearBit(num, position);
                printf("Cleared bit at position %d.\n", position);
                break;

            case 3:
                num = flipBit(num, position);
                printf("Flipped bit at position %d.\n", position);
                break;

            case 4:
                if (isBitSet(num, position)) {
                    printf("Bit at position %d is SET.\n", position);
                } else {
                    printf("Bit at position %d is NOT SET.\n", position);
                }
                break;

            case 5:
                printf("Current value in binary: ");
                displayBits(num);
                break;
        }
    }

    return 0;
}