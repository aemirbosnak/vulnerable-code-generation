//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a valid hexadecimal number
int is_valid_hex(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char c = tolower(str[i]);
        if (!isxdigit(c)) {
            return 0;
        }
    }
    return 1;
}

// Function to convert a hexadecimal string to an RGB color
int hex_to_rgb(char *hex, int *r, int *g, int *b) {
    char r_str[3] = { hex[0], hex[1], '\0' };
    char g_str[3] = { hex[2], hex[3], '\0' };
    char b_str[3] = { hex[4], hex[5], '\0' };

    *r = strtol(r_str, NULL, 16);
    *g = strtol(g_str, NULL, 16);
    *b = strtol(b_str, NULL, 16);

    return 1;
}

// Function to convert an RGB color to a hexadecimal string
void rgb_to_hex(int r, int g, int b, char *hex) {
    sprintf(hex, "#%02x%02x%02x", r, g, b);
}

void main() {
    char hex[7];
    int r, g, b;

    // Prompt user for a hexadecimal color code
    printf("Enter a hexadecimal color code: ");
    scanf("%s", hex);

    // Check if the input is a valid hexadecimal number
    if (!is_valid_hex(hex)) {
        printf("Invalid hexadecimal number\n");
        exit(1);
    }

    // Convert the hexadecimal color code to an RGB color
    hex_to_rgb(hex, &r, &g, &b);

    // Convert the RGB color to a hexadecimal string
    char rgb_hex[9];
    rgb_to_hex(r, g, b, rgb_hex);

    // Print the converted hexadecimal color code
    printf("RGB: %d, %d, %d\n", r, g, b);
    printf("Hexadecimal: %s\n", rgb_hex);
}