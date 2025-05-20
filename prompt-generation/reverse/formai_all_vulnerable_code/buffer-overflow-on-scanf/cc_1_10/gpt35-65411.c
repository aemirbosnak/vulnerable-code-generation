//FormAI DATASET v1.0 Category: Color Code Converter ; Style: decentralized
#include <stdio.h> 

int main() {
    int choice;
    float r, g, b;
    float c, m, y, k;

    printf("Choose a conversion type: \n");
    printf("1. RGB to CMYK\n");
    printf("2. CMYK to RGB\n");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter Red value (0-255): ");
        scanf("%f", &r);
        printf("Enter Green value (0-255): ");
        scanf("%f", &g);
        printf("Enter Blue value (0-255): ");
        scanf("%f", &b);

        // Conversion formula for RGB to CMYK
        if(r == 0 && g == 0 && b == 0) {
            c = 0;
            m = 0;
            y = 0;
            k = 1;
        }
        else {
            c = 1 - (r / 255);
            m = 1 - (g / 255);
            y = 1 - (b / 255);

            float min = (c < m) ? c : m;
            min = (min < y) ? min : y;
            k = min;
            c = (c - k) / (1 - k);
            m = (m - k) / (1 - k);
            y = (y - k) / (1 - k);
        }

        printf("The CMYK values are: %f, %f, %f, %f\n", c, m, y, k);
    }
    else if(choice == 2) {
        printf("Enter Cyan value (0-1): ");
        scanf("%f", &c);
        printf("Enter Magenta value (0-1): ");
        scanf("%f", &m);
        printf("Enter Yellow value (0-1): ");
        scanf("%f", &y);
        printf("Enter Black value (0-1): ");
        scanf("%f", &k);

        // Conversion formula for CMYK to RGB
        float r = 255 * (1 - c) * (1 - k);
        float g = 255 * (1 - m) * (1 - k);
        float b = 255 * (1 - y) * (1 - k);

        printf("The RGB values are: %f, %f, %f\n", r, g, b);
    }
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}