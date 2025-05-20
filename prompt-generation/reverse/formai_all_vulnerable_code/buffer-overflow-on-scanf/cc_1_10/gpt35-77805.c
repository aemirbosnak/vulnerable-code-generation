//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Ada Lovelace
#include <stdio.h> // Standard Input/Output Library

// Function to convert Decimal to Hexadecimal
void decimalToHexadecimal(int decimalNumber) {
    int remainder;
    char hexadecimalNumber[100];

    int i = 0;
    while(decimalNumber != 0) {
        remainder = decimalNumber % 16;
        if(remainder < 10) {
            hexadecimalNumber[i] = remainder + 48;
        }
        else {
            hexadecimalNumber[i] = remainder + 55;
        }
        i++;
        decimalNumber /= 16;
    }
    printf("Hexadecimal Number: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimalNumber[j]);
    }
}

// Function to convert Hexadecimal to Decimal
void hexadecimalToDecimal(char hexadecimalNumber[]) {
    int decimalNumber = 0;
    int i = 0;
    while(hexadecimalNumber[i] != '\0') {
        if(hexadecimalNumber[i] >= '0' && hexadecimalNumber[i] <= '9') {
            decimalNumber = decimalNumber * 16 + (hexadecimalNumber[i] - '0');
        }
        else if(hexadecimalNumber[i] >= 'a' && hexadecimalNumber[i] <= 'f') {
            decimalNumber = decimalNumber * 16 + (hexadecimalNumber[i] - 'a' + 10);
        }
        else if(hexadecimalNumber[i] >= 'A' && hexadecimalNumber[i] <= 'F') {
            decimalNumber = decimalNumber * 16 + (hexadecimalNumber[i] - 'A' + 10);
        }
        i++;
    }
    printf("Decimal Number: %d", decimalNumber);
}

// Main function
int main() {
    int choice;

    // Menu
    printf("1. Decimal to Hexadecimal Conversion.\n");
    printf("2. Hexadecimal to Decimal Conversion.\n");
    
    // User choice
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    // Decimal to Hexadecimal Conversion
    if(choice == 1) {
        int decimalNumber;
        printf("\nEnter the decimal number: ");
        scanf("%d", &decimalNumber);
        decimalToHexadecimal(decimalNumber);
    }
    // Hexadecimal to Decimal Conversion
    else if(choice == 2) {
        char hexadecimalNumber[100];
        printf("\nEnter the hexadecimal number: ");
        scanf("%s", hexadecimalNumber);
        hexadecimalToDecimal(hexadecimalNumber);
    }
    // Invalid choice
    else {
        printf("\nInvalid choice!");
    }

    return 0;
}