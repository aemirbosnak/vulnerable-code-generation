//FormAI DATASET v1.0 Category: Color Code Converter ; Style: imaginative
#include <stdio.h>

int main() {
    // Ask for user input
    printf("Enter the color code you want to convert (RGB, HEX, or CMYK):\n");

    char colorCode[4];
    scanf("%s", colorCode);

    // Convert RGB to HEX
    if (strcmp(colorCode, "RGB") == 0) {
        int r, g, b;

        printf("Enter the red value (0-255):\n");
        scanf("%d", &r);
        printf("Enter the green value (0-255):\n");
        scanf("%d", &g);
        printf("Enter the blue value (0-255):\n");
        scanf("%d", &b);

        printf("The converted color code is: #%02x%02x%02x\n", r, g, b);
    }

    // Convert HEX to RGB
    else if (strcmp(colorCode, "HEX") == 0) {
        char hex[7];

        printf("Enter the hex value (without the #):\n");
        scanf("%s", hex);

        unsigned int r, g, b;
        sscanf(hex, "%02x%02x%02x", &r, &g, &b);

        printf("The converted color code is: %d, %d, %d\n", r, g, b);
    }

    // Convert CMYK to RGB
    else if (strcmp(colorCode, "CMYK") == 0) {
        float c, m, y, k;

        printf("Enter the cyan value (0-100):\n");
        scanf("%f", &c);
        printf("Enter the magenta value (0-100):\n");
        scanf("%f", &m);
        printf("Enter the yellow value (0-100):\n");
        scanf("%f", &y);
        printf("Enter the black value (0-100):\n");
        scanf("%f", &k);

        int r, g, b;
        r = (int)(255 * (1 - c / 100) * (1 - k / 100));
        g = (int)(255 * (1 - m / 100) * (1 - k / 100));
        b = (int)(255 * (1 - y / 100) * (1 - k / 100));

        printf("The converted color code is: %d, %d, %d\n", r, g, b);
    }

    else {
        printf("Invalid color code entered.");
    }

    return 0;
}