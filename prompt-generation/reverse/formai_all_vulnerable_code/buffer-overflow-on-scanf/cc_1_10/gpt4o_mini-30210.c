//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert an integer to hexadecimal string
void intToHex(int num, char *hexStr) {
    sprintf(hexStr, "%X", num);
}

// Function to convert hexadecimal string to integer
int hexToInt(const char *hexStr) {
    return (int) strtol(hexStr, NULL, 16);
}

// Function to display menu options to the user
void displayMenu() {
    printf("Hexadecimal Converter\n");
    printf("=====================\n");
    printf("1. Convert Integer to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Integer\n");
    printf("3. Exit\n");
    printf("\nPlease select an option (1-3): ");
}

// Function to handle the integer to hexadecimal conversion
void convertIntToHex() {
    int number;
    char hexString[20];

    printf("Enter an integer: ");
    scanf("%d", &number);

    intToHex(number, hexString);
    printf("The hexadecimal representation of %d is: %s\n", number, hexString);
}

// Function to handle the hexadecimal to integer conversion
void convertHexToInt() {
    char hexString[20];
    int number;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hexString);

    number = hexToInt(hexString);
    printf("The integer representation of %s is: %d\n", hexString, number);
}

// Main function to control the program flow
int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convertIntToHex();
                break;
            case 2:
                convertHexToInt();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}