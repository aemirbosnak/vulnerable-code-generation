//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define RGB_MAX 255

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

void printMenu() {
    printf("\nColor Code Converter\n");
    printf("1. RGB to HSV\n");
    printf("2. HSV to RGB\n");
    printf("3. Exit\n");
    printf("Choose an option (1-3): ");
}

void rgbToHsv(RGB rgb, HSV *hsv) {
    float r = rgb.r / (float)RGB_MAX;
    float g = rgb.g / (float)RGB_MAX;
    float b = rgb.b / (float)RGB_MAX;

    float max = fmaxf(r, fmaxf(g, b));
    float min = fminf(r, fminf(g, b));
    float delta = max - min;

    if (max == 0) {
        hsv->s = 0;
    } else {
        hsv->s = (delta / max) * 100; // Convert to percentage
    }

    if (delta == 0) {
        hsv->h = 0;
    } else {
        if (max == r) {
            hsv->h = (int)((60 * ((g - b) / delta) + 360)) % 360;
        } else if (max == g) {
            hsv->h = (int)((60 * ((b - r) / delta) + 120));
        } else {
            hsv->h = (int)((60 * ((r - g) / delta) + 240));
        }
    }

    hsv->v = (int)(max * 100); // Convert to percentage
}

void hsvToRgb(HSV hsv, RGB *rgb) {
    float s = hsv.s / 100.0;
    float v = hsv.v / 100.0;
    
    float c = v * s;
    float x = c * (1 - fabsf(fmodf((hsv.h / 60.0), 2) - 1));
    float m = v - c;

    float r = 0, g = 0, b = 0;

    if (hsv.h < 60) {
        r = c, g = x, b = 0;
    } else if (hsv.h < 120) {
        r = x, g = c, b = 0;
    } else if (hsv.h < 180) {
        r = 0, g = c, b = x;
    } else if (hsv.h < 240) {
        r = 0, g = x, b = c;
    } else if (hsv.h < 300) {
        r = x, g = 0, b = c;
    } else {
        r = c, g = 0, b = x;
    }
    
    rgb->r = (int)((r + m) * RGB_MAX);
    rgb->g = (int)((g + m) * RGB_MAX);
    rgb->b = (int)((b + m) * RGB_MAX);
}

void getRGBInput(RGB *rgb) {
    printf("Enter RGB values (0-255):\n");
    printf("R: ");
    scanf("%d", &rgb->r);
    printf("G: ");
    scanf("%d", &rgb->g);
    printf("B: ");
    scanf("%d", &rgb->b);
}

void getHSVInput(HSV *hsv) {
    printf("Enter HSV values (H: 0-360, S: 0-100, V: 0-100):\n");
    printf("H: ");
    scanf("%d", &hsv->h);
    printf("S: ");
    scanf("%d", &hsv->s);
    printf("V: ");
    scanf("%d", &hsv->v);
}

int main() {
    int option;
    RGB rgb;
    HSV hsv;

    while (1) {
        printMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                getRGBInput(&rgb);
                rgbToHsv(rgb, &hsv);
                printf("HSV: H=%d, S=%d%%, V=%d%%\n", hsv.h, hsv.s, hsv.v);
                break;
            case 2:
                getHSVInput(&hsv);
                hsvToRgb(hsv, &rgb);
                printf("RGB: R=%d, G=%d, B=%d\n", rgb.r, rgb.g, rgb.b);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}