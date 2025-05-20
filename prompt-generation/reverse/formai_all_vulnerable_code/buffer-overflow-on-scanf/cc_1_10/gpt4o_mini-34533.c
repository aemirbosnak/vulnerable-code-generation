//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToHex(int decimal, char *hex) {
    int index = 0;
    char temp;

    // Handling zero as a special case
    if (decimal == 0) {
        strcpy(hex, "0");
        return;
    }

    while (decimal != 0) {
        int remainder = decimal % 16;

        // Convert remainder to hex character
        if (remainder < 10) {
            hex[index] = remainder + '0';
        } else {
            hex[index] = (remainder - 10) + 'A';
        }
        index++;
        decimal = decimal / 16;
    }
    
    hex[index] = '\0'; // Null-terminate the string

    // Reverse the string to get the correct hex representation
    for (int i = 0; i < index / 2; i++) {
        temp = hex[i];
        hex[i] = hex[index - i - 1];
        hex[index - i - 1] = temp;
    }
}

void readDecimalNumber(int *number) {
    char input[100];
    printf("Enter a decimal number: ");
    fgets(input, sizeof(input), stdin);
    *number = atoi(input); // Convert string to integer
}

void displayHexadecimal(char *hex) {
    printf("The hexadecimal representation is: %s\n", hex);
}

int main() {
    int decimalNumber;
    char hex[100]; // Allocating space for hexadecimal representation

    readDecimalNumber(&decimalNumber);
    convertToHex(decimalNumber, hex);
    displayHexadecimal(hex);
    
    while (1) {
        char choice;
        printf("Do you want to convert another number? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Clear newline character from buffer

        if (choice == 'y' || choice == 'Y') {
            readDecimalNumber(&decimalNumber);
            convertToHex(decimalNumber, hex);
            displayHexadecimal(hex);
        } else if (choice == 'n' || choice == 'N') {
            printf("Thank you for using the Hexadecimal Converter. Goodbye!\n");
            break;
        } else {
            printf("Invalid option, please enter 'y' or 'n'.\n");
        }
    }
    
    return 0;
}