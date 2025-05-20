//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 100
#define CHAR_SET_SIZE (6 * 10)

char char_set[] = "@%#*+=-:. ";

void print_image(char *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", char_set[image[y * width + x]]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char filename[100];
    char image[WIDTH * HEIGHT];
    char ascii_art[WIDTH * (HEIGHT + 2)];

    printf("Enter image file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    fread(image, sizeof(char), WIDTH * HEIGHT, fp);
    fclose(fp);

    int i = 0;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int gray_level = image[y * WIDTH + x];
            ascii_art[i++] = char_set[gray_level / 32];
        }
        ascii_art[i++] = '\n';
    }

    print_image(ascii_art, WIDTH, HEIGHT + 2);

    return 0;
}