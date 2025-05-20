//FormAI DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>
#include <math.h>

int main() {
    // Declare variables to hold RGB values
    int red, green, blue;

    // Prompt user to enter RGB values
    printf("Enter RGB values ranging from 0 to 255:\n");
    printf("Red: ");
    scanf("%d", &red);
    printf("Green: ");
    scanf("%d", &green);
    printf("Blue: ");
    scanf("%d", &blue);

    // Ensure RGB values are within range
    if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
        printf("Invalid RGB values. Please enter values within the range of 0 to 255.\n");
        return 1; // Exit program with error code
    }

    // Convert RGB values to float values between 0 and 1
    float redFloat = red / 255.0f;
    float greenFloat = green / 255.0f;
    float blueFloat = blue / 255.0f;

    // Declare variables to hold HSL and HSV values
    float hueHSL, saturationHSL, lightnessHSL;
    float hueHSV, saturationHSV, valueHSV;

    // Calculate HSL values
    float minRGB = fmin(fmin(redFloat, greenFloat), blueFloat);
    float maxRGB = fmax(fmax(redFloat, greenFloat), blueFloat);
    float deltaRGB = maxRGB - minRGB;

    // Calculate lightnessHSL
    lightnessHSL = (maxRGB + minRGB) / 2;

    if (deltaRGB == 0) { // If red, green, and blue are all the same
        hueHSL = 0;
        saturationHSL = 0;
    } else { // If red, green, and blue are different
        // Calculate hueHSL
        if (maxRGB == redFloat) {
            hueHSL = fmod(((greenFloat - blueFloat) / deltaRGB), 6);
        } else if (maxRGB == greenFloat) {
            hueHSL = (((blueFloat - redFloat) / deltaRGB) + 2);
        } else { // maxRGB == blueFloat
            hueHSL = (((redFloat - greenFloat) / deltaRGB) + 4);
        }
        hueHSL *= 60; // Convert hue to degrees

        // Calculate saturationHSL
        if (lightnessHSL <= 0.5) {
            saturationHSL = deltaRGB / (maxRGB + minRGB);
        } else {
            saturationHSL = deltaRGB / (2 - maxRGB - minRGB);
        }
    }

    // Calculate HSV values
    // Calculate valueHSV
    valueHSV = maxRGB;

    if (deltaRGB == 0) { // If red, green, and blue are all the same
        hueHSV = 0;
        saturationHSV = 0;
    } else { // If red, green, and blue are different
        // Calculate hueHSV
        if (maxRGB == redFloat) {
            hueHSV = fmod(((greenFloat - blueFloat) / deltaRGB), 6);
        } else if (maxRGB == greenFloat) {
            hueHSV = (((blueFloat - redFloat) / deltaRGB) + 2);
        } else { // maxRGB == blueFloat
            hueHSV = (((redFloat - greenFloat) / deltaRGB) + 4);
        }
        hueHSV *= 60; // Convert hue to degrees

        // Calculate saturationHSV
        if (maxRGB == 0) { // black
            saturationHSV = 0;
        } else {
            saturationHSV = (deltaRGB / maxRGB);
        }
    }

    // Display results
    printf("\nRGB: %d,%d,%d\n", red, green, blue);
    printf("HSL: %.1f°, %.1f%%, %.1f%%\n", hueHSL, saturationHSL * 100, lightnessHSL * 100);
    printf("HSV: %.1f°, %.1f%%, %.1f%%\n", hueHSV, saturationHSV * 100, valueHSV * 100);

    return 0; // Exit program with success code
}