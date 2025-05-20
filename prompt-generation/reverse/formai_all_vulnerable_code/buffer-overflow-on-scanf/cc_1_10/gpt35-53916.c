//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures to hold metadata
typedef struct {
    char artist[50];
    char album[50];
    char title[100];
    char genre[20];
    int year;
} Metadata;

// Function to extract metadata
void extract_metadata(FILE* file, Metadata* md) {
    char line[200];
    int found;

    // Read each line of file until metadata is found
    while(fgets(line, 200, file)) {
        found = 0;

        // Check for artist metadata
        if(strstr(line, "ARTIST=")) {
            sscanf(line, "ARTIST=%s", md->artist);
            found = 1;
        }

        // Check for album metadata
        if(strstr(line, "ALBUM=")) {
            sscanf(line, "ALBUM=%s", md->album);
            found = 1;
        }

        // Check for title metadata
        if(strstr(line, "TITLE=")) {
            sscanf(line, "TITLE=%s", md->title);
            found = 1;
        }

        // Check for genre metadata
        if(strstr(line, "GENRE=")) {
            sscanf(line, "GENRE=%s", md->genre);
            found = 1;
        }

        // Check for year metadata
        if(strstr(line, "YEAR=")) {
            sscanf(line, "YEAR=%d", &md->year);
            found = 1;
        }

        // Break loop if all metadata is found
        if(found == 1 && md->artist[0] != '\0' && md->album[0] != '\0' && md->title[0] != '\0' && md->genre[0] != '\0' && md->year != 0)
            break;
    }
}

int main(int argc, char** argv) {
    FILE* file;
    Metadata md;
    char filename[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open file and extract metadata
    file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    else {
        extract_metadata(file, &md);
        printf("Metadata:\nArtist: %s\nAlbum: %s\nTitle: %s\nGenre: %s\nYear: %d\n", md.artist, md.album, md.title, md.genre, md.year);
        fclose(file);
    }

    return 0;
}