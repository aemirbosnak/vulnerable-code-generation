//FormAI DATASET v1.0 Category: Image Steganography ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s input_image output_image message\n", argv[0]);
        return 1;
    }

    FILE *in_file = fopen(argv[1], "rb");
    if (in_file == NULL) {
        printf("Could not open input image file %s\n", argv[1]);
        return 1;
    }

    FILE *out_file = fopen(argv[2], "wb");
    if (out_file == NULL) {
        printf("Could not open output image file %s\n", argv[2]);
        fclose(in_file);
        return 1;
    }

    char *message = argv[3];
    int message_length = strlen(message);
    if (message_length > 255) {
        printf("Message too long (maximum length is 255 characters)\n");
        fclose(in_file);
        fclose(out_file);
        return 1;
    }

    // Read header information from input image file
    unsigned char header[54];
    fread(header, sizeof(char), 54, in_file);

    // Write header information to output image file
    fwrite(header, sizeof(char), 54, out_file);

    // Allocate memory for image data
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int padding = (4 - (width * 3) % 4) % 4;
    int size = height * (width * 3 + padding);
    unsigned char *data = malloc(size);

    // Read data from input image file
    fread(data, sizeof(char), size, in_file);

    // Encode message in image data
    int i, j, k;
    for (i = 0; i < message_length; i++) {
        unsigned char byte = message[i];

        for (j = 0; j < 8; j++) {
            int bit = (byte >> j) & 1;
            int offset = i * 8 + j;

            int x = offset % width;
            int y = offset / width;

            k = (height - y - 1) * (width * 3 + padding) + x * 3;
            data[k] = (data[k] & 0xFE) | bit;
        }
    }

    // Write encoded data to output image file
    fwrite(data, sizeof(char), size, out_file);

    // Free memory and close files
    free(data);
    fclose(in_file);
    fclose(out_file);

    printf("Message successfully encoded in image!\n");
    return 0;
}