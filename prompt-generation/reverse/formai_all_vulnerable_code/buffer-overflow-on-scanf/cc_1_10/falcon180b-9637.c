//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COLOR_CODE_LENGTH 7

// Function prototypes
char* convert_color_code(char* color_code, bool is_hex);
bool is_valid_color_code(char* color_code);

int main() {
    char color_code[MAX_COLOR_CODE_LENGTH + 1];
    printf("Enter a color code: ");
    scanf("%s", color_code);

    char* converted_color_code = convert_color_code(color_code, false);

    if (converted_color_code!= NULL) {
        printf("Converted color code: %s\n", converted_color_code);
    } else {
        printf("Invalid color code.\n");
    }

    return 0;
}

// Converts a color code from one format to another
char* convert_color_code(char* color_code, bool is_hex) {
    char* converted_color_code = malloc(MAX_COLOR_CODE_LENGTH + 1);

    if (is_valid_color_code(color_code)) {
        if (is_hex) {
            // Convert RGB to hexadecimal
            sprintf(converted_color_code, "#%02X%02X%02X",
                    color_code[0] * 16 + color_code[1],
                    color_code[2] * 16 + color_code[3],
                    color_code[4] * 16 + color_code[5]);
        } else {
            // Convert hexadecimal to RGB
            sprintf(converted_color_code, "RGB(%d, %d, %d)",
                    color_code[1] * 16 + color_code[2],
                    color_code[3] * 16 + color_code[4],
                    color_code[5] * 16 + color_code[6]);
        }
    } else {
        converted_color_code = NULL;
    }

    return converted_color_code;
}

// Checks if a color code is valid
bool is_valid_color_code(char* color_code) {
    if (strlen(color_code)!= 6) {
        return false;
    }

    for (int i = 0; i < 6; i++) {
        if (!isdigit(color_code[i]) && (color_code[i] < 'A' || color_code[i] > 'F')) {
            return false;
        }
    }

    return true;
}