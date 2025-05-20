//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char hex[100], binary[400];
int bin_len = 0;

void decimal_to_hex(int decimal) {
    int temp, i = 1, j;
    char hexa[100];
    while (decimal != 0) {
        temp = decimal % 16;
        if (temp < 10) {
            hexa[i++] = temp + 48;
        } else {
            hexa[i++] = temp + 55;
        }
        decimal /= 16;
    }
    printf("\nHexadecimal value of decimal is: ");
    for (j = i - 1; j > 0; j--)
        printf("%c", hexa[j]);
}

void decimal_to_binary(int decimal) {
    int temp, i = 0, j;
    while (decimal != 0) {
        temp = decimal % 2;
        binary[i++] = temp + 48;
        decimal /= 2;
    }
    bin_len = i;
    printf("\nBinary value of decimal is: ");
    for (j = i - 1; j >= 0; j--)
        printf("%c", binary[j]);
}

void binary_to_hex() {
    int i, j;
    char str[4];
    strcat(binary, "0000");
    int len = strlen(binary);
    len = len / 4;
    printf("\nHexadecimal value of binary is: ");
    for (i = 0, j = 0; j < len; i+=4, j++) {
        strncpy(str, &binary[i], 4);
        if (strcmp(str, "0000") == 0) {
            hex[j] = '0';
        } else if (strcmp(str, "0001") == 0) {
            hex[j] = '1';
        } else if (strcmp(str, "0010") == 0) {
            hex[j] = '2';
        } else if (strcmp(str, "0011") == 0) {
            hex[j] = '3';
        } else if (strcmp(str, "0100") == 0) {
            hex[j] = '4';
        } else if (strcmp(str, "0101") == 0) {
            hex[j] = '5';
        } else if (strcmp(str, "0110") == 0) {
            hex[j] = '6';
        } else if (strcmp(str, "0111") == 0) {
            hex[j] = '7';
        } else if (strcmp(str, "1000") == 0) {
            hex[j] = '8';
        } else if (strcmp(str, "1001") == 0) {
            hex[j] = '9';
        } else if (strcmp(str, "1010") == 0) {
            hex[j] = 'A';
        } else if (strcmp(str, "1011") == 0) {
            hex[j] = 'B';
        } else if (strcmp(str, "1100") == 0) {
            hex[j] = 'C';
        } else if (strcmp(str, "1101") == 0) {
            hex[j] = 'D';
        } else if (strcmp(str, "1110") == 0) {
            hex[j] = 'E';
        } else if (strcmp(str, "1111") == 0) {
            hex[j] = 'F';
        } else {
            printf("\nError!");
            return;
        }
        printf("%c", hex[j]);
    }
}

int main() {
    int decimal;
    printf("Welcome to the Hexadecimal Converter Program.\n");
    printf("Please enter a decimal number: ");
    scanf("%d", &decimal);
    decimal_to_hex(decimal);
    decimal_to_binary(decimal);
    binary_to_hex();
    printf("\nThank you for using the Hexadecimal Converter Program.\n");
    return 0;
}