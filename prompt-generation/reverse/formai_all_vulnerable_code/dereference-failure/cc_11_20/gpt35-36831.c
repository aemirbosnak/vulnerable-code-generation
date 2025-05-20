//FormAI DATASET v1.0 Category: Data recovery tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    // Check for valid usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open raw file
    FILE *raw_file = fopen(argv[1], "r");

    if (raw_file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }

    // Initialize variables
    int jpeg_count = 0;
    char filename[8];
    BYTE buffer[BLOCK_SIZE];
    FILE *jpeg;

    // Read file in blocks of size BLOCK_SIZE
    while (fread(buffer, BLOCK_SIZE, 1, raw_file))
    {
        // Check if beginning of jpeg is found
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous jpeg file
            if (jpeg_count > 0)
            {
                fclose(jpeg);
            }

            // Create new jpeg file
            sprintf(filename, "%03i.jpg", jpeg_count);
            jpeg = fopen(filename, "w");

            if (jpeg == NULL)
            {
                fclose(raw_file);
                printf("Could not create %s.\n", filename);
                return 3;
            }

            jpeg_count++;
        }

        // Write current block to jpeg file
        if (jpeg_count > 0)
        {
            fwrite(buffer, BLOCK_SIZE, 1, jpeg);
        }
    }

    // Close remaining files
    fclose(jpeg);
    fclose(raw_file);
    return 0;
}