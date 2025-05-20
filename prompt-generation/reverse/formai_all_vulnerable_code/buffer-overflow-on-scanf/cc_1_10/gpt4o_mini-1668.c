//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEX_DIGITS 16

// Function to convert an integer to its hexadecimal representation
void intToHex(int num, char *hexStr) {
    const char *hexChars = "0123456789ABCDEF";
    int i = 0;
    while (num > 0) {
        hexStr[i++] = hexChars[num % HEX_DIGITS];
        num /= HEX_DIGITS;
    }
    hexStr[i] = '\0';
    
    // Reverse the string
    for (int j = 0; j < i / 2; j++) {
        char temp = hexStr[j];
        hexStr[j] = hexStr[i - j - 1];
        hexStr[i - j - 1] = temp;
    }
}

// Function to convert a hexadecimal string to an integer
int hexToInt(const char *hexStr) {
    int length = strlen(hexStr);
    int result = 0;
    for (int i = 0; i < length; i++) {
        char c = hexStr[length - i - 1];
        int value;
        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;
        } else {
            printf("Invalid hexadecimal number '%c'\n", c);
            return -1; // Return an indication of error
        }
        result += value * (1 << (i * 4)); // Shift by 4 bits for each digit
    }
    return result;
}

// Function to display the menu
void displayMenu() {
    printf("Hexadecimal Converter\n");
    printf("=====================\n");
    printf("1. Convert an Integer to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Integer\n");
    printf("3. Exit\n");
    printf("=====================\n");
}

// Main function to handle user input and conversion
int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        if (choice == 1) {
            int num;
            char hexStr[20];
            printf("Enter an integer: ");
            scanf("%d", &num);
            intToHex(num, hexStr);
            printf("Hexadecimal representation: %s\n", hexStr);
        } else if (choice == 2) {
            char hexStr[20];
            printf("Enter a hexadecimal number (without '0x' prefix): ");
            scanf("%s", hexStr);
            int result = hexToInt(hexStr);
            if (result != -1) {
                printf("Integer representation: %d\n", result);
            }
        } else if (choice != 3) {
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    printf("Exiting the program. Goodbye!\n");
    return 0;
}