//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char hex[100], buffer[1000];
    int i, j, len, input_len;
    char *ptr;

    printf("Post-Apocalyptic Hexadecimal Converter\n");
    printf("======================================\n\n");

    if (argc == 1) {
        printf("Usage: %s <hexadecimal number>\n", argv[0]);
        return 1;
    }

    strcpy(hex, argv[1]);
    len = strlen(hex);

    if (len == 0) {
        printf("Error: Empty input\n");
        return 1;
    }

    for (i = 0; i < len; i++) {
        if (!isxdigit(hex[i])) {
            printf("Error: Invalid hexadecimal input\n");
            return 1;
        }
    }

    sprintf(buffer, "Hexadecimal: %s\n", hex);
    printf(buffer);

    sprintf(buffer, "Decimal: %d\n", strtol(hex, &ptr, 16));
    printf(buffer);

    sprintf(buffer, "Binary: ");
    for (i = 0, j = 0; i < len; i++, j++) {
        if (j == 8) {
            printf("%s\n", buffer);
            j = 0;
        }
        sprintf(buffer + strlen(buffer), "%02X ", hex[i]);
    }
    printf("%s\n", buffer);

    return 0;
}