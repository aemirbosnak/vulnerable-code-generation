//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: mathematical
#include <stdio.h>

void decimalToHexadecimal(int decimal, char *hexadecimal) {
    // Create an array to hold the hexadecimal values
    char hexChars[] = "0123456789ABCDEF";
    int remainder, index = 0;
    
    // Process the number until it becomes 0
    while (decimal != 0) {
        // Get the remainder when dividing by 16
        remainder = decimal % 16;
        // Convert the remainder to its respective hexadecimal character
        hexadecimal[index++] = hexChars[remainder];
        // Reduce the decimal number
        decimal = decimal / 16;
    }

    // Reverse the string to get the correct hexadecimal representation
    hexadecimal[index] = '\0'; // Null-terminate the string
    for (int i = 0; i < index / 2; i++) {
        char temp = hexadecimal[i];
        hexadecimal[i] = hexadecimal[index - i - 1];
        hexadecimal[index - i - 1] = temp;
    }
}

int main() {
    int decimalNumber;
    char hexadecimal[20]; // Array to store the hexadecimal string

    // Request input from the user
    printf("Enter a decimal number to convert to hexadecimal: ");
    scanf("%d", &decimalNumber);

    // Check for a non-negative value
    if (decimalNumber < 0) {
        printf("Please enter a non-negative number.\n");
        return 1;
    }

    // Convert the decimal number to hexadecimal
    decimalToHexadecimal(decimalNumber, hexadecimal);
    
    // Display the result
    printf("The hexadecimal representation of %d is: %s\n", decimalNumber, hexadecimal);
    
    // Optionally continue converting more numbers
    char continueConversion = 'y';
    while (continueConversion == 'y' || continueConversion == 'Y') {
        printf("Enter another decimal number to convert to hexadecimal: ");
        scanf("%d", &decimalNumber);

        if (decimalNumber < 0) {
            printf("Please enter a non-negative number.\n");
        } else {
            decimalToHexadecimal(decimalNumber, hexadecimal);
            printf("The hexadecimal representation of %d is: %s\n", decimalNumber, hexadecimal);
        }

        printf("Do you want to convert another number? (y/n): ");
        scanf(" %c", &continueConversion);
    }

    printf("Thank you for using the Decimal to Hexadecimal Converter!\n");
    return 0;
}