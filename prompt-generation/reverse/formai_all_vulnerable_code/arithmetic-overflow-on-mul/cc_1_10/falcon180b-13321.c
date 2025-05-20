//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80

void print_image(char *image_data, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (image_data[i * width + j] == 0) {
                printf("  ");
            } else {
                printf("##");
            }
        }
        printf("\n");
    }
}

void image_to_ascii(char *filename, char *output_filename) {
    FILE *fp, *out_fp;
    char header[54];
    int width, height, channels;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Cannot open input file.\n");
        exit(1);
    }

    fread(header, 1, 54, fp);
    if (strncmp(header, "BM", 2)!= 0) {
        printf("Error: Input file is not a valid BMP file.\n");
        fclose(fp);
        exit(1);
    }

    width = *(int *)&header[18];
    height = *(int *)&header[22];
    channels = *(int *)&header[28];

    if (channels!= 3) {
        printf("Error: Input file must have 3 channels (RGB).\n");
        fclose(fp);
        exit(1);
    }

    char *image_data = malloc(width * height * 3);
    fread(image_data, width * height * 3, 1, fp);
    fclose(fp);

    out_fp = fopen(output_filename, "w");
    if (out_fp == NULL) {
        printf("Error: Cannot open output file.\n");
        free(image_data);
        exit(1);
    }

    int ascii_width = (width * 3 + MAX_WIDTH - 1) / MAX_WIDTH;
    int ascii_height = (height * 3 + MAX_WIDTH - 1) / MAX_WIDTH;

    printf("Converting image to ASCII art...\n");
    for (int i = 0; i < ascii_height; i++) {
        for (int j = 0; j < ascii_width; j++) {
            int x = j * 3;
            int y = i * 3;

            int r = image_data[y * width + x + 2];
            int g = image_data[y * width + x + 1];
            int b = image_data[y * width + x];

            int avg = (r + g + b) / 3;

            if (avg < 128) {
                fprintf(out_fp, "  ");
            } else {
                fprintf(out_fp, "##");
            }
        }
        fprintf(out_fp, "\n");
    }

    fclose(out_fp);
    free(image_data);
    printf("ASCII art saved to %s.\n", output_filename);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];

    image_to_ascii(input_filename, output_filename);

    return 0;
}