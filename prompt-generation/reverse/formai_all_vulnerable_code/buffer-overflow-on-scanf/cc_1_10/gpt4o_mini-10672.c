//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decimalToBinary(int n, char *binaryStr) {
    int index = 0; // Keeps track of position in binaryStr
    if(n == 0) {
        strcpy(binaryStr, "0");
        return;
    }
    while (n > 0) {
        binaryStr[index++] = (n % 2) + '0'; // Store binary digit
        n = n / 2; // Shift to right
    }
    binaryStr[index] = '\0'; // Null-terminate the string
    
    // Reverse the string
    for(int i = 0; i < index / 2; i++) {
        char temp = binaryStr[i];
        binaryStr[i] = binaryStr[index - i - 1];
        binaryStr[index - i - 1] = temp;
    }
}

// Function to print with shapes
void printWithShapes(const char *binaryStr) {
    int length = strlen(binaryStr);
    printf("\nConverting to Binary:\n");
    
    printf(" ________ \n");
    printf("|        |\n");
    printf("|  Binary|  %s\n", binaryStr);
    printf("|________|\n");

    // Shape-shifting effect
    for (int i = 0; i < length; i++) {
        char output[50];
        sprintf(output, "| Bit %d  |  %s", i + 1, binaryStr[i] == '1' ? "On" : "Off");
        printf("%s\n", output);
    }
    
    printf("¯¯¯¯¯¯¯¯¯¯¯¯\n");
}

int main() {
    int decimalNumber;
    
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Error handling for negative input
    if (decimalNumber < 0) {
        printf("Please enter a non-negative integer.\n");
        return EXIT_FAILURE;
    }

    char binaryStr[32]; // Enough to hold a 32-bit binary representation
    decimalToBinary(decimalNumber, binaryStr);
    printWithShapes(binaryStr);

    return EXIT_SUCCESS;
}