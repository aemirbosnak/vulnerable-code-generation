//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char hex[MAX_SIZE];
    int dec;
} HexDec;

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void hexToDec(HexDec *hexdec) {
    hexdec->dec = 0;
    for (int i = 0; hexdec->hex[i] != '\0'; i++) {
        if (isdigit(hexdec->hex[i])) {
            hexdec->dec = hexdec->dec * 16 + (hexdec->hex[i] - '0');
        } else if (isalpha(hexdec->hex[i])) {
            hexdec->dec = hexdec->dec * 16 + (10 + (hexdec->hex[i] - 'A'));
        }
    }
}

void decToHex(HexDec *hexdec) {
    int digit;
    reverseString(hexdec->hex);
    int index = 0;
    while (hexdec->dec != 0) {
        digit = hexdec->dec % 16;
        if (digit < 10) {
            hexdec->hex[index] = digit + '0';
        } else {
            hexdec->hex[index] = digit + 'A' - 10;
        }
        hexdec->dec /= 16;
        index++;
    }
    hexdec->hex[index] = '\0';
    reverseString(hexdec->hex);
}

int main() {
    HexDec hexdec;
    char input[MAX_SIZE];
    char operation;

    printf("Enter the operation (+, -, *, /, Hx->D, D->Hx): ");
    scanf("%c", &operation);

    if (operation == 'H' || operation == 'h') {
        printf("Enter the Hexadecimal number: ");
        scanf("%s", input);
        strcpy(hexdec.hex, input);
        hexToDec(&hexdec);
        printf("Decimal equivalent: %d\n", hexdec.dec);
    } else if (operation == 'D' || operation == 'd') {
        printf("Enter the Decimal number: ");
        scanf("%d", &hexdec.dec);
        sprintf(hexdec.hex, "%X", hexdec.dec);
        printf("Hexadecimal equivalent: %s\n", hexdec.hex);
    } else {
        printf("Invalid operation.\n");
    }

    return 0;
}