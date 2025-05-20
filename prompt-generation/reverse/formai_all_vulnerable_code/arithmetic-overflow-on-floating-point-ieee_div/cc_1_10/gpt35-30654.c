//FormAI DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>
#include <math.h>

// function to convert RGB to HSL
void RGBtoHSL(int r, int g, int b)
{
    float h, s, l;
    float red, green, blue;
    float max, min, delta;

    red = r / 255.0;
    green = g / 255.0;
    blue = b / 255.0;

    max = fmax(fmax(red, green), blue);
    min = fmin(fmin(red, green), blue);
    delta = max - min;

    // calculate luminance
    l = (max + min) / 2;

    if(delta == 0)
    {
        h = 0;
        s = 0;
    }
    else
    {
        // calculate hue
        if(max == red)
            h = 60 * fmod(((green - blue) / delta), 6);
        else if(max == green)
            h = 60 * (((blue - red) / delta) + 2);
        else if(max == blue)
            h = 60 * (((red - green) / delta) + 4);

        // calculate saturation
        if(l < 0.5)
            s = delta / (2 * l);
        else
            s = delta / (2 - (2 * l));
    }

    printf("HSL: %f,%f,%f\n", h, s, l);
}

// function to convert HSL to RGB
void HSLtoRGB(float h, float s, float l)
{
    float r, g, b;
    float c, x, m;
    int hr;

    if(s == 0)
    {
        r = g = b = l;
    }
    else
    {
        if(l < 0.5)
            c = 2 * l * s;
        else
            c = (2 - (2 * l)) * s;

        hr = (int)(h / 60);
        x = c * (1 - fabs(fmod((h / 60), 2) - 1));
        m = l - (c / 2);

        switch(hr)
        {
            case 0:
                r = c;
                g = x;
                b = 0;
                break;
            case 1:
                r = x;
                g = c;
                b = 0;
                break;
            case 2:
                r = 0;
                g = c;
                b = x;
                break;
            case 3:
                r = 0;
                g = x;
                b = c;
                break;
            case 4:
                r = x;
                g = 0;
                b = c;
                break;
            case 5:
                r = c;
                g = 0;
                b = x;
                break;
        }

        r += m;
        g += m;
        b += m;
    }

    printf("RGB: %f,%f,%f\n", r*255, g*255, b*255);
}

// main function
int main()
{
    int r, g, b;
    float h, s, l;
    char choice;

    printf("Enter color in RGB format (e.g 255,0,0): ");
    scanf("%d,%d,%d", &r, &g, &b);

    RGBtoHSL(r, g, b);

    printf("Enter color in HSL format (e.g 0,1,0.5): ");
    scanf("%f,%f,%f", &h, &s, &l);

    HSLtoRGB(h, s, l);

    printf("Do you want to convert another color? (y/n): ");
    scanf(" %c", &choice);

    if(choice == 'y' || choice == 'Y')
        main();
            
    return 0;
}