//FormAI DATASET v1.0 Category: Color Code Converter ; Style: immersive
#include <stdio.h>

int main() {
    printf("Welcome to C Color Code Converter!\n\n");
    printf("Please enter the hexadecimal color code you want to convert: ");
    char hex[7];
    scanf("%s", hex);

    int red = 0;
    int green = 0;
    int blue = 0;

    // Convert hex to RGB
    for (int i = 0; i < 6; i += 2) {
        char hexValue[3] = { hex[i], hex[i+1], '\0' };
        int decimalValue = (int)strtol(hexValue, NULL, 16);
        switch(i) {
            case 0:
                red = decimalValue;
                break;
            case 2:
                green = decimalValue;
                break;
            case 4:
                blue = decimalValue;
                break;
        }
    }

    printf("\nRGB Color Code: (%d, %d, %d)\n", red, green, blue);

    // Convert RGB to CMYK
    float c = 0.0f;
    float m = 0.0f;
    float y = 0.0f;
    float k = 0.0f;

    if (red == 0 && green == 0 && blue == 0) {
        k = 1;
    } else {
        c = 1 - (red / 255.0f);
        m = 1 - (green / 255.0f);
        y = 1 - (blue / 255.0f);

        float minCMY = c < m ? c : m;
        minCMY = minCMY < y ? minCMY : y;

        c = (c - minCMY) / (1 - minCMY);
        m = (m - minCMY) / (1 - minCMY);
        y = (y - minCMY) / (1 - minCMY);
        k = minCMY;
    }

    printf("CMYK Color Code: (%.2f, %.2f, %.2f, %.2f)\n", c, m, y, k);

    return 0;
}