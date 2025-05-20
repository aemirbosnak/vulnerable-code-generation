//FormAI DATASET v1.0 Category: Data recovery tool ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512 // block size for file system

int main(int argc, char *argv[]) {
    // check for command line argument
    if (argc != 2) {
        printf("Usage: %s <image>\n", argv[0]);
        exit(1);
    }

    // open the image file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Could not open %s.\n", argv[1]);
        exit(2);
    }

    // check image file size
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // allocate memory for image file
    unsigned char *img_file = malloc(file_size);
    if (img_file == NULL) {
        printf("Could not allocate memory.\n");
        exit(3);
    }

    // read image file into memory
    int read_size = fread(img_file, 1, file_size, file);
    if (read_size != file_size) {
        printf("Error reading file %s.\n", argv[1]);
        exit(4);
    }

    // locate the JPEG files
    int jpeg_count = 0;
    for (int i = 0; i < file_size - BLOCK_SIZE; i++) {
        if (img_file[i] == 0xff && img_file[i + 1] == 0xd8 &&
            img_file[i + 2] == 0xff && (img_file[i + 3] & 0xf0) == 0xe0) {
            jpeg_count++;

            // create a file name for the JPEG
            char filename[10];
            sprintf(filename, "%03i.jpg", jpeg_count);

            // open the new JPEG file
            FILE *new_file = fopen(filename, "w");
            if (new_file == NULL) {
                printf("Could not create %s.\n", filename);
                exit(5);
            }

            // write the JPEG to the new file
            fwrite(&img_file[i], 1, BLOCK_SIZE, new_file);

            // close the new file
            fclose(new_file);
        }
    }

    // free allocated memory and close file
    free(img_file);
    fclose(file);

    // print number of JPEG files recovered
    printf("%i JPEG files recovered.\n", jpeg_count);

    return 0;
}