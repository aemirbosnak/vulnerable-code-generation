//FormAI DATASET v1.0 Category: Color Code Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("Welcome to the Color Code Converter!\n");

    char color_code[8];
    printf("Please enter a hexadecimal color code in the format \"XXXXXXX\": ");
    scanf("%s", color_code);

    if (color_code[0] != '#') {
        printf("Error: Invalid format. Please enter a hexadecimal color code preceded by a #.\n");
        exit(0);
    }

    int red = strtol(color_code + 1, NULL, 16);
    int green = strtol(color_code + 3, NULL, 16);
    int blue = strtol(color_code + 5, NULL, 16);

    printf("[R: %d, G: %d, B: %d]\n", red, green, blue);

    float hue, saturation, value;
    float r = red / 255.0f;
    float g = green / 255.0f;
    float b = blue / 255.0f;

    float cmax = r > g ? (r > b ? r : b) : (g > b ? g : b);
    float cmin = r < g ? (r < b ? r : b) : (g < b ? g : b);

    if (cmax == cmin) {
        hue = 0;
    } else if (cmax == r) {
        hue = ((g - b) / (cmax - cmin));
    } else if (cmax == g) {
        hue = 2 + (b - r) / (cmax - cmin);
    } else {
        hue = 4 + (r - g) / (cmax - cmin);
    }

    hue *= 60;

    if (hue < 0) {
        hue += 360;
    }

    if (cmax == 0) {
        saturation = 0;
    } else {
        saturation = (cmax - cmin) / cmax;
    }

    value = cmax;

    printf("[H: %f, S: %f, V: %f]\n", hue, saturation, value);

    printf("Would you like to convert to RGB or HEX format? (\"RGB\" or \"HEX\"): ");
    char format[4];
    scanf("%s", format);

    if (format[0] == 'R' && format[1] == 'G' && format[2] == 'B') {
        printf("Your color in RGB format is: [%d, %d, %d]\n", red, green, blue);
    } else if (format[0] == 'H' && format[1] == 'E' && format[2] == 'X') {
        printf("Your color in HEX format is: #%02X%02X%02X\n", red, green, blue);
    } else {
        printf("Error: Invalid format. Please enter either \"RGB\" or \"HEX\".\n");
        exit(0);
    }

    printf("Thank you for using our Color Code Converter!");

    return 0;
}