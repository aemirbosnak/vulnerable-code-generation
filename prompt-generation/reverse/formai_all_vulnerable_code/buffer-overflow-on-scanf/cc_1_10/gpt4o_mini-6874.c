//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

void convertToBinary(int number, char *binaryArray) {
    int index = 0;
    
    // Handle the case when number is zero
    if (number == 0) {
        binaryArray[index++] = '0';
    } else {
        while (number > 0) {
            binaryArray[index++] = (number % 2) + '0';
            number = number / 2;
        }
    }

    // Reverse the binary array
    binaryArray[index] = '\0'; // Null-terminate the string
    for (int i = 0; i < index / 2; i++) {
        char temp = binaryArray[i];
        binaryArray[i] = binaryArray[index - i - 1];
        binaryArray[index - i - 1] = temp;
    }
}

void displayBinaryRepresentation(char *binaryArray) {
    printf("Binary Representation: %s\n", binaryArray);
}

void interactiveBinaryConverter() {
    int userInput;
    char binaryArray[32]; // Enough to hold the binary representation of int (32 bits)

    printf("Welcome to the Visionary Binary Converter!\n");
    printf("Enter a decimal number (positive integer) to convert it to binary: ");

    while (scanf("%d", &userInput) == 1) {
        if (userInput < 0) {
            printf("Please enter a non-negative integer only. Try again: ");
            continue;
        }

        // Convert decimal to binary
        convertToBinary(userInput, binaryArray);
        
        // Display the binary representation
        displayBinaryRepresentation(binaryArray);
        
        printf("Enter another decimal number to continue or a negative number to exit: ");
    }

    printf("Exiting the Visionary Binary Converter. Goodbye!\n");
}

int main() {
    interactiveBinaryConverter();
    return 0;
}