//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input image> <secret message>\n", argv[0]);
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE *output_file = fopen("output.bmp", "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    unsigned char header[54];
    fread(header, 1, 54, input_file);
    fwrite(header, 1, 54, output_file);

    int width, height;
    fread(&width, 4, 1, input_file);
    fread(&height, 4, 1, input_file);

    unsigned char *input_data = malloc(3 * width * height);
    fread(input_data, 3 * width * height, 1, input_file);

    unsigned char *secret_message = argv[2];
    int message_length = strlen(secret_message);

    int current_pixel = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = (i * width + j) * 3;
            if (message_length > 0) {
                unsigned char message_byte = secret_message[current_pixel % message_length];
                input_data[index] = (input_data[index] & 0xFC) | (message_byte & 0x03);
                current_pixel++;
            }
        }
    }

    fwrite(input_data, 3 * width * height, 1, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("Steganography complete!\n");

    return 0;
}