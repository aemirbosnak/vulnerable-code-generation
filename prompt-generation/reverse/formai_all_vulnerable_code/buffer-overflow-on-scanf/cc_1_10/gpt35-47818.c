//FormAI DATASET v1.0 Category: Color Code Converter ; Style: scalable
#include<stdio.h>
#include<string.h>

// Defining a struct to store RGB values
typedef struct RGB {
    int r;
    int g;
    int b;
} RGB;

// Defining a struct to store Hexadecimal values
typedef struct Hex {
    char hex[7];
} Hex;

// Function to convert RGB to Hexadecimal color code
Hex rgb_to_hex(RGB rgb) {
    Hex hex;
    sprintf(hex.hex, "#%02x%02x%02x", rgb.r, rgb.g, rgb.b);
    return hex;
}

// Function to convert Hexadecimal color code to RGB
RGB hex_to_rgb(char *hex_code) {
    RGB rgb;
    sscanf(hex_code, "#%02x%02x%02x", &rgb.r, &rgb.g, &rgb.b);
    return rgb;
}

int main() {
    RGB rgb;
    printf("Enter RGB values in the range 0-255\n");
    printf("Enter R value: ");
    scanf("%d", &rgb.r);
    printf("Enter G value: ");
    scanf("%d", &rgb.g);
    printf("Enter B value: ");
    scanf("%d", &rgb.b);

    // Validating input values
    if(rgb.r < 0 || rgb.r > 255 || rgb.g < 0 || rgb.g > 255 || rgb.b < 0 || rgb.b > 255) {
        printf("Invalid input. RGB values should be between 0-255.");
        return 1;
    }

    // Converting RGB color code to Hexadecimal color code
    Hex hex = rgb_to_hex(rgb);
    printf("The Hexadecimal equivalent of RGB(%d,%d,%d) is %s\n", rgb.r, rgb.g, rgb.b, hex.hex);

    char hex_code[7];
    printf("\nEnter a Hexadecimal color code: ");
    scanf("%s", hex_code);

    //Converting Hexadecimal color code to RGB color code
    RGB converted_rgb = hex_to_rgb(hex_code);
    printf("The RGB equivalent of %s is RGB(%d,%d,%d)", hex_code, converted_rgb.r, converted_rgb.g, converted_rgb.b);

    return 0;
}