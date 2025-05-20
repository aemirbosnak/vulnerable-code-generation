//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_METADATA_LENGTH 512

typedef struct {
    char title[MAX_METADATA_LENGTH];
    char artist[MAX_METADATA_LENGTH];
    char album[MAX_METADATA_LENGTH];
    char year[MAX_METADATA_LENGTH];
    char genre[MAX_METADATA_LENGTH];
} Metadata;

void clearMetadata(Metadata *meta) {
    memset(meta, 0, sizeof(Metadata));
}

void displayMetadata(const Metadata *meta) {
    printf("Title: %s\n", meta->title[0] ? meta->title : "Unknown");
    printf("Artist: %s\n", meta->artist[0] ? meta->artist : "Unknown");
    printf("Album: %s\n", meta->album[0] ? meta->album : "Unknown");
    printf("Year: %s\n", meta->year[0] ? meta->year : "Unknown");
    printf("Genre: %s\n", meta->genre[0] ? meta->genre : "Unknown");
}

void extractMetadata(const char* filename, Metadata *meta) {
    // Simulate metadata extraction
    if (strcmp(filename, "song1.mp3") == 0) {
        strcpy(meta->title, "First Song");
        strcpy(meta->artist, "The Artists");
        strcpy(meta->album, "Great Album");
        strcpy(meta->year, "2020");
        strcpy(meta->genre, "Pop");
    } else if (strcmp(filename, "song2.mp3") == 0) {
        strcpy(meta->title, "Second Song");
        strcpy(meta->artist, "Another Band");
        strcpy(meta->album, "Another Album");
        strcpy(meta->year, "2019");
        strcpy(meta->genre, "Rock");
    } else {
        strcpy(meta->title, "Unknown");
        strcpy(meta->artist, "Unknown");
        strcpy(meta->album, "Unknown");
        strcpy(meta->year, "Unknown");
        strcpy(meta->genre, "Unknown");
    }
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    Metadata meta;
    char continueExtraction;

    printf("Welcome to the Metadata Extractor!\n");
    
    do {
        clearMetadata(&meta);
        printf("Enter the filename of the audio file (e.g. song.mp3): ");
        scanf("%s", filename);

        extractMetadata(filename, &meta);
        displayMetadata(&meta);

        printf("Do you want to extract metadata for another file? (y/n): ");
        scanf(" %c", &continueExtraction);
    } while (continueExtraction == 'y' || continueExtraction == 'Y');

    printf("Exiting Metadata Extractor. Goodbye!\n");
    return 0;
}