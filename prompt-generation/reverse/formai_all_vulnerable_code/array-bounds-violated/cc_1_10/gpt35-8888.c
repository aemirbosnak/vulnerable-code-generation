//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char title[MAX_SIZE];
    char artist[MAX_SIZE];
    char album[MAX_SIZE];
    char year[MAX_SIZE];
} metadata;

int main() {
    FILE *file;
    metadata song;
    char filePath[MAX_SIZE];

    // Get file path from user
    printf("Enter file path: ");
    fgets(filePath, MAX_SIZE, stdin);
    filePath[strlen(filePath) - 1] = '\0'; // Remove newline character

    file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Could not open file!\n");
        exit(1);
    }

    // Extract metadata from file
    char line[MAX_SIZE];
    while (fgets(line, MAX_SIZE, file)) {
        if (strstr(line, "Title:")) {
            strcpy(song.title, line + strlen("Title:"));
            song.title[strlen(song.title) - 1] = '\0'; // Remove newline character
        }

        if (strstr(line, "Artist:")) {
            strcpy(song.artist, line + strlen("Artist:"));
            song.artist[strlen(song.artist) - 1] = '\0';
        }

        if (strstr(line, "Album:")) {
            strcpy(song.album, line + strlen("Album:"));
            song.album[strlen(song.album) - 1] = '\0';
        }

        if (strstr(line, "Year:")) {
            strcpy(song.year, line + strlen("Year:"));
            song.year[strlen(song.year) - 1] = '\0';
        }
    }

    // Print extracted metadata
    printf("Title: %s\n", song.title);
    printf("Artist: %s\n", song.artist);
    printf("Album: %s\n", song.album);
    printf("Year: %s\n", song.year);

    fclose(file);
    return 0;
}