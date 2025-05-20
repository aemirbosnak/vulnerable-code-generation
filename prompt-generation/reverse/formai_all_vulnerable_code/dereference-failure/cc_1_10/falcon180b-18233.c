//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MAX_HEX_DIGITS 8

static int hex_to_int(const char *hex, unsigned long int *result) {
    int len = strlen(hex);
    if (len > MAX_HEX_DIGITS) {
        errno = EINVAL;
        return -1;
    }
    int value = 0;
    for (int i = 0; i < len; i++) {
        char c = tolower(hex[i]);
        if (!isxdigit(c)) {
            errno = EINVAL;
            return -1;
        }
        value = (value << 4) | (c - '0');
    }
    *result = value;
    return 0;
}

static void int_to_hex(unsigned long int value, char *hex) {
    char buffer[MAX_HEX_DIGITS + 1];
    sprintf(buffer, "%lx", value);
    strncpy(hex, buffer, MAX_HEX_DIGITS);
    hex[MAX_HEX_DIGITS] = '\0';
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hex_number> <decimal_number>\n", argv[0]);
        return 1;
    }

    unsigned long int decimal = 0;
    if (hex_to_int(argv[1], &decimal)!= 0) {
        fprintf(stderr, "Invalid hexadecimal number: %s\n", argv[1]);
        return 1;
    }

    char hex[MAX_HEX_DIGITS + 1] = { 0 };
    int_to_hex(decimal, hex);

    printf("Hexadecimal number: %s\n", hex);

    return 0;
}