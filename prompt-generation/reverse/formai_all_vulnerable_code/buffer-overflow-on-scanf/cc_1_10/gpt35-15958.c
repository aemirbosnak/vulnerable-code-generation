//FormAI DATASET v1.0 Category: Color Code Converter ; Style: detailed
#include<stdio.h>

int main() {
    int choice;
    float r, g, b, c, m, y, k;
    printf("Welcome to Color Code Converter!\n\n");
    printf("Select the type of color code that you have:\n");
    printf("1. RGB (Red, Green, Blue)\n");
    printf("2. CMY (Cyan, Magenta, Yellow)\n");
    printf("3. CMYK (Cyan, Magenta, Yellow, Key/Black)\n");
    scanf("%d", &choice);

    // RGB to CMY conversion
    if (choice == 1) {
        printf("\nEnter the values of Red, Green, and Blue color code (0 to 255):\n");
        scanf("%f%f%f", &r, &g, &b);

        c = (255 - r) / 255.0;
        m = (255 - g) / 255.0;
        y = (255 - b) / 255.0;

        printf("\nCMY Color Code: %.2f, %.2f, %.2f\n", c, m, y);
    }

    // CMY to RGB conversion
    else if (choice == 2) {
        printf("\nEnter the values of Cyan, Magenta, and Yellow color code (0 to 1):\n");
        scanf("%f%f%f", &c, &m, &y);

        r = (1.0 - c) * 255.0;
        g = (1.0 - m) * 255.0;
        b = (1.0 - y) * 255.0;

        printf("\nRGB Color Code: %.0f, %.0f, %.0f\n", r, g, b);
    }

    // CMYK to RGB conversion
    else if (choice == 3) {
        printf("\nEnter the values of Cyan, Magenta, Yellow, and Key/Black color code (0 to 1):\n");
        scanf("%f%f%f%f", &c, &m, &y, &k);

        r = (1.0 - c) * (1.0 - k) * 255.0;
        g = (1.0 - m) * (1.0 - k) * 255.0;
        b = (1.0 - y) * (1.0 - k) * 255.0;

        printf("\nRGB Color Code: %.0f, %.0f, %.0f\n", r, g, b);
    }

    // Invalid choice
    else {
        printf("\nInvalid choice. Please select from the given options.\n");
    }

    return 0;
}