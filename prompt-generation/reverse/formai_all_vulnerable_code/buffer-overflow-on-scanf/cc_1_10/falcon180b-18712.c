//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_METADATA_LEN 1024

// Function to extract metadata from a file
void extract_metadata(char* filename, char* metadata) {
    // Open the file for reading
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        strcpy(metadata, "Error: could not open file for reading");
        return;
    }

    // Read the file header to determine its type
    char header[4];
    fread(header, 1, 4, file);
    if (strcmp(header, "RIFF") == 0) {
        // RIFF file (e.g. WAV, AVI)
        strcpy(metadata, "RIFF file");
    } else if (strcmp(header, "FORM") == 0) {
        // AIFF file
        strcpy(metadata, "AIFF file");
    } else if (strcmp(header, "ID3") == 0) {
        // MP3 file with ID3 tag
        strcpy(metadata, "MP3 with ID3 tag");
    } else {
        // Unknown file type
        strcpy(metadata, "Unknown file type");
    }

    // Close the file
    fclose(file);
}

int main() {
    char filename[MAX_FILENAME_LEN];
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Allocate memory for the metadata string
    char metadata[MAX_METADATA_LEN];
    strcpy(metadata, "");

    // Extract metadata from the file
    extract_metadata(filename, metadata);

    // Print the metadata
    printf("Metadata: %s\n", metadata);

    return 0;
}