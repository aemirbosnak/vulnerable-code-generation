//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: Cyberpunk
#include <stdio.h>

// Neon City Hexadecimal Converter

// Welcome message
void neonCityWelcome() {
    printf("\nWelcome to Neon City, runner! This is your one-stop shop for converting those cryptic hex codes.\n");
}

// Get user input
void getUserInput(char *hexString) {
    printf("Input your hexadecimal number (without the leading '0x'): ");
    scanf("%s", hexString);
}

// Convert hex to decimal
int hexToDecimal(char hexString[]) {
    int decimal = 0;
    int length = strlen(hexString);
    for (int i = 0; i < length; i++) {
        int digit;
        if (hexString[i] >= '0' && hexString[i] <= '9') {
            digit = hexString[i] - '0';
        } else if (hexString[i] >= 'A' && hexString[i] <= 'F') {
            digit = hexString[i] - 'A' + 10;
        } else if (hexString[i] >= 'a' && hexString[i] <= 'f') {
            digit = hexString[i] - 'a' + 10;
        } else {
            printf("Invalid hex digit: %c\n", hexString[i]);
            return -1;
        }
        decimal += digit * pow(16, length - i - 1);
    }
    return decimal;
}

// Display the result
void displayResult(int decimal) {
    printf("\nConverted decimal: %d\n", decimal);
}

// Main function
int main() {
    // Set up the cyberpunk aesthetic
    printf("\n=================================================\n");
    printf("  _.-'''`-..                                    _.-'''`-._\n");
    printf(" /           \\                                  /           \\\n");
    printf("|             |          NEON CITY           |             |\n");
    printf(" \\           /                                  \\           /\n");
    printf("  `-._       .-'                                  `-._       .-'\n");
    printf("      `---''                                        `---''\n");
    printf("==================================================\n\n");

    // Welcome the user
    neonCityWelcome();

    // Get the hex string from the user
    char hexString[100];
    getUserInput(hexString);

    // Convert the hex string to decimal
    int decimal = hexToDecimal(hexString);

    if (decimal != -1) {
        // Display the result
        displayResult(decimal);
    }

    return 0;
}