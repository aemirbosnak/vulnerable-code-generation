//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_HEX_LEN 16

void paranoid_hex_to_bin(char hex_str[], char bin_str[]) {
    int i;
    for (i = 0; i < strlen(hex_str); i++) {
        if (hex_str[i] == '0') {
            bin_str[i] = '0';
        } else if (hex_str[i] == '1') {
            bin_str[i] = '1';
        } else if (hex_str[i] == '2') {
            bin_str[i] = '10';
        } else if (hex_str[i] == '3') {
            bin_str[i] = '11';
        } else if (hex_str[i] == '4') {
            bin_str[i] = '100';
        } else if (hex_str[i] == '5') {
            bin_str[i] = '101';
        } else if (hex_str[i] == '6') {
            bin_str[i] = '110';
        } else if (hex_str[i] == '7') {
            bin_str[i] = '111';
        } else if (hex_str[i] == '8') {
            bin_str[i] = '1000';
        } else if (hex_str[i] == '9') {
            bin_str[i] = '1001';
        } else if (hex_str[i] == 'A') {
            bin_str[i] = '1010';
        } else if (hex_str[i] == 'B') {
            bin_str[i] = '1011';
        } else if (hex_str[i] == 'C') {
            bin_str[i] = '1100';
        } else if (hex_str[i] == 'D') {
            bin_str[i] = '1101';
        } else if (hex_str[i] == 'E') {
            bin_str[i] = '1110';
        } else if (hex_str[i] == 'F') {
            bin_str[i] = '1111';
        } else {
            printf("Invalid character in hex string\n");
            exit(1);
        }
    }
}

void paranoid_hex_to_oct(char hex_str[], char oct_str[]) {
    int i;
    for (i = 0; i < strlen(hex_str); i++) {
        if (hex_str[i] == '0') {
            oct_str[i] = '0';
        } else if (hex_str[i] == '1') {
            oct_str[i] = '1';
        } else if (hex_str[i] == '2') {
            oct_str[i] = '2';
        } else if (hex_str[i] == '3') {
            oct_str[i] = '3';
        } else if (hex_str[i] == '4') {
            oct_str[i] = '4';
        } else if (hex_str[i] == '5') {
            oct_str[i] = '5';
        } else if (hex_str[i] == '6') {
            oct_str[i] = '6';
        } else if (hex_str[i] == '7') {
            oct_str[i] = '7';
        } else if (hex_str[i] == '8') {
            oct_str[i] = '8';
        } else if (hex_str[i] == '9') {
            oct_str[i] = '9';
        } else if (hex_str[i] == 'A') {
            oct_str[i] = 'A';
        } else if (hex_str[i] == 'B') {
            oct_str[i] = 'B';
        } else if (hex_str[i] == 'C') {
            oct_str[i] = 'C';
        } else if (hex_str[i] == 'D') {
            oct_str[i] = 'D';
        } else if (hex_str[i] == 'E') {
            oct_str[i] = 'E';
        } else if (hex_str[i] == 'F') {
            oct_str[i] = 'F';
        } else {
            printf("Invalid character in hex string\n");
            exit(1);
        }
    }
}

void paranoid_hex_to_dec(char hex_str[], char dec_str[]) {
    int i;
    for (i = 0; i < strlen(hex_str); i++) {
        if (hex_str[i] == '0') {
            dec_str[i] = '0';
        } else if (hex_str[i] == '1') {
            dec_str[i] = '1';
        } else if (hex_str[i] == '2') {
            dec_str[i] = '2';
        } else if (hex_str[i] == '3') {
            dec_str[i] = '3';
        } else if (hex_str[i] == '4') {
            dec_str[i] = '4';
        } else if (hex_str[i] == '5') {
            dec_str[i] = '5';
        } else if (hex_str[i] == '6') {
            dec_str[i] = '6';
        } else if (hex_str[i] == '7') {
            dec_str[i] = '7';
        } else if (hex_str[i] == '8') {
            dec_str[i] = '8';
        } else if (hex_str[i] == '9') {
            dec_str[i] = '9';
        } else if (hex_str[i] == 'A') {
            dec_str[i] = '10';
        } else if (hex_str[i] == 'B') {
            dec_str[i] = '11';
        } else if (hex_str[i] == 'C') {
            dec_str[i] = '12';
        } else if (hex_str[i] == 'D') {
            dec_str[i] = '13';
        } else if (hex_str[i] == 'E') {
            dec_str[i] = '14';
        } else if (hex_str[i] == 'F') {
            dec_str[i] = '15';
        } else {
            printf("Invalid character in hex string\n");
            exit(1);
        }
    }
}

int main() {
    char hex_str[MAX_HEX_LEN];
    char bin_str[MAX_HEX_LEN];
    char oct_str[MAX_HEX_LEN];
    char dec_str[MAX_HEX_LEN];

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_str);

    paranoid_hex_to_bin(hex_str, bin_str);
    paranoid_hex_to_oct(hex_str, oct_str);
    paranoid_hex_to_dec(hex_str, dec_str);

    printf("Binary representation: %s\n", bin_str);
    printf("Octal representation: %s\n", oct_str);
    printf("Decimal representation: %s\n", dec_str);

    return 0;
}