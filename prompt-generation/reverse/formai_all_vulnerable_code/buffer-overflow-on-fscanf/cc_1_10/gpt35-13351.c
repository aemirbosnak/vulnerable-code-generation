//FormAI DATASET v1.0 Category: Image Steganography ; Style: secure
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    uint8_t r, g, b;
} RGB;

int main(int argc, char **argv) {
    FILE *in_file, *out_file;
    RGB *image_buffer, *embed_buffer;
    int width, height, max_value;
    int embed_size, embed_count, random_seed;
    int i, j, k, bit;
    uint8_t mask;
    char *input_filename, *output_filename, *message;
    long int image_size;

    // Ensure proper usage
    if (argc != 5) {
        printf("Usage: %s [input filename] [output filename] [message] [random seed]\n", argv[0]);
        return 1;
    }

    // Parse command line arguments
    input_filename = argv[1];
    output_filename = argv[2];
    message = argv[3];
    random_seed = atoi(argv[4]);

    // Open input file for reading
    in_file = fopen(input_filename, "rb");
    if (in_file == NULL) {
        printf("Could not open file %s\n", input_filename);
        return 1;
    }

    // Read header of input file
    fscanf(in_file, "P6\n%d %d\n%d\n", &width, &height, &max_value);

    // Allocate memory for input file image buffer
    image_size = width * height * sizeof(RGB);
    image_buffer = (RGB *) malloc(image_size);
    if (image_buffer == NULL) {
        printf("Could not allocate memory for image buffer\n");
        return 1;
    }

    // Read input file image data into buffer
    fread(image_buffer, sizeof(RGB), width * height, in_file);

    // Close input file
    fclose(in_file);

    // Generate random embedding sequence
    srand(random_seed);
    embed_size = strlen(message) * 8;
    embed_buffer = (RGB *) malloc(embed_size * sizeof(RGB));
    if (embed_buffer == NULL) {
        printf("Could not allocate memory for embedding buffer\n");
        return 1;
    }

    for (i = 0; i < embed_size; i++) {
        embed_buffer[i].r = rand() % 256;
        embed_buffer[i].g = rand() % 256;
        embed_buffer[i].b = rand() % 256;
    }

    // Embed message into image buffer using least significant bit method
    embed_count = 0;
    for (i = 0; i < strlen(message); i++) {
        for (j = 0; j < 8; j++) {
            // Get next bit from message
            bit = (message[i] >> (7 - j)) & 0x01;

            // Get next embedding pixel and bit mask
            k = embed_count / 3;
            mask = 0x01 << (embed_count % 3) * 2;

            // Embed bit into pixel using bit mask
            if (bit) {
                image_buffer[k].r |= mask;
            } else {
                image_buffer[k].r &= ~mask;
            }

            embed_count++;
        }
    }

    // Open output file for writing
    out_file = fopen(output_filename, "wb");
    if (out_file == NULL) {
        printf("Could not open file %s\n", output_filename);
        return 1;
    }

    // Write header of output file
    fprintf(out_file, "P6\n%d %d\n%d\n", width, height, max_value);

    // Write image buffer to output file
    fwrite(image_buffer, sizeof(RGB), width * height, out_file);

    // Close output file
    fclose(out_file);

    // Free memory buffers
    free(image_buffer);
    free(embed_buffer);

    return 0;
}