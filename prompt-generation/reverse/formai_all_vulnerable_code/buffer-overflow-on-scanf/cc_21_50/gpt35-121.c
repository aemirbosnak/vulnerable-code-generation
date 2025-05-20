//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char hex_num[100];
    int dec_num = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_num);

    for (int i = 0; hex_num[i] != '\0'; i++) {
        switch(hex_num[i]) {
            case '0':
                dec_num = dec_num * 16 + 0;
                break;
            case '1':
                dec_num = dec_num * 16 + 1;
                break;
            case '2':
                dec_num = dec_num * 16 + 2;
                break;
            case '3':
                dec_num = dec_num * 16 + 3;
                break;
            case '4':
                dec_num = dec_num * 16 + 4;
                break;
            case '5':
                dec_num = dec_num * 16 + 5;
                break;
            case '6':
                dec_num = dec_num * 16 + 6;
                break;
            case '7':
                dec_num = dec_num * 16 + 7;
                break;
            case '8':
                dec_num = dec_num * 16 + 8;
                break;
            case '9':
                dec_num = dec_num * 16 + 9;
                break;
            case 'A':
            case 'a':
                dec_num = dec_num * 16 + 10;
                break;
            case 'B':
            case 'b':
                dec_num = dec_num * 16 + 11;
                break;
            case 'C':
            case 'c':
                dec_num = dec_num * 16 + 12;
                break;
            case 'D':
            case 'd':
                dec_num = dec_num * 16 + 13;
                break;
            case 'E':
            case 'e':
                dec_num = dec_num * 16 + 14;
                break;
            case 'F':
            case 'f':
                dec_num = dec_num * 16 + 15;
                break;
            default:
                printf("Invalid hexadecimal digit %c \n", hex_num[i]);
                exit(0);
        }
    }

    printf("The decimal number for %s is %d\n", hex_num, dec_num);

    return 0;
}