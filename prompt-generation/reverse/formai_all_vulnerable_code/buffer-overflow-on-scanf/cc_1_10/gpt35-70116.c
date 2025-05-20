//FormAI DATASET v1.0 Category: Color Code Converter ; Style: satisfied
#include <stdio.h>

// convert hexadecimal to decimal function
int hex_to_dec(char c) {
    if (c >= 48 && c <= 57) {
        return c - 48;
    } else if (c >= 65 && c <= 70) {
        return c - 55;
    } else {
        return -1; // return -1 if character is invalid
    }
}

// convert decimal to hexadecimal function
char dec_to_hex(int n) {
    if (n >= 0 && n <= 9) {
        return n + 48;
    } else if (n >= 10 && n <= 15) {
        return n + 55;
    } else {
        return '!'; // return '!' if value is invalid
    }
}

int main() {
    char color_code[7];
    printf("Enter a 6-digit hexadecimal color code (ex: 'FF0000' for red): ");
    scanf("%s", color_code);
    
    // validate the input
    int invalid_code = 0;
    for (int i = 0; i < 6; i++) {
        if (hex_to_dec(color_code[i]) == -1) {
            invalid_code = 1;
            break;
        }
    }
    
    if (invalid_code) {
        printf("Invalid color code!"); 
    } else {
        int red = hex_to_dec(color_code[0]) * 16 + hex_to_dec(color_code[1]);
        int green = hex_to_dec(color_code[2]) * 16 + hex_to_dec(color_code[3]);
        int blue = hex_to_dec(color_code[4]) * 16 + hex_to_dec(color_code[5]);
        
        // print the RGB values
        printf("RGB: (%d,%d,%d)\n", red, green, blue);
        
        // convert RGB to CMYK (source: https://www.rapidtables.com/convert/color/rgb-to-cmyk.html)
        double r = (double)red / 255;
        double g = (double)green / 255;
        double b = (double)blue / 255;
        
        double k = 1 - fmax(fmax(r, g), b);
        double c = (1 - r - k) / (1 - k);
        double m = (1 - g - k) / (1 - k);
        double y = (1 - b - k) / (1 - k);
        
        // print the CMYK values
        printf("CMYK: (%.2f,%.2f,%.2f,%.2f)\n", c, m, y, k);
        
        // convert RGB to HSL (source: https://www.rapidtables.com/convert/color/rgb-to-hsl.html)
        double min_rgb = fmin(fmin(r, g), b);
        double max_rgb = fmax(fmax(r, g), b);
        double delta = max_rgb - min_rgb;
        
        double h, s, l;
        l = (max_rgb + min_rgb) / 2;
        
        if (delta == 0) {
            h = 0;
            s = 0;
        } else {
            if (l < 0.5) {
                s = delta / (max_rgb + min_rgb);
            } else {
                s = delta / (2.0 - max_rgb - min_rgb);
            }
            
            if (r == max_rgb) {
                h = (g - b) / delta;
            } else if (g == max_rgb) {
                h = 2.0 + (b - r) / delta;
            } else {
                h = 4.0 + (r - g) / delta;
            }
            
            h *= 60;
            if (h < 0) { h += 360; }
        }
        
        // print the HSL values
        printf("HSL: (%.2f,%.2f,%.2f)\n", h, s, l);
        
        // convert RGB to HSV (source: https://www.rapidtables.com/convert/color/rgb-to-hsv.html)
        double v = max_rgb;
        double sv;
        
        if (delta == 0) {
            sv = 0;
        } else {
            sv = delta / v;
        }
        
        double h2;
        
        if (r == max_rgb) {
            h2 = (g - b) / delta;
        } else if (g == max_rgb) {
            h2 = 2.0 + (b - r) / delta;
        } else {
            h2 = 4.0 + (r - g) / delta;
        }
        
        h2 *= 60;
        if (h2 < 0) { h2 += 360; }
        
        // print the HSV values
        printf("HSV: (%.2f,%.2f,%.2f)\n", h2, sv, v);
    }
    
    return 0;
}