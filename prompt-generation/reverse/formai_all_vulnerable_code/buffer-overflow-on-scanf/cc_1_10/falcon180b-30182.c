//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH (8)
#define MAX_INT_LENGTH (11)
#define MAX_HEX_DIGITS (2)

int main() {
    char hex_str[MAX_HEX_LENGTH+1];
    char int_str[MAX_INT_LENGTH+1];
    int hex_len;
    int int_len;
    int i;
    int j;
    int num;
    int hex_num;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_str);

    hex_len = strlen(hex_str);

    if (hex_len > MAX_HEX_LENGTH) {
        printf("Error: Hexadecimal number too long.\n");
        exit(1);
    }

    for (i = 0; i < hex_len; i++) {
        if (!isxdigit(hex_str[i])) {
            printf("Error: Invalid hexadecimal character.\n");
            exit(1);
        }
    }

    int_len = 0;
    for (i = 0, j = hex_len - 1; i < hex_len; i++, j--) {
        if (isdigit(hex_str[i])) {
            int_str[int_len++] = hex_str[i];
        } else {
            int_str[int_len++] = toupper(hex_str[i]);
        }
    }

    int_str[int_len] = '\0';

    if (int_len > MAX_INT_LENGTH) {
        printf("Error: Integer too long.\n");
        exit(1);
    }

    num = strtol(int_str, NULL, 10);

    printf("Hexadecimal: %s\n", hex_str);
    printf("Integer: %d\n", num);

    return 0;
}