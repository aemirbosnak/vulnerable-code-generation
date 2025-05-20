//Code Llama-13B DATASET v1.0 Category: Color Code Converter ; Style: secure
// Color Code Converter

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE_LENGTH 7

int main(int argc, char **argv) {
    char input_color_code[MAX_COLOR_CODE_LENGTH];
    char output_color_code[MAX_COLOR_CODE_LENGTH];
    char *ptr;

    // Check if the input is valid
    if (argc < 2) {
        printf("Usage: %s <color_code>\n", argv[0]);
        return 1;
    }

    // Get the input color code
    strcpy(input_color_code, argv[1]);

    // Check if the input color code is valid
    if (strlen(input_color_code) != MAX_COLOR_CODE_LENGTH) {
        printf("Invalid color code\n");
        return 1;
    }

    // Convert the input color code to uppercase
    for (int i = 0; i < MAX_COLOR_CODE_LENGTH; i++) {
        input_color_code[i] = toupper(input_color_code[i]);
    }

    // Check if the input color code is a valid color code
    if (input_color_code[0] != '#') {
        printf("Invalid color code\n");
        return 1;
    }

    // Convert the input color code to a hexadecimal value
    ptr = &input_color_code[1];
    int r = (int)strtol(ptr, &ptr, 16);
    int g = (int)strtol(ptr, &ptr, 16);
    int b = (int)strtol(ptr, &ptr, 16);

    // Check if the input color code is a valid hexadecimal value
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        printf("Invalid color code\n");
        return 1;
    }

    // Convert the hexadecimal value to a color code
    sprintf(output_color_code, "#%02x%02x%02x", r, g, b);

    // Print the output color code
    printf("Color Code: %s\n", output_color_code);

    return 0;
}