//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>

void printBinary(int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" "); // Creating a space every 4 bits for readability
    }
    printf("\n");
}

void setBit(int *num, int bitPosition) {
    *num |= (1 << bitPosition);
    printf("Bit %d set.\n", bitPosition);
}

void clearBit(int *num, int bitPosition) {
    *num &= ~(1 << bitPosition);
    printf("Bit %d cleared.\n", bitPosition);
}

void toggleBit(int *num, int bitPosition) {
    *num ^= (1 << bitPosition);
    printf("Bit %d toggled.\n", bitPosition);
}

void checkBit(int num, int bitPosition) {
    if (num & (1 << bitPosition)) {
        printf("Bit %d is set.\n", bitPosition);
    } else {
        printf("Bit %d is not set.\n", bitPosition);
    }
}

int main() {
    int num = 0; // Starting with zero
    int choice, position;

    printf("Welcome to the Bitwise Operations Tool!\n");
    printf("Starting with number: %d\n", num);
    printf("Current binary representation: ");
    printBinary(num);

    do {
        printf("\nChoose an operation:\n");
        printf("1. Set a bit\n");
        printf("2. Clear a bit\n");
        printf("3. Toggle a bit\n");
        printf("4. Check a bit\n");
        printf("5. Display current number in binary\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter bit position to set (0-31): ");
                scanf("%d", &position);
                if (position >= 0 && position < 32) {
                    setBit(&num, position);
                } else {
                    printf("Invalid bit position!\n");
                }
                break;
            case 2:
                printf("Enter bit position to clear (0-31): ");
                scanf("%d", &position);
                if (position >= 0 && position < 32) {
                    clearBit(&num, position);
                } else {
                    printf("Invalid bit position!\n");
                }
                break;
            case 3:
                printf("Enter bit position to toggle (0-31): ");
                scanf("%d", &position);
                if (position >= 0 && position < 32) {
                    toggleBit(&num, position);
                } else {
                    printf("Invalid bit position!\n");
                }
                break;
            case 4:
                printf("Enter bit position to check (0-31): ");
                scanf("%d", &position);
                if (position >= 0 && position < 32) {
                    checkBit(num, position);
                } else {
                    printf("Invalid bit position!\n");
                }
                break;
            case 5:
                printf("Current number in binary: ");
                printBinary(num);
                break;
            case 6:
                printf("Exiting the tool. Bye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}