//FormAI DATASET v1.0 Category: Binary Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* decimalToBinary(unsigned int decimalNumber) {
    // create a char array to hold the binary number
    char* binaryNumber = (char*) malloc(sizeof(char) * 33);
    // set all bits to 0
    memset(binaryNumber, '0', 33);

    int i = 0;
    while (decimalNumber > 0 || i < 32) {
        // perform division by 2 to get the remainder
        binaryNumber[i++] = (decimalNumber % 2) + '0';
        decimalNumber /= 2;
    }

    // reverse the binary number
    int j = strlen(binaryNumber) - 1;
    i = 0;
    while (i < j) {
        char tmp = binaryNumber[i];
        binaryNumber[i] = binaryNumber[j];
        binaryNumber[j] = tmp;
        i++;
        j--;
    }

    // null terminate the string
    binaryNumber[strlen(binaryNumber)] = '\0';

    return binaryNumber;
}

unsigned int binaryToDecimal(char* binaryNumber) {
    // initialize the decimal number to 0
    unsigned int decimalNumber = 0;
    int power = 0;
    int length = strlen(binaryNumber);

    // iterate through the binary number from right to left
    for (int i = length - 1; i >= 0; i--) {
        if (binaryNumber[i] == '1') {
            // add the corresponding power of 2 to the decimal number
            decimalNumber += (unsigned int) pow(2, power);
        }
        power++;
    }

    return decimalNumber;
}

int main() {
    printf("\nEnter a decimal number: ");
    unsigned int decimalNumber;
    scanf("%d", &decimalNumber);

    char* binaryNumber = decimalToBinary(decimalNumber);
    printf("\nBinary conversion: %s", binaryNumber);

    printf("\nEnter a binary number: ");
    char binaryString[33];
    scanf("%s", binaryString);

    unsigned int decimalValue = binaryToDecimal(binaryString);
    printf("\nDecimal conversion: %u", decimalValue);

    return 0;
}