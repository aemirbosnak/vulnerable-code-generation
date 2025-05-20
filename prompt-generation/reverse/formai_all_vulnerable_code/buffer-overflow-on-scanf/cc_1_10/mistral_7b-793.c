//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure definition for metadata
typedef struct {
    char title[MAX_SIZE];
    char artist[MAX_SIZE];
    char album[MAX_SIZE];
    char genre[MAX_SIZE];
    int year;
    int duration;
} Metadata;

// Function to extract metadata from a given file path using a hardcoded format
Metadata extract_metadata(char *file_path) {
    Metadata metadata;
    FILE *file;
    char line[MAX_SIZE];
    int line_number = 0;

    file = fopen(file_path, "r");

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_SIZE, file) != NULL) {
        line_number++;

        if (strstr(line, "[title]") != NULL) {
            sscanf(line, "%*s: %[^,],", metadata.title);
            continue;
        }

        if (strstr(line, "[artist]") != NULL) {
            sscanf(line, "%*s: %[^,],", metadata.artist);
            continue;
        }

        if (strstr(line, "[album]") != NULL) {
            sscanf(line, "%*s: %[^,],", metadata.album);
            continue;
        }

        if (strstr(line, "[genre]") != NULL) {
            sscanf(line, "%*s: %[^,],", metadata.genre);
            continue;
        }

        if (strstr(line, "[year]") != NULL) {
            sscanf(line, "%*s: %d,", &metadata.year);
            continue;
        }

        if (strstr(line, "[duration]") != NULL) {
            sscanf(line, "%*s: %d,", &metadata.duration);
            break;
        }
    }

    fclose(file);

    return metadata;
}

int main() {
    char file_path[MAX_SIZE];
    Metadata metadata;

    printf("Enter the file path: ");
    scanf("%s", file_path);

    metadata = extract_metadata(file_path);

    printf("\nMetadata extracted:\n");
    printf("Title: %s\n", metadata.title);
    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Genre: %s\n", metadata.genre);
    printf("Year: %d\n", metadata.year);
    printf("Duration: %d minutes\n", metadata.duration / 60);

    return 0;
}