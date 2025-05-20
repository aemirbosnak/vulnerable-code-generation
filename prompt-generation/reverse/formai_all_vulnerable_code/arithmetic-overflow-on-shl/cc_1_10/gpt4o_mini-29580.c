//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bitwise operations functions

// Function to set a bit at position 'pos'
void setBit(int *num, int pos) {
    *num |= (1 << pos);
}

// Function to clear a bit at position 'pos'
void clearBit(int *num, int pos) {
    *num &= ~(1 << pos);
}

// Function to toggle a bit at position 'pos'
void toggleBit(int *num, int pos) {
    *num ^= (1 << pos);
}

// Function to check if a bit at position 'pos' is set
int isBitSet(int num, int pos) {
    return (num & (1 << pos)) != 0;
}

// Function to display bits of a number
void displayBits(int num) {
    printf("Binary representation: ");
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num & (1 << i)) ? 1 : 0);
    }
    printf("\n");
}

// Main program
int main() {
    int num = 0;  // The number to work with
    char command[20];  // Command input from user
    int position;  // Position for bitwise operations

    printf("Welcome to the Bitwise Operations Program!\n");
    printf("You can perform the following operations:\n");
    printf("1: Set Bit\n");
    printf("2: Clear Bit\n");
    printf("3: Toggle Bit\n");
    printf("4: Check if Bit is Set\n");
    printf("5: Display Binary Representation\n");
    printf("6: Exit\n");

    while (1) {
        printf("\nEnter command (1-6): ");
        fgets(command, sizeof(command), stdin);
        int cmd = atoi(command);  // Convert command string to int

        switch (cmd) {
            case 1:
                printf("Enter position (0-31): ");
                fgets(command, sizeof(command), stdin);
                position = atoi(command);
                setBit(&num, position);
                printf("Bit at position %d set.\n", position);
                break;

            case 2:
                printf("Enter position (0-31): ");
                fgets(command, sizeof(command), stdin);
                position = atoi(command);
                clearBit(&num, position);
                printf("Bit at position %d cleared.\n", position);
                break;

            case 3:
                printf("Enter position (0-31): ");
                fgets(command, sizeof(command), stdin);
                position = atoi(command);
                toggleBit(&num, position);
                printf("Bit at position %d toggled.\n", position);
                break;

            case 4:
                printf("Enter position (0-31): ");
                fgets(command, sizeof(command), stdin);
                position = atoi(command);
                if (isBitSet(num, position)) {
                    printf("Bit at position %d is set.\n", position);
                } else {
                    printf("Bit at position %d is not set.\n", position);
                }
                break;

            case 5:
                displayBits(num);
                break;

            case 6:
                printf("Exiting program.\n");
                exit(0);
                break;

            default:
                printf("Invalid command. Please try again.\n");
                break;
        }
    }

    return 0;
}