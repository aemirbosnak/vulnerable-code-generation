//FormAI DATASET v1.0 Category: Color Code Converter ; Style: scientific
#include <stdio.h>

// Convert RGB values to hexadecimal color code
int rgbToHex(int r, int g, int b) {
    int hex = ((r << 16) & 0xFF0000) | ((g << 8) & 0x00FF00) | (b & 0x0000FF);
    return hex;
}

// Convert hexadecimal color code to RGB values
void hexToRGB(int hex, int *r, int *g, int *b) {
    *r = (hex >> 16) & 0xFF;
    *g = (hex >> 8) & 0xFF;
    *b = hex & 0xFF;
}

int main() {
    int r, g, b, hex;
    printf("Enter R value (0 - 255): ");
    scanf("%d", &r);
    printf("Enter G value (0 - 255): ");
    scanf("%d", &g);
    printf("Enter B value (0 - 255): ");
    scanf("%d", &b);

    // Validate input values
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        printf("Invalid RGB value!\n");
        return 1;
    }

    // Convert RGB values to hexadecimal color code
    hex = rgbToHex(r, g, b);
    printf("\nRGB value: (%d, %d, %d)\n", r, g, b);
    printf("Hexadecimal color code: #%06X\n\n", hex);

    // Convert hexadecimal color code to RGB values
    int rr, gg, bb;
    printf("Enter hexadecimal color code (e.g. #FF0000): ");
    char code[7];
    scanf("%s", &code);

    // Validate input code
    if (code[0] != '#' || strlen(code) != 7) {
        printf("Invalid hexadecimal color code!\n");
        return 1;
    }

    // Convert code to integer value
    hex = (int) strtol(code + 1, NULL, 16);

    // Convert hexadecimal color code to RGB values
    hexToRGB(hex, &rr, &gg, &bb);
    printf("\nHexadecimal color code: %s\n", code);
    printf("RGB value: (%d, %d, %d)\n", rr, gg, bb);

    return 0;
}