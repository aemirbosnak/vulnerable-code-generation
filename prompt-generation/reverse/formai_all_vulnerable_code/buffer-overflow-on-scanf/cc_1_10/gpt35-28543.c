//FormAI DATASET v1.0 Category: Binary Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert decimal to binary
void decimalToBinary(int decimalNumber) {
    // Initialize binary array to store binary digits
    int binaryArray[32];
    // Initialize index for binary array
    int index = 0;

    // Convert decimal to binary
    while(decimalNumber > 0) {
        binaryArray[index++] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
    }

    // Print binary digits in reverse order
    for(int i = index - 1; i >= 0; i--) {
        printf("%d", binaryArray[i]);
    }
    printf("\n");
}

// Function to convert binary to decimal
void binaryToDecimal(char binaryNumber[]) {
    // Initialize decimalNumber to store decimal value
    int decimalNumber = 0;
    // Initialize power to calculate decimal value
    int power = 0;

    // Convert binary to decimal
    for(int i = strlen(binaryNumber) - 1; i >= 0; i--) {
        if(binaryNumber[i] == '1') {
            decimalNumber += pow(2, power);
        }
        power++;
    }

    printf("%d\n", decimalNumber);
}

int main() {
    // Initialize input values
    int decimalNumber;
    char binaryNumber[32];

    // Prompt user for input type
    printf("Enter input type (1 for decimal, 2 for binary): ");
    int inputType;
    scanf("%d", &inputType);

    // Perform conversion based on input type
    if(inputType == 1) {
        printf("Enter decimal number: ");
        scanf("%d", &decimalNumber);
        printf("Binary conversion: ");
        decimalToBinary(decimalNumber);
    } else if(inputType == 2) {
        printf("Enter binary number: ");
        scanf("%s", binaryNumber);
        printf("Decimal conversion: ");
        binaryToDecimal(binaryNumber);
    } else {
        printf("Invalid input type\n");
    }

    return 0;
}