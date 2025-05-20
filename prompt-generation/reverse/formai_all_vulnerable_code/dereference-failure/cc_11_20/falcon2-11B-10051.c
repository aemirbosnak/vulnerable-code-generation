//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <errno.h>
#include <time.h>

#define MAX_IMAGE_NAME_LEN 100
#define MAX_IMAGE_SIZE 10000

int main(int argc, char *argv[])
{
    char image_name[MAX_IMAGE_NAME_LEN];
    char output_name[MAX_IMAGE_NAME_LEN];
    FILE *image_file;
    int image_size;
    char *image_data;
    int width, height;
    int index;
    int x, y;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s input_image_file output_image_file\n", argv[0]);
        return 1;
    }

    strcpy(image_name, argv[1]);
    strcpy(output_name, argv[2]);

    image_file = fopen(image_name, "rb");
    if (image_file == NULL) {
        fprintf(stderr, "Error opening input image file %s: %s\n", image_name, strerror(errno));
        return 1;
    }

    fseek(image_file, 0L, SEEK_END);
    image_size = ftell(image_file);
    rewind(image_file);

    image_data = malloc(image_size);
    if (image_data == NULL) {
        fprintf(stderr, "Error allocating memory for image data: %s\n", strerror(errno));
        return 1;
    }

    fread(image_data, sizeof(char), image_size, image_file);
    fclose(image_file);

    image_file = fopen(output_name, "wb");
    if (image_file == NULL) {
        fprintf(stderr, "Error opening output image file %s: %s\n", output_name, strerror(errno));
        return 1;
    }

    width = image_size / 3;
    height = image_size / 3;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            index = 3 * (y * width + x);
            if (image_data[index] == 0 && image_data[index + 1] == 0 && image_data[index + 2] == 0) {
                image_data[index] = 255;
                image_data[index + 1] = 0;
                image_data[index + 2] = 0;
            } else if (image_data[index] == 255 && image_data[index + 1] == 0 && image_data[index + 2] == 0) {
                image_data[index] = 0;
                image_data[index + 1] = 0;
                image_data[index + 2] = 255;
            }
        }
    }

    fwrite(image_data, sizeof(char), image_size, image_file);
    fclose(image_file);

    free(image_data);

    return 0;
}