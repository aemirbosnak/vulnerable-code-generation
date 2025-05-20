//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal, char *hexadecimal) {
    int index = 0;
    
    // Handle 0 explicitly
    if (decimal == 0) {
        strcpy(hexadecimal, "0");
        return;
    }

    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal[index++] = '0' + remainder;
        } else {
            hexadecimal[index++] = 'A' + (remainder - 10);
        }
        decimal /= 16;
    }
    hexadecimal[index] = '\0';

    // Reverse the string to get the correct hexadecimal representation
    for (int i = 0; i < index / 2; i++) {
        char temp = hexadecimal[i];
        hexadecimal[i] = hexadecimal[index - i - 1];
        hexadecimal[index - i - 1] = temp;
    }
}

// Function to convert hexadecimal to decimal
int hexadecimalToDecimal(const char *hexadecimal) {
    int decimal = 0;
    int base = 1;
    int length = strlen(hexadecimal);

    for (int i = length - 1; i >= 0; i--) {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            decimal += (hexadecimal[i] - '0') * base;
        } else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            decimal += (hexadecimal[i] - 'A' + 10) * base;
        } else if (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f') {
            decimal += (hexadecimal[i] - 'a' + 10) * base;
        }
        base *= 16;
    }

    return decimal;
}

// Function to display menu
void displayMenu() {
    printf("\n=== Hexadecimal Converter ===\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("Please choose an option: ");
}

// Main program
int main() {
    int choice;
    char hexOutput[MAX_INPUT];
    char hexInput[MAX_INPUT];

    printf("Welcome to the Hexadecimal Converter!\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
        case 1: // Decimal to Hexadecimal
            {
                int decimalInput;
                printf("Enter a decimal number: ");
                scanf("%d", &decimalInput);
                decimalToHexadecimal(decimalInput, hexOutput);
                printf("Hexadecimal: %s\n", hexOutput);
            }
            break;

        case 2: // Hexadecimal to Decimal
            {
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexInput);
                int decimalOutput = hexadecimalToDecimal(hexInput);
                printf("Decimal: %d\n", decimalOutput);
            }
            break;

        case 3: // Exit
            printf("Exiting the program. Goodbye!\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}