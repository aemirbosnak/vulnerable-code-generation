//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char hex_num[20];
    int dec_num = 0, hex_len, i, digit;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_num);

    hex_len = strlen(hex_num);

    for (i = 0; i < hex_len; i++) {
        switch(hex_num[i]) {
            case '0':
                digit = 0;
                break;
            case '1':
                digit = 1;
                break;
            case '2':
                digit = 2;
                break;
            case '3':
                digit = 3;
                break;
            case '4':
                digit = 4;
                break;
            case '5':
                digit = 5;
                break;
            case '6':
                digit = 6;
                break;
            case '7':
                digit = 7;
                break;
            case '8':
                digit = 8;
                break;
            case '9':
                digit = 9;
                break;
            case 'A':
            case 'a':
                digit = 10;
                break;
            case 'B':
            case 'b':
                digit = 11;
                break;
            case 'C':
            case 'c':
                digit = 12;
                break;
            case 'D':
            case 'd':
                digit = 13;
                break;
            case 'E':
            case 'e':
                digit = 14;
                break;
            case 'F':
            case 'f':
                digit = 15;
                break;
            default:
                printf("Invalid hexadecimal input.\n");
                return 0;
        }

        dec_num += digit * pow(16, hex_len - i - 1);
    }

    printf("The decimal equivalent of %s is %d.\n", hex_num, dec_num);

    return 0;
}