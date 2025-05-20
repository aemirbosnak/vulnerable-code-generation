//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void to_hex(int decimal, char *hexadecimal);
int to_decimal(char *hexadecimal);
int is_hexadecimal(char *string);

int main(void) {
    int decimal;
    char hexadecimal[MAX_LENGTH];
    char input[MAX_LENGTH];
    char *end_ptr;

    printf("Welcome to the Hexadecimal Converter!\n\n");

    while(1) {
        printf("Enter a decimal number or a hexadecimal number: ");
        fgets(input, MAX_LENGTH, stdin);

        if(strchr(input, '\n') == NULL) {
            printf("Input too long.\n");
            while(getchar() != '\n');
            continue;
        }

        if(sscanf(input, "%d", &decimal) == 1) {
            to_hex(decimal, hexadecimal);
            printf("Hexadecimal: 0x%s\n\n", hexadecimal);
        }
        else if(is_hexadecimal(input)) {
            decimal = to_decimal(input);
            printf("Decimal: %d\n\n", decimal);
        }
        else {
            printf("Invalid input.\n\n");
        }
    }

    return 0;
}

void to_hex(int decimal, char *hexadecimal) {
    int quotient;
    int remainder;
    int i = 0;

    while(decimal != 0) {
        quotient = decimal / 16;
        remainder = decimal % 16;

        if(remainder < 10) {
            hexadecimal[i] = remainder + 48;
        }
        else {
            hexadecimal[i] = remainder + 55;
        }

        i++;
        decimal = quotient;
    }

    hexadecimal[i] = '\0';

    int length = strlen(hexadecimal);
    for(int j = 0; j < length / 2; j++) {
        char temp = hexadecimal[j];
        hexadecimal[j] = hexadecimal[length - j - 1];
        hexadecimal[length - j - 1] = temp;
    }
}

int to_decimal(char *hexadecimal) {
    int decimal = 0;
    int length = strlen(hexadecimal);

    for(int i = 0; i < length; i++) {
        if(hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            decimal += (hexadecimal[i] - 48) * pow(16, length - i - 1);
        }
        else if(hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            decimal += (hexadecimal[i] - 55) * pow(16, length - i - 1);
        }
        else if(hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f') {
            decimal += (hexadecimal[i] - 87) * pow(16, length - i - 1);
        }
    }

    return decimal;
}

int is_hexadecimal(char *string) {
    int length = strlen(string);

    if(length < 2) {
        return 0;
    }

    if(string[0] != '0' && string[1] != 'x') {
        return 0;
    }

    for(int i = 2; i < length; i++) {
        if((string[i] < '0' || string[i] > '9') && (string[i] < 'A' || string[i] > 'F') && (string[i] < 'a' || string[i] > 'f')) {
            return 0;
        }
    }

    return 1;
}