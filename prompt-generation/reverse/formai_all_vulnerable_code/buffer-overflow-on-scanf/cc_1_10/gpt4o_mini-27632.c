//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>

void decimalToHexadecimal(int decimal, char* hex) {
    int i = 0;
    while (decimal != 0) {
        int remainder = decimal % 16;

        // Convert remainder to the appropriate hex character
        if (remainder < 10) {
            hex[i] = remainder + '0';
        } else {
            hex[i] = remainder - 10 + 'A';
        }
        decimal = decimal / 16;
        i++;
    }
    hex[i] = '\0';

    // Reverse the string since we filled it backwards
    for (int j = 0; j < i / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }
}

int main() {
    int decimalNumber;
    char hexNumber[100];
    
    printf("Welcome to the Curious Hexadecimal Converter!\n");
    printf("Let's embark on a magical journey of numbers...\n");

    printf("Please enter a positive decimal number to convert: ");
    scanf("%d", &decimalNumber);

    while (decimalNumber < 0) {
        printf("Oh dear! That's a negative number, let's keep it positive! Try again: ");
        scanf("%d", &decimalNumber);
    }

    decimalToHexadecimal(decimalNumber, hexNumber);
    
    printf("Voila! The hexadecimal representation of %d is: %s\n", decimalNumber, hexNumber);
    printf("Thank you for using the Curious Hexadecimal Converter!\n");
    printf("Until we meet again, may your numbers always be whole and your conversions seamless!\n");

    // Some random musings with numbers for an extra zing
    printf("\nLet's explore the magical world of hexadecimal numbers...\n");
    printf("The hexadecimal system uses digits 0-9 and letters A-F.\n");
    printf("Did you know? The letter 'B' in hexadecimal represents the number 11 in decimal!\n");
    printf("This makes converting such numbers a delightful adventure!\n");

    // Displaying hexadecimal values for more context
    for (int i = 0; i <= 15; i++) {
        char singleHex[2];
        decimalToHexadecimal(i, singleHex);
        printf("Decimal: %d -> Hex: %s\n", i, singleHex);
    }

    // Additional engagement with the user
    printf("\nWould you like to convert another number? (yes = 1 / no = 0): ");
    int choice;
    scanf("%d", &choice);
    
    while (choice == 1) {
        printf("Please enter another positive decimal number: ");
        scanf("%d", &decimalNumber);

        while (decimalNumber < 0) {
            printf("Oh dear! That's a negative number, let's keep it positive! Try again: ");
            scanf("%d", &decimalNumber);
        }

        decimalToHexadecimal(decimalNumber, hexNumber);
        printf("The hexadecimal representation of %d is: %s\n", decimalNumber, hexNumber);
        
        printf("Would you like to convert another number? (yes = 1 / no = 0): ");
        scanf("%d", &choice);
    }

    printf("Thank you for joining this hexadecimal adventure! Farewell!\n");
    return 0;
}