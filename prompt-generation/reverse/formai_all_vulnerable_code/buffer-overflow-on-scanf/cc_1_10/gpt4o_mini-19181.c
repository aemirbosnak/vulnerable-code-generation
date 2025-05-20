//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decToBinary(int n) {
    // Maximum 32 bits for the sake of simplicity
    char binary[32];
    int index = 0;

    // If the number is 0, handle the special case
    if (n == 0) {
        printf("Binary: 0\n");
        return;
    }

    // Fill the binary array with 0s
    for (int i = 0; i < 32; i++) {
        binary[i] = '0';
    }

    // Converting decimal to binary
    while (n > 0) {
        binary[index++] = (n % 2) + '0'; // Store the binary digit as character
        n /= 2;
    }

    // Print the result in reverse order
    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        putchar(binary[i]);
    }
    putchar('\n');
}

void binaryToDec(const char *binary) {
    int decimal = 0;
    int base = 1;
    int length = strlen(binary);

    // Convert from binary to decimal
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    printf("Decimal: %d\n", decimal);
}

void displayMenu() {
    printf("Welcome to the Amazing Binary Converter!\n");
    printf("Please select an option:\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
}

int getUserChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int choice;
    int decimalNumber;
    char binaryInput[33]; // 32 bits + 1 for the null terminator

    while (1) {
        displayMenu();
        choice = getUserChoice();

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNumber);
                decToBinary(decimalNumber);
                break;

            case 2:
                printf("Enter a binary number: ");
                scanf("%s", binaryInput);
                // Ensure input is valid (composed only of 0s and 1s)
                if (strspn(binaryInput, "01") == strlen(binaryInput)) {
                    binaryToDec(binaryInput);
                } else {
                    printf("Invalid binary number! Please use only 0s and 1s.\n");
                }
                break;

            case 3:
                printf("Thank you for using the Amazing Binary Converter! Goodbye!\n");
                exit(0);
            
            default:
                printf("Invalid option! Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}