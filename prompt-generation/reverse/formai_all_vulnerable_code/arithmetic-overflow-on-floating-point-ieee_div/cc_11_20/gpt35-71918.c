//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int hexToDecimal(char hex) {
    if(hex >= '0' && hex <= '9') {
        return hex - '0';
    } else if(hex >= 'a' && hex <= 'f') {
        return hex - 'a' + 10;
    } else if(hex >= 'A' && hex <= 'F') {
        return hex - 'A' + 10;
    } else {
        return -1;
    }
}

int main() {
    char colorCode[7];
    printf("Enter a 6-digit color code (in hexadecimal): ");
    scanf("%s", colorCode);

    int r, g, b;
    r = (hexToDecimal(colorCode[0]) * 16) + hexToDecimal(colorCode[1]);
    g = (hexToDecimal(colorCode[2]) * 16) + hexToDecimal(colorCode[3]);
    b = (hexToDecimal(colorCode[4]) * 16) + hexToDecimal(colorCode[5]);

    printf("RGB code : (%d,%d,%d)\n", r, g, b);

    int choice;
    printf("Convert RGB to which color space? Enter 1 for CMYK, 2 for HSL, 3 for HSV: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            float c, m, y, k;
            c = 1 - (r/255.0);
            m = 1 - (g/255.0);
            y = 1 - (b/255.0);

            k = c;
            if(m < k) k = m;
            if(y < k) k = y;

            c = (c - k) / (1 - k);
            m = (m - k) / (1 - k);
            y = (y - k) / (1 - k);

            printf("CMYK code : (%.2f,%.2f,%.2f,%.2f)\n", c, m, y, k);
            break;
        }
        case 2: {
            float h, s, l;
            float r_ = r/255.0, g_ = g/255.0, b_ = b/255.0;

            float minRGB = r_;
            if(g_ < minRGB) minRGB = g_;
            if(b_ < minRGB) minRGB = b_;

            float maxRGB = r_;
            if(g_ > maxRGB) maxRGB = g_;
            if(b_ > maxRGB) maxRGB = b_;

            // hue calculation
            if(maxRGB == minRGB) {
                h = 0;
            } else if(maxRGB == r_) {
                h = 60*((g_ - b_)/(maxRGB - minRGB)) + 0;
            } else if(maxRGB == g_) {
                h = 60*((b_ - r_)/(maxRGB - minRGB)) + 120.0;
            } else if(maxRGB == b_) {
                h = 60*((r_ - g_)/(maxRGB - minRGB)) + 240.0;
            }

            // lightness calculation
            l = (maxRGB + minRGB) / 2;

            // saturation calculation
            if(l == 0 || maxRGB == minRGB) {
                s = 0;
            } else if(l > 0 && l <= 0.5) {
                s = (maxRGB - minRGB) / (2 * l);
            } else if(l > 0.5) {
                s = (maxRGB - minRGB) / (2 - (2 * l));
            }

            printf("HSL code : (%.2f,%.2f,%.2f)\n", h, s, l);
            break;
        }
        case 3: {
            float h, s, v;
            float r_ = r/255.0, g_ = g/255.0, b_ = b/255.0;

            float minRGB = r_;
            if(g_ < minRGB) minRGB = g_;
            if(b_ < minRGB) minRGB = b_;

            float maxRGB = r_;
            if(g_ > maxRGB) maxRGB = g_;
            if(b_ > maxRGB) maxRGB = b_;

            // value calculation
            v = maxRGB;

            // saturation calculation
            if(maxRGB == 0) {
                s = 0;
            } else {
                s = 1 - (minRGB/maxRGB);
            }

            // hue calculation
            if(maxRGB == minRGB) {
                h = 0;
            } else if(maxRGB == r_) {
                h = 60*((g_ - b_)/(maxRGB - minRGB)) + 0;
            } else if(maxRGB == g_) {
                h = 60*((b_ - r_)/(maxRGB - minRGB)) + 120.0;
            } else if(maxRGB == b_) {
                h = 60*((r_ - g_)/(maxRGB - minRGB)) + 240.0;
            }

            if(h < 0) h = h + 360.0;

            printf("HSV code : (%.2f,%.2f,%.2f)\n", h, s, v);
            break;
        }
        default:
            printf("Invalid choice!\n");
            exit(1);
    }

    return 0;
}