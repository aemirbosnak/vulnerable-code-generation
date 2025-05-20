//FormAI DATASET v1.0 Category: Color Code Converter ; Style: enthusiastic
//Welcome to the Color Code Converter!
//This program allows you to convert between different color code formats.
//Let's get started with some fun colorful coding!
#include <stdio.h>

int main() {
    
    //First let's get the user's input
    printf("Enter a color code in RGB format: ");
    int red, green, blue;
    scanf("%d, %d, %d", &red, &green, &blue);
    
    //Now let's convert it to Hex format
    int hex_red, hex_green, hex_blue;
    hex_red = (red / 16) * 10 + (red % 16);
    hex_green = (green / 16) * 10 + (green % 16);
    hex_blue = (blue / 16) * 10 + (blue % 16);
    printf("Hex color code is: #%02x%02x%02x\n", hex_red, hex_green, hex_blue);

    //Next, let's convert it to HSL format
    float h, s, l;
    float float_red = (float)red / 255;
    float float_green = (float)green / 255;
    float float_blue = (float)blue / 255;

    float cmax = float_red;
    if (float_green > cmax) {
        cmax = float_green;
    }
    if (float_blue > cmax) {
        cmax = float_blue;
    }

    float cmin = float_red;
    if (float_green < cmin) {
        cmin = float_green;
    }
    if (float_blue < cmin) {
        cmin = float_blue;
    }

    float delta = cmax - cmin;
    if(delta == 0){
        h = 0;
    } else if (cmax == float_red) {
        h = fmod(((float_green - float_blue)/ delta), 6);
    } else if (cmax == float_green) {
        h = ((float_blue - float_red) / delta) + 2;
    } else {
        h = ((float_red - float_green) / delta) + 4;
    }

    h = h * 60;
    if(h < 0) {
        h = h + 360;
    }

    l = (cmax + cmin) / 2;

    if(delta == 0){
        s = 0;
    } else {
        s = delta / (1 - fabs(2*l - 1));
    }
    
    printf("HSL color code is: hsl(%.f, %.2f%%, %.2f%%)\n", h, s * 100, l * 100);
    
    //Finally, let's convert it to CMYK format
    float c, m, y, k;
    c = (1 - float_red - k) / (1 - k);
    m = (1 - float_green - k) / (1 - k);
    y = (1 - float_blue - k) / (1 - k);
    k = 1 - fmax(float_red, fmax(float_green, float_blue));

    printf("CMYK color code is: cmyk(%.2f%%, %.2f%%, %.2f%%, %.2f%%)\n", c * 100, m * 100, y * 100, k * 100);
    
    //Thank you for using the Color Code Converter!
    return 0;
}