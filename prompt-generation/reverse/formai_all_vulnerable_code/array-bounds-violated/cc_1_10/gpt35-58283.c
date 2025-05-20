//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXELS 10000

int main(int argc, char **argv) {
    char gray_char[] = {'#', 'M', 'H', 'V', 'A', 'W', 'S', 'T', '*', 'o', 
	                    'i', ';', ':', ',', '.', ' '};

    int row, col;
    int gray[MAX_PIXELS][MAX_PIXELS];
    FILE *image, *ascii_art;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s image_file grayscale_value > output_file\n", argv[0]);
        exit(1);
    }

    if ((image = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error: can't open %s\n", argv[1]);
        exit(1);
    }

    fread(&row, sizeof(int), 1, image);
    fread(&col, sizeof(int), 1, image);

    int size = row * col;
    if (size > MAX_PIXELS * MAX_PIXELS) {
        fprintf(stderr, "Error: image too large\n");
        exit(1);
    }

    fread(gray, sizeof(int), size, image);
    fclose(image);

    if ((ascii_art = fopen(argv[2], "w")) == NULL) {
        fprintf(stderr, "Error: can't open %s\n", argv[2]);
        exit(1);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int index = gray[i][j] / 25;
            fputc(gray_char[index], ascii_art);
        }
        fputc('\n', ascii_art);
    }

    fclose(ascii_art);

    return 0;
}