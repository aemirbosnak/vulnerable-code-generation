//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 64
#define HEIGHT 32
#define CHARS " .,cO8%@"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s image.bmp\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    fseek(fp, 10, SEEK_SET);
    int offset = fgetc(fp) + (fgetc(fp) << 8) + (fgetc(fp) << 16) + (fgetc(fp) << 24);
    fseek(fp, offset, SEEK_SET);

    unsigned char *data = malloc(WIDTH * HEIGHT * 3);
    if (data == NULL) {
        perror("malloc");
        fclose(fp);
        return 1;
    }

    fread(data, WIDTH * HEIGHT * 3, 1, fp);
    fclose(fp);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int r = data[3 * (y * WIDTH + x) + 2];
            int g = data[3 * (y * WIDTH + x) + 1];
            int b = data[3 * (y * WIDTH + x) + 0];

            double luma = 0.2126 * r + 0.7152 * g + 0.0722 * b;
            int index = (int) (luma / 255.0 * (sizeof(CHARS) - 1));

            printf("%c", CHARS[index]);
        }
        printf("\n");
    }

    free(data);

    return 0;
}