//FormAI DATASET v1.0 Category: Data recovery tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512  // Block size in bytes

typedef unsigned char byte;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s image.img\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    // Open file for reading
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        return 1;
    }

    // Create output file
    char *output_filename = "recovered.txt";
    FILE *output_file = fopen(output_filename, "w");

    if (!output_file) {
        fprintf(stderr, "Could not create output file: %s\n", output_filename);
        return 1;
    }

    byte buffer[BLOCK_SIZE];
    int jpg_count = 0;
    int jpg_open = 0;
    int jpg_size = 0;
    char jpg_filename[10];

    while (fread(buffer, BLOCK_SIZE, 1, file)) {
        // If the first 4 bytes are the header of a JPG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
            // If a file is already open, close it
            if (jpg_open) {
                fclose(output_file);
                jpg_open = 0;
            }

            // Create a filename for the new JPG file
            sprintf(jpg_filename, "%03i.jpg", jpg_count);
            jpg_count++;

            // Open the new JPG file for writing
            output_file = fopen(jpg_filename, "w");

            if (!output_file) {
                fprintf(stderr, "Could not create file: %s\n", jpg_filename);
                return 1;
            }

            // Write the first block to the new file
            fwrite(buffer, BLOCK_SIZE, 1, output_file);
            jpg_open = 1;
            jpg_size = BLOCK_SIZE;
        } else if (jpg_open) {
            // Write the current block to the new file
            fwrite(buffer, BLOCK_SIZE, 1, output_file);
            jpg_size += BLOCK_SIZE;

            // If the end of a JPG file is reached (final byte of JPG file is 0xd9)
            if (buffer[BLOCK_SIZE - 2] == 0xff && buffer[BLOCK_SIZE - 1] == 0xd9) {
                // Close the current file
                fclose(output_file);
                jpg_open = 0;

                // Remove padding from last block
                jpg_size -= BLOCK_SIZE - 2;
                fseek(output_file, -2, SEEK_END);
                ftruncate(fileno(output_file), ftell(output_file) + 2);
                fflush(output_file);
            }
        }
    }

    // If a file is still open, close it
    if (jpg_open) {
        fclose(output_file);
    }

    fclose(file);

    return 0;
}