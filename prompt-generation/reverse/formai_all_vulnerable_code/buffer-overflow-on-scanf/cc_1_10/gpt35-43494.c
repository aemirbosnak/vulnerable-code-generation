//FormAI DATASET v1.0 Category: Binary Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {

    int input;
    char binary[33]; // 32 bits for binary digits + 1 bit for null terminator 

    printf("Welcome to the C Binary Converter program! \n\n");
    printf("Please enter a decimal number to convert to binary: ");
    scanf("%d", &input);

    // check for negative input 
    if (input < 0) {
        printf("Sorry, this program only accepts positive decimal numbers. Please try again. \n");
        return 0;
    }

    // convert input to binary 
    int quotient = input;
    int index = 0;

    while (quotient != 0) {
        int remainder = quotient % 2;
        quotient /= 2; 
        binary[index++] = remainder + '0'; // add to binary array 
    }

    // add leading zeros if necessary 
    while (index < 32) {
        binary[index++] = '0';
    }

    // null terminator 
    binary[index] = '\0';

    // reverse the binary array 
    char reversed[33];
    int i, j;
    for (i = 0, j = index - 1; j >= 0; i++, j--) {
        reversed[i] = binary[j];
    }
    reversed[i] = '\0';

    printf("\nDecimal  : %d\nBinary   : %s\n", input, reversed);

    // end of program 
    printf("\nThank you for using the C Binary Converter program! Goodbye. \n");
    return 0;
}