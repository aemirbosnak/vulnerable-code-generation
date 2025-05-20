//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decimalToBinary(int n) {
    // Assign maximum bits for a standard 32-bit integer
    int binary[32];
    int index = 0;

    // While there's still a part of the number to process
    while (n > 0) {
        binary[index] = n % 2;  // Store remainder (0 or 1)
        n = n / 2;               // Divide number by 2
        index++;
    }

    // Binary digits are stored in reverse order
    printf("Binary Representation: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// Function to convert binary to decimal
int binaryToDecimal(const char *binaryStr) {
    int decimalValue = 0;
    int base = 1; // Initialize base value (2^0)

    // Length of the binary string
    int len = strlen(binaryStr);

    // Loop through each character of the binary string
    for (int i = len - 1; i >= 0; i--) {
        if (binaryStr[i] == '1') {
            decimalValue += base;
        }
        base *= 2; // Increase base by powers of 2
    }

    return decimalValue;
}

// Function to check if the input string is a valid binary number
int isValidBinary(const char *binaryStr) {
    for (int i = 0; binaryStr[i] != '\0'; i++) {
        if (binaryStr[i] != '0' && binaryStr[i] != '1') {
            return 0; // Invalid binary number
        }
    }
    return 1; // Valid binary number
}

// Main function to execute the converter
int main() {
    int choice;
    printf("Welcome to the Binary Converter!\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            int decimalNumber;
            printf("Enter a decimal number: ");
            scanf("%d", &decimalNumber);
            decimalToBinary(decimalNumber);
            break;
        }
        case 2: {
            char binaryStr[33]; // 32 bits + 1 null terminator
            printf("Enter a binary number: ");
            scanf("%s", binaryStr);
            
            if (isValidBinary(binaryStr)) {
                int decimalValue = binaryToDecimal(binaryStr);
                printf("Decimal Representation: %d\n", decimalValue);
            } else {
                printf("Invalid binary number entered!\n");
            }
            break;
        }
        default:
            printf("Invalid choice! Please select 1 or 2.\n");
    }
    
    printf("Thank you for using the Binary Converter!\n");
    return 0;
}