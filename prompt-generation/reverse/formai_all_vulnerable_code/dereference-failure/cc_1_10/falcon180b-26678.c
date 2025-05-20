//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_LINE_LENGTH 1000

void print_romantic_message(void) {
    printf("My love for you is like the stars in the sky,\n");
    printf("Endless and infinite, it will never die.\n");
    printf("Just like the colors of the rainbow,\n");
    printf("My love for you will always glow.\n");
    printf("With every beat of my heart,\n");
    printf("I promise to never be apart.\n");
    printf("You are the missing puzzle piece,\n");
    printf("That completes my heart's peace.\n");
    printf("I love you more than words can say,\n");
    printf("And I'll love you more each passing day.\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hex_color_code>\n", argv[0]);
        return 1;
    }

    char *color_code = argv[1];
    if (strlen(color_code)!= 7 || color_code[0]!= '#') {
        printf("Invalid color code format.\n");
        return 1;
    }

    int red, green, blue;
    if (sscanf(color_code + 1, "%02x%02x%02x", &red, &green, &blue)!= 3) {
        printf("Invalid color code format.\n");
        return 1;
    }

    double hue, saturation, value;
    hue = ((double)red / 255.0) * 6.0;
    saturation = ((double)green / 255.0) * 100.0;
    value = ((double)blue / 255.0) * 100.0;

    printf("Color code: %s\n", color_code);
    printf("HSV values: Hue = %.2f, Saturation = %.2f, Value = %.2f\n", hue, saturation, value);
    printf("RGB values: Red = %d, Green = %d, Blue = %d\n", red, green, blue);

    print_romantic_message();

    return 0;
}