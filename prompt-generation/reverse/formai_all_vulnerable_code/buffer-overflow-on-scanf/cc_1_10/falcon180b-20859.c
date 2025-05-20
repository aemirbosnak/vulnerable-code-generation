//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

void hex_to_decimal(char* hex_num, int* decimal) {
    int len = strlen(hex_num);
    int i = 0;
    *decimal = 0;
    while (i < len) {
        char c = tolower(hex_num[i]);
        if (c >= '0' && c <= '9') {
            *decimal = *decimal * 16 + (c - '0');
        } else if (c >= 'a' && c <= 'f') {
            *decimal = *decimal * 16 + (c - 'a' + 10);
        } else {
            printf("Invalid hexadecimal character '%c' at position %d\n", c, i);
            exit(1);
        }
        i++;
    }
}

void decimal_to_hex(int decimal, char* hex_num) {
    char hex_digits[] = "0123456789abcdef";
    int i = 0;
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex_num[i++] = remainder + '0';
        } else {
            hex_num[i++] = remainder + 'a' - 10;
        }
        decimal /= 16;
    }
    hex_num[i] = '\0';
}

int main() {
    char hex_num[MAX_SIZE];
    int decimal;
    
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_num);
    
    hex_to_decimal(hex_num, &decimal);
    
    printf("Decimal equivalent: %d\n", decimal);
    
    decimal_to_hex(decimal, hex_num);
    
    printf("Hexadecimal equivalent: %s\n", hex_num);
    
    return 0;
}