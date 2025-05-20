//FormAI DATASET v1.0 Category: Image Editor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

void grayscale(unsigned char *data, int width, int height);
void sepia(unsigned char *data, int width, int height);
void invert(unsigned char *data, int width, int height);

int main(int argc, char *argv[]) {
    char infile[MAX_LEN], outfile[MAX_LEN];
    int width, height;
    unsigned char *data;
    FILE *fp;

    // check input arguments
    if (argc < 4) {
        printf("Usage: %s [grayscale | sepia | invert] infile outfile\n", argv[0]);
        return 0;
    }

    // read input file
    strcpy(infile, argv[2]);
    fp = fopen(infile, "rb");
    if (fp == NULL) {
        printf("Cannot open input file %s\n", infile);
        return 0;
    }
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    data = (unsigned char *) malloc(width * height * 3);
    fread(data, sizeof(unsigned char), width * height * 3, fp);
    fclose(fp);

    // apply image effect
    if (strcmp(argv[1], "grayscale") == 0) {
        grayscale(data, width, height);
    } else if (strcmp(argv[1], "sepia") == 0) {
        sepia(data, width, height);
    } else if (strcmp(argv[1], "invert") == 0) {
        invert(data, width, height);
    } else {
        printf("Invalid option %s\n", argv[1]);
        return 0;
    }

    // save output file
    strcpy(outfile, argv[3]);
    fp = fopen(outfile, "wb");
    if (fp == NULL) {
        printf("Cannot open output file %s\n", outfile);
        return 0;
    }
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);
    fwrite(data, sizeof(unsigned char), width * height * 3, fp);
    fclose(fp);

    // free memory
    free(data);

    printf("Done!\n");

    return 0;
}

void grayscale(unsigned char *data, int width, int height) {
    for (int i = 0; i < width * height * 3; i += 3) {
        unsigned char r = data[i];
        unsigned char g = data[i+1];
        unsigned char b = data[i+2];
        unsigned char gray = 0.21*r + 0.72*g + 0.07*b;
        data[i] = data[i+1] = data[i+2] = gray;
    }
}

void sepia(unsigned char *data, int width, int height) {
    for (int i = 0; i < width * height * 3; i += 3) {
        unsigned char r = data[i];
        unsigned char g = data[i+1];
        unsigned char b = data[i+2];
        int tr = 0.393*r + 0.769*g + 0.189*b;
        int tg = 0.349*r + 0.686*g + 0.168*b;
        int tb = 0.272*r + 0.534*g + 0.131*b;
        data[i] = tr > 255 ? 255 : tr;
        data[i+1] = tg > 255 ? 255 : tg;
        data[i+2] = tb > 255 ? 255 : tb;
    }
}

void invert(unsigned char *data, int width, int height) {
    for (int i = 0; i < width * height * 3; i += 3) {
        data[i] = 255 - data[i];
        data[i+1] = 255 - data[i+1];
        data[i+2] = 255 - data[i+2];
    }
}