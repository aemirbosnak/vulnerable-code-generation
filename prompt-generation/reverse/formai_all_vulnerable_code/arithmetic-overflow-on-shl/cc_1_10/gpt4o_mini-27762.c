//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: Donald Knuth
#include <stdio.h>

#define MAX_BITS 32

// Function prototypes
void displayBits(unsigned int num);
unsigned int setBit(unsigned int num, int bit);
unsigned int clearBit(unsigned int num, int bit);
unsigned int toggleBit(unsigned int num, int bit);
int checkBit(unsigned int num, int bit);
unsigned int shiftLeft(unsigned int num, int positions);
unsigned int shiftRight(unsigned int num, int positions);

int main() {
    unsigned int number = 0;
    int bit, positions, choice;

    printf("Bitwise Operations Playground\n");
    printf("=============================\n");

    while (1) {
        printf("\nCurrent number: %u\n", number);
        displayBits(number);
        
        printf("\nChoose an operation:\n");
        printf("1. Set Bit\n");
        printf("2. Clear Bit\n");
        printf("3. Toggle Bit\n");
        printf("4. Check Bit\n");
        printf("5. Shift Left\n");
        printf("6. Shift Right\n");
        printf("7. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 7) {
            printf("Exiting... Goodbye!\n");
            break;
        }
        
        switch (choice) {
            case 1:
                printf("Enter bit position to set (0-31): ");
                scanf("%d", &bit);
                number = setBit(number, bit);
                break;
            case 2:
                printf("Enter bit position to clear (0-31): ");
                scanf("%d", &bit);
                number = clearBit(number, bit);
                break;
            case 3:
                printf("Enter bit position to toggle (0-31): ");
                scanf("%d", &bit);
                number = toggleBit(number, bit);
                break;
            case 4:
                printf("Enter bit position to check (0-31): ");
                scanf("%d", &bit);
                if (checkBit(number, bit))
                    printf("Bit %d is set.\n", bit);
                else
                    printf("Bit %d is not set.\n", bit);
                break;
            case 5:
                printf("Enter number of positions to shift left: ");
                scanf("%d", &positions);
                number = shiftLeft(number, positions);
                break;
            case 6:
                printf("Enter number of positions to shift right: ");
                scanf("%d", &positions);
                number = shiftRight(number, positions);
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}

// Function to display bits of a number
void displayBits(unsigned int num) {
    printf("Bits: ");
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" "); // Format for better readability
    }
    printf("\n");
}

// Function to set a bit
unsigned int setBit(unsigned int num, int bit) {
    return num | (1 << bit);
}

// Function to clear a bit
unsigned int clearBit(unsigned int num, int bit) {
    return num & ~(1 << bit);
}

// Function to toggle a bit
unsigned int toggleBit(unsigned int num, int bit) {
    return num ^ (1 << bit);
}

// Function to check if a bit is set
int checkBit(unsigned int num, int bit) {
    return (num >> bit) & 1;
}

// Function to shift left
unsigned int shiftLeft(unsigned int num, int positions) {
    return num << positions;
}

// Function to shift right
unsigned int shiftRight(unsigned int num, int positions) {
    return num >> positions;
}