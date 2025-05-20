//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LENGTH 100
#define HEX_CHARS "0123456789ABCDEF"

int main() {
    char hex[MAX_HEX_LENGTH];
    int hex_len;
    char binary[MAX_HEX_LENGTH * 4];
    int binary_len;
    char input[MAX_HEX_LENGTH];

    printf("Welcome to the C Hexadecimal Converter!\n");
    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    // Remove leading zeros
    int i, j;
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (input[i]!= '0') {
            input[j] = input[i];
            j++;
        }
    }
    input[j] = '\0';

    // Convert hexadecimal to binary
    hex_len = strlen(input);
    for (int i = 0; i < hex_len; i++) {
        int index = 0;
        if (input[i] >= 'A') {
            index = input[i] - 'A' + 10;
        } else if (input[i] >= 'a') {
            index = input[i] - 'a' + 10;
        } else {
            index = input[i] - '0';
        }
        strncat(binary, hex_len > i + 1? HEX_CHARS : "", 1);
        strncat(binary, &HEX_CHARS[index], 1);
    }
    binary_len = strlen(binary);

    // Convert binary to ASCII
    for (int i = 0; i < binary_len; i += 8) {
        char ascii = 0;
        for (int j = 0; j < 8 && i + j < binary_len; j++) {
            if (binary[i + j] == '1') {
                ascii |= 1 << (7 - j);
            }
        }
        printf("%c", ascii);
    }

    return 0;
}