//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: authentic
#include <stdio.h>

void displayBits(unsigned int n) {
    printf("The bits are: ");
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

unsigned int setBit(unsigned int n, int bitPosition) {
    return n | (1 << bitPosition);
}

unsigned int clearBit(unsigned int n, int bitPosition) {
    return n & ~(1 << bitPosition);
}

unsigned int toggleBit(unsigned int n, int bitPosition) {
    return n ^ (1 << bitPosition);
}

int checkBit(unsigned int n, int bitPosition) {
    return (n >> bitPosition) & 1;
}

int main() {
    unsigned int number;
    int bitPosition;
    int choice;

    printf("Enter a positive integer: ");
    scanf("%u", &number);

    while (1) {
        printf("\nCurrent number: %u\n", number);
        displayBits(number);
        printf("Choose an operation:\n");
        printf("1. Set a bit\n");
        printf("2. Clear a bit\n");
        printf("3. Toggle a bit\n");
        printf("4. Check a bit\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting.\n");
            break;
        }

        printf("Enter bit position (0 to 31): ");
        scanf("%d", &bitPosition);

        if (bitPosition < 0 || bitPosition > 31) {
            printf("Invalid bit position. Please enter a value between 0 and 31.\n");
            continue;
        }

        switch (choice) {
            case 1:
                number = setBit(number, bitPosition);
                printf("Bit %d set.\n", bitPosition);
                break;
            case 2:
                number = clearBit(number, bitPosition);
                printf("Bit %d cleared.\n", bitPosition);
                break;
            case 3:
                number = toggleBit(number, bitPosition);
                printf("Bit %d toggled.\n", bitPosition);
                break;
            case 4:
                if (checkBit(number, bitPosition)) {
                    printf("Bit %d is set.\n", bitPosition);
                } else {
                    printf("Bit %d is not set.\n", bitPosition);
                }
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}