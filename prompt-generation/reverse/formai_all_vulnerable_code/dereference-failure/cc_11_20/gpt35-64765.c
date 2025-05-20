//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define struct to hold metadata information
typedef struct Metadata {
    char* artist;
    char* album;
    char* title;
    int year;
    char* genre;
} Metadata;

// Function to extract metadata from file
Metadata extractMetadata(char* filename) {
    // Open file with filename
    FILE* file = fopen(filename, "rb");
    
    // Check if file opened successfully
    if (file == NULL) {
        printf("Error: Unable to open file\n");
        exit(1);
    }
    
    // Seek to end of file to get file size
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    rewind(file);

    // Create buffer to hold file data
    char* buffer = (char*) malloc(sizeof(char) * filesize);
    fread(buffer, 1, filesize, file);
    
    // Close file
    fclose(file);
    
    // Create metadata struct and initialize values to NULL or 0
    Metadata metadata;
    metadata.artist = NULL;
    metadata.album = NULL;
    metadata.title = NULL;
    metadata.year = 0;
    metadata.genre = NULL;
    
    // Loop through buffer looking for metadata tags
    int i = 0;
    while (i < filesize) {
        // Check for artist tag
        if (buffer[i] == 'A' && buffer[i+1] == 'R' && buffer[i+2] == 'T' && buffer[i+3] == 'I' && buffer[i+4] == 'S' && buffer[i+5] == 'T' && buffer[i+6] == '=') {
            i += 7;
            int artistLength = 0;
            while (buffer[i+artistLength] != '\0') {
                artistLength++;
            }
            metadata.artist = (char*) malloc(sizeof(char) * artistLength);
            strncpy(metadata.artist, buffer+i, artistLength);
        }
        
        // Check for album tag
        if (buffer[i] == 'A' && buffer[i+1] == 'L' && buffer[i+2] == 'B' && buffer[i+3] == 'U' && buffer[i+4] == 'M' && buffer[i+5] == '=') {
            i += 6;
            int albumLength = 0;
            while (buffer[i+albumLength] != '\0') {
                albumLength++;
            }
            metadata.album = (char*) malloc(sizeof(char) * albumLength);
            strncpy(metadata.album, buffer+i, albumLength);
        }
        
        // Check for title tag
        if (buffer[i] == 'T' && buffer[i+1] == 'I' && buffer[i+2] == 'T' && buffer[i+3] == '2' && buffer[i+4] == 'L' && buffer[i+5] == 'E' && buffer[i+6] == '=') {
            i += 7;
            int titleLength = 0;
            while (buffer[i+titleLength] != '\0') {
                titleLength++;
            }
            metadata.title = (char*) malloc(sizeof(char) * titleLength);
            strncpy(metadata.title, buffer+i, titleLength);
        }
        
        // Check for year tag
        if (buffer[i] == 'Y' && buffer[i+1] == 'E' && buffer[i+2] == 'A' && buffer[i+3] == 'R' && buffer[i+4] == '=') {
            i += 5;
            char yearString[4];
            strncpy(yearString, buffer+i, 4);
            metadata.year = atoi(yearString);
        }
        
        // Check for genre tag
        if (buffer[i] == 'G' && buffer[i+1] == 'E' && buffer[i+2] == 'N' && buffer[i+3] == 'R' && buffer[i+4] == 'E' && buffer[i+5] == '=') {
            i += 6;
            int genreLength = 0;
            while (buffer[i+genreLength] != '\0') {
                genreLength++;
            }
            metadata.genre = (char*) malloc(sizeof(char) * genreLength);
            strncpy(metadata.genre, buffer+i, genreLength);
        }
        
        // Increment i to move to next tag
        i++;
    }
    
    // Free buffer memory
    free(buffer);
    
    // Return metadata struct
    return metadata;
}

// Main function to test metadata extraction
int main() {
    char* filename = "song.mp3";
    Metadata metadata = extractMetadata(filename);
    
    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Title: %s\n", metadata.title);
    printf("Year: %d\n", metadata.year);
    printf("Genre: %s\n", metadata.genre);
    
    // Free metadata memory
    free(metadata.artist);
    free(metadata.album);
    free(metadata.title);
    free(metadata.genre);
    
    return 0;
}