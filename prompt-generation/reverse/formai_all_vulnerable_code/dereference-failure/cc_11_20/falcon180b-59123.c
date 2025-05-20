//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE_LENGTH 7
#define HEX_DIGITS "0123456789ABCDEF"

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <color_code>\n", argv[0]);
        return 1;
    }

    char *color_code = argv[1];
    int code_length = strlen(color_code);

    if (code_length!= MAX_CODE_LENGTH) {
        printf("Invalid color code length.\n");
        return 1;
    }

    for (int i = 0; i < code_length; i++) {
        char c = tolower(color_code[i]);

        if (!isxdigit(c)) {
            printf("Invalid color code.\n");
            return 1;
        }
    }

    int red = 0, green = 0, blue = 0;

    for (int i = 0; i < code_length; i++) {
        char c = color_code[i];

        if (isdigit(c)) {
            red = red * 16 + c - '0';
        } else {
            red = red * 16 + (c - 'A' + 10);
        }
    }

    for (int i = 0; i < code_length; i++) {
        char c = color_code[i];

        if (isdigit(c)) {
            green = green * 16 + c - '0';
        } else {
            green = green * 16 + (c - 'A' + 10);
        }
    }

    for (int i = 0; i < code_length; i++) {
        char c = color_code[i];

        if (isdigit(c)) {
            blue = blue * 16 + c - '0';
        } else {
            blue = blue * 16 + (c - 'A' + 10);
        }
    }

    printf("Red: %d\n", red);
    printf("Green: %d\n", green);
    printf("Blue: %d\n", blue);

    return 0;
}