//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decimalToBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    int binary[32]; // Enough space for a 32-bit integer
    int i = 0;

    while (n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }

    // Print the binary array in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

// Function to convert binary to decimal
int binaryToDecimal(char *binaryString) {
    int decimal = 0;
    int base = 1;

    int length = strlen(binaryString);
    for (int i = length - 1; i >= 0; i--) {
        if (binaryString[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

// Function to handle menu options
void showMenu() {
    printf("\n--- Binary Converter Menu ---\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Exit\n");
    printf("-----------------------------\n");
    printf("Select an option: ");
}

int main() {
    int option, decimalNumber;
    char binaryString[33]; // Space for 32 bits + null terminator

    do {
        showMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNumber);
                printf("Binary representation: ");
                decimalToBinary(decimalNumber);
                printf("\n");
                break;
            case 2:
                printf("Enter a binary number (up to 32 bits): ");
                scanf("%s", binaryString);
                int decimalResult = binaryToDecimal(binaryString);
                printf("Decimal representation: %d\n", decimalResult);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 3);

    return 0;
}