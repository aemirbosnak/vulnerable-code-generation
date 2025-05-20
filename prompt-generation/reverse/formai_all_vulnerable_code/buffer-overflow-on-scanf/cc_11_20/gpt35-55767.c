//FormAI DATASET v1.0 Category: Color Code Converter ; Style: artistic
#include <stdio.h>

int main()
{
    int c;
    printf("Please enter an RGB color code: ");
    scanf("%d", &c);

    int r = (c >> 16) & 255;
    int g = (c >> 8) & 255;
    int b = c & 255;

    printf("The RGB values for color code #%d are: ", c);
    printf("R=%d, G=%d, B=%d\n", r, g, b);

    int h, s, v;
    int max = (r > g) ? ((r > b) ? r : b) : ((g > b) ? g : b);
    int min = (r < g) ? ((r < b) ? r : b) : ((g < b) ? g : b);

    if (max == min)
    {
        h = 0;
    }
    else if (max == r)
    {
        h = (60 * ((g - b) / (float)(max - min))) + 360;
    }
    else if (max == g)
    {
        h = (60 * ((b - r) / (float)(max - min))) + 120;
    }
    else if (max == b)
    {
        h = (60 * ((r - g) / (float)(max - min))) + 240;
    }

    if (max == 0)
    {
        s = 0;
    }
    else
    {
        s = ((max - min) / (float)max) * 100;
    }

    v = (max / (float)255) * 100;

    printf("The HSV values for color code #%d are: ", c);
    printf("H=%d°, S=%d%%, V=%d%%", h, s, v);

    return 0;
}