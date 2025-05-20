//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 256
#define MAX_METADATA_LENGTH 512

typedef struct {
    char title[MAX_METADATA_LENGTH];
    char author[MAX_METADATA_LENGTH];
    int year;
    char genre[MAX_METADATA_LENGTH];
} Metadata;

void initialize_metadata(Metadata *metadata) {
    strcpy(metadata->title, "Unknown");
    strcpy(metadata->author, "Unknown");
    metadata->year = 0;
    strcpy(metadata->genre, "Unknown");
}

void extract_metadata(const char *filename, Metadata *metadata) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    char line[MAX_METADATA_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Title:")) {
            sscanf(line, "Title: %[^\n]", metadata->title);
        } else if (strstr(line, "Author:")) {
            sscanf(line, "Author: %[^\n]", metadata->author);
        } else if (strstr(line, "Year:")) {
            sscanf(line, "Year: %d", &metadata->year);
        } else if (strstr(line, "Genre:")) {
            sscanf(line, "Genre: %[^\n]", metadata->genre);
        }
    }
    fclose(file);
}

void print_metadata(const Metadata *metadata) {
    printf("Metadata:\n");
    printf("  Title:  %s\n", metadata->title);
    printf("  Author: %s\n", metadata->author);
    printf("  Year:   %d\n", metadata->year);
    printf("  Genre:  %s\n\n", metadata->genre);
}

void process_files(const char *filenames[], int file_count) {
    Metadata metadata[MAX_FILES];

    for (int i = 0; i < file_count; ++i) {
        initialize_metadata(&metadata[i]);
        extract_metadata(filenames[i], &metadata[i]);
        print_metadata(&metadata[i]);
    }
}

void get_filenames(char filenames[MAX_FILES][MAX_FILENAME_LENGTH], int *file_count) {
    printf("Enter the number of files: ");
    scanf("%d", file_count);
    
    for (int i = 0; i < *file_count; i++) {
        printf("Enter filename %d: ", i + 1);
        scanf("%s", filenames[i]);
    }
}

int main() {
    char filenames[MAX_FILES][MAX_FILENAME_LENGTH];
    int file_count;

    get_filenames(filenames, &file_count);
    process_files((const char **)filenames, file_count);

    return 0;
}