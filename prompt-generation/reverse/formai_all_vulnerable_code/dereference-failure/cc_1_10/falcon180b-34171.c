//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_CHARS (WIDTH * HEIGHT)

typedef struct {
    int x, y;
    char c;
    int r, g, b;
} pixel;

pixel *pixels;
int num_pixels;

void init_pixels() {
    srand(time(NULL));
    pixels = malloc(MAX_CHARS * sizeof(pixel));
    num_pixels = 0;
}

void add_pixel(int x, int y, char c, int r, int g, int b) {
    if (num_pixels >= MAX_CHARS) {
        return;
    }

    pixel p = {x, y, c, r, g, b};
    pixels[num_pixels++] = p;
}

void print_ascii_art(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char c = toupper(str[i]);
        if (c >= 'A' && c <= 'Z') {
            add_pixel(i % WIDTH, i / WIDTH, c, 255, 255, 255);
        }
    }
}

void print_pixels() {
    for (int i = 0; i < num_pixels; i++) {
        pixel p = pixels[i];
        printf("%d,%d,%c,%d,%d,%d\n", p.x, p.y, p.c, p.r, p.g, p.b);
    }
}

int main() {
    init_pixels();
    char input[1024];

    while (fgets(input, sizeof(input), stdin)) {
        if (input[0] == '#') {
            continue;
        }

        print_ascii_art(input);
    }

    print_pixels();

    return 0;
}