//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: light-weight
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

void initialize_metadata(Metadata *meta) {
    strcpy(meta->filename, "UNKNOWN");
    strcpy(meta->title, "UNKNOWN");
    strcpy(meta->artist, "UNKNOWN");
    strcpy(meta->album, "UNKNOWN");
    meta->year = 0;
}

void print_metadata(const Metadata *meta) {
    printf("File: %s\n", meta->filename);
    printf("Title: %s\n", meta->title);
    printf("Artist: %s\n", meta->artist);
    printf("Album: %s\n", meta->album);
    printf("Year: %d\n", meta->year);
}

void read_metadata_from_file(const char *filename, Metadata *meta) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    strcpy(meta->filename, filename);
    
    // Simulating reading metadata; in real scenarios, parse file headers
    fscanf(file, "Title: %[^\n]\n", meta->title);
    fscanf(file, "Artist: %[^\n]\n", meta->artist);
    fscanf(file, "Album: %[^\n]\n", meta->album);
    fscanf(file, "Year: %d\n", &meta->year);

    fclose(file);
}

void save_metadata_to_file(const char *filename, const Metadata *meta) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error saving metadata");
        return;
    }

    fprintf(file, "Title: %s\n", meta->title);
    fprintf(file, "Artist: %s\n", meta->artist);
    fprintf(file, "Album: %s\n", meta->album);
    fprintf(file, "Year: %d\n", meta->year);

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <audio_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *audio_file = argv[1];
    Metadata meta;
    initialize_metadata(&meta);
    
    read_metadata_from_file(audio_file, &meta);
    
    printf("\n--- Metadata Extractor ---\n");
    print_metadata(&meta);
    
    // Modify some metadata (for demonstration purposes)
    strcpy(meta.artist, "New Artist");
    meta.year = 2023;

    // Save modified metadata back to a new file
    char output_file[MAX_FILENAME_LENGTH];
    sprintf(output_file, "modified_%s", audio_file);
    save_metadata_to_file(output_file, &meta);
    
    printf("\nModified metadata saved to: %s\n", output_file);
    
    return 0;
}