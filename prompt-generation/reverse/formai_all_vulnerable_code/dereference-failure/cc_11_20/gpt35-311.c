//FormAI DATASET v1.0 Category: Data recovery tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[]) {

    // Verify that user inputs one command line argument
    if (argc != 2) {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open input file for reading
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Allocate memory for filename character array
    char *filename = malloc(sizeof(char) * 8);
    if (filename == NULL) {
        printf("Could not allocate memory for filename.\n");
        return 1;
    }

    // Initialize counter for JPEG files found
    int jpeg_counter = 0;

    // Start reading input file
    unsigned char buffer[BLOCK_SIZE];
    FILE *jpg_file = NULL;
    int jpg_found = 0;

    while (fread(buffer, BLOCK_SIZE, 1, input_file)) {

        // Check first bytes to see if it is a JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {

            // If a JPEG file is found and the previous file is not closed, close it
            if (jpg_found == 1) {
                fclose(jpg_file);
            }

            // Create new filename for JPEG file
            sprintf(filename, "%03i.jpg", jpeg_counter);
            jpeg_counter++;

            // Open new JPEG file for writing
            jpg_file = fopen(filename, "w");
            if (jpg_file == NULL) {
                printf("Could not create JPEG file.\n");
                return 1;
            }

            // Write buffer to JPEG file
            fwrite(buffer, BLOCK_SIZE, 1, jpg_file);

            // Set flag to show that a JPEG file is found
            jpg_found = 1;

        } else if (jpg_found == 1) {

            // Write buffer to current JPEG file
            fwrite(buffer, BLOCK_SIZE, 1, jpg_file);

        }

    }

    // Close any open files before exiting
    fclose(input_file);
    fclose(jpg_file);
    free(filename);

    return 0;
}