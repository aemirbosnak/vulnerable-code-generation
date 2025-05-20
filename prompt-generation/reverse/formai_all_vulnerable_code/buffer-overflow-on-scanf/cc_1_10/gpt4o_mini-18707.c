//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Function declarations
int setBit(int number, int bit);
int clearBit(int number, int bit);
int toggleBit(int number, int bit);
int checkBit(int number, int bit);
void displayBits(int number);
int countSetBits(int number);
int rotateLeft(int number, int positions);
int rotateRight(int number, int positions);

int main(void) {
    int number, bit, choice, positions;

    while (1) {
        printf("\nBitwise Operations Menu:\n");
        printf("1. Set Bit\n");
        printf("2. Clear Bit\n");
        printf("3. Toggle Bit\n");
        printf("4. Check Bit\n");
        printf("5. Display Bits\n");
        printf("6. Count Set Bits\n");
        printf("7. Rotate Left\n");
        printf("8. Rotate Right\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 9) {
            break;
        }

        printf("Enter an integer: ");
        scanf("%d", &number);

        switch (choice) {
            case 1:
                printf("Enter bit position to set (0-31): ");
                scanf("%d", &bit);
                number = setBit(number, bit);
                printf("Result after setting bit %d: %d\n", bit, number);
                break;
            case 2:
                printf("Enter bit position to clear (0-31): ");
                scanf("%d", &bit);
                number = clearBit(number, bit);
                printf("Result after clearing bit %d: %d\n", bit, number);
                break;
            case 3:
                printf("Enter bit position to toggle (0-31): ");
                scanf("%d", &bit);
                number = toggleBit(number, bit);
                printf("Result after toggling bit %d: %d\n", bit, number);
                break;
            case 4:
                printf("Enter bit position to check (0-31): ");
                scanf("%d", &bit);
                if (checkBit(number, bit)) {
                    printf("Bit %d is set in %d\n", bit, number);
                } else {
                    printf("Bit %d is not set in %d\n", bit, number);
                }
                break;
            case 5:
                printf("Binary representation of %d: ", number);
                displayBits(number);
                break;
            case 6:
                printf("Number of set bits in %d: %d\n", number, countSetBits(number));
                break;
            case 7:
                printf("Enter number of positions to rotate left: ");
                scanf("%d", &positions);
                number = rotateLeft(number, positions);
                printf("Result after rotating left by %d: %d\n", positions, number);
                break;
            case 8:
                printf("Enter number of positions to rotate right: ");
                scanf("%d", &positions);
                number = rotateRight(number, positions);
                printf("Result after rotating right by %d: %d\n", positions, number);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    printf("Exiting... Goodbye!\n");
    return 0;
}

// Function to set a bit in an integer
int setBit(int number, int bit) {
    return number | (1 << bit);
}

// Function to clear a bit in an integer
int clearBit(int number, int bit) {
    return number & ~(1 << bit);
}

// Function to toggle a bit in an integer
int toggleBit(int number, int bit) {
    return number ^ (1 << bit);
}

// Function to check if a bit is set
int checkBit(int number, int bit) {
    return (number & (1 << bit)) != 0;
}

// Function to display the bits of a number
void displayBits(int number) {
    for (int i = sizeof(number) * 8 - 1; i >= 0; i--) {
        printf("%d", (number >> i) & 1);
    }
    printf("\n");
}

// Function to count the number of set bits
int countSetBits(int number) {
    int count = 0;
    while (number) {
        count += number & 1;
        number >>= 1;
    }
    return count;
}

// Function to perform a left rotation
int rotateLeft(int number, int positions) {
    int bits = sizeof(number) * 8;  // Calculate the total number of bits
    positions %= bits;  // In case positions exceed the number of bits
    return (number << positions) | (number >> (bits - positions));
}

// Function to perform a right rotation
int rotateRight(int number, int positions) {
    int bits = sizeof(number) * 8;  // Calculate the total number of bits
    positions %= bits;  // In case positions exceed the number of bits
    return (number >> positions) | (number << (bits - positions));
}