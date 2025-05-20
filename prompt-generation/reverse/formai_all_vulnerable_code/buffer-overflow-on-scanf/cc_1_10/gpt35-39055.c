//FormAI DATASET v1.0 Category: Color Code Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Color Code Converter!\n");
    printf("Enter the type of code you want to convert (RGB or CMYK): ");

    char code_type[5];
    scanf("%s", code_type);

    if (strcmp(code_type, "RGB") == 0)
    {
        printf("Enter the RGB values (separated by commas): ");
        int r, g, b;
        scanf("%d,%d,%d", &r, &g, &b);

        // Conversion formula for RGB to CMYK
        double c = 1 - ((double) r / 255);
        double m = 1 - ((double) g / 255);
        double y = 1 - ((double) b / 255);
        double k = 0;

        if (c < k)
            k = c;
        if (m < k)
            k = m;
        if (y < k)
            k = y;
        if (k == 1)
            c = m = y = 0;
        else
        {
            c = (c - k) / (1 - k);
            m = (m - k) / (1 - k);
            y = (y - k) / (1 - k);
        }

        // Output the CMYK values
        printf("The CMYK values are: %f, %f, %f, %f\n", c, m, y, k);
    }
    else if (strcmp(code_type, "CMYK") == 0)
    {
        printf("Enter the CMYK values (separated by commas): ");
        double c, m, y, k;
        scanf("%lf,%lf,%lf,%lf", &c, &m, &y, &k);

        // Conversion formula for CMYK to RGB
        int r = (int) (255 * (1 - c) * (1 - k));
        int g = (int) (255 * (1 - m) * (1 - k));
        int b = (int) (255 * (1 - y) * (1 - k));

        // Output the RGB values
        printf("The RGB values are: %d, %d, %d\n", r, g, b);
    }
    else
    {
        printf("Invalid code type entered. Please enter RGB or CMYK.\n");
    }

    return 0;
}