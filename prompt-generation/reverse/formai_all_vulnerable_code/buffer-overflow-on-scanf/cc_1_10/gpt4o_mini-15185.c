//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// A mind-bending journey through hexadecimal conversion.

void decimalToHex(int decimal, char hex[]) {
    int i = 0;
    while (decimal != 0) {
        int temp = decimal % 16;
        hex[i++] = (temp < 10) ? (temp + '0') : (temp - 10 + 'A');
        decimal /= 16;
    }
    hex[i] = '\0';

    // Reverse the string to get the correct hex representation
    for (int j = 0; j < i / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }
}

void hexToDecimal(const char *hex, int *decimal) {
    *decimal = 0;
    int len = strlen(hex);
    
    for (int i = 0; i < len; i++) {
        char ch = hex[len - i - 1];
        int value = (ch >= '0' && ch <= '9') ? (ch - '0') : (ch - 'A' + 10);
        *decimal += value * (int)pow(16, i);
    }
}

void displayMenu() {
    printf("\n== Hexadecimal Converter ==\n");
    printf("1. Decimal to Hexadecimal\n");
    printf("2. Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("==========================\n");
}

void handleConversion(int choice) {
    if (choice == 1) {
        int decimal;
        char hex[25];
        printf("Enter a decimal number: ");
        scanf("%d", &decimal);
        decimalToHex(decimal, hex);
        printf("Hexadecimal: %s\n", hex);
    } else if (choice == 2) {
        char hex[25];
        int decimal;
        printf("Enter a hexadecimal number: ");
        scanf("%s", hex);
        hexToDecimal(hex, &decimal);
        printf("Decimal: %d\n", decimal);
    }
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        if (choice < 1 || choice > 3) {
            printf("Invalid choice, please try again.\n");
        } else if (choice != 3) {
            handleConversion(choice);
        }
    } while (choice != 3);
    
    printf("Exiting the Hexadecimal Converter. Goodbye!\n");
    return 0;
}