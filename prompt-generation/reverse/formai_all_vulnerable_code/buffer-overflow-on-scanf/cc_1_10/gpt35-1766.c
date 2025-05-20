//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold metadata information
typedef struct Metadata {
    char artist[50];
    char song_title[100];
    int duration_in_seconds;
} Metadata;

int main() {
    // Prompt user for file path
    char file_path[100];
    printf("Enter file path: ");
    scanf("%s", file_path);

    // Open the file in read mode
    FILE *file_pointer = fopen(file_path, "r");
    if(file_pointer == NULL) {
        printf("File not found. Please check the file path and try again.\n");
        exit(0);
    }

    // Initialize metadata struct
    Metadata metadata;
    strcpy(metadata.artist, "Unknown");
    strcpy(metadata.song_title, "Unknown");
    metadata.duration_in_seconds = 0;

    // Read each line of the file
    char line[100];
    while(fgets(line, 100, file_pointer)) {
        // Check if line contains artist metadata
        if(strncmp(line, "ARTIST:", 7) == 0) { // strncmp() compares the first 7 characters of line to "ARTIST:"
            strcpy(metadata.artist, &line[8]); // Copy the artist name from the 8th character of line to metadata.artist
            metadata.artist[strcspn(metadata.artist, "\n")] = 0; // Remove the newline character from the end of the string
        }

        // Check if line contains song title metadata
        if(strncmp(line, "TITLE:", 6) == 0) {
            strcpy(metadata.song_title, &line[7]);
            metadata.song_title[strcspn(metadata.song_title, "\n")] = 0;
        }

        // Check if line contains duration metadata
        if(strncmp(line, "DURATION:", 9) == 0) {
            metadata.duration_in_seconds = atoi(&line[10]); // Convert string to integer starting at the 10th character of line
        }
    }

    // Close the file
    fclose(file_pointer);

    // Print out the metadata information
    printf("Artist: %s\n", metadata.artist);
    printf("Song Title: %s\n", metadata.song_title);
    printf("Duration (in seconds): %d\n", metadata.duration_in_seconds);

    return 0;
}