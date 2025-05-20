//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void decimalToBinary(int n, char *binary) {
    int index = 0;
    if (n == 0) {
        binary[index++] = '0';
    } else {
        while (n > 0) {
            binary[index++] = (n % 2) + '0';
            n = n / 2;
        }
    }

    binary[index] = '\0';

    // Reverse the binary string
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }
}

void binaryToDecimal(const char *binary, int *decimal) {
    *decimal = 0;
    int length = strlen(binary);
    
    for (int i = 0; i < length; i++) {
        if (binary[length - i - 1] == '1') {
            *decimal += pow(2, i);
        }
    }
}

void displayMenu() {
    printf("---- Binary Converter ----\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
    printf("--------------------------\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char binary[65]; // Enough to hold binary representation of 64-bit integer
    int decimal;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                decimalToBinary(decimal, binary);
                printf("Binary Representation: %s\n", binary);
                break;

            case 2:
                printf("Enter a binary number: ");
                scanf("%s", binary);
                binaryToDecimal(binary, &decimal);
                printf("Decimal Representation: %d\n", decimal);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}