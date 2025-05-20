//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} RGB;

typedef struct {
    float hue;
    float saturation;
    float value;
} HSV;

// Function to convert RGB to HSV
HSV rgb_to_hsv(RGB rgb) {
    HSV hsv;
    float r = rgb.red / 255.0f;
    float g = rgb.green / 255.0f;
    float b = rgb.blue / 255.0f;

    float max = r > g ? (r > b ? r : b) : (g > b ? g : b);
    float min = r < g ? (r < b ? r : b) : (g < b ? g : b);
    float delta = max - min;

    // Compute hue
    if (delta == 0) {
        hsv.hue = 0; // undefined hue
    } else if (max == r) {
        hsv.hue = fmod(((g - b) / delta), 6);
    } else if (max == g) {
        hsv.hue = ((b - r) / delta) + 2;
    } else {
        hsv.hue = ((r - g) / delta) + 4;
    }

    hsv.hue *= 60;
    if (hsv.hue < 0) hsv.hue += 360;

    // Compute saturation
    hsv.saturation = (max == 0) ? 0 : (delta / max);

    // Compute value
    hsv.value = max;

    return hsv;
}

// Function to convert HSV to RGB
RGB hsv_to_rgb(HSV hsv) {
    RGB rgb;
    float c = hsv.value * hsv.saturation;
    float x = c * (1 - fabs(fmod((hsv.hue / 60), 2) - 1));
    float m = hsv.value - c;

    if (hsv.hue < 60) {
        rgb.red = (c + m) * 255;
        rgb.green = (x + m) * 255;
        rgb.blue = m * 255;
    } else if (hsv.hue < 120) {
        rgb.red = (x + m) * 255;
        rgb.green = (c + m) * 255;
        rgb.blue = m * 255;
    } else if (hsv.hue < 180) {
        rgb.red = m * 255;
        rgb.green = (c + m) * 255;
        rgb.blue = (x + m) * 255;
    } else if (hsv.hue < 240) {
        rgb.red = m * 255;
        rgb.green = (x + m) * 255;
        rgb.blue = (c + m) * 255;
    } else if (hsv.hue < 300) {
        rgb.red = (x + m) * 255;
        rgb.green = m * 255;
        rgb.blue = (c + m) * 255;
    } else {
        rgb.red = (c + m) * 255;
        rgb.green = m * 255;
        rgb.blue = (x + m) * 255;
    }

    return rgb;
}

// Function to display Menu and get user selection
void display_menu() {
    printf("Color Code Converter\n");
    printf("1. Convert RGB to HSV\n");
    printf("2. Convert HSV to RGB\n");
    printf("3. Exit\n");
}

// Main function
int main() {
    int choice;
    RGB rgb;
    HSV hsv;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter RGB values (r g b): ");
                scanf("%hhu %hhu %hhu", &rgb.red, &rgb.green, &rgb.blue);
                hsv = rgb_to_hsv(rgb);
                printf("HSV: %.2f, %.2f, %.2f\n", hsv.hue, hsv.saturation * 100, hsv.value * 100);
                break;

            case 2:
                printf("Enter HSV values (h s v): ");
                scanf("%f %f %f", &hsv.hue, &hsv.saturation, &hsv.value);
                rgb = hsv_to_rgb(hsv);
                printf("RGB: %d, %d, %d\n", rgb.red, rgb.green, rgb.blue);
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}