//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file> <recovery_file>\n", argv[0]);
        return 1;
    }

    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL) {
        fprintf(stderr, "Could not open file for reading.\n");
        return 2;
    }

    FILE *outptr = fopen(argv[2], "w");
    if (outptr == NULL) {
        fprintf(stderr, "Could not open file for writing.\n");
        return 3;
    }

    unsigned char buffer[BLOCK_SIZE];
    int jpeg_count = 0, jpeg_open = 0;
    char jpeg_name[8];

    while (fread(buffer, BLOCK_SIZE, 1, inptr) == 1) {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
            if (jpeg_open) {
                fclose(outptr);
            } else {
                jpeg_open = 1;
            }

            sprintf(jpeg_name, "%03i.jpg", jpeg_count);
            outptr = fopen(jpeg_name, "w");
            if (outptr == NULL) {
                fclose(inptr);
                fprintf(stderr, "Could not create output file.\n");
                return 4;
            }

            jpeg_count++;
        }

        if (jpeg_open) {
            fwrite(buffer, BLOCK_SIZE, 1, outptr);
        }
    }

    fclose(inptr);
    fclose(outptr);

    return 0;
}