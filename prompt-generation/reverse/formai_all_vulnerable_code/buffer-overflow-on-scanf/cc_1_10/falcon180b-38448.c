//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024 // maximum size of input buffer

// function to convert hexadecimal string to decimal integer
int hexToDec(char* hex) {
    int dec = 0;
    int len = strlen(hex);
    for (int i = 0; i < len; i++) {
        char c = tolower(hex[i]);
        if (c >= '0' && c <= '9') {
            dec = dec * 16 + c - '0';
        } else if (c >= 'a' && c <= 'f') {
            dec = dec * 16 + c - 'a' + 10;
        } else {
            return -1; // invalid hexadecimal digit
        }
    }
    return dec;
}

// function to convert decimal integer to hexadecimal string
void decToHex(int dec, char* hex) {
    int len = BUFFER_SIZE;
    char buffer[BUFFER_SIZE];
    char* p = buffer + len - 1;
    *p = '\0';
    while (dec > 0) {
        int digit = dec % 16;
        if (digit < 10) {
            *p-- = digit + '0';
        } else {
            *p-- = digit - 10 + 'a';
        }
        dec /= 16;
    }
    strcpy(hex, p);
}

int main() {
    char input[BUFFER_SIZE];
    char output[BUFFER_SIZE];
    int choice;
    do {
        printf("Enter a hexadecimal number (or enter 0 to quit):\n");
        fgets(input, BUFFER_SIZE, stdin);
        if (strlen(input) == 1 && input[0] == '0') {
            break;
        }
        int hexLen = strlen(input);
        if (hexLen > 0 && input[0] == '0') {
            input[0] = 'x';
            hexLen--;
        }
        int dec = hexToDec(input);
        if (dec == -1) {
            printf("Invalid hexadecimal number\n");
        } else {
            decToHex(dec, output);
            printf("Decimal: %s\n", output);
        }
        printf("Enter 1 to convert another number or 0 to quit:\n");
        scanf("%d", &choice);
    } while (choice!= 0);
    return 0;
}