//FormAI DATASET v1.0 Category: Data recovery tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512
#define MINIMUM_FILE_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./data-recovery-tool <image>\n");
        return 1;
    }

    char *image_path = argv[1];
    FILE *image = fopen(image_path, "r");
    if (image == NULL) {
        fprintf(stderr, "Could not open the image file.\n");
        return 1;
    }

    unsigned char buffer[BLOCK_SIZE];
    int file_count = 0;
    FILE *output_file = NULL;
    while (fread(buffer, BLOCK_SIZE, 1, image)) {
        if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF && (buffer[3] & 0xE0) == 0xE0) {
            // This is the start of a new JPEG file.
            // Close the previous output file (if any) and create a new one with a unique name.
            if (output_file != NULL) {
                fclose(output_file);
            }
            char filename[8];
            sprintf(filename, "%03i.jpg", file_count);
            output_file = fopen(filename, "w");
            if (output_file == NULL) {
                fprintf(stderr, "Could not create the output file.\n");
                return 1;
            }
            file_count++;
        }
        // Check if we have found at least one JPEG file and the current buffer is not just zeroes.
        if (output_file != NULL && memcmp(buffer, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", BLOCK_SIZE) != 0) {
            fwrite(buffer, BLOCK_SIZE, 1, output_file);
        }
    }

    // Close the last output file (if any).
    if (output_file != NULL) {
        fclose(output_file);
    }

    // Check if we have recovered any files.
    if (file_count == 0) {
        fprintf(stderr, "Could not recover any files from the image.\n");
        return 1;
    }

    // Check the size of each recovered file.
    for (int i = 0; i < file_count; i++) {
        char filename[8];
        sprintf(filename, "%03i.jpg", i);
        FILE *file = fopen(filename, "r");
        if (file == NULL) {
            fprintf(stderr, "Could not open the output file %s.\n", filename);
            return 1;
        }
        fseek(file, 0L, SEEK_END);
        long file_size = ftell(file);
        fclose(file);
        if (file_size < MINIMUM_FILE_SIZE) {
            fprintf(stderr, "The output file %s is too small to be a valid JPEG file.\n", filename);
            return 1;
        }
    }

    printf("Successfully recovered %i JPEG files.\n", file_count);
    return 0;
}