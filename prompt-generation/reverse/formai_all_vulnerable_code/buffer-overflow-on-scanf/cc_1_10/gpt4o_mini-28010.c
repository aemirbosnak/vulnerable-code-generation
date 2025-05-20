//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

typedef struct {
    int red;
    int green;
    int blue;
} RGB;

typedef struct {
    float hue;
    float saturation;
    float value;
} HSV;

// Function Prototypes
void rgbToHSV(RGB rgb, HSV *hsv);
void hsvToRGB(HSV hsv, RGB *rgb);
void printColor(const char *format, RGB rgb, HSV hsv);
void getInputRGB(RGB *rgb);
void getInputHSV(HSV *hsv);
void displayMenu();
void executeOption(int option);

int main() {
    int option;

    do {
        displayMenu();
        printf("Choose an option (1-4) or 0 to exit: ");
        scanf("%d", &option);
        executeOption(option);
    } while (option != 0);

    printf("Thank you for using Color Code Converter! Goodbye!\n");
    return 0;
}

void displayMenu() {
    printf("\n--- Color Code Converter ---\n");
    printf("1. Convert RGB to HSV\n");
    printf("2. Convert HSV to RGB\n");
    printf("3. Show the Color\n");
    printf("0. Exit\n");
}

void executeOption(int option) {
    RGB rgb;
    HSV hsv;

    switch (option) {
        case 1:
            getInputRGB(&rgb);
            rgbToHSV(rgb, &hsv);
            printf("Converted RGB(%d, %d, %d) to HSV(%.2f, %.2f, %.2f)\n", rgb.red, rgb.green, rgb.blue, hsv.hue, hsv.saturation, hsv.value);
            break;
        case 2:
            getInputHSV(&hsv);
            hsvToRGB(hsv, &rgb);
            printf("Converted HSV(%.2f, %.2f, %.2f) to RGB(%d, %d, %d)\n", hsv.hue, hsv.saturation, hsv.value, rgb.red, rgb.green, rgb.blue);
            break;
        case 3:
            printf("Choose format to display (1 for RGB, 2 for HSV): ");
            int format_choice;
            scanf("%d", &format_choice);
            if (format_choice == 1) {
                getInputRGB(&rgb);
                printColor("RGB", rgb, hsv);
            } else if (format_choice == 2) {
                getInputHSV(&hsv);
                printColor("HSV", rgb, hsv);
            } else {
                printf("Invalid choice. Please select either 1 or 2.\n");
            }
            break;
        case 0:
            // Exit the program
            break;
        default:
            printf("Invalid option! Please try again.\n");
    }
}

void printColor(const char *format, RGB rgb, HSV hsv) {
    if (strcmp(format, "RGB") == 0) {
        printf("RGB Color: R=%d, G=%d, B=%d\n", rgb.red, rgb.green, rgb.blue);
    } else if (strcmp(format, "HSV") == 0) {
        printf("HSV Color: H=%.2f, S=%.2f, V=%.2f\n", hsv.hue, hsv.saturation, hsv.value);
    }
}

void getInputRGB(RGB *rgb) {
    printf("Enter Red (0-255): ");
    scanf("%d", &rgb->red);
    printf("Enter Green (0-255): ");
    scanf("%d", &rgb->green);
    printf("Enter Blue (0-255): ");
    scanf("%d", &rgb->blue);
}

void getInputHSV(HSV *hsv) {
    printf("Enter Hue (0-360): ");
    scanf("%f", &hsv->hue);
    printf("Enter Saturation (0-1): ");
    scanf("%f", &hsv->saturation);
    printf("Enter Value (0-1): ");
    scanf("%f", &hsv->value);
}

void rgbToHSV(RGB rgb, HSV *hsv) {
    float r = rgb.red / 255.0;
    float g = rgb.green / 255.0;
    float b = rgb.blue / 255.0;

    float max = r > g ? (r > b ? r : b) : (g > b ? g : b);
    float min = r < g ? (r < b ? r : b) : (g < b ? g : b);
    float delta = max - min;

    // Calculate Hue
    if (delta < 0.00001) {
        hsv->hue = 0; // Undefined
    } else if (max == r) {
        hsv->hue = 60 * fmod((g - b) / delta + 6, 6);
    } else if (max == g) {
        hsv->hue = 60 * ((b - r) / delta + 2);
    } else {
        hsv->hue = 60 * ((r - g) / delta + 4);
    }

    // Calculate Saturation
    hsv->saturation = (max == 0) ? 0 : (delta / max);

    // Calculate Value
    hsv->value = max;
}

void hsvToRGB(HSV hsv, RGB *rgb) {
    float r, g, b;
    int i;
    float f, p, q, t;

    if (hsv.saturation == 0) {
        r = g = b = hsv.value; // Achromatic (grey)
    } else {
        hsv.hue /= 60; // sector 0 to 5
        i = (int)floor(hsv.hue);
        f = hsv.hue - i; // factorial part of h
        p = hsv.value * (1 - hsv.saturation);
        q = hsv.value * (1 - hsv.saturation * f);
        t = hsv.value * (1 - hsv.saturation * (1 - f));

        switch (i) {
            case 0: r = hsv.value; g = t; b = p; break;
            case 1: r = q; g = hsv.value; b = p; break;
            case 2: r = p; g = hsv.value; b = t; break;
            case 3: r = p; g = q; b = hsv.value; break;
            case 4: r = t; g = p; b = hsv.value; break;
            default: r = hsv.value; g = p; b = q; break;
        }
    }

    rgb->red = (int)(r * 255 + 0.5);
    rgb->green = (int)(g * 255 + 0.5);
    rgb->blue = (int)(b * 255 + 0.5);
}