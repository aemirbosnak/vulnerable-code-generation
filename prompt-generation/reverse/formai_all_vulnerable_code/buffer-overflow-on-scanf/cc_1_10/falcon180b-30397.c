//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_LENGTH 32 // Maximum length of input number

// Function to reverse a string
void reverse_string(char* str, int length) {
    char temp;
    for (int i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// Function to convert decimal to binary
void decimal_to_binary(int decimal, char* binary) {
    int remainder, i = 0;
    while (decimal > 0) {
        remainder = decimal % 2;
        binary[i] = remainder + '0';
        decimal /= 2;
        i++;
    }
    reverse_string(binary, i);
}

// Function to convert binary to decimal
int binary_to_decimal(char* binary) {
    int decimal = 0, power = 0;
    while (*binary!= '\0') {
        if (*binary == '1') {
            decimal += pow(2, power);
        }
        power++;
        binary++;
    }
    return decimal;
}

int main() {
    char decimal_str[MAX_NUM_LENGTH], binary_str[MAX_NUM_LENGTH];
    printf("Enter a decimal number: ");
    scanf("%s", decimal_str);

    // Convert decimal to binary
    decimal_to_binary(atoi(decimal_str), binary_str);

    // Print binary number
    printf("Binary number: %s\n", binary_str);

    // Convert binary to decimal
    int decimal_num = binary_to_decimal(binary_str);
    printf("Decimal number: %d\n", decimal_num);

    return 0;
}