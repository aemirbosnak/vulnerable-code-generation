//FormAI DATASET v1.0 Category: Bitwise operations ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Function to check if a bit in a number is set or not
bool check_bit(int num, int bit)
{
    // Use bitwise AND to check if bit is set or not
    if((num & (1 << bit)) != 0)
        return true;
    else
        return false;
}

// Function to set a bit in a number
int set_bit(int num, int bit)
{
    // Use bitwise OR to set the bit
    return num | (1 << bit);
}

// Function to clear a bit in a number
int clear_bit(int num, int bit)
{
    // Use bitwise AND with complement of the bit
    return num & ~(1 << bit);
}

// Function to toggle a bit in a number
int toggle_bit(int num, int bit)
{
    // Use bitwise XOR to toggle the bit
    return num ^ (1 << bit);
}

int main()
{
    int num, bit;
    int choice;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Enter the bit to manipulate: ");
    scanf("%d", &bit);

    printf("\nChoose an operation to perform on the bit: ");
    printf("\n1. Check if the bit is set");
    printf("\n2. Set the bit");
    printf("\n3. Clear the bit");
    printf("\n4. Toggle the bit\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            if(check_bit(num, bit))
                printf("\nBit %d is set in %d", bit, num);
            else
                printf("\nBit %d is not set in %d", bit, num);
            break;

        case 2:
            num = set_bit(num, bit);
            printf("\nBit %d set in %d: %d", bit, num, num);
            break;

        case 3:
            num = clear_bit(num, bit);
            printf("\nBit %d cleared in %d: %d", bit, num, num);
            break;

        case 4:
            num = toggle_bit(num, bit);
            printf("\nBit %d toggled in %d: %d", bit, num, num);
            break;

        default:
            printf("\nInvalid choice!");
            break;
    }

    return 0;
}