//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 50

int main(int argc, char** argv) {
    if(argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "rb");
    if(input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE* output_file = fopen(argv[2], "w");
    if(output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    unsigned char header[54];
    fread(header, 1, 54, input_file);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    if(width > WIDTH || height > HEIGHT) {
        printf("Image dimensions too large.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    unsigned char* image_data = malloc(width * height * 3);
    fread(image_data, 1, width * height * 3, input_file);
    fclose(input_file);

    int ascii_art_width = WIDTH / width;
    int ascii_art_height = HEIGHT / height;

    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            int r = image_data[(y * width + x) * 3];
            int g = image_data[(y * width + x) * 3 + 1];
            int b = image_data[(y * width + x) * 3 + 2];

            int ascii_art_x = x * ascii_art_width;
            int ascii_art_y = y * ascii_art_height;

            int brightness = (r + g + b) / 3;

            if(brightness > 127) {
                fprintf(output_file, "@");
            } else if(brightness > 64) {
                fprintf(output_file, "=");
            } else if(brightness > 32) {
                fprintf(output_file, "-");
            } else {
                fprintf(output_file, ".");
            }
        }

        fprintf(output_file, "\n");
    }

    free(image_data);
    fclose(output_file);

    return 0;
}