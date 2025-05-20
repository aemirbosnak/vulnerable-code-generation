//FormAI DATASET v1.0 Category: Color Code Converter ; Style: complete
#include <stdio.h>
#include <string.h>
#include <math.h>

// Function to convert hex color code to RGB values
void hexToRGB(char* hex, int* r, int* g, int* b) {
    // Check if hex code is valid
    if (strlen(hex) != 6) {
        printf("Invalid hex color code\n");
        return;
    }

    // Convert each two hex characters to an integer
    int r_hex = (hex[0] - 48) * 16 + (hex[1] - 48);
    int g_hex = (hex[2] - 48) * 16 + (hex[3] - 48);
    int b_hex = (hex[4] - 48) * 16 + (hex[5] - 48);

    // Calculate RGB values
    *r = round((float)r_hex * 255 / 255);
    *g = round((float)g_hex * 255 / 255);
    *b = round((float)b_hex * 255 / 255);
}

// Function to convert RGB values to hex color code
void RGBToHex(int r, int g, int b, char* hex) {
    // Calculate each hex character from RGB values
    int r_hex1 = floor((float)r / 16);
    int r_hex2 = r % 16;
    int g_hex1 = floor((float)g / 16);
    int g_hex2 = g % 16;
    int b_hex1 = floor((float)b / 16);
    int b_hex2 = b % 16;

    // Convert each hex character to its ASCII character
    hex[0] = r_hex1 < 10 ? r_hex1 + 48 : r_hex1 + 55;
    hex[1] = r_hex2 < 10 ? r_hex2 + 48 : r_hex2 + 55;
    hex[2] = g_hex1 < 10 ? g_hex1 + 48 : g_hex1 + 55;
    hex[3] = g_hex2 < 10 ? g_hex2 + 48 : g_hex2 + 55;
    hex[4] = b_hex1 < 10 ? b_hex1 + 48 : b_hex1 + 55;
    hex[5] = b_hex2 < 10 ? b_hex2 + 48 : b_hex2 + 55;
}

int main() {
    char hex[7];
    int r, g, b;

    // Get hex color code from user
    printf("Enter hex color code: ");
    scanf("%s", hex);

    // Convert hex code to RGB values
    hexToRGB(hex, &r, &g, &b);

    // Print RGB values
    printf("RGB values: %d %d %d\n", r, g, b);

    // Convert RGB values to hex color code
    RGBToHex(r, g, b, hex);

    // Print hex color code
    printf("Hex color code: #%s\n", hex);

    return 0;
}