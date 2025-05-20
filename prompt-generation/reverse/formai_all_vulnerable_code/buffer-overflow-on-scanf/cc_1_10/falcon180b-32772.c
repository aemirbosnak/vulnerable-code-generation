//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert binary to decimal
int binToDec(char* binary) {
    int decimal = 0, power = 0;
    for (int i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

// Function to convert decimal to binary
void decToBin(int decimal, char* binary) {
    int temp = decimal;
    int power = 0;
    while (temp > 0) {
        if (temp % 2 == 1) {
            strcat(binary, "1");
        } else {
            strcat(binary, "0");
        }
        temp /= 2;
        power++;
    }
    for (int i = power - 1; i >= 0; i--) {
        strcat(binary, "0");
    }
    strcat(binary, "\0");
}

// Function to validate binary input
int isBinary(char* binary) {
    for (int i = 0; i < strlen(binary); i++) {
        if (binary[i]!= '0' && binary[i]!= '1') {
            return 0;
        }
    }
    return 1;
}

int main() {
    // Prompt user for input
    char binary[100];
    printf("Enter a binary number: ");
    scanf("%s", binary);

    // Validate binary input
    if (!isBinary(binary)) {
        printf("Invalid binary input.\n");
        return 1;
    }

    // Convert binary to decimal
    int decimal = binToDec(binary);

    // Convert decimal to binary
    char decBinary[100];
    decToBin(decimal, decBinary);

    // Print results
    printf("Binary: %s\nDecimal: %d\n", binary, decimal);
    printf("Decimal to binary: %s\n", decBinary);

    return 0;
}