//FormAI DATASET v1.0 Category: Binary Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char* decimalToBinary(int num)
{
    int binary[32];
    int idx = 0;

    // convert decimal to binary
    while (num > 0) {
        binary[idx++] = num % 2;
        num /= 2;
    }

    // convert array to string
    char* binaryStr = (char*) malloc(33 * sizeof(char));
    int i;

    for (i = 0; i < idx; i++) {
        binaryStr[i] = (char) (binary[idx - i - 1] + '0');
    }

    binaryStr[i] = '\0';

    return binaryStr;
}

int binaryToDecimal(char* binaryStr)
{
    int decimal = 0;
    int binaryLen = strlen(binaryStr);
    int idx = 0;

    // loop through the binary string and calculate decimal value
    while (idx < binaryLen) {
        int bit = binaryStr[idx] - '0';
        decimal += bit * pow(2, binaryLen - idx - 1);
        idx++;
    }

    return decimal;
}

int main()
{
    int convertChoice, inputNum;
    char* inputBinary;

    printf("Binary Converter:\n");
    printf("1. Decimal to Binary\n2. Binary to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &convertChoice);

    if (convertChoice == 1) {
        printf("Enter a decimal number: ");
        scanf("%d", &inputNum);

        char* binaryStr = decimalToBinary(inputNum);
        printf("Binary conversion of %d is %s\n", inputNum, binaryStr);
        free(binaryStr);

    } else if (convertChoice == 2) {
        printf("Enter a binary number: ");
        scanf("%s", inputBinary);

        int decimal = binaryToDecimal(inputBinary);
        printf("Decimal conversion of %s is %d\n", inputBinary, decimal);

    } else {
        printf("Invalid choice. Please enter 1 or 2.\n");
    }

    return 0;
}