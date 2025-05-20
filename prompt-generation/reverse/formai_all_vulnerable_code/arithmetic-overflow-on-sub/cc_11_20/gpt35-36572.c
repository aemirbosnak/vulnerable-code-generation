//FormAI DATASET v1.0 Category: Color Code Converter ; Style: creative
#include <stdio.h>

int main() {

    int r, g, b;
    
    printf("Enter the RGB values (0-255):\n");
    scanf("%d %d %d", &r, &g, &b);
    
    int max, min;
    float h = 0, s, v;
    
    // Find the maximum and minimum values of r, g, b
    
    max = r;
    min = r;
    
    if (g > max) {
        max = g;
    }
    
    if (b > max) {
        max = b;
    }
    
    if (g < min) {
        min = g;
    }
    
    if (b < min) {
        min = b;
    }
    
    // Calculate hue, saturation and value
    
    if (max == min) {
        h = 0;
    } else if (max == r) {
        h = 60 * ((g - b) / (float)(max - min));
    } else if (max == g) {
        h = 60 * ((b - r) / (float)(max - min)) + 120;
    } else if (max == b) {
        h = 60 * ((r - g) / (float)(max - min)) + 240;
    }
    
    if (max == 0) {
        s = 0;
    } else {
        s = (max - min) / (float)max;
    }
    
    v = max / (float)255;
    
    // Convert HSV to HSL
    
    float l, s_l;
    
    l = (2 - s) * v / 2;
    
    if (l == 0 || v == 0) {
        s_l = 0;
    } else if (l == 1 || v == 1) {
        s_l = 0;
    } else if (l <= 0.5) {
        s_l = s * v / (l * 2);
    } else {
        s_l = s * v / (2 - l * 2);
    }
    
    // Convert HSL to CSS color code
    
    int h_c, s_c, l_c;
    char css_code[8];
    
    h_c = (int)h % 360;
    s_c = (int)(s_l * 100);
    l_c = (int)(l * 100);
    
    sprintf(css_code, "#%02x%02x%02x", r, g, b);
    
    printf("Color code in CSS: %s\n", css_code);
    printf("Color code in HSL: hsl(%d, %d%%, %d%%)", h_c, s_c, l_c);
    
    return 0;
}