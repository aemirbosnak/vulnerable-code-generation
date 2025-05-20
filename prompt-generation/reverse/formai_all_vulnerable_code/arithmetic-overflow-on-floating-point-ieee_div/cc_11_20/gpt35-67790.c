//FormAI DATASET v1.0 Category: Color Code Converter ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Welcome to the C Color Code Converter! Let's get started!\n");
    printf("\nEnter the HEX color code without the initial #:\n");
    char hex[6];
    scanf("%s", hex);

    // covert HEX to RGB
    int r, g, b;
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);

    // calculate color's brightness
    float brightness = ((float)r * 299 + (float)g * 587 + (float)b * 114) / 1000;

    // determine if color is light or dark
    char light_or_dark[6];
    if (brightness > 125) {
        sprintf(light_or_dark, "light");
    } else {
        sprintf(light_or_dark, "dark");
    }
    printf("\nGreat! Your color is a %s color!\n", light_or_dark);

    // prompt user to convert to RGB or HSL
    printf("\nWould you like to convert your color to RGB or HSL?\n");
    printf("Enter 1 for RGB or 2 for HSL:\n");
    int choice;
    scanf("%d", &choice);

    // convert to RGB
    if (choice == 1) {
        printf("\nConverting %s to RGB...\n", hex);
        printf("R: %d\n", r);
        printf("G: %d\n", g);
        printf("B: %d\n", b);
        printf("\nThank you for using the C Color Code Converter! Have a colorful day!\n");
    }

    // convert to HSL
    if (choice == 2) {
        float h = 0, s = 0, l = 0;

        // normalize RGB values
        float rf = (float)r/255;
        float gf = (float)g/255;
        float bf = (float)b/255;

        // find the minimum and maximum RGB values
        float cmax = (rf > gf) ? rf : gf;
        if (bf > cmax) {
            cmax = bf;
        }
        float cmin = (rf < gf) ? rf : gf;
        if (bf < cmin) {
            cmin = bf;
        }

        // calculate lightness and saturation values
        l = (cmax + cmin) / 2;

        if (cmax == cmin) {
            s = 0;
        } else if (l < 0.5) {
            s = (cmax - cmin) / (cmax + cmin);
        } else {
            s = (cmax - cmin) / (2 - cmax - cmin);
        }

        // calculate hue value
        float delta = cmax - cmin;

        if (delta == 0) {
            h = 0;
        } else if (cmax == rf) {
            h = ((gf - bf) / delta) * 60;
        } else if (cmax == gf) {
            h = (((bf - rf) / delta) + 2) * 60;
        } else {
            h = (((rf - gf) / delta) + 4) * 60;
        }

        if (h < 0) {
            h += 360;
        }

        printf("\nConverting %s to HSL...\n", hex);
        printf("H: %.2f degrees\n", h);
        printf("S: %.2f%%\n", s * 100);
        printf("L: %.2f%%\n", l * 100);
        printf("\nThank you for using the C Color Code Converter! Have a colorful day!\n");
    }
    
    return 0;
}