//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 100

typedef struct {
    int r;
    int g;
    int b;
} RGB;

typedef struct {
    int h;
    int s;
    int v;
} HSV;

// Function prototypes
void rgbToHSV(RGB rgb, HSV *hsv);
void hsvToRGB(HSV hsv, RGB *rgb);
void printRGB(RGB rgb);
void printHSV(HSV hsv);
void clearInputBuffer();

// Main program
int main() {
    int choice;
    RGB rgb;
    HSV hsv;

    printf("Color Code Converter\n");
    printf("====================\n");
    printf("1. RGB to HSV\n");
    printf("2. HSV to RGB\n");
    printf("3. Exit\n");

    do {
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear the input buffer

        switch (choice) {
            case 1:
                printf("Enter RGB values (r g b): ");
                scanf("%d %d %d", &rgb.r, &rgb.g, &rgb.b);
                clearInputBuffer(); // Clear the input buffer
                rgbToHSV(rgb, &hsv);
                printRGB(rgb);
                printHSV(hsv);
                break;

            case 2:
                printf("Enter HSV values (h s v): ");
                scanf("%d %d %d", &hsv.h, &hsv.s, &hsv.v);
                clearInputBuffer(); // Clear the input buffer
                hsvToRGB(hsv, &rgb);
                printHSV(hsv);
                printRGB(rgb);
                break;

            case 3:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice! Please enter a number between 1 and 3.\n");
                break;
        }
        printf("\n");
    } while (choice != 3);

    return 0;
}

// Function to convert RGB to HSV
void rgbToHSV(RGB rgb, HSV *hsv) {
    float r = rgb.r / 255.0;
    float g = rgb.g / 255.0;
    float b = rgb.b / 255.0;

    float max = r > g ? (r > b ? r : b) : (g > b ? g : b);
    float min = r < g ? (r < b ? r : b) : (g < b ? g : b);
    float delta = max - min;

    // Calculate hue
    if (delta == 0) {
        hsv->h = 0; // undefined
    } else if (max == r) {
        hsv->h = (60 * ((g - b) / delta) + 360);
        if (hsv->h >= 360) hsv->h -= 360;
    } else if (max == g) {
        hsv->h = (60 * ((b - r) / delta) + 120);
    } else {
        hsv->h = (60 * ((r - g) / delta) + 240);
    }

    // Calculate saturation
    hsv->s = (max == 0) ? 0 : (delta / max) * 100;

    // Calculate value
    hsv->v = max * 100;
}

// Function to convert HSV to RGB
void hsvToRGB(HSV hsv, RGB *rgb) {
    float h = hsv.h / 60.0;
    float s = hsv.s / 100.0;
    float v = hsv.v / 100.0;

    int hi = (int)h % 6;
    float f = h - (int)h;
    float p = v * (1 - s);
    float q = v * (1 - f * s);
    float t = v * (1 - (1 - f) * s);

    switch (hi) {
        case 0:
            rgb->r = v * 255;
            rgb->g = t * 255;
            rgb->b = p * 255;
            break;
        case 1:
            rgb->r = q * 255;
            rgb->g = v * 255;
            rgb->b = p * 255;
            break;
        case 2:
            rgb->r = p * 255;
            rgb->g = v * 255;
            rgb->b = t * 255;
            break;
        case 3:
            rgb->r = p * 255;
            rgb->g = q * 255;
            rgb->b = v * 255;
            break;
        case 4:
            rgb->r = t * 255;
            rgb->g = p * 255;
            rgb->b = v * 255;
            break;
        case 5:
            rgb->r = v * 255;
            rgb->g = p * 255;
            rgb->b = q * 255;
            break;
    }
}

// Function to print RGB values
void printRGB(RGB rgb) {
    printf("RGB: (%d, %d, %d)\n", rgb.r, rgb.g, rgb.b);
}

// Function to print HSV values
void printHSV(HSV hsv) {
    printf("HSV: (%d, %d%%, %d%%)\n", hsv.h, hsv.s, hsv.v);
}

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}