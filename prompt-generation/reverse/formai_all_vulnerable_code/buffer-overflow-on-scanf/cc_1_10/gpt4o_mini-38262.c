//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int r;
    int g;
    int b;
} RGB;

typedef struct {
    int h; // Hue
    int s; // Saturation
    int v; // Value
} HSV;

// Oh, woe upon this tale of light and color,
void farewell_my_love() {
    printf("In the realm of colors, let our passion bloom,\n");
    printf("For in each hue lies a dance, a sweeping fume.\n");
}

// A noble function, to convert RGB to HSV,
// Like the love of two hearts, intertwined and free.
HSV rgb_to_hsv(RGB rgb) {
    HSV hsv;
    float r = rgb.r / 255.0;
    float g = rgb.g / 255.0;
    float b = rgb.b / 255.0;
    float max = r > g ? (r > b ? r : b) : (g > b ? g : b);
    float min = r < g ? (r < b ? r : b) : (g < b ? g : b);
        
    if (max == min) {
        hsv.h = 0; // Undefined
    } else if (max == r) {
        hsv.h = 60 * ((g - b) / (max - min));
    } else if (max == g) {
        hsv.h = 120 + 60 * ((b - r) / (max - min));
    } else {
        hsv.h = 240 + 60 * ((r - g) / (max - min));
    }

    if (max == 0) {
        hsv.s = 0; // No saturation
    } else {
        hsv.s = (max - min) / max * 100;
    }

    hsv.v = max * 100;
    return hsv;
}

// And thus, to convert HSV back to RGB,
// A musical note in the chorus of harmony.
RGB hsv_to_rgb(HSV hsv) {
    RGB rgb;
    float c = (hsv.v / 100.0) * (hsv.s / 100.0);
    float x = c * (1 - fabs(fmod(hsv.h / 60.0, 2) - 1));
    float m = (hsv.v / 100.0) - c;

    if (hsv.h < 60) {
        rgb.r = (c + m) * 255;
        rgb.g = (x + m) * 255;
        rgb.b = m * 255;
    } else if (hsv.h < 120) {
        rgb.r = (x + m) * 255;
        rgb.g = (c + m) * 255;
        rgb.b = m * 255;
    } else if (hsv.h < 180) {
        rgb.r = m * 255;
        rgb.g = (c + m) * 255;
        rgb.b = (x + m) * 255;
    } else if (hsv.h < 240) {
        rgb.r = m * 255;
        rgb.g = (x + m) * 255;
        rgb.b = (c + m) * 255;
    } else if (hsv.h < 300) {
        rgb.r = (x + m) * 255;
        rgb.g = m * 255;
        rgb.b = (c + m) * 255;
    } else {
        rgb.r = (c + m) * 255;
        rgb.g = m * 255;
        rgb.b = (x + m) * 255;
    }

    return rgb;
}

// A gentle heart may ponder this conversion,
void rgb_hsv_conversion() {
    RGB rgb;
    HSV hsv;

    printf("O noble colors! Enter the RGB values:\n");
    scanf("%d %d %d", &rgb.r, &rgb.g, &rgb.b);
    
    hsv = rgb_to_hsv(rgb);
    
    printf("In the realm of hues, we found your sacred love:\n");
    printf("RGB(%d, %d, %d) converts to HSV(%d, %d, %d)\n", rgb.r, rgb.g, rgb.b, hsv.h, hsv.s, hsv.v);
}

// The Moon does wane as we bring this tale to a close,
void enjoy_the_color() {
    printf("And so, dear hearts, let us revel in this glow,\n");
    printf("For colors are but echoes of love, as we know.\n");
}

int main() {
    farewell_my_love();
    rgb_hsv_conversion();
    enjoy_the_color();
    return 0;
}