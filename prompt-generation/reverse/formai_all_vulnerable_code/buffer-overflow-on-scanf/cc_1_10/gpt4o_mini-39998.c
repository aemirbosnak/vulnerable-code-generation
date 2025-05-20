//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// The remnants of civilization faded, 
// Yet, the need for color persisted in the minds of the few 
// survivors. Welcome to the C Color Code Converter for the lost world.

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

// Function to convert RGB to HSV
HSV rgbToHsv(RGB rgb) {
    HSV hsv;
    float r = rgb.r / 255.0, g = rgb.g / 255.0, b = rgb.b / 255.0;
    float max = fmaxf(r, fmaxf(g, b));
    float min = fminf(r, fminf(g, b));
    float delta = max - min;

    // Hue
    if (delta < 0.00001) {
        hsv.h = 0;
    } else if (max == r) {
        hsv.h = (int)(60 * fmod(((g - b) / delta), 6));
    } else if (max == g) {
        hsv.h = (int)(60 * (((b - r) / delta) + 2));
    } else {
        hsv.h = (int)(60 * (((r - g) / delta) + 4));
    }
    if (hsv.h < 0) {
        hsv.h += 360;
    }

    // Saturation
    if (max < 0.00001) {
        hsv.s = 0;
    } else {
        hsv.s = (int)(delta / max * 100);
    }

    // Value
    hsv.v = (int)(max * 100);
    
    return hsv;
}

// Function to convert HSV to RGB
RGB hsvToRgb(HSV hsv) {
    RGB rgb;
    float r, g, b;
    float hp = hsv.h / 60.0;
    float c = (hsv.v / 100.0) * (hsv.s / 100.0);
    float x = c * (1 - fabs(fmod(hp, 2) - 1));
    float m = (hsv.v / 100.0) - c;

    if (0 <= hp && hp < 1) {
        r = c; g = x; b = 0;
    } else if (1 <= hp && hp < 2) {
        r = x; g = c; b = 0;
    } else if (2 <= hp && hp < 3) {
        r = 0; g = c; b = x;
    } else if (3 <= hp && hp < 4) {
        r = 0; g = x; b = c;
    } else if (4 <= hp && hp < 5) {
        r = x; g = 0; b = c;
    } else {
        r = c; g = 0; b = x;
    }

    rgb.r = (int)((r + m) * 255);
    rgb.g = (int)((g + m) * 255);
    rgb.b = (int)((b + m) * 255);

    return rgb;
}

// Function to display the menu
void displayMenu() {
    printf("In a world turned to ash, colors still breathe life.\n");
    printf("1. Convert RGB to HSV\n");
    printf("2. Convert HSV to RGB\n");
    printf("3. Exit\n");
    printf("Choose your destiny (1-3): ");
}

// The last bastion of programming in a broken world
int main() {
    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);

        if (choice == 3) {
            printf("The colors fade as you leave...\n");
            break;
        }

        if (choice == 1) {
            RGB rgb;
            printf("Enter values of R, G, B (0-255): ");
            scanf("%d %d %d", &rgb.r, &rgb.g, &rgb.b);
            HSV hsv = rgbToHsv(rgb);
            printf("The new hue stands at: H: %d, S: %d, V: %d\n", hsv.h, hsv.s, hsv.v);
        } else if (choice == 2) {
            HSV hsv;
            printf("Enter values of H (0-360), S (0-100), V (0-100): ");
            scanf("%d %d %d", &hsv.h, &hsv.s, &hsv.v);
            RGB rgb = hsvToRgb(hsv);
            printf("Colors rise anew as: R: %d, G: %d, B: %d\n", rgb.r, rgb.g, rgb.b);
        } else {
            printf("In the ashes of your choice, the wrong path lays.\n");
        }
    }
    return 0;
}