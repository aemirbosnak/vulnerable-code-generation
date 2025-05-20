//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

// Function to generate a random 32-bit number
uint32_t generateRandomNumber() {
    return rand() % 0xFFFFFFFF;
}

// Function to display the binary representation of a number
void displayBinary(uint32_t num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) {
            putchar(' '); // Added space for better readability
        }
    }
    printf("\n");
}

// Function to perform and display the bitwise operations
void performBitwiseOperations(uint32_t a, uint32_t b) {
    printf("\nCybernetic Calculation Log:\n");
    printf("A: ");
    displayBinary(a);
    printf("B: ");
    displayBinary(b);

    // Bitwise AND
    uint32_t andResult = a & b;
    printf("A & B: ");
    displayBinary(andResult);

    // Bitwise OR
    uint32_t orResult = a | b;
    printf("A | B: ");
    displayBinary(orResult);

    // Bitwise XOR
    uint32_t xorResult = a ^ b;
    printf("A ^ B: ");
    displayBinary(xorResult);

    // Bitwise NOT
    uint32_t notA = ~a;
    printf("~A: ");
    displayBinary(notA);

    uint32_t notB = ~b;
    printf("~B: ");
    displayBinary(notB);

    // Left Shift
    uint32_t leftShiftA = a << 2;
    printf("A << 2: ");
    displayBinary(leftShiftA);

    // Right Shift
    uint32_t rightShiftA = a >> 2;
    printf("A >> 2: ");
    displayBinary(rightShiftA);
}

// Function to create a cyberpunk-style user interface
void cyberpunkUI() {
    printf("\nWelcome to the Cyberpunk Bitwise Operation Terminal!\n");
    printf("===============================================\n");
    printf("1. Generate Random Numbers\n");
    printf("2. Perform Bitwise Operations\n");
    printf("3. Exit\n");
    printf("===============================================\n");
}

// Main function to run the program
int main() {
    srand(time(0)); // Seed for random number generation

    uint32_t a, b;
    int choice;

    while (1) {
        cyberpunkUI();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                a = generateRandomNumber();
                b = generateRandomNumber();
                printf("Generated numbers:\n");
                printf("A = %u\n", a);
                printf("B = %u\n", b);
                break;
            case 2:
                printf("Enter two 32-bit unsigned integers (press 1 to generate):\n");
                printf("A: ");
                scanf("%u", &a);
                printf("B: ");
                scanf("%u", &b);
                performBitwiseOperations(a, b);
                break;
            case 3:
                printf("Exiting the Cyberpunk Bitwise Terminal...\n");
                exit(0);
            default:
                printf("Invalid choice, come back to the grid!\n");
                break;
        }
    }

    return 0;
}