//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char color_name[MAX_COLOR_CODE_LENGTH];
    char hex_code[MAX_COLOR_CODE_LENGTH];
} ColorCode;

// Function to convert color name to hex code
void convert_color_name_to_hex_code(ColorCode *color_code) {
    strcpy(color_code->hex_code, "#");
    int i = 0;
    while (i < strlen(color_code->color_name)) {
        if (isalpha(color_code->color_name[i])) {
            color_code->hex_code[i * 2] = toupper(color_code->color_name[i]);
        } else {
            color_code->hex_code[i * 2] = '0';
        }
        i++;
        if (i % 2 == 0) {
            color_code->hex_code[i * 2] = '0';
        }
    }
}

// Function to check if input is a valid color name
int is_valid_color_name(char *input) {
    int i = 0;
    while (i < strlen(input)) {
        if (!isalpha(input[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to print usage instructions
void print_usage() {
    printf("Usage:./color_code_converter [color_name]\n");
    printf("  [color_name] - A valid color name (e.g. red, blue, green)\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        print_usage();
        return 1;
    }

    ColorCode color_code;
    strcpy(color_code.color_name, argv[1]);

    if (!is_valid_color_name(color_code.color_name)) {
        printf("Error: Invalid color name\n");
        return 1;
    }

    convert_color_name_to_hex_code(&color_code);
    printf("Hex code for %s: %s\n", color_code.color_name, color_code.hex_code);

    return 0;
}