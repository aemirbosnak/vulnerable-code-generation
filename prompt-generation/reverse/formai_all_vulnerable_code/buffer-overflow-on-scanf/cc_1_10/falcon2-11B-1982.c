//Falcon2-11B DATASET v1.0 Category: Color Code Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert RGB values to their C color code
void rgbToC(int r, int g, int b, char* c) {
    sprintf(c, "#%02x%02x%02x", r, g, b);
}

// Function to convert C color code to RGB values
void cToRgb(char* c, int* r, int* g, int* b) {
    char* endptr;
    int r_val, g_val, b_val;
    r_val = strtol(c, &endptr, 16);
    if (endptr == c) {
        printf("Invalid C color code\n");
        return;
    }
    g_val = strtol(endptr + 1, &endptr, 16);
    if (endptr == c) {
        printf("Invalid C color code\n");
        return;
    }
    b_val = strtol(endptr + 2, &endptr, 16);
    if (endptr == c) {
        printf("Invalid C color code\n");
        return;
    }
    *r = r_val;
    *g = g_val;
    *b = b_val;
}

int main() {
    char c_code[8];
    int r, g, b;

    printf("Enter the C color code: ");
    scanf("%s", c_code);

    rgbToC(0, 0, 0, c_code);  // Setting the C color code to black
    cToRgb(c_code, &r, &g, &b);
    printf("RGB values: (%d, %d, %d)\n", r, g, b);

    rgbToC(255, 0, 0, c_code);  // Setting the C color code to red
    cToRgb(c_code, &r, &g, &b);
    printf("RGB values: (%d, %d, %d)\n", r, g, b);

    rgbToC(0, 255, 0, c_code);  // Setting the C color code to green
    cToRgb(c_code, &r, &g, &b);
    printf("RGB values: (%d, %d, %d)\n", r, g, b);

    rgbToC(0, 0, 255, c_code);  // Setting the C color code to blue
    cToRgb(c_code, &r, &g, &b);
    printf("RGB values: (%d, %d, %d)\n", r, g, b);

    rgbToC(255, 255, 255, c_code);  // Setting the C color code to white
    cToRgb(c_code, &r, &g, &b);
    printf("RGB values: (%d, %d, %d)\n", r, g, b);

    return 0;
}