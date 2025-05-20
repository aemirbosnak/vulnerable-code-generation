//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct to hold metadata information
typedef struct {
    char artist[50];
    char title[50];
    char album[50];
    int year;
} Metadata;

// Declare function to extract metadata from file
Metadata extractMetadata(char *filename);

int main() {
    char filename[100];
    Metadata data;

    printf("Enter filename: ");
    scanf("%s", filename);

    // Call function to extract metadata
    data = extractMetadata(filename);

    // Display extracted metadata
    printf("Artist: %s\nTitle: %s\nAlbum: %s\nYear: %d\n", 
           data.artist, data.title, data.album, data.year);
    
    return 0;
}

Metadata extractMetadata(char *filename) {
    Metadata data;
    char line[100];
    FILE *fp;

    // Open file
    fp = fopen(filename, "r");

    // Check if file exists
    if (fp == NULL) {
        printf("File does not exist.\n");
        exit(1);
    }

    // Read file line by line
    while (fgets(line, 100, fp)) {
        // Check if line contains artist information
        if (strstr(line, "Artist:") != NULL) {
            sscanf(line, "Artist: %[^\n]s", data.artist);
        }
        // Check if line contains title information
        if (strstr(line, "Title:") != NULL) {
            sscanf(line, "Title: %[^\n]s", data.title);
        }
        // Check if line contains album information
        if (strstr(line, "Album:") != NULL) {
            sscanf(line, "Album: %[^\n]s", data.album);
        }
        // Check if line contains year information
        if (strstr(line, "Year:") != NULL) {
            sscanf(line, "Year: %d", &data.year);
        }
    }

    // Close file
    fclose(fp);

    return data;
}