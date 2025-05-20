//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: post-apocalyptic
// Welcome to the Wasteland, survivor.
// This program will convert your scavenged hex codes into ASCII art for survival.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a palette of rusty and faded colors.
const char *colors[] = {
    "000000", "808080", "C0C0C0", "FFFFFF",
    "FF0000", "00FF00", "0000FF", "FFFF00",
    "00FFFF", "FF00FF", "800000", "008000",
    "000080", "808000", "800080", "008080"
};
const char *color_names[] = {
    "Black", "Gray", "Light Gray", "White",
    "Red", "Green", "Blue", "Yellow",
    "Cyan", "Magenta", "Maroon", "Olive",
    "Navy", "Brown", "Purple", "Teal"
};

// Convert a hex code to an ASCII art representation.
char *hex_to_ascii(const char *hex) {
    int r, g, b;
    sscanf(hex, "%2x%2x%2x", &r, &g, &b);
    char *ascii = malloc(6);
    ascii[0] = (r > 128) ? '#' : '_';
    ascii[1] = (g > 128) ? '#' : '_';
    ascii[2] = (b > 128) ? '#' : '_';
    ascii[3] = (r > 64) ? '#' : '_';
    ascii[4] = (g > 64) ? '#' : '_';
    ascii[5] = (b > 64) ? '#' : '_';
    return ascii;
}

// Convert an ASCII art representation to a hex code.
char *ascii_to_hex(const char *ascii) {
    int r = (ascii[0] == '#') ? 255 : 128;
    int g = (ascii[1] == '#') ? 255 : 128;
    int b = (ascii[2] == '#') ? 255 : 128;
    char *hex = malloc(7);
    sprintf(hex, "#%02x%02x%02x", r, g, b);
    return hex;
}

// Get the closest color name to a hex code.
char *closest_color(const char *hex) {
    int r, g, b;
    sscanf(hex, "%2x%2x%2x", &r, &g, &b);
    int min_diff = 255 * 3;
    int min_index = -1;
    for (int i = 0; i < 16; i++) {
        int dr = r - sscanf(colors[i], "%2x%2x%2x", &r, &g, &b);
        int dg = g - sscanf(colors[i], "%2x%2x%2x", &r, &g, &b);
        int db = b - sscanf(colors[i], "%2x%2x%2x", &r, &g, &b);
        int diff = dr * dr + dg * dg + db * db;
        if (diff < min_diff) {
            min_diff = diff;
            min_index = i;
        }
    }
    return color_names[min_index];
}

// Main function.
int main() {
    char hex[7];
    char ascii[6];
    char color[20];
    printf("Enter a hex code (e.g. #FF0000): ");
    scanf("%s", hex);
    strcpy(ascii, hex_to_ascii(hex));
    strcpy(color, closest_color(hex));
    printf("ASCII art: %s\n", ascii);
    printf("Closest color: %s\n", color);
    return 0;
}