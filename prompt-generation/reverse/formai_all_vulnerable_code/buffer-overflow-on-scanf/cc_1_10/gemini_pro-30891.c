//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
char *decimalToBinary(int n) {
    int binaryNum[1000];

    // Counter for binary array
    int i = 0;
    while (n > 0) {

        // Storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // Reversing the binary array
    char *binary = (char *)malloc(i + 1);
    int j = 0;
    while (i >= 0) {
        binary[j++] = binaryNum[i--] + '0';
    }

    binary[j] = '\0';

    return binary;
}

// Function to convert binary to decimal
int binaryToDecimal(char *binary) {
    int decimal = 0;
    int base = 1;
    int len = strlen(binary);

    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }

    return decimal;
}

// Driver code
int main() {
    // Decimal number to be converted
    int decimalNum;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);

    // Converting decimal to binary
    char *binary = decimalToBinary(decimalNum);
    printf("Binary representation: %s\n", binary);

    // Converting binary to decimal
    int decimal = binaryToDecimal(binary);
    printf("Decimal representation: %d\n", decimal);

    return 0;
}