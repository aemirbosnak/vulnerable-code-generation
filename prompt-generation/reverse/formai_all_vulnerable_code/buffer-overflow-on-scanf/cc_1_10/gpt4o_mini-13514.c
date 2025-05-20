//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void decimalToHexadecimal(int decimalNumber, char* hexadecimalString) {
    if (decimalNumber == 0) {
        strcpy(hexadecimalString, "0");
        return;
    }

    char temp[BUFFER_SIZE];
    int index = 0;
    
    while (decimalNumber > 0) {
        int remainder = decimalNumber % 16;

        if (remainder < 10) {
            temp[index++] = '0' + remainder;
        } else {
            temp[index++] = 'A' + (remainder - 10);
        }
        
        decimalNumber /= 16;
    }
    
    // Reverse the order of the hex digits
    for (int i = 0; i < index; i++) {
        hexadecimalString[i] = temp[index - i - 1];
    }
    hexadecimalString[index] = '\0'; // Null-terminate the string
}

void hexToDecimal(const char* hexadecimalString, int* decimalNumber) {
    *decimalNumber = 0;
    int length = strlen(hexadecimalString);
    
    for (int i = 0; i < length; i++) {
        char currentChar = hexadecimalString[i];
        if (currentChar >= '0' && currentChar <= '9') {
            *decimalNumber = (*decimalNumber << 4) | (currentChar - '0');
        } else if (currentChar >= 'A' && currentChar <= 'F') {
            *decimalNumber = (*decimalNumber << 4) | (currentChar - 'A' + 10);
        } else {
            fprintf(stderr, "Invalid hexadecimal character: %c\n", currentChar);
            exit(EXIT_FAILURE);
        }
    }
}

void displayMenu() {
    printf("Welcome to the Hexadecimal Converter!\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("Please select an option: ");
}

int main() {
    int choice;
    char hexString[BUFFER_SIZE];
    int decimalNumber;

    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1: {
                printf("Enter a decimal number: ");
                if (scanf("%d", &decimalNumber) != 1) {
                    fprintf(stderr, "Invalid input. Please enter a valid decimal number.\n");
                    while (getchar() != '\n'); // clear input buffer
                    continue;
                }

                char hexadecimalString[BUFFER_SIZE];
                decimalToHexadecimal(decimalNumber, hexadecimalString);
                printf("Hexadecimal Conversion: %d -> %s\n", decimalNumber, hexadecimalString);
                break;
            }

            case 2: {
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexString);
                hexToDecimal(hexString, &decimalNumber);
                printf("Decimal Conversion: %s -> %d\n", hexString, decimalNumber);
                break;
            }

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(EXIT_SUCCESS);

            default:
                fprintf(stderr, "Invalid choice. Please select a valid option.\n");
        }
    }

    return 0; // Though this line will never be reached
}