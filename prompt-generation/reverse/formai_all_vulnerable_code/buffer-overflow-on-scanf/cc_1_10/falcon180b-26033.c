//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to convert binary to decimal
int binary_to_decimal(char* binary) {
    int decimal = 0;
    int power = 0;
    int length = strlen(binary);

    // iterate through the binary string from right to left
    for (int i = length - 1; i >= 0; i--) {
        char c = binary[i];

        // check if the character is a valid binary digit
        if (c!= '0' && c!= '1') {
            printf("Invalid binary string.\n");
            return -1;
        }

        // convert the binary digit to decimal and add it to the total
        decimal += (c - '0') * pow(2, power);

        // increment the power for the next digit
        power++;
    }

    return decimal;
}

// function to convert decimal to binary
void decimal_to_binary(int decimal) {
    char binary[33];
    int index = 0;

    // iterate until the decimal becomes zero
    while (decimal > 0) {
        // get the remainder when dividing by 2
        int remainder = decimal % 2;

        // add the remainder to the binary string
        binary[index++] = remainder + '0';

        // divide the decimal by 2
        decimal /= 2;
    }

    // reverse the binary string
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - 1 - i];
        binary[index - 1 - i] = temp;
    }

    // print the binary string
    printf("Binary: %s\n", binary);
}

int main() {
    char input[100];
    printf("Enter a binary string: ");
    scanf("%s", input);

    // convert binary to decimal
    int decimal = binary_to_decimal(input);
    if (decimal == -1) {
        return 1;
    }

    // convert decimal to binary
    decimal_to_binary(decimal);

    return 0;
}