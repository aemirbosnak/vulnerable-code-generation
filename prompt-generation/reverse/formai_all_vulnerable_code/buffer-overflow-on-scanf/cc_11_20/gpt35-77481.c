//FormAI DATASET v1.0 Category: Color Code Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int red, green, blue;

    printf("Enter the RGB color code (R,G,B): ");
    scanf("%d,%d,%d", &red, &green, &blue);

    // Convert RGB values to percentages
    float rPercent = red / 255.0;
    float gPercent = green / 255.0;
    float bPercent = blue / 255.0;

    // Find the maximum and minimum RGB values
    float max = rPercent > gPercent ? (rPercent > bPercent ? rPercent : bPercent) : (gPercent > bPercent ? gPercent : bPercent);
    float min = rPercent < gPercent ? (rPercent < bPercent ? rPercent : bPercent) : (gPercent < bPercent ? gPercent : bPercent);

    // Calculate the hue, saturation, and value
    float hue, saturation, value = max;

    float delta = max - min;

    if (max == 0 || delta == 0) {
        hue = 0;
        saturation = 0;
    } else {
        saturation = delta / max;

        if (rPercent == max) {
            hue = (gPercent - bPercent) / delta;
        } else if (gPercent == max) {
            hue = 2 + (bPercent - rPercent) / delta;
        } else if (bPercent == max) {
            hue = 4 + (rPercent - gPercent) / delta;
        }

        hue *= 60;

        if (hue < 0) {
            hue += 360;
        }
    }

    // Format the output string for printing
    char* output = malloc(60 * sizeof(char));
    sprintf(output, "The color is %d,%d,%d in RGB and %f,%f,%f in HSV\n", red, green, blue, hue, saturation, value);

    // Print the output string
    printf("%s", output);

    free(output);

    return 0;
}