//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: intelligent
#include <stdio.h>
#include <stdint.h>

// Function prototypes
void displayMenu();
void setBit(uint32_t *num, int bitPosition);
void clearBit(uint32_t *num, int bitPosition);
void toggleBit(uint32_t *num, int bitPosition);
int isBitSet(uint32_t num, int bitPosition);
void displayBits(uint32_t num);

int main() {
    uint32_t number = 0;
    int choice, bitPosition;

    do {
        displayMenu();
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the bit position to Set (0-31): ");
                scanf("%d", &bitPosition);
                setBit(&number, bitPosition);
                break;
            case 2:
                printf("Enter the bit position to Clear (0-31): ");
                scanf("%d", &bitPosition);
                clearBit(&number, bitPosition);
                break;
            case 3:
                printf("Enter the bit position to Toggle (0-31): ");
                scanf("%d", &bitPosition);
                toggleBit(&number, bitPosition);
                break;
            case 4:
                printf("Enter the bit position to Check (0-31): ");
                scanf("%d", &bitPosition);
                if (isBitSet(number, bitPosition)) {
                    printf("Bit %d is SET.\n", bitPosition);
                } else {
                    printf("Bit %d is NOT SET.\n", bitPosition);
                }
                break;
            case 5:
                printf("Current Number: %u\n", number);
                printf("Binary Representation: ");
                displayBits(number);
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n*** Bitwise Operations Menu ***\n");
    printf("1. Set Bit\n");
    printf("2. Clear Bit\n");
    printf("3. Toggle Bit\n");
    printf("4. Check Bit\n");
    printf("5. Display Current Number in Binary\n");
    printf("0. Exit\n");
}

// Function to set a bit
void setBit(uint32_t *num, int bitPosition) {
    if (bitPosition < 0 || bitPosition > 31) {
        printf("Invalid bit position!\n");
        return;
    }
    *num |= (1U << bitPosition);
    printf("Bit %d set successfully.\n", bitPosition);
}

// Function to clear a bit
void clearBit(uint32_t *num, int bitPosition) {
    if (bitPosition < 0 || bitPosition > 31) {
        printf("Invalid bit position!\n");
        return;
    }
    *num &= ~(1U << bitPosition);
    printf("Bit %d cleared successfully.\n", bitPosition);
}

// Function to toggle a bit
void toggleBit(uint32_t *num, int bitPosition) {
    if (bitPosition < 0 || bitPosition > 31) {
        printf("Invalid bit position!\n");
        return;
    }
    *num ^= (1U << bitPosition);
    printf("Bit %d toggled successfully.\n", bitPosition);
}

// Function to check if a bit is set
int isBitSet(uint32_t num, int bitPosition) {
    if (bitPosition < 0 || bitPosition > 31) {
        printf("Invalid bit position!\n");
        return 0;
    }
    return (num & (1U << bitPosition)) != 0;
}

// Function to display binary representation
void displayBits(uint32_t num) {
    for (int i = 31; i >= 0; i--) {
        putchar((num & (1U << i)) ? '1' : '0');
        if (i % 4 == 0) putchar(' '); // Space every 4 bits
    }
    putchar('\n');
}