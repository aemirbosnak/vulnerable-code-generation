//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a given string is a valid binary number
int is_binary(char *str) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        if(str[i]!= '0' && str[i]!= '1') {
            return 0;
        }
    }
    return 1;
}

// Function to convert a binary number to decimal
int binary_to_decimal(char *binary) {
    int decimal = 0;
    int power = 0;
    int len = strlen(binary);
    for(int i=len-1; i>=0; i--) {
        if(binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

// Function to convert a decimal number to binary
void decimal_to_binary(int decimal) {
    char binary[33];
    int len = 0;
    while(decimal > 0) {
        if(decimal % 2 == 0) {
            strcat(binary, "0");
        } else {
            strcat(binary, "1");
        }
        decimal /= 2;
        len++;
    }
    for(int i=0; i<32-len; i++) {
        strcat(binary, "0");
    }
    printf("%s\n", binary);
}

int main() {
    char input[33];
    printf("Enter a binary number: ");
    scanf("%s", input);
    if(is_binary(input)) {
        int decimal = binary_to_decimal(input);
        printf("Decimal equivalent: %d\n", decimal);
        decimal_to_binary(decimal);
    } else {
        printf("Invalid binary number\n");
    }
    return 0;
}