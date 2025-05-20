//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void hex2bin(char* hex, int len, char* bin) {
    int i;
    for (i = 0; i < len; i++) {
        if (hex[i] == '0') {
            bin[i] = '0';
        } else if (hex[i] == '1') {
            bin[i] = '1';
        } else if (hex[i] == '2') {
            bin[i] = '2';
        } else if (hex[i] == '3') {
            bin[i] = '3';
        } else if (hex[i] == '4') {
            bin[i] = '4';
        } else if (hex[i] == '5') {
            bin[i] = '5';
        } else if (hex[i] == '6') {
            bin[i] = '6';
        } else if (hex[i] == '7') {
            bin[i] = '7';
        } else if (hex[i] == '8') {
            bin[i] = '8';
        } else if (hex[i] == '9') {
            bin[i] = '9';
        } else if (hex[i] == 'A') {
            bin[i] = '10';
        } else if (hex[i] == 'B') {
            bin[i] = '11';
        } else if (hex[i] == 'C') {
            bin[i] = '12';
        } else if (hex[i] == 'D') {
            bin[i] = '13';
        } else if (hex[i] == 'E') {
            bin[i] = '14';
        } else if (hex[i] == 'F') {
            bin[i] = '15';
        }
    }
}

int main() {
    char hex[16];
    char bin[16];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    int len = strlen(hex);
    hex2bin(hex, len, bin);
    printf("Binary representation: %s\n", bin);
    return 0;
}