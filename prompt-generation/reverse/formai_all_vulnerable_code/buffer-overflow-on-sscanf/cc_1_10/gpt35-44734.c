//FormAI DATASET v1.0 Category: Color Code Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double min(double x, double y) {
    return x < y ? x : y;
}

double max(double x, double y) {
    return x > y ? x : y;
}

void rgb_to_hex(int r, int g, int b, char *hex_code) {
    sprintf(hex_code, "%02x%02x%02x", r, g, b);
}

void hex_to_rgb(char *hex_code, int *r, int *g, int *b) {
    long hex_value = strtol(hex_code, NULL, 16);
    *r = hex_value >> 16;
    *g = (hex_value >> 8) & 0xFF;
    *b = hex_value & 0xFF;
}

void rgb_to_cmyk(int r, int g, int b, double *c, double *m, double *y, double *k) {
    double r2 = r / 255.0;
    double g2 = g / 255.0;
    double b2 = b / 255.0;
    *k = 1 - max(max(r2, g2), b2);
    *c = (*k == 1) ? 0 : (1 - r2 - *k) / (1 - *k);
    *m = (*k == 1) ? 0 : (1 - g2 - *k) / (1 - *k);
    *y = (*k == 1) ? 0 : (1 - b2 - *k) / (1 - *k);
}

void cmyk_to_rgb(double c, double m, double y, double k, int *r, int *g, int *b) {
    *r = (int) (255 * (1 - c) * (1 - k));
    *g = (int) (255 * (1 - m) * (1 - k));
    *b = (int) (255 * (1 - y) * (1 - k));
}

int main() {
    char input[32];
    char format;
    int r, g, b;
    double c, m, y, k;
    char hex_code[7];
    
    printf("Enter color code or values (e.g. 'FF0000' or '255,0,0' or '1.0,0,0,0'): ");
    fgets(input, 32, stdin);
    format = tolower(input[1]);
    if (format == 'x') { // hex input
        hex_to_rgb(input, &r, &g, &b);
        printf("RGB: %d,%d,%d\n", r, g, b);
        rgb_to_cmyk(r, g, b, &c, &m, &y, &k);
        printf("CMYK: %.2f,%.2f,%.2f,%.2f\n", c, m, y, k);
    } else if (format == 'y') { // cmyk input
        sscanf(input, "%lf,%lf,%lf,%lf", &c, &m, &y, &k);
        cmyk_to_rgb(c, m, y, k, &r, &g, &b);
        printf("RGB: %d,%d,%d\n", r, g, b);
        rgb_to_hex(r, g, b, hex_code);
        printf("Hex: #%s\n", hex_code);
    } else { // rgb input
        sscanf(input, "%d,%d,%d", &r, &g, &b);
        printf("Hex: #");
        rgb_to_hex(r, g, b, hex_code);
        printf("%s\n", hex_code);
        rgb_to_cmyk(r, g, b, &c, &m, &y, &k);
        printf("CMYK: %.2f,%.2f,%.2f,%.2f\n", c, m, y, k);
    }
    
    return 0;
}