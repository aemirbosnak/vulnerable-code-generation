//FormAI DATASET v1.0 Category: Color Code Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void displayMenu();
void convertToRGB();
void convertToHex();
void convertToCMYK();

int main()
{
    displayMenu();
    return 0;
}

void displayMenu()
{
    int choice;
    printf("=== Color Code Converter ===\n");
    printf("1. Convert CMYK to RGB\n");
    printf("2. Convert RGB to Hex\n");
    printf("3. Convert Hex to RGB\n");
    printf("4. Convert RGB to CMYK\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            convertToRGB();
            break;
        case 2:
            convertToHex();
            break;
        case 3:
            convertToRGB();
            break;
        case 4:
            convertToCMYK();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice. Try again.\n");
            displayMenu();
            break;
    }
}

void convertToRGB()
{
    float c, m, y, k, r, g, b;
    printf("Enter CMYK values (separated by comma): ");
    scanf("%f,%f,%f,%f", &c, &m, &y, &k);

    r = (1 - c) * (1 - k);
    g = (1 - m) * (1 - k);
    b = (1 - y) * (1 - k);

    printf("RGB values: %.0f, %.0f, %.0f\n", r * 255, g * 255, b * 255);
}

void convertToHex()
{
    int r, g, b;
    printf("Enter RGB values (separated by comma): ");
    scanf("%d,%d,%d", &r, &g, &b);

    char hex[7];
    snprintf(hex, sizeof hex, "#%02x%02x%02x", r, g, b);

    printf("Hex code: %s\n", hex);
}

void convertToCMYK()
{
    int r, g, b;
    printf("Enter RGB values (separated by comma): ");
    scanf("%d,%d,%d", &r, &g, &b);

    float c, m, y, k;

    float R = (float) r / 255;
    float G = (float) g / 255;
    float B = (float) b / 255;

    float max = R > G ? (R > B ? R : B) : (G > B ? G : B);
    k = 1 - max;

    if (max == 0)
    {
        c = m = y = 0;
    }
    else
    {
        c = (max - R) / max;
        m = (max - G) / max;
        y = (max - B) / max;
    }

    printf("CMYK values: %.2f, %.2f, %.2f, %.2f\n", c, m, y, k);
}