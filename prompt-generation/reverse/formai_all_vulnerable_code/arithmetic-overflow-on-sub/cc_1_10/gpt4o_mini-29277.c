//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int red;
    int green;
    int blue;
} RGB;

typedef struct {
    int cyan;
    int magenta;
    int yellow;
    int black;
} CMYK;

RGB hexToRGB(const char *hex) {
    RGB rgb;
    if (hex[0] == '#') {
        hex++;
    }
    sscanf(hex, "%02x%02x%02x", &rgb.red, &rgb.green, &rgb.blue);
    return rgb;
}

CMYK rgbToCMYK(RGB rgb) {
    CMYK cmyk;
    int r = rgb.red;
    int g = rgb.green;
    int b = rgb.blue;

    int k = 255 - (r > g ? (r > b ? r : b) : (g > b ? g : b));
    cmyk.black = k;

    if (k == 255) {
        cmyk.cyan = 0;
        cmyk.magenta = 0;
        cmyk.yellow = 0;
    } else {
        cmyk.cyan = (255 - r - k) * 255 / (255 - k);
        cmyk.magenta = (255 - g - k) * 255 / (255 - k);
        cmyk.yellow = (255 - b - k) * 255 / (255 - k);
    }
    
    return cmyk;
}

void printCMYK(CMYK cmyk) {
    printf("C: %d%%, M: %d%%, Y: %d%%, K: %d%%\n", cmyk.cyan, cmyk.magenta, cmyk.yellow, cmyk.black);
}

void printRGB(RGB rgb) {
    printf("R: %d, G: %d, B: %d\n", rgb.red, rgb.green, rgb.blue);
}

int main() {
    char hexColor[8];
    
    printf("Enter a HEX color code (e.g. #FF5733): ");
    if (!fgets(hexColor, sizeof(hexColor), stdin)) {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }
    
    hexColor[strcspn(hexColor, "\n")] = 0; // Removing newline character
    if (hexColor[0] != '#' || strlen(hexColor) != 7) {
        fprintf(stderr, "Invalid HEX format. Please use #RRGGBB format.\n");
        return EXIT_FAILURE;
    }

    RGB rgb = hexToRGB(hexColor);
    printf("RGB values:\n");
    printRGB(rgb);
    
    CMYK cmyk = rgbToCMYK(rgb);
    printf("CMYK values:\n");
    printCMYK(cmyk);

    return EXIT_SUCCESS;
}