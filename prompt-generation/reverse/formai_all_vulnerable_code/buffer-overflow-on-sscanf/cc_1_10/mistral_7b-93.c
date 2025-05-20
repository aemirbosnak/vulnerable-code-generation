//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 128
#define HEIGHT 128
#define MAX_COLOR 256
#define BUFFER_SIZE 1024

typedef struct {
    unsigned char r, g, b;
} Color;

Color colors[MAX_COLOR];
unsigned char *image;

void load_color_palette(char *filename) {
    FILE *fp;
    char line[BUFFER_SIZE];
    char token[32];
    int i, len;

    fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: could not open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    i = 0;
    while (fgets(line, BUFFER_SIZE, fp)) {
        sscanf(line, "%s %s %s", token, token, token);
        len = strlen(token);
        colors[i].r = strtoul(token, NULL, 16);
        colors[i].g = strtoul(strchr(line, ' ') + 1, NULL, 16);
        colors[i].b = strtoul(strchr(line, ' ') + 1 + strlen(strchr(line, ' ') + 1), NULL, 16);
        i++;
    }

    fclose(fp);
}

void generate_pixel(int x, int y) {
    int i;
    Color c;

    c = colors[x & 15 | (y & 3) * 16];
    image[y * WIDTH + x] = c.b;
    image[y * WIDTH + x] |= c.g << 5;
    image[y * WIDTH + x] |= c.r << 11;
}

void generate_image() {
    int x, y;

    image = malloc(WIDTH * HEIGHT);
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            generate_pixel(x, y);
        }
    }
}

void save_image(char *filename) {
    FILE *fp;
    int x, y;

    fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: could not open %s for writing\n", filename);
        exit(EXIT_FAILURE);
    }

    fwrite("P6\n", 3, 1, fp);
    fprintf(fp, "%d %d\n255\n", WIDTH, HEIGHT);

    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            fputc(image[y * WIDTH + x], fp);
        }
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <palette.txt>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    load_color_palette(argv[1]);
    generate_image();
    save_image("output.pgm");
    free(image);
    return EXIT_SUCCESS;
}