//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>

void printBinary(int num) {
    // Array to hold binary digits
    int binary[32];
    int index = 0;

    // Convert to binary
    while (num > 0) {
        binary[index] = num % 2;
        num = num / 2;
        index++;
    }

    // Print in reverse order
    printf("Binary: ");
    for (index--; index >= 0; index--) {
        printf("%d", binary[index]);
    }
    printf("\n");
}

void binaryToDecimal(char *binaryString) {
    int decimalValue = 0;
    int base = 1;
    int length = 0;

    // Compute the length of the binary string
    while (binaryString[length] != '\0') {
        length++;
    }

    // Convert binary to decimal
    for (int i = length - 1; i >= 0; i--) {
        if (binaryString[i] == '1') {
            decimalValue += base;
        }
        base *= 2;
    }

    printf("Decimal: %d\n", decimalValue);
}

int main() {
    int choice;
    int number;
    char binaryString[32];

    // User interface loop
    do {
        printf("\n=== Binary Converter ===\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                printBinary(number);
                break;

            case 2:
                printf("Enter a binary number: ");
                scanf("%s", binaryString);
                binaryToDecimal(binaryString);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}