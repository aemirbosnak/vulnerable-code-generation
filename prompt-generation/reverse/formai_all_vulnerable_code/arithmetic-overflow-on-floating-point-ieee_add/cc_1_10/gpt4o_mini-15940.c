//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int r, g, b;
} RGB;

typedef struct {
    float h; // Hue
    float s; // Saturation
    float l; // Lightness
} HSL;

char *rgbToHex(RGB rgb) {
    static char hex[8];
    snprintf(hex, sizeof(hex), "#%02X%02X%02X", rgb.r, rgb.g, rgb.b);
    return hex;
}

RGB hexToRGB(const char *hex) {
    RGB rgb;
    sscanf(hex + 1, "%2X%2X%2X", &rgb.r, &rgb.g, &rgb.b);
    return rgb;
}

HSL rgbToHSL(RGB rgb) {
    HSL hsl;
    float r = rgb.r / 255.0;
    float g = rgb.g / 255.0;
    float b = rgb.b / 255.0;

    float max = fmaxf(r, fmaxf(g, b));
    float min = fminf(r, fminf(g, b));
    float delta = max - min;

    // Lightness
    hsl.l = (max + min) / 2;

    // Saturation
    if (delta == 0) {
        hsl.s = 0;
        hsl.h = 0; // Undefined
    } else {
        hsl.s = (hsl.l < 0.5) ? (delta / (max + min)) : (delta / (2 - max - min));
        
        // Hue
        if (max == r) {
            hsl.h = fmodf((g - b) / delta, 6);
        } else if (max == g) {
            hsl.h = (b - r) / delta + 2;
        } else {
            hsl.h = (r - g) / delta + 4;
        }
        hsl.h *= 60;
        if (hsl.h < 0) {
            hsl.h += 360;
        }
    }
    return hsl;
}

RGB hslToRGB(HSL hsl) {
    RGB rgb;
    float c = (1 - fabs(2 * hsl.l - 1)) * hsl.s;
    float x = c * (1 - fabs(fmod(hsl.h / 60.0, 2) - 1));
    float m = hsl.l - c / 2;
    
    if (hsl.h < 60) {
        rgb.r = (c + m) * 255;
        rgb.g = (x + m) * 255;
        rgb.b = m * 255;
    } else if (hsl.h < 120) {
        rgb.r = (x + m) * 255;
        rgb.g = (c + m) * 255;
        rgb.b = m * 255;
    } else if (hsl.h < 180) {
        rgb.r = m * 255;
        rgb.g = (c + m) * 255;
        rgb.b = (x + m) * 255;
    } else if (hsl.h < 240) {
        rgb.r = m * 255;
        rgb.g = (x + m) * 255;
        rgb.b = (c + m) * 255;
    } else if (hsl.h < 300) {
        rgb.r = (x + m) * 255;
        rgb.g = m * 255;
        rgb.b = (c + m) * 255;
    } else {
        rgb.r = (c + m) * 255;
        rgb.g = m * 255;
        rgb.b = (x + m) * 255;
    }
    
    return rgb;
}

void showMenu() {
    printf("\nColor Code Converter\n");
    printf("1. RGB to HEX\n");
    printf("2. HEX to RGB\n");
    printf("3. RGB to HSL\n");
    printf("4. HSL to RGB\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    while (1) {
        showMenu();
        scanf("%d", &choice);
        
        if (choice == 1) {
            RGB rgb;
            printf("Enter RGB values (0-255) separated by spaces: ");
            scanf("%d %d %d", &rgb.r, &rgb.g, &rgb.b);
            printf("HEX code: %s\n", rgbToHex(rgb));
        } else if (choice == 2) {
            char hex[8];
            printf("Enter HEX code (e.g. #FF5733): ");
            scanf("%s", hex);
            RGB rgb = hexToRGB(hex);
            printf("RGB values: %d %d %d\n", rgb.r, rgb.g, rgb.b);
        } else if (choice == 3) {
            RGB rgb;
            printf("Enter RGB values (0-255) separated by spaces: ");
            scanf("%d %d %d", &rgb.r, &rgb.g, &rgb.b);
            HSL hsl = rgbToHSL(rgb);
            printf("HSL values: %.2f %.2f %.2f\n", hsl.h, hsl.s, hsl.l);
        } else if (choice == 4) {
            HSL hsl;
            printf("Enter HSL values (0-360, 0-1, 0-1) separated by spaces: ");
            scanf("%f %f %f", &hsl.h, &hsl.s, &hsl.l);
            RGB rgb = hslToRGB(hsl);
            printf("RGB values: %d %d %d\n", rgb.r, rgb.g, rgb.b);
        } else if (choice == 5) {
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}