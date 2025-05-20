//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract metadata from file
void extract_metadata(char* filename) {
    // Open file
    FILE* fp = fopen(filename, "rb");
    if(fp == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return;
    }

    // Define metadata structure
    typedef struct {
        char* artist;
        char* title;
        char* album;
        int year;
        int track_number;
    } metadata;

    // Initialize metadata structure
    metadata mdata;
    mdata.artist = NULL;
    mdata.title = NULL;
    mdata.album = NULL;
    mdata.year = 0;
    mdata.track_number = 0;

    // Read file in 128 byte chunks
    char buffer[128];
    while(fread(buffer, sizeof(char), 128, fp)) {
        // Check for ID3v1 tag
        if(strncmp(buffer+sizeof(buffer)-128, "TAG", 3) == 0) {
            // Extract metadata fields
            mdata.title = strndup(buffer+sizeof(buffer)-125, 30);
            mdata.artist = strndup(buffer+sizeof(buffer)-95, 30);
            mdata.album = strndup(buffer+sizeof(buffer)-65, 30);
            sscanf(buffer+sizeof(buffer)-35, "%d", &mdata.year);
            sscanf(buffer+sizeof(buffer)-31, "%d", &mdata.track_number);

            // Print metadata
            printf("Title: %s\n", mdata.title);
            printf("Artist: %s\n", mdata.artist);
            printf("Album: %s\n", mdata.album);
            printf("Year: %d\n", mdata.year);
            printf("Track Number: %d\n", mdata.track_number);

            // Free memory allocated for metadata fields
            free(mdata.title);
            free(mdata.artist);
            free(mdata.album);

            // Close file and return
            fclose(fp);
            return;
        }
    }

    // If no ID3v1 tag found, print error message
    fprintf(stderr, "Error: File %s does not have ID3v1 tag\n", filename);

    // Close file
    fclose(fp);
}

// Test program
int main(int argc, char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }
    extract_metadata(argv[1]);
    return 0;
}