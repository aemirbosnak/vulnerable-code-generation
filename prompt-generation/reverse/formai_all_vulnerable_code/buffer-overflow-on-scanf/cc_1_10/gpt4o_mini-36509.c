//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: recursive
#include <stdio.h>

// Function prototype
void decimalToHex(int decimal);
void reverseString(char str[], int length);
void decimalToHexRecursive(int decimal, char hex[], int *index);

// Main function
int main() {
    int decimal;
    
    printf("Decimal to Hexadecimal Converter\n");
    printf("Please enter a decimal number (non-negative): ");
    
    // Read user input
    while (1) {
        scanf("%d", &decimal);
        if (decimal >= 0)
            break;
        printf("Invalid input, please enter a non-negative decimal number: ");
    }
    
    printf("The hexadecimal representation of %d is: ", decimal);
    decimalToHex(decimal);
    printf("\n");

    return 0;
}

// Function to convert decimal to hexadecimal using recursion
void decimalToHex(int decimal) {
    char hex[100];
    int index = 0;

    // Call the recursive function
    decimalToHexRecursive(decimal, hex, &index);
    
    // Null-terminate the string
    hex[index] = '\0';
    
    // Reverse the string to get the correct hexadecimal representation
    reverseString(hex, index);
    
    // Print the result
    printf("%s", hex);
}

// Recursive function to build the hexadecimal representation
void decimalToHexRecursive(int decimal, char hex[], int *index) {
    if (decimal == 0)
        return;
    
    // Store next digit (last digit of hex)
    int remainder = decimal % 16;

    // Convert to appropriate hex character
    if (remainder < 10)
        hex[(*index)++] = remainder + '0';
    else
        hex[(*index)++] = remainder - 10 + 'A';

    // Continue recursively with the quotient
    decimalToHexRecursive(decimal / 16, hex, index);
}

// Function to reverse a string in-place
void reverseString(char str[], int length) {
    int start = 0;
    int end = length - 1;
    
    while (start < end) {
        // Swap characters
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}