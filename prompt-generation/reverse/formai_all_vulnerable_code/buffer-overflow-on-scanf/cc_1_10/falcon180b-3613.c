//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: relaxed
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_HEX_DIGITS 8

void hex_to_dec(char* hex, int* dec) {
    int i = 0;
    int j = strlen(hex)-1;
    int decimal_value = 0;

    *dec = 0;

    while(i <= j) {
        if(isdigit(hex[i])) {
            decimal_value += (hex[i] - '0') * pow(16, j - i);
        } else if(isupper(hex[i])) {
            decimal_value += (hex[i] - 'A' + 10) * pow(16, j - i);
        } else if(islower(hex[i])) {
            decimal_value += (hex[i] - 'a' + 10) * pow(16, j - i);
        }

        i++;
    }

    *dec = decimal_value;
}

void dec_to_hex(int dec, char* hex) {
    int i = 0;
    int j = 0;

    while(dec > 0) {
        int temp = dec % 16;

        if(temp < 10) {
            hex[i++] = temp + '0';
        } else {
            hex[i++] = temp + 'A' - 10;
        }

        dec /= 16;
    }

    while(i < MAX_HEX_DIGITS) {
        hex[i++] = '0';
    }

    hex[i] = '\0';

    for(i = 0, j = strlen(hex)-1; i < j; i++, j--) {
        char temp = hex[i];
        hex[i] = hex[j];
        hex[j] = temp;
    }
}

int main() {
    char hex_str[MAX_HEX_DIGITS+1];
    int dec_val;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_str);

    hex_to_dec(hex_str, &dec_val);

    printf("Decimal value of %s is: %d\n", hex_str, dec_val);

    dec_to_hex(dec_val, hex_str);

    printf("Hexadecimal value of %d is: %s\n", dec_val, hex_str);

    return 0;
}