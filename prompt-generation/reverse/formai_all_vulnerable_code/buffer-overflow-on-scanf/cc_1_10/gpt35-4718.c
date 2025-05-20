//FormAI DATASET v1.0 Category: Color Code Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int hexToDec(char hex)
{
    if (hex >= '0' && hex <= '9')
    {
        return hex - '0';
    }
    else if (hex >= 'A' && hex <= 'F')
    {
        return hex - 'A' + 10;
    }
    else if (hex >= 'a' && hex <= 'f')
    {
        return hex - 'a' + 10;
    }
    else
    {
        return -1;
    }
}

void printRgb(int r, int g, int b)
{
    printf("RGB Color: (%d, %d, %d)\n", r, g, b);
}

void printCmyk(float c, float m, float y, float k)
{
    printf("CMYK Color: (%.2f, %.2f, %.2f, %.2f)\n", c, m, y, k);
}

void printHex(char* hex)
{
    printf("Hex Color: %s\n", hex);
}

int main()
{
    int r, g, b;
    float c, m, y, k;
    char hex[7];

    printf("Enter a color in hexadecimal format (RRGGBB): ");
    scanf("%s", hex);

    // Convert hex to RGB
    r = hexToDec(hex[0]) * 16 + hexToDec(hex[1]);
    g = hexToDec(hex[2]) * 16 + hexToDec(hex[3]);
    b = hexToDec(hex[4]) * 16 + hexToDec(hex[5]);

    // Print RGB color
    printRgb(r, g, b);

    // Convert RGB to CMYK
    float r_norm = r / 255.0;
    float g_norm = g / 255.0;
    float b_norm = b / 255.0;

    k = 1 - fmaxf(fmaxf(r_norm, g_norm), b_norm);

    if (k == 1.0)
    {
        c = 0.0;
        m = 0.0;
        y = 0.0;
    }
    else
    {
        c = (1 - r_norm - k) / (1 - k);
        m = (1 - g_norm - k) / (1 - k);
        y = (1 - b_norm - k) / (1 - k);   
    }

    // Print CMYK color
    printCmyk(c, m, y, k);

    // Print Hex color
    printHex(hex);

    return 0;
}