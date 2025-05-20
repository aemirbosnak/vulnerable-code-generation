//FormAI DATASET v1.0 Category: Data recovery tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512 // block size of the file system

typedef struct {
    unsigned char bytes[BLOCK_SIZE];
} block;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./datarecovery [image_file] [output_file]\n");
        return 1;
    }

    char *image_file = argv[1];
    char *output_file = argv[2];

    FILE *file = fopen(image_file, "r");
    if (file == NULL) {
        printf("Could not open image file %s\n", image_file);
        return 1;
    }

    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Could not create output file %s\n", output_file);
        return 1;
    }

    block buffer;
    int counter = 0;
    int found = 0;

    // scan the file system for deleted files
    while (fread(&buffer, BLOCK_SIZE, 1, file) == 1) {
        // check for a jpeg header
        if (buffer.bytes[0] == 0xff && buffer.bytes[1] == 0xd8 && buffer.bytes[2] == 0xff && (buffer.bytes[3] & 0xf0) == 0xe0) {
            // we found a header, now recover the file
            if (found) {
                fclose(output);
            } else {
                found = 1;
            }
            char filename[8];
            sprintf(filename, "%03i.jpg", counter++);
            output = fopen(filename, "w");
            if (output == NULL) {
                printf("Could not create output file %s\n", filename);
                return 1;
            }
        }
        if (found) {
            fwrite(&buffer, BLOCK_SIZE, 1, output);
        }
    }

    fclose(file);
    fclose(output);
    return 0;
}