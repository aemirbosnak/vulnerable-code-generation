//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: modular
#include <stdio.h>

void displayMenu();
void setBit(int *num, int position);
void clearBit(int *num, int position);
void toggleBit(int *num, int position);
int checkBit(int num, int position);
void displayBits(int num);

int main() {
    int number = 0; // Start with 0
    int choice, bitPosition;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Current number: %d\n", number);
                printf("Enter the bit position to set (0-31): ");
                scanf("%d", &bitPosition);
                setBit(&number, bitPosition);
                displayBits(number);
                break;
            case 2:
                printf("Current number: %d\n", number);
                printf("Enter the bit position to clear (0-31): ");
                scanf("%d", &bitPosition);
                clearBit(&number, bitPosition);
                displayBits(number);
                break;
            case 3:
                printf("Current number: %d\n", number);
                printf("Enter the bit position to toggle (0-31): ");
                scanf("%d", &bitPosition);
                toggleBit(&number, bitPosition);
                displayBits(number);
                break;
            case 4:
                printf("Current number: %d\n", number);
                printf("Enter the bit position to check (0-31): ");
                scanf("%d", &bitPosition);
                if (checkBit(number, bitPosition))
                    printf("Bit %d is set.\n", bitPosition);
                else
                    printf("Bit %d is not set.\n", bitPosition);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n---- Bitwise Operations Menu ----\n");
    printf("1. Set a bit\n");
    printf("2. Clear a bit\n");
    printf("3. Toggle a bit\n");
    printf("4. Check a bit\n");
    printf("5. Exit\n");
}

void setBit(int *num, int position) {
    if (position < 0 || position > 31) {
        printf("Invalid bit position!\n");
        return;
    }
    *num |= (1 << position);
    printf("Bit %d set successfully.\n", position);
}

void clearBit(int *num, int position) {
    if (position < 0 || position > 31) {
        printf("Invalid bit position!\n");
        return;
    }
    *num &= ~(1 << position);
    printf("Bit %d cleared successfully.\n", position);
}

void toggleBit(int *num, int position) {
    if (position < 0 || position > 31) {
        printf("Invalid bit position!\n");
        return;
    }
    *num ^= (1 << position);
    printf("Bit %d toggled successfully.\n", position);
}

int checkBit(int num, int position) {
    if (position < 0 || position > 31) {
        printf("Invalid bit position!\n");
        return -1; // Invalid position
    }
    return (num & (1 << position)) != 0; // Return 1 if bit is set, 0 otherwise
}

void displayBits(int num) {
    printf("Binary representation: ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\nDecimal representation: %d\n", num);
}