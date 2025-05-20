//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 100
#define MAX_NUMBER_OF_CONVERTIONS 10

// Function to convert binary to decimal
int binaryToDec(char binary[]) {
    int i, result = 0;
    for (i = 0; i < strlen(binary); i++) {
        result += (binary[i] - '0') * pow(2, strlen(binary) - i - 1);
    }
    return result;
}

// Function to convert decimal to binary
int decimalToBinary(int dec) {
    int i, binary[MAX_INPUT_LENGTH];
    for (i = 0; dec != 0; i++) {
        binary[i] = dec % 2 == 0 ? '0' : '1';
        dec /= 2;
    }
    return binary;
}

// Function to print the conversion
void printConversion(char binary[], int dec) {
    printf("Binary: %s\nDecimal: %d\n", binary, dec);
}

int main() {
    int numToConvert, convertedNum;
    char binary[MAX_INPUT_LENGTH];

    // Prompt user for number to convert
    printf("Enter a number to convert (0-99): ");
    scanf("%d", &numToConvert);

    // Convert number to binary
    convertedNum = binaryToDec(binary);

    // Convert number to decimal
    int dec = decimalToBinary(convertedNum);

    // Print the conversion
    printConversion(binary, dec);

    // Ask user if they want to convert again
    printf("Do you want to convert again? (y/n): ");
    char input;
    scanf(" %c", &input);

    // If user wants to convert again, repeat the process
    if (input == 'y' || input == 'Y') {
        printf("Enter a number to convert (0-99): ");
        scanf("%d", &numToConvert);
        convertedNum = binaryToDec(binary);
        dec = decimalToBinary(convertedNum);
        printConversion(binary, dec);
    }

    return 0;
}