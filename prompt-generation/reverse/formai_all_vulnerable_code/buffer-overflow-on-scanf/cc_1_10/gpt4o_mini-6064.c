//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: synchronous
#include <stdio.h>

void displayBits(unsigned int num) {
    printf("Bits: ");
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

unsigned int setBit(unsigned int num, unsigned int bitPosition) {
    return num | (1U << bitPosition);
}

unsigned int clearBit(unsigned int num, unsigned int bitPosition) {
    return num & ~(1U << bitPosition);
}

unsigned int toggleBit(unsigned int num, unsigned int bitPosition) {
    return num ^ (1U << bitPosition);
}

unsigned int checkBit(unsigned int num, unsigned int bitPosition) {
    return (num >> bitPosition) & 1U;
}

int main() {
    unsigned int num = 0;
    unsigned int choice;
    unsigned int bitPosition;

    while (1) {
        printf("\nBitwise Operations Menu:\n");
        printf("1. Set a bit\n");
        printf("2. Clear a bit\n");
        printf("3. Toggle a bit\n");
        printf("4. Check a bit\n");
        printf("5. Display the number in bits\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%u", &choice);

        switch (choice) {
            case 1:
                printf("Enter the bit position to set (0-31): ");
                scanf("%u", &bitPosition);
                if (bitPosition >= 0 && bitPosition < 32) {
                    num = setBit(num, bitPosition);
                    printf("Bit %u set successfully.\n", bitPosition);
                } else {
                    printf("Invalid bit position!\n");
                }
                break;

            case 2:
                printf("Enter the bit position to clear (0-31): ");
                scanf("%u", &bitPosition);
                if (bitPosition >= 0 && bitPosition < 32) {
                    num = clearBit(num, bitPosition);
                    printf("Bit %u cleared successfully.\n", bitPosition);
                } else {
                    printf("Invalid bit position!\n");
                }
                break;

            case 3:
                printf("Enter the bit position to toggle (0-31): ");
                scanf("%u", &bitPosition);
                if (bitPosition >= 0 && bitPosition < 32) {
                    num = toggleBit(num, bitPosition);
                    printf("Bit %u toggled successfully.\n", bitPosition);
                } else {
                    printf("Invalid bit position!\n");
                }
                break;

            case 4:
                printf("Enter the bit position to check (0-31): ");
                scanf("%u", &bitPosition);
                if (bitPosition >= 0 && bitPosition < 32) {
                    unsigned int bitValue = checkBit(num, bitPosition);
                    printf("Bit %u is %s.\n", bitPosition, bitValue ? "set" : "not set");
                } else {
                    printf("Invalid bit position!\n");
                }
                break;

            case 5:
                displayBits(num);
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    return 0;
}