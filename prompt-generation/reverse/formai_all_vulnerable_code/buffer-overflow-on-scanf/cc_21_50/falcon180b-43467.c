//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char input[100], hex[100], rgb[100];
    int r, g, b;

    printf("Enter a color code (e.g. #FF0000): ");
    scanf("%s", input);

    // Check if input is in hexadecimal format
    if (strlen(input)!= 7 || input[0]!= '#') {
        printf("Invalid color code.\n");
        return 1;
    }

    // Convert hexadecimal input to RGB values
    sscanf(input, "#%02x%02x%02x", &r, &g, &b);

    // Convert RGB values to hexadecimal format
    sprintf(hex, "#%02x%02x%02x", r, g, b);

    // Convert RGB values to color name
    if (r == 255 && g == 0 && b == 0) {
        strcpy(rgb, "red");
    } else if (r == 0 && g == 255 && b == 0) {
        strcpy(rgb, "green");
    } else if (r == 0 && g == 0 && b == 255) {
        strcpy(rgb, "blue");
    } else if (r == 255 && g == 255 && b == 0) {
        strcpy(rgb, "yellow");
    } else if (r == 255 && g == 0 && b == 255) {
        strcpy(rgb, "magenta");
    } else if (r == 0 && g == 255 && b == 255) {
        strcpy(rgb, "cyan");
    } else if (r == 255 && g == 255 && b == 255) {
        strcpy(rgb, "white");
    } else if (r == 0 && g == 0 && b == 0) {
        strcpy(rgb, "black");
    } else {
        strcpy(rgb, "unknown");
    }

    // Print results
    printf("Hexadecimal code: %s\n", hex);
    printf("RGB values: (%d, %d, %d)\n", r, g, b);
    printf("Color name: %s\n", rgb);

    return 0;
}