//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: creative
#include <stdio.h>
#include <string.h>

typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    char year[10];
} metadata;

metadata extract_metadata(char *filename);

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    metadata data = extract_metadata(filename);

    printf("\nTitle: %s\n", data.title);
    printf("Artist: %s\n", data.artist);
    printf("Album: %s\n", data.album);
    printf("Year: %s\n", data.year);

    return 0;
}

metadata extract_metadata(char *filename) {
    metadata data;

    // Open file in read-only mode
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        // Error handling
        printf("File not found.\n");
        strcpy(data.title, "Unknown");
        strcpy(data.artist, "Unknown");
        strcpy(data.album, "Unknown");
        strcpy(data.year, "Unknown");
        return data;
    }

    // Seek to ID3 tag position
    int seek_result = fseek(file, -128, SEEK_END);
    if (seek_result != 0) {
        // Error handling
        printf("ID3 tag not found.\n");
        strcpy(data.title, "Unknown");
        strcpy(data.artist, "Unknown");
        strcpy(data.album, "Unknown");
        strcpy(data.year, "Unknown");
        return data;
    }

    // Read ID3 tag data
    char id3[3];
    fread(id3, 1, 3, file);
    char title[31];
    fread(title, 1, 30, file);
    char artist[31];
    fread(artist, 1, 30, file);
    char album[31];
    fread(album, 1, 30, file);
    char year[5];
    fread(year, 1, 4, file);

    // Set metadata values
    strcpy(data.title, title);
    strcpy(data.artist, artist);
    strcpy(data.album, album);
    strcpy(data.year, year);

    // Close file
    fclose(file);

    return data;
}