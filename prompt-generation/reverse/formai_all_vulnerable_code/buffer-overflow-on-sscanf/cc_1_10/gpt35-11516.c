//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_LEN 128

typedef struct {
    char title[MAX_METADATA_LEN];
    char artist[MAX_METADATA_LEN];
    char album[MAX_METADATA_LEN];
    char year[MAX_METADATA_LEN];
} Metadata;

void extract_metadata(const char* filename, Metadata* metadata) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: couldn't open file '%s'.\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_METADATA_LEN];
    while (fgets(line, MAX_METADATA_LEN, file)) {
        if (strstr(line, "Title:")) {
            sscanf(line, "Title: %s", metadata->title);
        } else if (strstr(line, "Artist:")) {
            sscanf(line, "Artist: %s", metadata->artist);
        } else if (strstr(line, "Album:")) {
            sscanf(line, "Album: %s", metadata->album);
        } else if (strstr(line, "Year:")) {
            sscanf(line, "Year: %s", metadata->year);
        }
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Metadata metadata;
    memset(&metadata, 0, sizeof(metadata));

    extract_metadata(argv[1], &metadata);

    printf("Title: %s\n", metadata.title);
    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Year: %s\n", metadata.year);

    return EXIT_SUCCESS;
}