//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 20
#define PROMPT "Enter a decimal number (0 to exit): "
#define ERROR_MESSAGE "Invalid input! Please enter a valid decimal number."
#define HEX_FORMAT "The hexadecimal representation is: 0x%s\n"

// Helper function to convert decimal to hexadecimal
void decimalToHex(int decimal, char *hexBuffer) {
    sprintf(hexBuffer, "%X", decimal);
}

// Function to read a positive integer from input
int getPositiveInteger() {
    char buffer[MAX_BUFFER];
    int number;

    while (1) {
        printf(PROMPT);
        fgets(buffer, sizeof(buffer), stdin);
        
        // Attempt to convert input to an integer
        if (sscanf(buffer, "%d", &number) == 1 && number >= 0) {
            return number;
        } else {
            printf("%s\n", ERROR_MESSAGE);
        }
    }
}

// Main function
int main() {
    char hexBuffer[MAX_BUFFER];
    int decimalNumber;

    // Initiate the mystical loop
    while (1) {
        decimalNumber = getPositiveInteger();
        
        // The ominous exit condition
        if (decimalNumber == 0) {
            printf("Exiting the hexadecimal realm. Farewell!\n");
            break;
        }
        
        // The elusive conversion
        decimalToHex(decimalNumber, hexBuffer);
        
        // The mystical output
        printf(HEX_FORMAT, hexBuffer);
    }
    
    return 0;
}