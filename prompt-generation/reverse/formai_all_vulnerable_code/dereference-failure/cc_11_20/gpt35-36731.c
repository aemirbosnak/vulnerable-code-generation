//FormAI DATASET v1.0 Category: Image Steganography ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char red, green, blue;
} pixel;

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s [input_file] [output_file] [secret_message]\n", argv[0]);
        return 1;
    }

    FILE *in_file = fopen(argv[1], "rb");
    FILE *out_file = fopen(argv[2], "wb");
    char *secret_message = argv[3];

    if ((in_file == NULL) || (out_file == NULL)) {
        printf("Error opening file.\n");
        return 1;
    }

    int width, height, max_color;
    char magic_number[3];

    fscanf(in_file, "%s\n", magic_number);

    if (magic_number[0] != 'P' || magic_number[1] != '6') {
        printf("Error: Invalid file type.\n");
        return 1;
    }

    fscanf(in_file, "%d %d\n", &width, &height);
    fscanf(in_file, "%d\n", &max_color);

    if (max_color > 255) {
        printf("Error: Maximum color value has to be less than or equal to 255.\n");
        return 1;
    }

    pixel *image = (pixel*) malloc(sizeof(pixel) * width * height);
    fread(image, sizeof(pixel), width * height, in_file);

    fclose(in_file);

    pixel current_pixel;
    int message_index = 0, bit_index = 0;

    while (secret_message[message_index] != '\0') {
        current_pixel = image[message_index];

        if (bit_index == 0) {
            current_pixel.red = ((current_pixel.red >> 1) << 1) | (secret_message[message_index] >> 7);
            bit_index++;
        }
        else if (bit_index == 1) {
            current_pixel.green = ((current_pixel.green >> 1) << 1) | ((secret_message[message_index] >> 6) & 0x01);
            bit_index++;
        }
        else if (bit_index == 2) {
            current_pixel.blue = ((current_pixel.blue >> 1) << 1) | ((secret_message[message_index] >> 5) & 0x01);
            bit_index++;
        }
        else if (bit_index == 3) {
            current_pixel.red = ((current_pixel.red >> 1) << 1) | ((secret_message[message_index] >> 4) & 0x01);
            bit_index++;
        }
        else if (bit_index == 4) {
            current_pixel.green = ((current_pixel.green >> 1) << 1) | ((secret_message[message_index] >> 3) & 0x01);
            bit_index++;
        }
        else if (bit_index == 5) {
            current_pixel.blue = ((current_pixel.blue >> 1) << 1) | ((secret_message[message_index] >> 2) & 0x01);
            bit_index++;
        }
        else if (bit_index == 6) {
            current_pixel.red = ((current_pixel.red >> 1) << 1) | ((secret_message[message_index] >> 1) & 0x01);
            bit_index++;
        }
        else if (bit_index == 7) {
            current_pixel.green = ((current_pixel.green >> 1) << 1) | (secret_message[message_index] & 0x01);
            bit_index = 0;
            message_index++;
        }

        image[message_index] = current_pixel;
    }

    fprintf(out_file, "P6\n%d %d\n%d\n", width, height, max_color);
    fwrite(image, sizeof(pixel), width * height, out_file);

    fclose(out_file);

    return 0;
}