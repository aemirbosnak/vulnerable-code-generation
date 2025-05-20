//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: ephemeral
#include <stdio.h>

// Function to convert a decimal number to its hexadecimal equivalent
void decimalToHexadecimal(int decimalNumber) {
    int remainder, hexadecimal = 0;
    
    // Perform division and remainder operations to get the hexadecimal equivalent
    while (decimalNumber > 0) {
        remainder = decimalNumber % 16;
        decimalNumber = decimalNumber / 16;
        
        if (remainder < 10) {
            hexadecimal = hexadecimal * 16 + remainder;
        }
        else {
            hexadecimal = hexadecimal * 16 + 'A' + (remainder - 10);
        }
    }
    
    // Print the hexadecimal equivalent
    printf("%d in hexadecimal is %X\n", decimalNumber, hexadecimal);
}

// Function to convert a hexadecimal number to its decimal equivalent
void hexadecimalToDecimal(char* hexadecimalNumber) {
    int decimal = 0;
    int i = 0;
    int power = 0;
    
    // Iterate through the hexadecimal number and calculate its decimal equivalent
    while (i < 4) {
        power = 4 * power;
        decimal = decimal + (hexadecimalNumber[i] - '0') * power;
        i++;
    }
    
    // Print the decimal equivalent
    printf("%s in decimal is %d\n", hexadecimalNumber, decimal);
}

// Main function
int main() {
    int decimalNumber = 0;
    char* hexadecimalNumber = "A";
    
    // Prompt the user to enter a decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);
    
    // Convert the decimal number to its hexadecimal equivalent
    decimalToHexadecimal(decimalNumber);
    
    // Prompt the user to enter a hexadecimal number
    printf("Enter a hexadecimal number: ");
    scanf("%s", hexadecimalNumber);
    
    // Convert the hexadecimal number to its decimal equivalent
    hexadecimalToDecimal(hexadecimalNumber);
    
    return 0;
}