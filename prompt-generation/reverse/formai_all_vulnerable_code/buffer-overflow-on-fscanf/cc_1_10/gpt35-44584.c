//FormAI DATASET v1.0 Category: Image Editor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pixel {
    int r, g, b;
};

void printHeader(FILE *in, FILE *out) {
    char buf[1024];
    fgets(buf, 1024, in);
    fputs(buf, out);
    fgets(buf, 1024, in);
    fputs(buf, out);
    fgets(buf, 1024, in);
    fputs(buf, out);
    fgets(buf, 1024, in);
    fputs(buf, out);
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s <infile> <outfile>\n", argv[0]);
        return EXIT_FAILURE;
    }
    FILE *fin = fopen(argv[1], "r");
    if(fin == NULL) {
        printf("Could not open %s for reading.\n", argv[1]);
        return EXIT_FAILURE;
    }
    FILE *fout = fopen(argv[2], "w");
    if(fout == NULL) {
        printf("Could not open %s for writing.\n", argv[2]);
        fclose(fin);
        return EXIT_FAILURE;
    }
    struct pixel **pixels;
    char header[3];
    int width, height, maxColor;
    fscanf(fin, "%s %d %d %d", header, &width, &height, &maxColor);
    pixels = malloc(sizeof(struct pixel *) * height);
    for(int i = 0; i < height; i++) {
        pixels[i] = malloc(sizeof(struct pixel) * width);
        for(int j = 0; j < width; j++) {
            fscanf(fin, "%d %d %d", &pixels[i][j].r, &pixels[i][j].g, &pixels[i][j].b);
            pixels[i][j].r = maxColor - pixels[i][j].r;
            pixels[i][j].g = maxColor - pixels[i][j].g;
            pixels[i][j].b = maxColor - pixels[i][j].b;
        }
    }
    fputs(header, fout);
    fprintf(fout, "%d %d\n%d\n", width, height, maxColor);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            fprintf(fout, "%d %d %d ", pixels[i][j].r, pixels[i][j].g, pixels[i][j].b);
        }
        fprintf(fout, "\n");
    }
    for(int i = 0; i < height; i++) {
        free(pixels[i]);
    }
    free(pixels);
    fclose(fin);
    fclose(fout);
    printf("Image successfully inverted and saved to %s.\n", argv[2]);
    return EXIT_SUCCESS;
}