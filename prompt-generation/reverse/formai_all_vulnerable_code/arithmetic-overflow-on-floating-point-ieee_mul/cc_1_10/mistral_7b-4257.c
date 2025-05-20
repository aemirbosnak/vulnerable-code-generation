//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI M_PI

typedef struct {
    float r, g, b;
} RGB;

typedef struct {
    float h, s, v;
} HSV;

RGB rgb_parser(char str[11]) {
    RGB color;
    sscanf(str, "(%f, %f, %f)", &color.r, &color.g, &color.b);

    if (color.r < 0 || color.r > 1 || color.g < 0 || color.g > 1 || color.b < 0 || color.b > 1) {
        fprintf(stderr, "Invalid RGB values! RGB values should be between 0 and 1.\n");
        exit(EXIT_FAILURE);
    }

    return color;
}

HSV rgb_to_hsv(RGB rgb) {
    float min, max, delta;

    if (rgb.r > rgb.g) {
        if (rgb.r > rgb.b) {
            max = rgb.r;
            if (rgb.g > rgb.b)
                min = rgb.g;
            else
                min = rgb.b;
        } else {
            max = rgb.g;
            min = rgb.b;
        }
    } else {
        if (rgb.g > rgb.b) {
            max = rgb.g;
            min = rgb.r;
        } else {
            max = rgb.b;
            min = rgb.r;
        }
    }

    HSV hsv;

    hsv.v = max;

    if (max == 0) {
        hsv.s = 0;
        hsv.h = 0;
    } else {
        delta = (rgb.r > max) ? rgb.r - max : max - rgb.r;
        hsv.s = (delta / max) * 100;

        if (rgb.r == max) {
            hsv.h = (rgb.g - rgb.b) / delta + (rgb.g < rgb.b ? PI : 0);
        } else if (rgb.g == max) {
            hsv.h = (rgb.b - rgb.r) / delta + 2 * PI;
        } else if (rgb.b == max) {
            hsv.h = (rgb.r - rgb.g) / delta + 3 * PI / 2;
        }

        hsv.h /= 6.0 * PI;
    }

    return hsv;
}

void print_hsv(HSV hsv) {
    printf("H: %0.3f, S: %0.2f%%, V: %0.3f\n", hsv.h, hsv.s, hsv.v);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s \"rgb values in the format (r, g, b)\"\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    RGB input = rgb_parser(argv[1]);
    HSV output = rgb_to_hsv(input);
    print_hsv(output);

    return EXIT_SUCCESS;
}