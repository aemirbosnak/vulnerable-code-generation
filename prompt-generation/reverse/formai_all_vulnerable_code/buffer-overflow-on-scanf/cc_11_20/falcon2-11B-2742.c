//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    char hex_str[100];
    char binary_str[100];
    int n;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_str);

    n = strlen(hex_str);
    if(n == 1) {
        printf("Enter a hexadecimal number with at least two characters\n");
        return;
    }

    for(int i = 0; i < n; i++) {
        switch(hex_str[i]) {
            case '0':
                binary_str[i] = '0';
                break;
            case '1':
                binary_str[i] = '1';
                break;
            case '2':
                binary_str[i] = '2';
                break;
            case '3':
                binary_str[i] = '3';
                break;
            case '4':
                binary_str[i] = '4';
                break;
            case '5':
                binary_str[i] = '5';
                break;
            case '6':
                binary_str[i] = '6';
                break;
            case '7':
                binary_str[i] = '7';
                break;
            case '8':
                binary_str[i] = '8';
                break;
            case '9':
                binary_str[i] = '9';
                break;
            case 'A':
                binary_str[i] = '10';
                break;
            case 'B':
                binary_str[i] = '11';
                break;
            case 'C':
                binary_str[i] = '12';
                break;
            case 'D':
                binary_str[i] = '13';
                break;
            case 'E':
                binary_str[i] = '14';
                break;
            case 'F':
                binary_str[i] = '15';
                break;
            default:
                binary_str[i] = '?';
                break;
        }
    }

    printf("Binary representation: %s\n", binary_str);
}