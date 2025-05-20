//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void rgbToHex(int r, int g, int b);
void hexToRgb(const char *hex);
void rgbToHsl(int r, int g, int b);
void hslToRgb(float h, float s, float l);
void displayMenu();

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting the program.\n");
            break;
        }

        switch (choice) {
            case 1: {
                int r, g, b;
                printf("Enter RGB values (0-255 each, separated by space): ");
                scanf("%d %d %d", &r, &g, &b);
                if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
                    printf("Invalid RGB values. Please enter values between 0 and 255.\n");
                } else {
                    rgbToHex(r, g, b);
                }
                break;
            }
            case 2: {
                char hex[8];
                printf("Enter HEX value (with #, e.g., #FF5733): ");
                scanf("%s", hex);
                hexToRgb(hex);
                break;
            }
            case 3: {
                int r, g, b;
                printf("Enter RGB values (0-255 each, separated by space): ");
                scanf("%d %d %d", &r, &g, &b);
                rgbToHsl(r, g, b);
                break;
            }
            case 4: {
                float h, s, l;
                printf("Enter HSL values (h: 0-360, s: 0-1, l: 0-1): ");
                scanf("%f %f %f", &h, &s, &l);
                hslToRgb(h, s, l);
                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}

void displayMenu() {
    printf("\nColor Code Converter\n");
    printf("1. RGB to HEX\n");
    printf("2. HEX to RGB\n");
    printf("3. RGB to HSL\n");
    printf("4. HSL to RGB\n");
    printf("5. Exit\n");
}

void rgbToHex(int r, int g, int b) {
    printf("HEX: #%02X%02X%02X\n", r, g, b);
}

void hexToRgb(const char *hex) {
    int r, g, b;
    if (sscanf(hex + 1, "%02X%02X%02X", &r, &g, &b) == 3) {
        printf("RGB: (%d, %d, %d)\n", r, g, b);
    } else {
        printf("Invalid HEX format.\n");
    }
}

void rgbToHsl(int r, int g, int b) {
    float rNorm = r / 255.0;
    float gNorm = g / 255.0;
    float bNorm = b / 255.0;

    float max = (rNorm > gNorm) ? (rNorm > bNorm ? rNorm : bNorm) : (gNorm > bNorm ? gNorm : bNorm);
    float min = (rNorm < gNorm) ? (rNorm < bNorm ? rNorm : bNorm) : (gNorm < bNorm ? gNorm : bNorm);
    float h, s, l = (max + min) / 2.0;

    if (max == min) {
        h = s = 0; // achromatic
    } else {
        float d = max - min;
        s = (l > 0.5) ? d / (2.0 - max - min) : d / (max + min);
        if (max == rNorm) {
            h = (gNorm - bNorm) / d + (gNorm < bNorm ? 6 : 0);
        } else if (max == gNorm) {
            h = (bNorm - rNorm) / d + 2.0;
        } else {
            h = (rNorm - gNorm) / d + 4.0;
        }
        h /= 6.0;
    }

    printf("HSL: (%.1f°, %.2f, %.2f)\n", h * 360, s, l);
}

void hslToRgb(float h, float s, float l) {
    float c = (1 - fabs(2 * l - 1)) * s;
    float x = c * (1 - fabs(fmod(h / 60.0, 2) - 1));
    float m = l - c / 2;

    float r, g, b;
    if (h < 60) {
        r = c; g = x; b = 0;
    } else if (h < 120) {
        r = x; g = c; b = 0;
    } else if (h < 180) {
        r = 0; g = c; b = x;
    } else if (h < 240) {
        r = 0; g = x; b = c;
    } else if (h < 300) {
        r = x; g = 0; b = c;
    } else {
        r = c; g = 0; b = x;
    }
    r = (r + m) * 255;
    g = (g + m) * 255;
    b = (b + m) * 255;

    printf("RGB: (%.0f, %.0f, %.0f)\n", r, g, b);
}