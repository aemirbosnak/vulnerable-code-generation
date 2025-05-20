//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void convert_color_code(char *color_code);
int is_valid_color_code(char *color_code);
void print_converted_color_code(char *color_code);

int main() {
    char color_code[10];

    // Get input from user
    printf("Enter a color code (e.g. #FF0000): ");
    scanf("%s", color_code);

    // Convert color code
    convert_color_code(color_code);

    // Print converted color code
    print_converted_color_code(color_code);

    return 0;
}

// Converts a color code from hexadecimal to RGB
void convert_color_code(char *color_code) {
    if (!is_valid_color_code(color_code)) {
        printf("Invalid color code.\n");
        return;
    }

    // Convert hexadecimal to decimal
    int red = (int)strtol(color_code + 1, NULL, 16);
    int green = (int)strtol(color_code + 3, NULL, 16);
    int blue = (int)strtol(color_code + 5, NULL, 16);

    // Convert decimal to RGB
    int max = red > green? red : green;
    max = max > blue? max : blue;

    red = (red * 255) / max;
    green = (green * 255) / max;
    blue = (blue * 255) / max;

    // Print converted color code
    printf("RGB: %d, %d, %d\n", red, green, blue);
}

// Checks if a color code is valid
int is_valid_color_code(char *color_code) {
    // Check for correct length
    if (strlen(color_code)!= 7) {
        return 0;
    }

    // Check if first character is '#'
    if (color_code[0]!= '#') {
        return 0;
    }

    // Check if remaining characters are hexadecimal
    for (int i = 1; i < strlen(color_code); i++) {
        if (!isxdigit(color_code[i])) {
            return 0;
        }
    }

    return 1;
}

// Prints a converted color code
void print_converted_color_code(char *color_code) {
    printf("Converted color code: %s\n", color_code);
}