//Falcon2-11B DATASET v1.0 Category: Color Code Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char colorCode[4];
    printf("Enter a color code (RRGGBB): ");
    scanf("%s", colorCode);

    // Check if the input is valid
    if (strlen(colorCode)!= 6) {
        printf("Invalid input. Please enter a 6-digit color code.\n");
        return 1;
    }

    char red, green, blue;
    red = colorCode[0];
    green = colorCode[1];
    blue = colorCode[2];

    printf("Red: %d\n", red);
    printf("Green: %d\n", green);
    printf("Blue: %d\n", blue);

    // Convert the RGB color code to the equivalent HSV color code
    int max = (red > green)? (red > blue)? red : blue : green;
    int min = (red < green)? (red < blue)? red : blue : green;
    float delta = max - min;
    float h = 0;
    float s = 0;
    float v = max;

    if (delta == 0) {
        h = 0;
    } else {
        if (max == red) {
            h = (green - blue) / delta;
            if (h < 0) {
                h += 1;
            }
        } else if (max == green) {
            h = (blue - red) / delta + 1;
        } else {
            h = (red - green) / delta + 2;
        }
    }

    if (max == red) {
        s = delta / max;
    } else if (max == green) {
        s = delta / max;
    } else {
        s = delta / max;
    }

    if (max == red) {
        v = max;
    } else if (max == green) {
        v = max;
    } else {
        v = max;
    }

    printf("Hue: %f\n", h);
    printf("Saturation: %f\n", s);
    printf("Value: %f\n", v);

    return 0;
}