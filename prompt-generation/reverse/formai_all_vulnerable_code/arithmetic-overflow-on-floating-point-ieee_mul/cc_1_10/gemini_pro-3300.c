//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the RGB color structure
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} RGB;

// Define the HSV color structure
typedef struct {
    float hue;
    float saturation;
    float value;
} HSV;

// Convert RGB to HSV
HSV rgb_to_hsv(RGB rgb) {
    HSV hsv;

    float min, max, delta;

    min = rgb.red < rgb.green ? rgb.red : rgb.green;
    min = min < rgb.blue ? min : rgb.blue;

    max = rgb.red > rgb.green ? rgb.red : rgb.green;
    max = max > rgb.blue ? max : rgb.blue;

    hsv.value = max;

    delta = max - min;

    if (max != 0) {
        hsv.saturation = delta / max;
    } else {
        // No saturation, hue is undefined
        hsv.saturation = 0.0;
        hsv.hue = -1.0;
        return hsv;
    }

    if (rgb.red == max) {
        hsv.hue = (rgb.green - rgb.blue) / delta;
    } else if (rgb.green == max) {
        hsv.hue = 2 + (rgb.blue - rgb.red) / delta;
    } else {
        hsv.hue = 4 + (rgb.red - rgb.green) / delta;
    }

    hsv.hue *= 60.0;

    if (hsv.hue < 0.0) {
        hsv.hue += 360.0;
    }

    return hsv;
}

// Convert HSV to RGB
RGB hsv_to_rgb(HSV hsv) {
    RGB rgb;

    float chroma, hue, x;

    chroma = hsv.value * hsv.saturation;

    if (hsv.hue == 360.0) {
        hue = 0.0;
    } else {
        hue = hsv.hue / 60.0;
    }

    x = chroma * (1.0 - abs(fmod(hue, 2.0) - 1.0));

    if (hue < 1.0) {
        rgb.red = chroma;
        rgb.green = x;
        rgb.blue = 0.0;
    } else if (hue < 2.0) {
        rgb.red = x;
        rgb.green = chroma;
        rgb.blue = 0.0;
    } else if (hue < 3.0) {
        rgb.red = 0.0;
        rgb.green = chroma;
        rgb.blue = x;
    } else if (hue < 4.0) {
        rgb.red = 0.0;
        rgb.green = x;
        rgb.blue = chroma;
    } else if (hue < 5.0) {
        rgb.red = x;
        rgb.green = 0.0;
        rgb.blue = chroma;
    } else {
        rgb.red = chroma;
        rgb.green = 0.0;
        rgb.blue = x;
    }

    rgb.red += hsv.value - chroma;
    rgb.green += hsv.value - chroma;
    rgb.blue += hsv.value - chroma;

    return rgb;
}

// Print the RGB color values
void print_rgb(RGB rgb) {
    printf("Red: %d\n", rgb.red);
    printf("Green: %d\n", rgb.green);
    printf("Blue: %d\n", rgb.blue);
}

// Print the HSV color values
void print_hsv(HSV hsv) {
    printf("Hue: %.2f\n", hsv.hue);
    printf("Saturation: %.2f\n", hsv.saturation);
    printf("Value: %.2f\n", hsv.value);
}

// Get the RGB color values from the user
RGB get_rgb(void) {
    RGB rgb;

    printf("Enter the red value (0-255): ");
    scanf("%hhu", &rgb.red);

    printf("Enter the green value (0-255): ");
    scanf("%hhu", &rgb.green);

    printf("Enter the blue value (0-255): ");
    scanf("%hhu", &rgb.blue);

    return rgb;
}

// Get the HSV color values from the user
HSV get_hsv(void) {
    HSV hsv;

    printf("Enter the hue value (0-360): ");
    scanf("%f", &hsv.hue);

    printf("Enter the saturation value (0.0-1.0): ");
    scanf("%f", &hsv.saturation);

    printf("Enter the value value (0.0-1.0): ");
    scanf("%f", &hsv.value);

    return hsv;
}

// Main function
int main(void) {
    int choice;

    do {
        printf("\n1. Convert RGB to HSV\n");
        printf("2. Convert HSV to RGB\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    RGB rgb = get_rgb();
                    HSV hsv = rgb_to_hsv(rgb);
                    print_hsv(hsv);
                }
                break;
            case 2:
                {
                    HSV hsv = get_hsv();
                    RGB rgb = hsv_to_rgb(hsv);
                    print_rgb(rgb);
                }
                break;
            case 3:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}