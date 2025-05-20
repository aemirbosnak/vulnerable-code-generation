//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: scientific
#include<stdio.h>
#include<stdlib.h>

// Function Prototypes
void setBit(int *, int, int);
void clearBit(int *, int, int);
void toggleBit(int *, int, int);
void getBit(int, int, int *);
void shiftLeft(int *, int, int);
void shiftRight(int *, int, int);

int main()
{
    int num, position, n;

    // Input from user
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter the position of the bit to be manipulated: ");
    scanf("%d", &position);

    // Manipulate bit at given position
    setBit(&num, position, 1);
    printf("Number after setting bit at position %d: %d\n", position, num);

    clearBit(&num, position, 1);
    printf("Number after clearing bit at position %d: %d\n", position, num);

    toggleBit(&num, position, 1);
    printf("Number after toggling bit at position %d: %d\n", position, num);

    // Get the value of the bit at given position
    getBit(num, position, &n);
    printf("Value of bit at position %d: %d\n", position, n);

    // Shift the bits to the left and right
    shiftLeft(&num, 2, 4);
    printf("Number after shifting left by 2 positions: %d\n", num);

    shiftRight(&num, 2, 4);
    printf("Number after shifting right by 2 positions: %d\n", num);

    return 0;
}

// Function to set a bit at given position
void setBit(int *num, int pos, int val)
{
    *num = (*num | (val << pos));
}

// Function to clear a bit at given position
void clearBit(int *num, int pos, int val)
{
    *num = (*num & ~(val << pos));
}

// Function to toggle a bit at given position
void toggleBit(int *num, int pos, int val)
{
    *num ^= (val << pos);
}

// Function to get the value of a bit at given position
void getBit(int num, int pos, int *val)
{
    *val = (num & (1 << pos)) >> pos;
}

// Function to shift the bits to the left
void shiftLeft(int *num, int pos, int n)
{
    *num = (*num << n) | (*num >> (32 - n));
}

// Function to shift the bits to the right
void shiftRight(int *num, int pos, int n)
{
    *num = (*num >> n) | (*num << (32 - n));
}