//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE_LENGTH 7

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <color code>\n", argv[0]);
        return 1;
    }

    char *color_code = argv[1];
    int code_length = strlen(color_code);

    if (code_length!= MAX_CODE_LENGTH) {
        printf("Invalid color code length.\n");
        return 1;
    }

    for (int i = 0; i < code_length; i++) {
        if (!isxdigit(color_code[i])) {
            printf("Invalid color code format.\n");
            return 1;
        }
    }

    int red = 0, green = 0, blue = 0;

    for (int i = 0; i < code_length; i++) {
        char c = toupper(color_code[i]);
        if (c >= '0' && c <= '9') {
            red = red * 16 + c - '0';
        } else if (c >= 'A' && c <= 'F') {
            red = red * 16 + c - 'A' + 10;
        }
    }

    for (int i = 0; i < code_length; i++) {
        char c = toupper(color_code[i]);
        if (c >= '0' && c <= '9') {
            green = green * 16 + c - '0';
        } else if (c >= 'A' && c <= 'F') {
            green = green * 16 + c - 'A' + 10;
        }
    }

    for (int i = 0; i < code_length; i++) {
        char c = toupper(color_code[i]);
        if (c >= '0' && c <= '9') {
            blue = blue * 16 + c - '0';
        } else if (c >= 'A' && c <= 'F') {
            blue = blue * 16 + c - 'A' + 10;
        }
    }

    printf("Red: %d\n", red);
    printf("Green: %d\n", green);
    printf("Blue: %d\n", blue);

    return 0;
}