//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define HEX_STRING_MAX_LEN 16

// Function Prototypes
void printMenu();
int getIntegerInput();
void intToHex(int value, char *hexString);
void hexToInt(const char *hexString, int *value);
int isValidHex(const char *hexString);
void clearBuffer();

int main() {
    int choice;
    char hexString[HEX_STRING_MAX_LEN + 1];
    int decimalValue;

    do {
        printMenu();
        choice = getIntegerInput();

        switch (choice) {
            case 1:
                printf("Enter an integer to convert to hexadecimal: ");
                decimalValue = getIntegerInput();
                char hexOutput[HEX_STRING_MAX_LEN + 1];
                intToHex(decimalValue, hexOutput);
                printf("Hexadecimal: %s\n", hexOutput);
                break;
            
            case 2:
                printf("Enter a hexadecimal number (max %d characters): ", HEX_STRING_MAX_LEN);
                scanf("%s", hexString);

                if (isValidHex(hexString)) {
                    hexToInt(hexString, &decimalValue);
                    printf("Decimal: %d\n", decimalValue);
                } else {
                    printf("Invalid hexadecimal number.\n");
                }
                clearBuffer();
                break;

            case 0:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter only 0, 1, or 2.\n");
        }
        
    } while (choice != 0);

    return 0;
}

void printMenu() {
    printf("\nHexadecimal Converter Menu:\n");
    printf("1. Convert Integer to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Integer\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}

int getIntegerInput() {
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);

    // Validate input to prevent integer overflow and ensure valid integer
    char *endptr;
    long inputValue = strtol(buffer, &endptr, 10);

    if (endptr == buffer || *endptr != '\n' || inputValue < INT_MIN || inputValue > INT_MAX) {
        fprintf(stderr, "Invalid input. Please enter a valid integer.\n");
        return 0;
    }

    return (int)inputValue;
}

void intToHex(int value, char *hexString) {
    snprintf(hexString, HEX_STRING_MAX_LEN + 1, "%X", value);
}

void hexToInt(const char *hexString, int *value) {
    *value = (int) strtol(hexString, NULL, 16);
}

int isValidHex(const char *hexString) {
    // Check if the input string is valid hexadecimal
    for (int i = 0; hexString[i] != '\0'; i++) {
        if (!((hexString[i] >= '0' && hexString[i] <= '9') ||
              (hexString[i] >= 'A' && hexString[i] <= 'F') ||
              (hexString[i] >= 'a' && hexString[i] <= 'f'))) {
            return 0;
        }
    }
    return 1;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}