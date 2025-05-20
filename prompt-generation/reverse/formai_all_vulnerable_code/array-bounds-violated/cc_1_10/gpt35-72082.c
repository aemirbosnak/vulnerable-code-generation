//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Hello there! Let's extract some metadata from a file!\n");
    
    // Prompt user to enter file path
    char file_path[100];
    printf("Enter file path: ");
    fgets(file_path, sizeof(file_path), stdin);

    // Remove newline character from file path
    file_path[strcspn(file_path, "\n")] = 0;

    // Open file in read mode
    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error opening file. Please try again.\n");
        return 0;
    }

    // Get file size
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);

    // Extract metadata
    char title[50], artist[50], album[50], year[5];
    fgets(title, sizeof(title), fp);
    if (title[strlen(title) - 1] == '\n') {
        title[strlen(title) - 1] = '\0';
    }
    fgets(artist, sizeof(artist), fp);
    if (artist[strlen(artist) - 1] == '\n') {
        artist[strlen(artist) - 1] = '\0';
    }
    fgets(album, sizeof(album), fp);
    if (album[strlen(album) - 1] == '\n') {
        album[strlen(album) - 1] = '\0';
    }
    fgets(year, sizeof(year), fp);
    if (year[strlen(year) - 1] == '\n') {
        year[strlen(year) - 1] = '\0';
    }

    // Print metadata
    printf("\nMetadata for file %s:\n", file_path);
    printf("Title: %s\n", title);
    printf("Artist: %s\n", artist);
    printf("Album: %s\n", album);
    printf("Year: %s\n", year);
    printf("File size: %d bytes\n", file_size);

    // Close file
    fclose(fp);

    printf("\nThank you for using our program!\n");
    return 0;
}