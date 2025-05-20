//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_SIZE 1024

typedef struct {
    char title[MAX_METADATA_SIZE];
    char artist[MAX_METADATA_SIZE];
    char album[MAX_METADATA_SIZE];
    int year;
    char genre[MAX_METADATA_SIZE];
} Metadata;

void parse_metadata(const char *filename, Metadata *data) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_METADATA_SIZE];
    
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Title: ", 7) == 0) {
            sscanf(line + 7, "%[^\n]", data->title);
        } else if (strncmp(line, "Artist: ", 8) == 0) {
            sscanf(line + 8, "%[^\n]", data->artist);
        } else if (strncmp(line, "Album: ", 7) == 0) {
            sscanf(line + 7, "%[^\n]", data->album);
        } else if (strncmp(line, "Year: ", 6) == 0) {
            sscanf(line + 6, "%d", &data->year);
        } else if (strncmp(line, "Genre: ", 7) == 0) {
            sscanf(line + 7, "%[^\n]", data->genre);
        }
    }
    
    fclose(file);
}

void display_metadata(const Metadata *data) {
    printf("\nMetadata Information:\n");
    printf("Title: %s\n", data->title);
    printf("Artist: %s\n", data->artist);
    printf("Album: %s\n", data->album);
    printf("Year: %d\n", data->year);
    printf("Genre: %s\n", data->genre);
}

void validate_metadata(const Metadata *data) {
    if (strlen(data->title) == 0) {
        fprintf(stderr, "Error: Title is missing!\n");
    }
    if (strlen(data->artist) == 0) {
        fprintf(stderr, "Error: Artist is missing!\n");
    }
    if (strlen(data->album) == 0) {
        fprintf(stderr, "Error: Album is missing!\n");
    }
    if (data->year < 1880 || data->year > 2023) {
        fprintf(stderr, "Error: Year must be valid!\n");
    }
    if (strlen(data->genre) == 0) {
        fprintf(stderr, "Error: Genre is missing!\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <metadata_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Metadata data;
    memset(&data, 0, sizeof(data));

    parse_metadata(argv[1], &data);
    validate_metadata(&data);
    display_metadata(&data);

    return EXIT_SUCCESS;
}