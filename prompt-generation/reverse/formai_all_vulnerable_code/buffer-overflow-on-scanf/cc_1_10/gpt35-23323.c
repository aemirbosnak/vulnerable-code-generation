//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILE_PATH_LENGTH 256
#define MAX_BUFFER_SIZE 512

void extract_metadata(char *file_path, char *artist, char *title, char *album, char *year);

int main() {
    // Define variables
    char file_path[MAX_FILE_PATH_LENGTH], artist[MAX_BUFFER_SIZE], title[MAX_BUFFER_SIZE], album[MAX_BUFFER_SIZE], year[MAX_BUFFER_SIZE];

    // Get file path from user
    printf("Enter the file path: ");
    scanf("%s", file_path);

    // Extract metadata
    extract_metadata(file_path, artist, title, album, year);

    // Print extracted metadata
    printf("Artist: %s\nTitle: %s\nAlbum: %s\nYear: %s\n", artist, title, album, year);

    return 0;
}

void extract_metadata(char *file_path, char *artist, char *title, char *album, char *year) {
    FILE *file = fopen(file_path, "r");

    if (file == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    char line[MAX_BUFFER_SIZE], *key, *value;

    while (fgets(line, MAX_BUFFER_SIZE, file)) {
        key = strtok(line, ":");
        value = strtok(NULL, "\n");

        if (key != NULL && value != NULL) {
            if (strcmp(key, "ARTIST") == 0) {
                strcpy(artist, value);
            } else if (strcmp(key, "TITLE") == 0) {
                strcpy(title, value);
            } else if (strcmp(key, "ALBUM") == 0) {
                strcpy(album, value);
            } else if (strcmp(key, "YEAR") == 0) {
                strcpy(year, value);
            }
        }
    }

    fclose(file);
}