//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct { float r, g, b; } RGB;
typedef struct { float h, s, v; } HSV;

void rgb_to_hsv(RGB rgb, HSV *hsv) {
    float min, max, delta;
    max = (rgb.r > rgb.g) ? rgb.r : rgb.g;
    min = (rgb.r < rgb.g) ? rgb.r : rgb.g;
    hsv->h = (rgb.g > rgb.b) ? (rgb.g - rgb.b) + (rgb.r > max ? 60 : 0) : (rgb.b - rgb.g) + 120;
    hsv->s = (max - min) / max;
    hsv->v = max;
    delta = (max - min);
    if (delta < 0.00001) {
        hsv->s = 0;
        hsv->h = 0;
    } else {
        if (hsv->h < 0) hsv->h += 360;
        hsv->h /= 60;
    }
}

void print_hsv(HSV hsv) {
    char h_str[10], s_str[10], v_str[10];
    sprintf(h_str, "%.2f", hsv.h);
    sprintf(s_str, "%.2f", hsv.s);
    sprintf(v_str, "%.2f", hsv.v);
    printf("H: %s, S: %s, V: %s\n", h_str, s_str, v_str);
}

int main(int argc, char *argv[]) {
    if (argc != 3 && argc != 4) {
        printf("Usage: %s <RGB value in hex format> [<RGB value in decimal format>]\n", argv[0]);
        return 1;
    }

    RGB rgb;
    HSV hsv;

    int decimal = 0;
    if (argc == 4) {
        decimal = 1;
        sscanf(argv[3], "%d %d %d", &rgb.r, &rgb.g, &rgb.b);
    } else {
        int pos = 2;
        for (int i = 0; i < 3; i++) {
            int base = i * 2;
            int value = 0;
            int has_next = 1;
            while (pos < argc && isdigit(argv[pos][0])) {
                value = value * 16 + (argv[pos][0] - '0');
                pos++;
                if (!isdigit(argv[pos][0])) break;
                has_next = 0;
            }
            switch (i) {
                case 0: rgb.r = value; break;
                case 1: rgb.g = value; break;
                case 2: rgb.b = value; break;
            }
            if (has_next && pos < argc) pos++;
        }
    }

    rgb_to_hsv(rgb, &hsv);
    print_hsv(hsv);

    return 0;
}