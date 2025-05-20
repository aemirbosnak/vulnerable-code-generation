//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to hexadecimal
void decimalToHexadecimal(int decimal, char *hexadecimal) {
    int index = 0;
    
    // Handle the case of decimal 0
    if (decimal == 0) {
        hexadecimal[index++] = '0';
    } else {
        while (decimal > 0) {
            int remainder = decimal % 16;
            // Convert remainder to a character
            if (remainder < 10) {
                hexadecimal[index++] = remainder + '0';
            } else {
                hexadecimal[index++] = (remainder - 10) + 'A'; // For A-F
            }
            decimal /= 16;
        }
    }
    
    // Reverse the hexadecimal string since we've built it backwards
    hexadecimal[index] = '\0'; // Null terminate the string
    for (int i = 0; i < index / 2; i++) {
        char temp = hexadecimal[i];
        hexadecimal[i] = hexadecimal[index - i - 1];
        hexadecimal[index - i - 1] = temp;
    }
}

// Function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int decimalNumber;
    char hexadecimal[100];

    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    
    while (1) {
        printf("Please enter a decimal number (0 to exit): ");
        // Checking input validity
        if (scanf("%d", &decimalNumber) != 1) {
            printf("Invalid input! Please enter a valid integer.\n");
            clearInputBuffer(); // Clear the buffer for wrong input
            continue; // Prompt for input again
        }

        if (decimalNumber == 0) {
            printf("Exiting the program. Goodbye!\n");
            break; // Exit condition
        }

        // Conversion
        decimalToHexadecimal(decimalNumber, hexadecimal);
        
        // Display the result
        printf("Decimal Number: %d -> Hexadecimal: %s\n", decimalNumber, hexadecimal);
    }
    
    return 0;
}