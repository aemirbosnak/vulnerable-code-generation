//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

void printBinary(unsigned int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

void displayMenu() {
    printf("\nBitwise Operations Menu:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    printf("7. Exit\n");
    printf("Select an option (1-7): ");
}

int main() {
    unsigned int num1, num2, result;
    int choice, shift;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Exiting the program.\n");
            break;
        }

        if (choice < 1 || choice > 6) {
            printf("Invalid option! Please select a valid option.\n");
            continue;
        }

        printf("Enter first number: ");
        scanf("%u", &num1);

        if (choice != 4) {
            printf("Enter second number: ");
            scanf("%u", &num2);
        }

        switch (choice) {
            case 1: // Bitwise AND
                result = num1 & num2;
                printf("Result of %u AND %u: %u\n", num1, num2, result);
                printf("Binary: ");
                printBinary(result);
                break;

            case 2: // Bitwise OR
                result = num1 | num2;
                printf("Result of %u OR %u: %u\n", num1, num2, result);
                printf("Binary: ");
                printBinary(result);
                break;

            case 3: // Bitwise XOR
                result = num1 ^ num2;
                printf("Result of %u XOR %u: %u\n", num1, num2, result);
                printf("Binary: ");
                printBinary(result);
                break;

            case 4: // Bitwise NOT
                result = ~num1;
                printf("Result of NOT %u: %u\n", num1, result);
                printf("Binary: ");
                printBinary(result);
                break;

            case 5: // Left Shift
                printf("Enter number of bits to shift left: ");
                scanf("%d", &shift);
                result = num1 << shift;
                printf("Result of %u << %d: %u\n", num1, shift, result);
                printf("Binary: ");
                printBinary(result);
                break;

            case 6: // Right Shift
                printf("Enter number of bits to shift right: ");
                scanf("%d", &shift);
                result = num1 >> shift;
                printf("Result of %u >> %d: %u\n", num1, shift, result);
                printf("Binary: ");
                printBinary(result);
                break;

            default:
                printf("Invalid selection.\n");
                break;
        }
    }

    return 0;
}