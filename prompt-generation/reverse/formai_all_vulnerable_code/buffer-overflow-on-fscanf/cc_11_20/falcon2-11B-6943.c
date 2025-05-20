//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char **argv) {
    char input_file[MAX_LINE_LENGTH];
    char output_file[MAX_LINE_LENGTH];
    FILE *infile = NULL;
    FILE *outfile = NULL;
    int image_width = 0;
    int image_height = 0;
    int i, j;
    unsigned char *image_data = NULL;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "-") == 0 || strcmp(argv[1], "stdin") == 0) {
        if (fgets(input_file, MAX_LINE_LENGTH, stdin) == NULL) {
            fprintf(stderr, "Error reading input file.\n");
            return 1;
        }
    } else {
        strcpy(input_file, argv[1]);
    }

    if (strcmp(argv[2], "-") == 0 || strcmp(argv[2], "stdout") == 0) {
        if (fgets(output_file, MAX_LINE_LENGTH, stdout) == NULL) {
            fprintf(stderr, "Error reading output file.\n");
            return 1;
        }
    } else {
        strcpy(output_file, argv[2]);
    }

    infile = fopen(input_file, "r");
    outfile = fopen(output_file, "w");
    if (infile == NULL || outfile == NULL) {
        fprintf(stderr, "Error opening input or output file.\n");
        return 1;
    }

    fscanf(infile, "%d %d\n", &image_width, &image_height);
    if (image_width <= 0 || image_height <= 0) {
        fprintf(stderr, "Invalid image dimensions.\n");
        return 1;
    }

    image_data = (unsigned char *)malloc(image_width * image_height * sizeof(unsigned char));
    if (image_data == NULL) {
        fprintf(stderr, "Error allocating memory for image data.\n");
        return 1;
    }

    fread(image_data, image_width * image_height, sizeof(unsigned char), infile);

    for (i = 0; i < image_height; i++) {
        for (j = 0; j < image_width; j++) {
            unsigned char brightness = image_data[i * image_width + j];
            unsigned char contrast = 255 - brightness;
            unsigned char new_brightness = brightness + contrast;
            unsigned char new_contrast = brightness - new_brightness;
            unsigned char new_pixel = (new_brightness * new_contrast + 255) / 2;
            image_data[i * image_width + j] = new_pixel;
        }
    }

    fwrite(image_data, image_width * image_height, sizeof(unsigned char), outfile);

    fclose(infile);
    fclose(outfile);

    free(image_data);

    return 0;
}