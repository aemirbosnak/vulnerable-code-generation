//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_LENGTH 256
#define MAX_ENTRIES 100

typedef struct {
    char title[MAX_METADATA_LENGTH];
    char artist[MAX_METADATA_LENGTH];
    char album[MAX_METADATA_LENGTH];
    int year;
    char genre[MAX_METADATA_LENGTH];
    unsigned long size; // In bytes
} MetadataEntry;

void initializeMetadata(MetadataEntry* entry) {
    strcpy(entry->title, "Unknown Title");
    strcpy(entry->artist, "Unknown Artist");
    strcpy(entry->album, "Unknown Album");
    entry->year = 0;
    strcpy(entry->genre, "Unknown Genre");
    entry->size = 0;
}

void printMetadata(const MetadataEntry* entry) {
    printf("Title: %s\n", entry->title);
    printf("Artist: %s\n", entry->artist);
    printf("Album: %s\n", entry->album);
    printf("Year: %d\n", entry->year);
    printf("Genre: %s\n", entry->genre);
    printf("Size: %lu bytes\n", entry->size);
}

void extractMetadata(const char* filepath, MetadataEntry* entry) {
    FILE* file = fopen(filepath, "rb");
    if (!file) {
        printf("Error: Could not open file %s\n", filepath);
        return;
    }

    // Sample extraction logic; a real implementation would parse an actual audio file.
    fgets(entry->title, MAX_METADATA_LENGTH, file);
    fgets(entry->artist, MAX_METADATA_LENGTH, file);
    fgets(entry->album, MAX_METADATA_LENGTH, file);
    fscanf(file, "%d\n", &entry->year);
    fgets(entry->genre, MAX_METADATA_LENGTH, file);
    fseek(file, 0, SEEK_END);
    entry->size = ftell(file);

    fclose(file);
}

void saveMetadataToFile(const MetadataEntry* entry, const char* output_file) {
    FILE* file = fopen(output_file, "w");
    if (!file) {
        printf("Error: Could not open output file %s\n", output_file);
        return;
    }

    fprintf(file, "Title: %s\n", entry->title);
    fprintf(file, "Artist: %s\n", entry->artist);
    fprintf(file, "Album: %s\n", entry->album);
    fprintf(file, "Year: %d\n", entry->year);
    fprintf(file, "Genre: %s\n", entry->genre);
    fprintf(file, "Size: %lu bytes\n", entry->size);

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_audio_file> [output_metadata_file]\n", argv[0]);
        return 1;
    }

    MetadataEntry entry;
    initializeMetadata(&entry);
    
    extractMetadata(argv[1], &entry);
    
    printf("Extracted Metadata:\n");
    printMetadata(&entry);

    const char* output_file = (argc > 2) ? argv[2] : "metadata.txt";
    saveMetadataToFile(&entry, output_file);
    
    printf("Metadata saved to %s\n", output_file);
    return 0;
}