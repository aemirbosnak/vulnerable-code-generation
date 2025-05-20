//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to hexadecimal
void decToHex(int decimal, char *hex) {
    int i = 0;
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[i] = remainder + '0';
        } else {
            hex[i] = (remainder - 10) + 'A';
        }
        decimal /= 16;
        i++;
    }
    hex[i] = '\0';
    
    // Helper for reversal (because we start from the least-significant digit)
    for (int j = 0; j < i / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }
}

// Embark on the "Decimal to Hexadecimal Adventure"
int main() {
    int decimalNumber;
    char hex[20];  // Buffer for hex representation (No dragon here!)

    printf("Welcome to the Decimal to Hexadecimal Adventure!\n");
    printf("Please enter a decimal number (or a treasure to uncover): ");
    
    // Reading user's input and getting ready for the conversion magic
    if (scanf("%d", &decimalNumber) != 1) {
        printf("Oops! You conjured an invalid number! ABRACADABRA!\n");
        return 1;
    }

    // Converting the magical number
    decToHex(decimalNumber, hex);

    // Displaying the mystical result
    printf("Huzzah! The hexadecimal representation of %d is: 0x%s\n", decimalNumber, hex);
    
    // Beware the melodrama, as we bid goodbye!
    printf("And with that, we conclude this whimsical journey of numbers.\n");
    printf("May your codes compile smoothly, and your bugs be ever elusive!\n");
    printf("Remember: hexadecimal is just decimal dressed in its fanciest clothes.\n");

    // Go forth and parse, my fellow coding adventurer!
    return 0;
}