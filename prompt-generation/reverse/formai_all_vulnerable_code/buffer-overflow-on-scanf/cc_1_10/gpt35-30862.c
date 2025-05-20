//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a decimal number to hexadecimal
char* decimalToHexadecimal(int decimalNum) {
    char* hexNum = malloc(sizeof(char)*100);   // Allocate memory for the hexadecimal number
    int i = 0;

    while(decimalNum != 0) {
        int remainder = decimalNum % 16;

        if(remainder < 10) {
            hexNum[i++] = remainder + 48;
        } else {
            hexNum[i++] = remainder + 55;
        }

        decimalNum /= 16;
    }

    char* hexNumReversed = malloc(sizeof(char)*100); // Allocate memory for the reversed hexadecimal number
    int j = 0;

    // Reverse the hexadecimal number
    for(int k = strlen(hexNum)-1; k >= 0; k--) {
        hexNumReversed[j++] = hexNum[k];
    }

    hexNumReversed[j] = '\0';

    return hexNumReversed;
}

// Function to convert a hexadecimal number to decimal
int hexadecimalToDecimal(char* hexNum) {
    int decimalNum = 0;

    for(int i = 0; i < strlen(hexNum); i++) {
        if(isdigit(hexNum[i])) {
            decimalNum = decimalNum * 16 + (hexNum[i] - '0');
        } else {
            decimalNum = decimalNum * 16 + (hexNum[i] - 'A' + 10);
        }
    }

    return decimalNum;
}

int main() {
    int menuChoice;
    char hexNum[100];
    int decimalNum;

    printf("Welcome to the Hexadecimal Converter Program!\n");

    do {
        // Display the menu options
        printf("\nPlease select an option:\n");
        printf("1. Convert Decimal to Hexadecimal\n");
        printf("2. Convert Hexadecimal to Decimal\n");
        printf("3. Quit\n");
        printf("Enter choice (1-3): ");

        // Get the user's menu choice
        scanf("%d", &menuChoice);

        switch(menuChoice) {
            case 1:
                // Convert decimal to hexadecimal
                printf("\nEnter a decimal number: ");
                scanf("%d", &decimalNum);

                printf("Hexadecimal equivalent: %s\n", decimalToHexadecimal(decimalNum));
                break;
            case 2:
                // Convert hexadecimal to decimal
                printf("\nEnter a hexadecimal number: ");
                scanf("%s", hexNum);

                printf("Decimal equivalent: %d\n", hexadecimalToDecimal(hexNum));
                break;
            case 3:
                // Quit the program
                printf("\nGoodbye!");
                break;
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 3.\n");
                break;
        }
    } while(menuChoice != 3);

    return 0;
}