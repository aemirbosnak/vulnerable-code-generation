//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double h;
    double s;
    double v;
} HSV;

void rgb_to_hsv(double r, double g, double b, HSV *hsv) {
    double min, max, delta;

    min = (r < g ? (r < b ? r : b) : (g < b ? g : b));
    max = (r > g ? (r > b ? r : b) : (g > b ? g : b));

    hsv->v = max;
    delta = max - min;

    if (delta < 0.00001) {
        hsv->s = 0.0;
        hsv->h = 0.0;
        return;
    }

    if (max > 0.0) {
        hsv->s = (delta / max);
    } else {
        hsv->s = 1.0;
        hsv->h = NAN;
        return;
    }

    if (r == max) {
        hsv->h = (g - b) / delta;
    } else if (g == max) {
        hsv->h = 2.0 + (b - r) / delta;
    } else if (b == max) {
        hsv->h = 4.0 + (r - g) / delta;
    }

    hsv->h *= 60.0;

    if (hsv->h < 0.0) {
        hsv->h += 360.0;
    }
}

void print_hsv(HSV hsv) {
    printf("H: %.2f, S: %.2f%%, V: %.2f%%\n", hsv.h, hsv.s * 100.0, hsv.v * 100.0);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s R G B\n", argv[0]);
        return 1;
    }

    HSV hsv;
    double r, g, b;

    sscanf(argv[1], "%lf", &r);
    sscanf(argv[2], "%lf", &g);
    sscanf(argv[3], "%lf", &b);

    rgb_to_hsv(r / 255.0, g / 255.0, b / 255.0, &hsv);

    print_hsv(hsv);

    return 0;
}