//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to set a bit at a given position
void setBit(int *num, int pos) {
    *num = *num | (1 << pos);
}

// Function to clear a bit at a given position
void clearBit(int *num, int pos) {
    *num = *num & ~(1 << pos);
}

// Function to toggle a bit at a given position
void toggleBit(int *num, int pos) {
    *num = *num ^ (1 << pos);
}

// Function to check if a bit is set at a given position
int checkBit(int num, int pos) {
    return (num & (1 << pos))!= 0;
}

int main() {
    int num = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    // Set the 3rd bit to 1
    setBit(&num, 2);
    printf("After setting the 3rd bit to 1: %d\n", num);

    // Clear the 5th bit
    clearBit(&num, 4);
    printf("After clearing the 5th bit: %d\n", num);

    // Toggle the 7th bit
    toggleBit(&num, 6);
    printf("After toggling the 7th bit: %d\n", num);

    // Check if the 9th bit is set
    if (checkBit(num, 8)) {
        printf("The 9th bit is set.\n");
    } else {
        printf("The 9th bit is not set.\n");
    }

    return 0;
}