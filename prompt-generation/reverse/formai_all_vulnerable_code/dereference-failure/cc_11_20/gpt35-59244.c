//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LENGTH 16

char* hex_to_bin(char* hex) {
    int i = 0;
    int len = strlen(hex);
    char* bin = malloc(len * 4 + 1);
    bin[len * 4] = '\0';

    for (i = 0; i < len; ++i) {
        switch (hex[i]) {
            case '0':
                strcat(bin, "0000");
                break;
            case '1':
                strcat(bin, "0001");
                break;
            case '2':
                strcat(bin, "0010");
                break;
            case '3':
                strcat(bin, "0011");
                break;
            case '4':
                strcat(bin, "0100");
                break;
            case '5':
                strcat(bin, "0101");
                break;
            case '6':
                strcat(bin, "0110");
                break;
            case '7':
                strcat(bin, "0111");
                break;
            case '8':
                strcat(bin, "1000");
                break;
            case '9':
                strcat(bin, "1001");
                break;
            case 'a':
            case 'A':
                strcat(bin, "1010");
                break;
            case 'b':
            case 'B':
                strcat(bin, "1011");
                break;
            case 'c':
            case 'C':
                strcat(bin, "1100");
                break;
            case 'd':
            case 'D':
                strcat(bin, "1101");
                break;
            case 'e':
            case 'E':
                strcat(bin, "1110");
                break;
            case 'f':
            case 'F':
                strcat(bin, "1111");
                break;
            default:
                printf("Invalid Hexadecimal input.\n");
                return NULL;
        }
    }

    return bin;
}

int main() {
    char hex[MAX_HEX_LENGTH];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    char* bin = hex_to_bin(hex);

    if (bin) {
        printf("The binary equivalent is: %s\n", bin);
        free(bin);
    }

    return 0;
}