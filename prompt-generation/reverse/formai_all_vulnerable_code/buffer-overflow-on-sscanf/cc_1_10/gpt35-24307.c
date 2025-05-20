//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Defining the metadata structure
typedef struct Metadata {
    char title[50];
    char artist[50];
    char album[50];
    int year;
} Metadata;

// Function to extract metadata from a given file
Metadata extractMetadata(char* filename) {

    // Open the file
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file!\n");
        exit(1);
    }

    char line[100];
    Metadata metadata;

    // Read each line of the file
    while (fgets(line, sizeof(line), file)) {

        // Check for title
        if (strstr(line, "Title")) {
            sscanf(line, "Title: %[^\n]s", metadata.title);
        }

        // Check for artist
        if (strstr(line, "Artist")) {
            sscanf(line, "Artist: %[^\n]s", metadata.artist);
        }

        // Check for album
        if (strstr(line, "Album")) {
            sscanf(line, "Album: %[^\n]s", metadata.album);
        }

        // Check for year
        if (strstr(line, "Year")) {
            sscanf(line, "Year: %d", &metadata.year);
        }
    }

    // Close the file
    fclose(file);

    // Return the extracted metadata
    return metadata;
}

int main() {

    // Extract metadata from a file named "song.txt"
    Metadata metadata = extractMetadata("song.txt");

    // Print the extracted metadata
    printf("Title: %s\n", metadata.title);
    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Year: %d\n", metadata.year);

    return 0;
}