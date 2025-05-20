//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printGratitude() {
    printf("*********************************************\n");
    printf("*  Welcome to the Hexadecimal Converter!   *\n");
    printf("*           We appreciate your use!        *\n");
    printf("*********************************************\n\n");
}

void decimalToHexadecimal(int decimalNumber) {
    char hexRepresentation[20]; // sufficient to hold hex representation
    int index = 0;

    if (decimalNumber == 0) {
        strcpy(hexRepresentation, "0");
        printf("Decimal: 0 => Hexadecimal: %s\n", hexRepresentation);
        return;
    }

    while (decimalNumber > 0) {
        int remainder = decimalNumber % 16;
        if (remainder < 10)
            hexRepresentation[index++] = remainder + '0';
        else
            hexRepresentation[index++] = (remainder - 10) + 'A';

        decimalNumber /= 16;
    }
    
    // Reverse the string
    hexRepresentation[index] = '\0';
    for (int i = 0; i < index / 2; i++) {
        char temp = hexRepresentation[i];
        hexRepresentation[i] = hexRepresentation[index - i - 1];
        hexRepresentation[index - i - 1] = temp;
    }

    printf("Decimal: %d => Hexadecimal: %s\n", decimalNumber, hexRepresentation);
}

void hexadecimalToDecimal(const char* hexNumber) {
    int decimalValue = 0;
    int base = 1;
    int hexLength = strlen(hexNumber);

    for (int i = hexLength - 1; i >= 0; i--) {
        char c = hexNumber[i];
        int digit;

        if (c >= '0' && c <= '9') 
            digit = c - '0';
        else if (c >= 'A' && c <= 'F') 
            digit = c - 'A' + 10;
        else if (c >= 'a' && c <= 'f') 
            digit = c - 'a' + 10;
        else {
            printf("Invalid hexadecimal input!\n");
            return;
        }
        
        decimalValue += digit * base;
        base *= 16;
    }

    printf("Hexadecimal: %s => Decimal: %d\n", hexNumber, decimalValue);
}

int main() {
    printGratitude();

    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Convert Decimal to Hexadecimal\n");
        printf("2. Convert Hexadecimal to Decimal\n");
        printf("3. Exit\n");
        printf("Please choose an option: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Thank you for using the Hexadecimal Converter!\n");
            break;
        }

        switch (choice) {
            case 1: {
                int decimalNumber;
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNumber);
                decimalToHexadecimal(decimalNumber);
                break;
            }
            case 2: {
                char hexNumber[20];
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                hexadecimalToDecimal(hexNumber);
                break;
            }
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
    }

    return 0;
}