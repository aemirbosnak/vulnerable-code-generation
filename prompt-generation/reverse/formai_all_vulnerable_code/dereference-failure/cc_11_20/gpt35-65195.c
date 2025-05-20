//FormAI DATASET v1.0 Category: Data recovery tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc != 3) {
        printf("Usage: %s image file\n", argv[0]);
        return 1;
    }
    
    // Open the image file
    FILE *image = fopen(argv[1], "r");
    if (image == NULL) {
        printf("Could not open image file\n");
        return 1;
    }
    
    // Create the output file
    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        printf("Could not create output file\n");
        return 1;
    }
    
    // Allocate memory for the buffer
    char buffer[BLOCK_SIZE];
    memset(buffer, 0, BLOCK_SIZE);
    
    int bytesRead = 0;
    int fileCount = 0;
    
    // Read each block from the image file
    while ((bytesRead = fread(buffer, 1, BLOCK_SIZE, image)) > 0) {
        
        // Check if we found a JPEG header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
            
            // Close the previous file (if we had one)
            if (fileCount > 0) {
                fclose(output);
            }
            
            char filename[8];
            sprintf(filename, "%03i.jpg", fileCount);
            
            // Create a new file
            output = fopen(filename, "w");
            if (output == NULL) {
                printf("Could not create output file\n");
                return 1;
            }
            
            fileCount++;
        }
        
        // Write the block to the output file (if we have one open)
        if (fileCount > 0) {
            fwrite(buffer, 1, bytesRead, output);
        }
    }
    
    // Close the final output file
    fclose(output);
    
    // Close the image file
    fclose(image);
    
    printf("Recovered %d files\n", fileCount);
    
    return 0;
}