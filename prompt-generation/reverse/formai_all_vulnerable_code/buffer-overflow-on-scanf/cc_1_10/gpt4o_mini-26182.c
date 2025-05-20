//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: multivariable
#include <stdio.h>

// Function prototypes
void displayBits(unsigned int num);
void setBit(unsigned int *num, int position);
void clearBit(unsigned int *num, int position);
void toggleBit(unsigned int *num, int position);
void shiftLeft(unsigned int *num, int positions);
void shiftRight(unsigned int *num, int positions);

int main() {
    unsigned int number = 0;
    int choice, position, shift;
    
    printf("Enter an initial number (integer): ");
    scanf("%u", &number);
    
    while(1) {
        printf("\nCurrent number: %u\n", number);
        displayBits(number);

        printf("\nMenu:\n");
        printf("1. Set a bit\n");
        printf("2. Clear a bit\n");
        printf("3. Toggle a bit\n");
        printf("4. Shift left\n");
        printf("5. Shift right\n");
        printf("6. Exit\n");
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter bit position to set (0-31): ");
                scanf("%d", &position);
                setBit(&number, position);
                break;
            case 2:
                printf("Enter bit position to clear (0-31): ");
                scanf("%d", &position);
                clearBit(&number, position);
                break;
            case 3:
                printf("Enter bit position to toggle (0-31): ");
                scanf("%d", &position);
                toggleBit(&number, position);
                break;
            case 4:
                printf("Enter number of positions to shift left (0-31): ");
                scanf("%d", &shift);
                shiftLeft(&number, shift);
                break;
            case 5:
                printf("Enter number of positions to shift right (0-31): ");
                scanf("%d", &shift);
                shiftRight(&number, shift);
                break;
            case 6:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void displayBits(unsigned int num) {
    printf("Binary representation: ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) {
            printf(" ");  // Space for readability
        }
    }
    printf("\n");
}

void setBit(unsigned int *num, int position) {
    if (position < 0 || position > 31) {
        printf("Invalid position! Must be between 0 and 31.\n");
        return;
    }
    *num |= (1 << position);
    printf("Bit %d set.\n", position);
}

void clearBit(unsigned int *num, int position) {
    if (position < 0 || position > 31) {
        printf("Invalid position! Must be between 0 and 31.\n");
        return;
    }
    *num &= ~(1 << position);
    printf("Bit %d cleared.\n", position);
}

void toggleBit(unsigned int *num, int position) {
    if (position < 0 || position > 31) {
        printf("Invalid position! Must be between 0 and 31.\n");
        return;
    }
    *num ^= (1 << position);
    printf("Bit %d toggled.\n", position);
}

void shiftLeft(unsigned int *num, int positions) {
    if (positions < 0 || positions > 31) {
        printf("Invalid shift! Must be between 0 and 31.\n");
        return;
    }
    *num <<= positions;
    printf("Number shifted left by %d positions.\n", positions);
}

void shiftRight(unsigned int *num, int positions) {
    if (positions < 0 || positions > 31) {
        printf("Invalid shift! Must be between 0 and 31.\n");
        return;
    }
    *num >>= positions;
    printf("Number shifted right by %d positions.\n", positions);
}