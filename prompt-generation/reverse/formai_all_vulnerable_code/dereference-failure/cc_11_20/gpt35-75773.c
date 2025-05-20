//FormAI DATASET v1.0 Category: Data recovery tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Check for correct number of command line arguments
    if (argc != 2) {
        printf("Usage: ./recover infile\n");
        return 1;
    }
    
    // Open input file
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL) {
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }
    
    // Create buffer to store blocks of data
    unsigned char buffer[BLOCK_SIZE];
    
    // Create output file pointer and file counter
    FILE *outptr;
    int filecount = 0;
    char filename[8];
    
    // Start reading input file by blocks
    while (fread(buffer, BLOCK_SIZE, 1, inptr) == 1) {
        
        // Check if the block matches JPEG header signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
            
            // If a file is already open, close it
            if (filecount > 0) {
                fclose(outptr);
            }
            
            // Create a new output file with a unique name
            sprintf(filename, "%03i.jpg", filecount);
            outptr = fopen(filename, "w");
            if (outptr == NULL) {
                fclose(inptr);
                fprintf(stderr, "Could not create %s.\n", filename);
                return 3;
            }
            
            // Write the first block of the new file
            fwrite(buffer, BLOCK_SIZE, 1, outptr);
            
            // Increment file count
            filecount++;
            
        } else {
            
            // If a file is already open, write the block to it
            if (filecount > 0) {
                fwrite(buffer, BLOCK_SIZE, 1, outptr);
            }
        }
    }
    
    // Close files
    fclose(inptr);
    fclose(outptr);
    
    // Exit program
    return 0;
}