//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LENGTH 100

void print_hex(char *hex, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%02X ", hex[i]);
    }
    printf("\n");
}

int main() {
    char input[MAX_HEX_LENGTH];
    char hex[MAX_HEX_LENGTH];
    int length;
    int i;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);
    length = strlen(input);

    if (length == 0) {
        printf("Invalid input.\n");
        return 1;
    }

    if (input[0] == '0' && (length == 1 || input[1] == 'X' || input[1] == 'x')) {
        printf("Invalid input.\n");
        return 1;
    }

    for (i = 0; i < length; i++) {
        if (!isxdigit(input[i])) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    sprintf(hex, "%02X", (unsigned char)input[0]);
    for (i = 1; i < length; i++) {
        sprintf(hex + (i * 2), "%02X", (unsigned char)input[i]);
    }

    printf("Hexadecimal representation: ");
    print_hex(hex, strlen(hex));

    return 0;
}