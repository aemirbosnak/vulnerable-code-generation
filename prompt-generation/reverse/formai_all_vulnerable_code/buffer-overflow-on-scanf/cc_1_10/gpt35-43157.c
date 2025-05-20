//FormAI DATASET v1.0 Category: Binary Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse(char *str) {
    char temp;
    int len = strlen(str);
    for(int i=0; i<len/2; i++) {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

// Function to convert decimal to binary
void decimalToBinary(int decimal, char *binary) {
    int quotient, remainder, i=0;
    while(decimal != 0) {
        quotient = decimal / 2;
        remainder = decimal % 2;
        binary[i++] = remainder + '0';
        decimal = quotient;
    }
    binary[i] = '\0';
    reverse(binary);
}

// Function to convert binary to decimal
int binaryToDecimal(char *binary) {
    int decimal = 0, power = 1;
    int len = strlen(binary);
    for(int i=len-1; i>=0; i--) {
        if(binary[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }
    return decimal;
}

int main() {
    int choice, decimal;
    char binary[100];

    printf("Welcome to the C Binary Converter!\n");
    printf("1. Decimal to Binary Conversion\n");
    printf("2. Binary to Decimal Conversion\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter the decimal number: ");
        scanf("%d", &decimal);
        decimalToBinary(decimal, binary);
        printf("The binary equivalent of %d is %s.\n", decimal, binary);
    } else if(choice == 2) {
        printf("Enter the binary number: ");
        scanf("%s", binary);
        decimal = binaryToDecimal(binary);
        printf("The decimal equivalent of %s is %d.\n", binary, decimal);
    } else {
        printf("Invalid choice. Please enter 1 or 2.\n");
    }

    return 0;
}