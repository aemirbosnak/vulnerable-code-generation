//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store metadata
struct Metadata {
    char name[100];
    char artist[100];
    char album[100];
    int year;
    char genre[100];
};

// Function to extract metadata from a file
void extractMetadata(const char* filePath, struct Metadata* metadata) {
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filePath);
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, "Title") != NULL) {
            sscanf(line, "Title: %s", metadata->name);
        } else if (strstr(line, "Artist") != NULL) {
            sscanf(line, "Artist: %s", metadata->artist);
        } else if (strstr(line, "Album") != NULL) {
            sscanf(line, "Album: %s", metadata->album);
        } else if (strstr(line, "Year") != NULL) {
            sscanf(line, "Year: %d", &metadata->year);
        } else if (strstr(line, "Genre") != NULL) {
            sscanf(line, "Genre: %s", metadata->genre);
        }
    }

    fclose(file);
}

// Function to display metadata
void displayMetadata(struct Metadata metadata) {
    printf("Name: %s\n", metadata.name);
    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Year: %d\n", metadata.year);
    printf("Genre: %s\n", metadata.genre);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    struct Metadata metadata;
    extractMetadata(argv[1], &metadata);
    displayMetadata(metadata);

    return 0;
}