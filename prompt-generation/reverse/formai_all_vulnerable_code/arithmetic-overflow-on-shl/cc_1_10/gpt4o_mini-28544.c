//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

void displayBinary(int n) {
    // Display binary representation of an integer
    for (int i = 31; i >= 0; i--) {
        putchar((n & (1 << i)) ? '1' : '0');
        if (i % 4 == 0) putchar(' '); // Pretty print every 4 bits
    }
    putchar('\n');
}

int main() {
    int numberA, numberB, choice;
    printf("Bitwise Operations Menu\n");
    printf("-----------------------\n");
    printf("1: AND\n");
    printf("2: OR\n");
    printf("3: XOR\n");
    printf("4: NOT\n");
    printf("5: Left Shift\n");
    printf("6: Right Shift\n");
    printf("7: Exit\n\n");

    while (1) {
        printf("Enter the first number (A): ");
        scanf("%d", &numberA);
        printf("Enter the second number (B): ");
        scanf("%d", &numberB);

        printf("\nChoose a bitwise operation (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // AND
                printf("A AND B = ");
                displayBinary(numberA & numberB);
                printf("Decimal Result: %d\n", numberA & numberB);
                break;
            case 2: // OR
                printf("A OR B = ");
                displayBinary(numberA | numberB);
                printf("Decimal Result: %d\n", numberA | numberB);
                break;
            case 3: // XOR
                printf("A XOR B = ");
                displayBinary(numberA ^ numberB);
                printf("Decimal Result: %d\n", numberA ^ numberB);
                break;
            case 4: // NOT A
                printf("NOT A = ");
                displayBinary(~numberA);
                printf("Decimal Result: %d\n", ~numberA);
                break;
            case 5: // Left Shift
                printf("A << 1 = ");
                displayBinary(numberA << 1);
                printf("Decimal Result: %d\n", numberA << 1);
                break;
            case 6: // Right Shift
                printf("A >> 1 = ");
                displayBinary(numberA >> 1);
                printf("Decimal Result: %d\n", numberA >> 1);
                break;
            case 7: // Exit
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid option! Please choose again.\n");
        }

        printf("\n");
    }

    return 0; // End of program
}