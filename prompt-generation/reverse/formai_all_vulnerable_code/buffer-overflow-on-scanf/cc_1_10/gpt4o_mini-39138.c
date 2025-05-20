//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

// Function to convert decimal to hexadecimal
void decimalToHex(int decimal, char *hexBuffer) {
    sprintf(hexBuffer, "0x%X", decimal);
}

// Function to convert hexadecimal to decimal
int hexToDecimal(const char *hexString) {
    int decimal;
    sscanf(hexString, "%x", &decimal);
    return decimal;
}

// Function to get user input
void getInput(char *inputBuffer) {
    printf("Enter a number (Decimal or Hexadecimal): ");
    fgets(inputBuffer, BUFFER_SIZE, stdin);
    inputBuffer[strcspn(inputBuffer, "\n")] = 0; // Remove newline character
}

// Function to display the introduction in a Cyberpunk style
void displayIntroduction() {
    printf("========================================\n");
    printf("        Cyberspace Hexagon Converter     \n");
    printf("         Neon Dreams and Shadows         \n");
    printf("========================================\n");
}

void displayMenu() {
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("Select your option: ");
}

// Function to check if the input string is hexadecimal
int isHexadecimal(const char *input) {
    if (input[0] == '0' && (input[1] == 'x' || input[1] == 'X')) {
        input += 2; // Skip '0x' prefix
    }
    while (*input) {
        if (!((*input >= '0' && *input <= '9') ||
               (*input >= 'a' && *input <= 'f') ||
               (*input >= 'A' && *input <= 'F'))) {
            return 0; // Not a valid hex digit
        }
        input++;
    }
    return 1; // Valid hexadecimal
}

int main() {
    char inputBuffer[BUFFER_SIZE];
    char hexBuffer[BUFFER_SIZE];
    int decimalValue;

    displayIntroduction();

    while (1) {
        displayMenu();
        int option;
        scanf("%d", &option);
        getchar(); // Clear newline character from input buffer

        switch (option) {
            case 1: // Decimal to Hexadecimal
                getInput(inputBuffer);
                decimalValue = atoi(inputBuffer);
                decimalToHex(decimalValue, hexBuffer);
                printf("Decimal: %d => Hexadecimal: %s\n", decimalValue, hexBuffer);
                break;

            case 2: // Hexadecimal to Decimal
                getInput(inputBuffer);
                if (isHexadecimal(inputBuffer)) {
                    decimalValue = hexToDecimal(inputBuffer);
                    printf("Hexadecimal: %s => Decimal: %d\n", inputBuffer, decimalValue);
                } else {
                    printf("Invalid Hexadecimal Input! Must start with '0x'.\n");
                }
                break;

            case 3: // Exit
                printf("Shutting down the neon lights... Until next time!\n");
                exit(0);

            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}