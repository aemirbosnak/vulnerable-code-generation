//FormAI DATASET v1.0 Category: Image Editor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 320
#define HEIGHT 240

struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

void read_image(struct Pixel image[HEIGHT][WIDTH]) {
    FILE *fp = fopen("input.ppm", "r");
    char buffer[128];
    fgets(buffer, 128, fp);
    fgets(buffer, 128, fp);
    fgets(buffer, 128, fp);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            unsigned int red, green, blue;
            fscanf(fp, "%d %d %d", &red, &green, &blue);
            image[y][x].red = red;
            image[y][x].green = green;
            image[y][x].blue = blue;
        }
    }
    fclose(fp);
}

void write_image(struct Pixel image[HEIGHT][WIDTH]) {
    FILE *fp = fopen("output.ppm", "w");
    fprintf(fp, "P3\n");
    fprintf(fp, "%d %d\n", WIDTH, HEIGHT);
    fprintf(fp, "255\n");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fprintf(fp, "%d %d %d ", image[y][x].red, image[y][x].green, image[y][x].blue);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void invert_colors(struct Pixel image[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            image[y][x].red = 255 - image[y][x].red;
            image[y][x].green = 255 - image[y][x].green;
            image[y][x].blue = 255 - image[y][x].blue;
        }
    }
}

int main(int argc, char *argv[]) {
    struct Pixel image[HEIGHT][WIDTH];
    read_image(image);
    invert_colors(image);
    write_image(image);
    return 0;
}