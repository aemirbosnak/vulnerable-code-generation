//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

// Function prototypes
void displayBits(uint32_t number);
uint32_t setBit(uint32_t number, int bitPosition);
uint32_t clearBit(uint32_t number, int bitPosition);
uint32_t toggleBit(uint32_t number, int bitPosition);
int checkBit(uint32_t number, int bitPosition);

void displayBits(uint32_t number) {
    printf("Binary representation: ");
    for (int i = sizeof(number) * CHAR_BIT - 1; i >= 0; --i) {
        printf("%d", (number >> i) & 1);
        if (i % 4 == 0) {
            printf(" "); // Adding space every 4 bits for readability
        }
    }
    printf("\n");
}

uint32_t setBit(uint32_t number, int bitPosition) {
    if (bitPosition < 0 || bitPosition >= sizeof(number) * CHAR_BIT) {
        fprintf(stderr, "Error: Bit position %d is out of bounds.\n", bitPosition);
        exit(EXIT_FAILURE);
    }
    return number | (1 << bitPosition);
}

uint32_t clearBit(uint32_t number, int bitPosition) {
    if (bitPosition < 0 || bitPosition >= sizeof(number) * CHAR_BIT) {
        fprintf(stderr, "Error: Bit position %d is out of bounds.\n", bitPosition);
        exit(EXIT_FAILURE);
    }
    return number & ~(1 << bitPosition);
}

uint32_t toggleBit(uint32_t number, int bitPosition) {
    if (bitPosition < 0 || bitPosition >= sizeof(number) * CHAR_BIT) {
        fprintf(stderr, "Error: Bit position %d is out of bounds.\n", bitPosition);
        exit(EXIT_FAILURE);
    }
    return number ^ (1 << bitPosition);
}

int checkBit(uint32_t number, int bitPosition) {
    if (bitPosition < 0 || bitPosition >= sizeof(number) * CHAR_BIT) {
        fprintf(stderr, "Error: Bit position %d is out of bounds.\n", bitPosition);
        exit(EXIT_FAILURE);
    }
    return (number & (1 << bitPosition)) != 0;
}

int main() {
    uint32_t number;
    int bitPosition, choice;

    printf("Enter a number (0 to 4294967295): ");
    if (scanf("%u", &number) != 1) {
        fprintf(stderr, "Invalid input. Please enter an unsigned integer.\n");
        return EXIT_FAILURE;
    }

    do {
        printf("\nMenu:\n");
        printf("1. Display bits\n");
        printf("2. Set a bit\n");
        printf("3. Clear a bit\n");
        printf("4. Toggle a bit\n");
        printf("5. Check a bit\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a valid option.\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                displayBits(number);
                break;
            case 2:
                printf("Enter bit position to set (0-31): ");
                scanf("%d", &bitPosition);
                number = setBit(number, bitPosition);
                break;
            case 3:
                printf("Enter bit position to clear (0-31): ");
                scanf("%d", &bitPosition);
                number = clearBit(number, bitPosition);
                break;
            case 4:
                printf("Enter bit position to toggle (0-31): ");
                scanf("%d", &bitPosition);
                number = toggleBit(number, bitPosition);
                break;
            case 5:
                printf("Enter bit position to check (0-31): ");
                scanf("%d", &bitPosition);
                if (checkBit(number, bitPosition)) {
                    printf("Bit %d is set.\n", bitPosition);
                } else {
                    printf("Bit %d is cleared.\n", bitPosition);
                }
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
        }
    } while (choice != 6);

    return EXIT_SUCCESS;
}