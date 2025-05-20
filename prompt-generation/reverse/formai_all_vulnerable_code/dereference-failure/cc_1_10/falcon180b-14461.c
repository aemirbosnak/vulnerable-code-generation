//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char* binary;
    char* hex;
    char* octal;
} NumberFormat;

void generateBinary(unsigned int decimal, char* binary, int size) {
    int i = 0;
    while (decimal > 0) {
        binary[i] = (decimal % 2) + '0';
        decimal /= 2;
        i++;
    }
    for (; i < size; i++) {
        binary[i] = '0';
    }
    binary[size] = '\0';
}

void generateHexadecimal(unsigned int decimal, char* hex, int size) {
    int i = 0;
    while (decimal > 0) {
        hex[i] = (decimal % 16) + (decimal < 10? '0' : 'A' - 10);
        decimal /= 16;
        i++;
    }
    for (; i < size; i++) {
        hex[i] = '0';
    }
    hex[size] = '\0';
}

void generateOctal(unsigned int decimal, char* octal, int size) {
    int i = 0;
    while (decimal > 0) {
        octal[i] = (decimal % 8) + '0';
        decimal /= 8;
        i++;
    }
    for (; i < size; i++) {
        octal[i] = '0';
    }
    octal[size] = '\0';
}

int main() {
    unsigned int decimal;
    printf("Enter a decimal number: ");
    scanf("%u", &decimal);
    printf("Binary: ");
    generateBinary(decimal, (char*) malloc(33 * sizeof(char)), 32);
    printf("%s\n", (char*) malloc(33 * sizeof(char)));
    printf("Hexadecimal: ");
    generateHexadecimal(decimal, (char*) malloc(9 * sizeof(char)), 8);
    printf("%s\n", (char*) malloc(9 * sizeof(char)));
    printf("Octal: ");
    generateOctal(decimal, (char*) malloc(12 * sizeof(char)), 11);
    printf("%s\n", (char*) malloc(12 * sizeof(char)));
    return 0;
}