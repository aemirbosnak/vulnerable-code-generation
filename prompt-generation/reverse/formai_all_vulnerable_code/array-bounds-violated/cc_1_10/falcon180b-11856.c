//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LEN 1000

int main() {
    char hex_str[MAX_HEX_LEN];
    char *ptr;
    int decimal_num;
    int i;
    int len;

    // Prompt user for hexadecimal string input
    printf("Enter a hexadecimal number: ");
    fgets(hex_str, MAX_HEX_LEN, stdin);

    // Remove newline character from input
    len = strlen(hex_str);
    if (hex_str[len-1] == '\n') {
        hex_str[len-1] = '\0';
    }

    // Check if input is a valid hexadecimal string
    if (strspn(hex_str, "0123456789ABCDEF")!= strlen(hex_str)) {
        printf("Invalid hexadecimal number.\n");
        return 1;
    }

    // Convert hexadecimal string to decimal number
    decimal_num = 0;
    for (ptr = hex_str; *ptr; ptr++) {
        i = *ptr;
        if (i >= '0' && i <= '9') {
            decimal_num = (decimal_num * 16) + (i - '0');
        } else if (i >= 'A' && i <= 'F') {
            decimal_num = (decimal_num * 16) + (i - 'A' + 10);
        } else if (i >= 'a' && i <= 'f') {
            decimal_num = (decimal_num * 16) + (i - 'a' + 10);
        } else {
            printf("Invalid hexadecimal number.\n");
            return 1;
        }
    }

    // Print the decimal equivalent of the hexadecimal number
    printf("The decimal equivalent of %s is %d.\n", hex_str, decimal_num);

    return 0;
}