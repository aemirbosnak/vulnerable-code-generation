//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Metadata {
    char artist[50];
    char album[50];
    char title[50];
    char year[5];
} Metadata;

void extractMetadata(char* filename, Metadata* metadata);

int main() {
    char filename[50];
    printf("Enter the file name: ");
    scanf("%s", filename);

    Metadata metadata;
    extractMetadata(filename, &metadata);

    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Title: %s\n", metadata.title);
    printf("Year: %s\n", metadata.year);

    return 0;
}

void extractMetadata(char* filename, Metadata* metadata) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, "ARTIST=")) {
            strcpy(metadata->artist, line + 7);
            metadata->artist[strcspn(metadata->artist, "\n")] = 0;
        }
        if (strstr(line, "ALBUM=")) {
            strcpy(metadata->album, line + 6);
            metadata->album[strcspn(metadata->album, "\n")] = 0;
        }
        if (strstr(line, "TITLE=")) {
            strcpy(metadata->title, line + 6);
            metadata->title[strcspn(metadata->title, "\n")] = 0;
        }
        if (strstr(line, "YEAR=")) {
            strcpy(metadata->year, line + 5);
            metadata->year[strcspn(metadata->year, "\n")] = 0;
        }
    }

    fclose(file);
    printf("Metadata extracted successfully.\n");
}