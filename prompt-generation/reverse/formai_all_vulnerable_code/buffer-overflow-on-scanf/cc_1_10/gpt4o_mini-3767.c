//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToHex(int decimal, char *hexBuffer) {
    int idx = 0, temp;

    if (decimal == 0) {
        strcpy(hexBuffer, "0");
        return;
    }

    while (decimal != 0) {
        temp = decimal % 16;
        if (temp < 10) {
            hexBuffer[idx] = temp + '0';
        } else {
            hexBuffer[idx] = temp - 10 + 'A';
        }
        decimal /= 16;
        idx++;
    }
    hexBuffer[idx] = '\0';

    // Reverse the string to get the correct hexadecimal representation
    for (int i = 0; i < idx / 2; i++) {
        char tempChar = hexBuffer[i];
        hexBuffer[i] = hexBuffer[idx - i - 1];
        hexBuffer[idx - i - 1] = tempChar;
    }
}

void displayMenu() {
    printf("\nHexadecimal Converter\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
}

void handleConversion() {
    int decimalValue;
    char hexBuffer[20];

    printf("Enter a decimal number: ");
    if (scanf("%d", &decimalValue) != 1) {
        printf("Invalid input. Please enter a valid decimal number.\n");
        while(getchar() != '\n'); // Clear invalid input
        return;
    }

    convertToHex(decimalValue, hexBuffer);
    printf("Decimal: %d => Hexadecimal: %s\n", decimalValue, hexBuffer);
}

int main() {
    int choice;

    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number from the menu.\n");
            while(getchar() != '\n'); // Clear invalid input
            choice = 0; // Reset choice to force loop
            continue;
        }

        switch (choice) {
            case 1:
                handleConversion();
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}