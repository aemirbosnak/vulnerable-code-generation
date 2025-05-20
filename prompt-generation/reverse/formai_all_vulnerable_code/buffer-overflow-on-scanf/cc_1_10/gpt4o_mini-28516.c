//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

void convertToBinary(int decimal, char *binary) {
    int index = 0;
    
    // Handling zero case explicitly
    if (decimal == 0) {
        binary[index++] = '0';
    } else {
        while (decimal > 0) {
            binary[index++] = (decimal % 2) + '0'; // Get remainder and convert to char
            decimal /= 2; // Divide decimal by 2
        }
    }
    
    binary[index] = '\0'; // Null-terminate the string
    
    // Reverse the binary string
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }
}

int main() {
    int decimal;
    char binary[32]; // Enough to hold binary representation of an int

    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("---------------------------------------------------\n");

    // Repeatedly ask for user input until they choose to exit
    while (1) {
        printf("Please enter a decimal number (negative number to exit): ");
        scanf("%d", &decimal);

        if (decimal < 0) {
            printf("Exiting the converter. Have a nice day!\n");
            break; // Exit on negative input
        }

        // Call the conversion function
        convertToBinary(decimal, binary);
        printf("The binary representation of %d is: %s\n", decimal, binary);
        printf("---------------------------------------------------\n");
    }

    return 0; // Exit program successfully
}