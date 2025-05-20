//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 256
#define MAX_METADATA_LENGTH 512

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char title[MAX_METADATA_LENGTH];
    char artist[MAX_METADATA_LENGTH];
    char album[MAX_METADATA_LENGTH];
    int year;
} Metadata;

void extractMetadata(const char *filename, Metadata *metadata) {
    // A very simple mock metadata extraction logic
    // In reality, you'd parse file types and read actual metadata

    snprintf(metadata->filename, MAX_FILENAME_LENGTH, "%s", filename);
    
    // Populate mock values for metadata
    snprintf(metadata->title, MAX_METADATA_LENGTH, "Sample Title for %s", filename);
    snprintf(metadata->artist, MAX_METADATA_LENGTH, "Sample Artist");
    snprintf(metadata->album, MAX_METADATA_LENGTH, "Sample Album");
    metadata->year = 2023; // A static value for simplification
}

void printMetadata(const Metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Title: %s\n", metadata->title);
    printf("Artist: %s\n", metadata->artist);
    printf("Album: %s\n", metadata->album);
    printf("Year: %d\n", metadata->year);
    printf("--------------------\n");
}

void processFiles(char (*files)[MAX_FILENAME_LENGTH], int numFiles) {
    Metadata metadata[MAX_FILES];

    for (int i = 0; i < numFiles; i++) {
        extractMetadata(files[i], &metadata[i]);
        printMetadata(&metadata[i]);
    }
}

int main() {
    char files[MAX_FILES][MAX_FILENAME_LENGTH];
    int numFiles = 0;

    // Simulating file input (in a real case this could be directory traversal)
    printf("Enter the number of files (up to %d): ", MAX_FILES);
    scanf("%d", &numFiles);

    if (numFiles > MAX_FILES) {
        printf("Error: Maximum number of files exceeded!\n");
        return 1;
    }

    for (int i = 0; i < numFiles; i++) {
        printf("Enter filename %d: ", i + 1);
        scanf("%s", files[i]);
    }

    printf("\nExtracting metadata...\n");
    processFiles(files, numFiles);

    return 0;
}