//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char hex[100], str[50];
    int i, j, len, val;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    // Check if input is a valid hexadecimal number
    for (i = 0; i < strlen(hex); i++) {
        if (!isxdigit(hex[i])) {
            printf("Invalid hexadecimal number!\n");
            exit(0);
        }
    }

    // Convert hexadecimal to decimal
    len = strlen(hex);
    val = 0;
    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            val += hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            val += hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            val += hex[i] - 'a' + 10;
        } else {
            printf("Invalid hexadecimal number!\n");
            exit(0);
        }
        val <<= 4;
    }

    // Convert decimal to binary
    str[0] = '\0';
    do {
        str[++len] = (val % 2) + '0';
        val >>= 1;
    } while (val!= 0);

    // Reverse the binary string
    for (i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    // Print the binary equivalent
    printf("Binary equivalent: %s\n", str);

    return 0;
}