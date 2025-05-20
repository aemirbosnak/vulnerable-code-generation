//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void hex_to_decimal(char* hex_str) {
    int decimal = 0;
    int power = 0;
    int len = strlen(hex_str);

    for(int i = len - 1; i >= 0; i--) {
        char c = hex_str[i];
        if(c >= '0' && c <= '9') {
            decimal += (c - '0') * (int)pow(16, power);
        } else if(c >= 'A' && c <= 'F') {
            decimal += (c - 'A' + 10) * (int)pow(16, power);
        } else if(c >= 'a' && c <= 'f') {
            decimal += (c - 'a' + 10) * (int)pow(16, power);
        }
        power++;
    }

    printf("%d\n", decimal);
}

void decimal_to_hex(int decimal) {
    char hex_str[MAX_LENGTH];
    int power = 0;
    int len = 0;

    while(decimal > 0) {
        int digit = decimal % 16;
        if(digit < 10) {
            hex_str[len++] = digit + '0';
        } else {
            hex_str[len++] = digit - 10 + 'A';
        }
        decimal /= 16;
        power++;
    }

    for(int i = 0; i < len / 2; i++) {
        char temp = hex_str[i];
        hex_str[i] = hex_str[len - i - 1];
        hex_str[len - i - 1] = temp;
    }

    printf("%s\n", hex_str);
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    if(strlen(input) > 0) {
        int first_char = input[0];
        if(first_char >= '0' && first_char <= '9') {
            decimal_to_hex(atoi(input));
        } else {
            hex_to_decimal(input);
        }
    }

    return 0;
}