//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: interoperable
#include <stdio.h>

// Function prototypes
void getInput(int *number);
void decimalToHexadecimal(int number, char hex[]);
void displayHexadecimal(char hex[]);

int main() {
    int decimalNumber;
    char hexadecimal[20]; // Buffer to store the hexadecimal string

    // Get user input
    getInput(&decimalNumber);
    
    // Convert decimal to hexadecimal
    decimalToHexadecimal(decimalNumber, hexadecimal);
    
    // Display the result
    displayHexadecimal(hexadecimal);
    
    return 0;
}

// Function to get a decimal number from user
void getInput(int *number) {
    printf("Enter a decimal number: ");
    while (scanf("%d", number) != 1 || *number < 0) {
        printf("Invalid input. Please enter a non-negative integer: ");
        while(getchar() != '\n'); // Clear the input buffer
    }
}

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int number, char hex[]) {
    int index = 0;
    int remainder;

    // Edge case for 0
    if (number == 0) {
        hex[index++] = '0';
        hex[index] = '\0';
        return;
    }

    while (number != 0) {
        remainder = number % 16;
        
        // Convert remainder to hex character
        if (remainder < 10) {
            hex[index++] = remainder + '0'; // for 0-9
        } else {
            hex[index++] = (remainder - 10) + 'A'; // for A-F
        }
        number /= 16; // Reduce the number
    }
    
    hex[index] = '\0'; // Null-terminate the string

    // Reverse the string to get the correct hexadecimal representation
    for (int i = 0; i < index / 2; i++) {
        char temp = hex[i];
        hex[i] = hex[index - i - 1];
        hex[index - i - 1] = temp;
    }
}

// Function to display the hexadecimal string
void displayHexadecimal(char hex[]) {
    printf("Hexadecimal: %s\n", hex);
}