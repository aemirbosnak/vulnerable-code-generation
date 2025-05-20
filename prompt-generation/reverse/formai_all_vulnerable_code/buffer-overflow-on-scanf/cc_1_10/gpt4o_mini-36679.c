//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: protected
#include <stdio.h>

void displayBits(unsigned int n);
void setBit(unsigned int *n, int position);
void clearBit(unsigned int *n, int position);
void toggleBit(unsigned int *n, int position);
int checkBit(unsigned int n, int position);

int main() {
    unsigned int number = 0; // Number to perform operations on
    int choice, bitPosition;

    printf("Bitwise Operations Menu\n");
    printf("=======================\n");

    while (1) {
        printf("\nCurrent number: %u\n", number);
        printf("1. Set a bit\n2. Clear a bit\n3. Toggle a bit\n4. Check a bit\n5. Display binary representation\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the bit position to set (0-31): ");
                scanf("%d", &bitPosition);
                setBit(&number, bitPosition);
                break;
            case 2:
                printf("Enter the bit position to clear (0-31): ");
                scanf("%d", &bitPosition);
                clearBit(&number, bitPosition);
                break;
            case 3:
                printf("Enter the bit position to toggle (0-31): ");
                scanf("%d", &bitPosition);
                toggleBit(&number, bitPosition);
                break;
            case 4:
                printf("Enter the bit position to check (0-31): ");
                scanf("%d", &bitPosition);
                if (checkBit(number, bitPosition)) {
                    printf("Bit %d is set.\n", bitPosition);
                } else {
                    printf("Bit %d is not set.\n", bitPosition);
                }
                break;
            case 5:
                printf("Binary representation: ");
                displayBits(number);
                printf("\n");
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option (1-6).\n");
                break;
        }
    }

    return 0;
}

void setBit(unsigned int *n, int position) {
    if (position < 0 || position > 31) {
        printf("Invalid position! Must be between 0 and 31.\n");
        return;
    }
    *n |= (1 << position);
    printf("Bit %d set.\n", position);
}

void clearBit(unsigned int *n, int position) {
    if (position < 0 || position > 31) {
        printf("Invalid position! Must be between 0 and 31.\n");
        return;
    }
    *n &= ~(1 << position);
    printf("Bit %d cleared.\n", position);
}

void toggleBit(unsigned int *n, int position) {
    if (position < 0 || position > 31) {
        printf("Invalid position! Must be between 0 and 31.\n");
        return;
    }
    *n ^= (1 << position);
    printf("Bit %d toggled.\n", position);
}

int checkBit(unsigned int n, int position) {
    if (position < 0 || position > 31) {
        printf("Invalid position! Must be between 0 and 31.\n");
        return -1;
    }
    return (n & (1 << position)) != 0;
}

void displayBits(unsigned int n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}