//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_LENGTH 100
#define MAX_FILES 50

// Structure to hold metadata
typedef struct {
    char title[MAX_METADATA_LENGTH];
    char artist[MAX_METADATA_LENGTH];
    char album[MAX_METADATA_LENGTH];
    int year;
} Metadata;

// Function to display metadata information
void displayMetadata(Metadata metadata) {
    printf("\n🎶 Metadata Information 🎶\n");
    printf("Title: %s\n", metadata.title);
    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Year: %d\n", metadata.year);
    printf("Thank you for using the Metadata Extractor! 😊\n");
}

// Function to extract metadata from a simulated file
void extractMetadata(const char *filename, Metadata *metadata) {
    // Simulating file read with hardcoded values
    strncpy(metadata->title, "Happy Song", MAX_METADATA_LENGTH);
    strncpy(metadata->artist, "Cheerful Artist", MAX_METADATA_LENGTH);
    strncpy(metadata->album, "Joyful Album", MAX_METADATA_LENGTH);
    metadata->year = 2023;

    printf("Extracting metadata from %s... 🎉\n", filename);
}

// Function to demonstrate the usage
void runMetadataExtractor() {
    Metadata metadata[MAX_FILES];
    char filename[MAX_METADATA_LENGTH];
    int numFiles;

    printf("Welcome to the Happy Metadata Extractor! 🌟\n");
    printf("How many files do you want to extract metadata from? (Max %d): ", MAX_FILES);
    scanf("%d", &numFiles);

    if (numFiles < 1 || numFiles > MAX_FILES) {
        printf("Please enter a valid number of files between 1 and %d! 😅\n", MAX_FILES);
        return;
    }

    for (int i = 0; i < numFiles; i++) {
        printf("Enter the filename for file %d: ", i + 1);
        scanf("%s", filename);

        // Extract metadata for the given file
        extractMetadata(filename, &metadata[i]);
        displayMetadata(metadata[i]);
    }
}

// Entry point for the program
int main() {
    runMetadataExtractor();
    printf("All done! Have a spectacular day filled with joyful tunes! 🎊\n");
    return 0;
}