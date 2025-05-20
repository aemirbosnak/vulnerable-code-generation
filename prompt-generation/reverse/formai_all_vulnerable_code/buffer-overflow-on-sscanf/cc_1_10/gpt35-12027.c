//FormAI DATASET v1.0 Category: Color Code Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void hex_to_rgb(char *hex, int *red, int *green, int *blue) {
    // Convert a hexadecimal color code into its corresponding RGB values
    int hex_value;
    sscanf(hex, "%x", &hex_value);
    *red = (hex_value >> 16) & 0xFF;
    *green = (hex_value >> 8) & 0xFF;
    *blue = hex_value & 0xFF;
}

char* rgb_to_hex(int red, int green, int blue) {
    // Convert RGB values into their hexadecimal representation
    char *hex_code = malloc(sizeof(char) * 7);
    sprintf(hex_code, "#%02x%02x%02x", red, green, blue);
    return hex_code;
}

char* convert_color(char *input_color, char *output_color_format) {
    // Convert a color from one format to another
    char *output_color;
    int red = 0, green = 0, blue = 0;

    if (input_color[0] == '#') {
        // Input color is in hexadecimal format
        hex_to_rgb(input_color + 1, &red, &green, &blue);
    } else if (input_color[0] == 'r' && input_color[1] == 'g' && input_color[2] == 'b') {
        // Input color is in RGB format
        sscanf(input_color + 3, "(%d,%d,%d)", &red, &green, &blue);
    } else {
        // Invalid input color format
        printf("Invalid input color format: %s\n", input_color);
        return NULL;
    } 

    if (output_color_format[0] == '#') {
        // Output color format is hexadecimal
        output_color = rgb_to_hex(red, green, blue);
    } else if (output_color_format[0] == 'r' && output_color_format[1] == 'g' && output_color_format[2] == 'b') {
        // Output color format is RGB
        output_color = malloc(sizeof(char) * 16);
        sprintf(output_color, "rgb(%d,%d,%d)", red, green, blue);
    } else {
        // Invalid output color format
        printf("Invalid output color format: %s\n", output_color_format);
        return NULL;
    }

    return output_color;
}

int main() {
    char *input_color = "#aabbcc";
    char *output_color_format = "rgb";

    char *output_color = convert_color(input_color, output_color_format);
    printf("Input color: %s\nOutput color: %s\n", input_color, output_color);

    free(output_color);
    
    return 0;
}