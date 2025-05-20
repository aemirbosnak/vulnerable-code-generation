//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* A utility function to count number of digits in a number */
int countDigits(unsigned int n) {
    int count = 0;
    while (n!= 0) {
        n /= 10;
        ++count;
    }
    return count;
}

/* A utility function to reverse a string */
void reverseString(char* str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start++] = str[end];
        str[end--] = temp;
    }
}

/* A utility function to convert binary number to decimal */
int binaryToDecimal(char* binary) {
    int decimal = 0, i = 0;
    while (binary[i]!= '\0') {
        if (binary[i] == '1') {
            decimal += pow(2, countDigits(decimal) - 1);
        }
        ++i;
    }
    return decimal;
}

/* A utility function to convert decimal number to binary */
void decimalToBinary(int decimal, char* binary) {
    int i = 0;
    while (decimal!= 0) {
        int remainder = decimal % 2;
        binary[i++] = remainder + '0';
        decimal /= 2;
    }
    binary[i] = '\0';
    reverseString(binary, 0, i - 1);
}

int main() {
    char binary[100], decimal[100];
    printf("Enter a binary number: ");
    scanf("%s", binary);
    int decimalNumber = binaryToDecimal(binary);
    printf("Decimal equivalent of %s is %d\n", binary, decimalNumber);
    sprintf(decimal, "%d", decimalNumber);
    printf("Binary equivalent of %d is %s\n", decimalNumber, decimal);
    return 0;
}