//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complex
#include <stdio.h>
#include <stdbool.h>

// Function to check the presence of a bit at a certain position
bool isBitSet(unsigned int num, int pos) {
    return (num & (1 << pos)) != 0;
}

// Function to set a bit at a certain position
unsigned int setBit(unsigned int num, int pos) {
    return num | (1 << pos);
}

// Function to clear a bit at a certain position
unsigned int clearBit(unsigned int num, int pos) {
    return num & (~(1 << pos));
}

// Function to toggle a bit at a certain position
unsigned int toggleBit(unsigned int num, int pos) {
    return num ^ (1 << pos);
}

// Function to print the binary representation of an unsigned integer
void printBinary(unsigned int num) {
    for(int i = 31; i >= 0; i--) {
        printf("%d", isBitSet(num, i));
    }
    printf("\n");
}

int main() {
    unsigned int num = 235;

    printf("The binary representation of %d is: ", num);
    printBinary(num);

    printf("Setting bit 5: ");
    num = setBit(num, 5);
    printBinary(num);

    printf("Clearing bit 2: ");
    num = clearBit(num, 2);
    printBinary(num);

    printf("Toggling bit 7: ");
    num = toggleBit(num, 7);
    printBinary(num);

    return 0;
}