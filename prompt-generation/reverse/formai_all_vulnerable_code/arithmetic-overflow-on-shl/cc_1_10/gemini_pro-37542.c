//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: paranoid
#pragma paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

/* Hexadecimal digits. */
static const char hex_digits[] = "0123456789abcdef";

/* Converts a hexadecimal string to an integer. */
int paranoid_hex2int(const char *hex) {
    int i, j, result;

    /* Basic sanity checks. */
    if (hex == NULL || strlen(hex) == 0) {
        return 0;
    }

    /* Initialize the result. */
    result = 0;

    /* Iterate over the hexadecimal digits. */
    for (i = strlen(hex) - 1; i >= 0; i--) {
        /* Find the index of the hexadecimal digit. */
        for (j = 0; j < ARRAY_SIZE(hex_digits); j++) {
            if (hex[i] == hex_digits[j]) {
                break;
            }
        }

        /* Check if the hexadecimal digit was found. */
        if (j == ARRAY_SIZE(hex_digits)) {
            return 0;
        }

        /* Shift the result to make room for the new digit. */
        result <<= 4;

        /* Add the new digit to the result. */
        result += j;
    }

    /* Return the result. */
    return result;
}

/* Converts an integer to a hexadecimal string. */
char *paranoid_int2hex(int value, char *hex) {
    int i, j;

    /* Basic sanity checks. */
    if (hex == NULL) {
        return NULL;
    }

    /* Initialize the hexadecimal string. */
    memset(hex, 0, sizeof(hex));

    /* Iterate over the hexadecimal digits. */
    for (i = 0; i < 8; i++) {
        /* Calculate the index of the hexadecimal digit. */
        j = value & 0xf;

        /* Convert the hexadecimal digit to a character. */
        hex[i] = hex_digits[j];

        /* Shift the value to make room for the next digit. */
        value >>= 4;
    }

    /* Return the hexadecimal string. */
    return hex;
}

/* Tests the hexadecimal converter. */
int main(void) {
    int value;
    char hex[9];

    /* Convert a hexadecimal string to an integer. */
    value = paranoid_hex2int("deadbeef");
    printf("0x%x\n", value);

    /* Convert an integer to a hexadecimal string. */
    paranoid_int2hex(value, hex);
    printf("%s\n", hex);

    return 0;
}