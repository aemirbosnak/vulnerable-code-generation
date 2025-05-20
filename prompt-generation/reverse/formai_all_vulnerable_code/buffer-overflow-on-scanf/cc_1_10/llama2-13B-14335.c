//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define BINARY_DIGITS 8
#define MAX_INPUT_LENGTH 1024

// Function to convert decimal to binary
void decimalToBinary(int num, char *binary) {
    int i = 0;
    while (num != 0) {
        binary[i++] = num % 2 == 0 ? '0' : '1';
        num /= 2;
    }
    binary[i] = '\0';
}

// Function to convert binary to decimal
int binaryToDecimal(char binary[MAX_INPUT_LENGTH]) {
    int num = 0;
    for (int i = 0; i < strlen(binary); i++) {
        if (binary[i] == '1') {
            num *= 2;
            num += (int)pow(2, i);
        }
    }
    return num;
}

int main() {
    // Declare input and output variables
    int num, input[MAX_INPUT_LENGTH];
    char binary[MAX_INPUT_LENGTH];

    // Ask user for input
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    // Convert decimal to binary
    decimalToBinary(num, binary);

    // Print binary representation
    printf("Binary representation of %d: %s\n", num, binary);

    // Ask user for input again
    printf("Enter another decimal number: ");

    // Convert binary to decimal
    char binary2[MAX_INPUT_LENGTH];
    decimalToBinary(num, binary2);
    int result = binaryToDecimal(binary2);

    // Print result
    printf("Decimal representation of %s: %d\n", binary2, result);

    return 0;
}