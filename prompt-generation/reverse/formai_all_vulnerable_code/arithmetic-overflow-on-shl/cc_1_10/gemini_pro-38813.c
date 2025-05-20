//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Functions to perform bitwise operations
int setBit(int num, int pos) { return num | (1 << pos); }
int clearBit(int num, int pos) { return num & ~(1 << pos); }
int toggleBit(int num, int pos) { return num ^ (1 << pos); }
int checkBit(int num, int pos) { return (num & (1 << pos)) >> pos; }

// Function to print binary representation of an integer
void printBinary(int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        printf("%d", checkBit(num, i));
        if (i % 4 == 0)
            printf(" ");
    }
    printf("\n");
}

int main() {
    int num, pos, choice;

    // Get the number and the position
    printf("Enter an integer: ");
    scanf("%d", &num);
    printf("Enter the position (0-31): ");
    scanf("%d", &pos);

    // Display the number in binary form
    printf("Original number in binary: ");
    printBinary(num);

    // Display the menu of operations
    printf("\nChoose an operation:\n");
    printf("1. Set bit\n");
    printf("2. Clear bit\n");
    printf("3. Toggle bit\n");
    printf("4. Check bit\n");
    printf("5. Exit\n");
    printf("\nYour choice: ");
    scanf("%d", &choice);

    // Perform the selected operation
    switch (choice) {
        case 1:
            num = setBit(num, pos);
            printf("Set bit at position %d\n", pos);
            break;
        case 2:
            num = clearBit(num, pos);
            printf("Cleared bit at position %d\n", pos);
            break;
        case 3:
            num = toggleBit(num, pos);
            printf("Toggled bit at position %d\n", pos);
            break;
        case 4:
            printf("Bit at position %d is %d\n", pos, checkBit(num, pos));
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
    }

    // Display the number in binary form again
    printf("Result in binary: ");
    printBinary(num);

    return 0;
}