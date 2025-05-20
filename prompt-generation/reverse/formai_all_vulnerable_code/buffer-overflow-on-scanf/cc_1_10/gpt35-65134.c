//FormAI DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_CODE_LENGTH 7

int get_hex_value(char hex_char) {
    if (isdigit(hex_char))
        return hex_char - '0';
    else
        return toupper(hex_char) - 'A' + 10;
}

int is_valid_hex_color_code(char* color_code) {
    int length = strlen(color_code);

    if (length != MAX_COLOR_CODE_LENGTH)
        return 0;

    for (int i = 0; i < length; i++) {
        if (!isxdigit(color_code[i]))
            return 0;
    }

    return 1;
}

void convert_color_code_to_rgb(char* color_code, int* red, int* green, int* blue) {
    int hex1 = get_hex_value(color_code[1]);
    int hex2 = get_hex_value(color_code[2]); 
    *red = hex1 * 16 + hex2;

    hex1 = get_hex_value(color_code[3]);
    hex2 = get_hex_value(color_code[4]); 
    *green = hex1 * 16 + hex2;

    hex1 = get_hex_value(color_code[5]);
    hex2 = get_hex_value(color_code[6]); 
    *blue = hex1 * 16 + hex2;
}

int main() {
    char color_code[MAX_COLOR_CODE_LENGTH + 1];
    int red, green, blue;

    printf("Enter a valid hexadecimal color code: #");
    scanf("%s", color_code);

    if (!is_valid_hex_color_code(color_code)) {
        printf("Invalid hexadecimal color code entered.");
        return 1;
    }

    convert_color_code_to_rgb(color_code, &red, &green, &blue);

    printf("RGB value of color code %s is (%d, %d, %d)", color_code, red, green, blue);

    return 0;
}