//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold metadata information
typedef struct {
    char *filename;
    char *author;
    int year;
    int duration;
    char *genre;
} Metadata;

// Function to extract metadata from an audio file
Metadata extract_metadata(char *filename) {
    Metadata metadata;
    FILE *file;
    char buffer[1024];

    // Open the audio file
    file = fopen(filename, "rb");

    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    // Extract filename
    metadata.filename = strdup(filename);

    // Extract author
    fseek(file, 0x34, SEEK_SET);
    fread(buffer, 1, 30, file);
    metadata.author = strdup(buffer);

    // Extract year
    fseek(file, 0x3c, SEEK_SET);
    fread(buffer, 1, 4, file);
    metadata.year = *(int *)buffer;

    // Extract duration
    fseek(file, 0x40, SEEK_SET);
    fread(buffer, 1, 4, file);
    metadata.duration = *(int *)buffer;

    // Extract genre
    fseek(file, 0x44, SEEK_SET);
    fread(buffer, 1, 3, file);
    metadata.genre = strdup(buffer);

    // Close the audio file
    fclose(file);

    return metadata;
}

// Function to print metadata information
void print_metadata(Metadata metadata) {
    printf("Filename: %s\n", metadata.filename);
    printf("Author: %s\n", metadata.author);
    printf("Year: %d\n", metadata.year);
    printf("Duration: %d seconds\n", metadata.duration);
    printf("Genre: %s\n", metadata.genre);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <audio_file>\n", argv[0]);
        exit(1);
    }

    Metadata metadata = extract_metadata(argv[1]);
    print_metadata(metadata);

    free(metadata.filename);
    free(metadata.author);
    free(metadata.genre);

    return 0;
}