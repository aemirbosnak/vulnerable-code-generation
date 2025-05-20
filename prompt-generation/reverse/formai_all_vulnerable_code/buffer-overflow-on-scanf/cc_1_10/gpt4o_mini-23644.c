//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void decimalToBinary(int decimal, char *binary);
int binaryToDecimal(const char *binary);
void printMenu();
void performConversion(int choice);

// Main function
int main(void) {
    int choice;
    
    while (1) {
        printMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        
        if (choice < 1 || choice > 4) {
            printf("Exiting program. Goodbye!\n");
            break;
        }
        
        performConversion(choice);
    }

    return 0;
}

// Function to print the menu
void printMenu() {
    printf("\n*** Binary Converter Menu ***\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Exit\n");
}

// Function to perform conversion based on user choice
void performConversion(int choice) {
    if (choice == 1) {
        int decimal;
        char binary[33]; // enough to hold binary representation of an integer (32 bits + null terminator)
        
        printf("Enter a decimal number: ");
        scanf("%d", &decimal);
        
        decimalToBinary(decimal, binary);
        printf("Binary representation of %d is: %s\n", decimal, binary);
    } else if (choice == 2) {
        char binary[33];
        int decimal;

        printf("Enter a binary number: ");
        scanf("%s", binary);

        decimal = binaryToDecimal(binary);
        printf("Decimal representation of %s is: %d\n", binary, decimal);
    } else {
        printf("Invalid option selected!\n");
    }
}

// Function to convert Decimal to Binary
void decimalToBinary(int decimal, char *binary) {
    int index = 0;

    // Handle the case when decimal is 0
    if (decimal == 0) {
        strcpy(binary, "0");
        return;
    }

    while (decimal > 0) {
        binary[index++] = (decimal % 2) + '0'; // Get the last bit and convert to char
        decimal /= 2; // Reduce the decimal number
    }
    binary[index] = '\0'; // Null-terminate the string

    // Reverse the binary string
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - 1 - i];
        binary[index - 1 - i] = temp;
    }
}

// Function to convert Binary to Decimal
int binaryToDecimal(const char *binary) {
    int decimal = 0;
    int base = 1; // Initialize base value for binary to decimal conversion
    int length = strlen(binary);
    
    // Convert binary string to decimal
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base; // Add base value to decimal if the bit is 1
        }
        base *= 2; // Move to next power of 2
    }

    return decimal;
}