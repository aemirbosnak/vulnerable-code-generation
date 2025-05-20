//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE_LENGTH 7

// Function to check if a string is a valid color code
int is_valid_color_code(char *color_code) {
    int length = strlen(color_code);
    if (length!= MAX_COLOR_CODE_LENGTH) {
        return 0;
    }
    if (color_code[0]!= '#') {
        return 0;
    }
    for (int i = 1; i < length; i++) {
        if (!isxdigit(color_code[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert a color code to RGB values
void color_code_to_rgb(char *color_code, int *red, int *green, int *blue) {
    int value;
    sscanf(color_code, "#%02x%02x%02x", &value, &value, &value);
    *red = value;
    *green = value;
    *blue = value;
}

// Function to convert RGB values to a color code
void rgb_to_color_code(int red, int green, int blue, char *color_code) {
    sprintf(color_code, "#%02x%02x%02x", red, green, blue);
}

int main() {
    char input_color_code[MAX_COLOR_CODE_LENGTH];
    char output_color_code[MAX_COLOR_CODE_LENGTH];
    int red, green, blue;

    // Get user input for a color code
    printf("Enter a color code (e.g. #FF0000): ");
    scanf("%s", input_color_code);

    // Check if input is a valid color code
    if (!is_valid_color_code(input_color_code)) {
        printf("Invalid color code.\n");
        return 1;
    }

    // Convert input color code to RGB values
    color_code_to_rgb(input_color_code, &red, &green, &blue);

    // Convert RGB values to a different color code
    rgb_to_color_code(red + 32, green + 64, blue + 128, output_color_code);

    // Print the converted color code
    printf("The converted color code is: %s\n", output_color_code);

    return 0;
}