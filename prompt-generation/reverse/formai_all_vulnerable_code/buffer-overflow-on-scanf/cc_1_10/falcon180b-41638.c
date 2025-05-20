//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7

struct ColorCode {
    char code[MAX_CODE_LENGTH];
    int red;
    int green;
    int blue;
};

void generate_color_code(char* code, int red, int green, int blue) {
    sprintf(code, "#%02X%02X%02X", red, green, blue);
}

int hex_to_int(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    return -1;
}

int string_to_color_code(char* str, struct ColorCode* color_code) {
    if (strlen(str)!= MAX_CODE_LENGTH) {
        return 0;
    }

    color_code->red = hex_to_int(str[0]) * 16 + hex_to_int(str[1]);
    color_code->green = hex_to_int(str[2]) * 16 + hex_to_int(str[3]);
    color_code->blue = hex_to_int(str[4]) * 16 + hex_to_int(str[5]);

    return 1;
}

void color_code_to_string(struct ColorCode* color_code, char* str) {
    sprintf(str, "#%02X%02X%02X", color_code->red, color_code->green, color_code->blue);
}

int main() {
    char input_code[MAX_CODE_LENGTH];
    struct ColorCode color_code;

    printf("Enter a color code (e.g. #FF0000): ");
    scanf("%s", input_code);

    if (string_to_color_code(input_code, &color_code)) {
        printf("Red: %d\n", color_code.red);
        printf("Green: %d\n", color_code.green);
        printf("Blue: %d\n", color_code.blue);

        char output_code[MAX_CODE_LENGTH];
        color_code_to_string(&color_code, output_code);
        printf("Output color code: %s\n", output_code);
    } else {
        printf("Invalid color code.\n");
    }

    return 0;
}