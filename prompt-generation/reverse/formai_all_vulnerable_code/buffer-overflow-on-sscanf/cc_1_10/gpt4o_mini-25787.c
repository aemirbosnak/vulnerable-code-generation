//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold metadata information
typedef struct {
    char title[100];
    char artist[100];
    char album[100];
    int year;
    char genre[50];
} Metadata;

// Function to read metadata from a file
Metadata read_metadata(const char *filename) {
    Metadata metadata = {"Unknown", "Unknown", "Unknown", 0, "Unknown"};
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return metadata; // Return default values
    }

    char line[256];

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Title:", 6) == 0) {
            sscanf(line + 6, " %[^\n]", metadata.title);
        } else if (strncmp(line, "Artist:", 7) == 0) {
            sscanf(line + 7, " %[^\n]", metadata.artist);
        } else if (strncmp(line, "Album:", 6) == 0) {
            sscanf(line + 6, " %[^\n]", metadata.album);
        } else if (strncmp(line, "Year:", 5) == 0) {
            sscanf(line + 5, "%d", &metadata.year);
        } else if (strncmp(line, "Genre:", 6) == 0) {
            sscanf(line + 6, " %[^\n]", metadata.genre);
        }
    }

    fclose(file);
    return metadata;
}

// Function to display metadata
void display_metadata(Metadata data) {
    printf("Metadata Information:\n");
    printf("Title:  %s\n", data.title);
    printf("Artist: %s\n", data.artist);
    printf("Album:  %s\n", data.album);
    printf("Year:   %d\n", data.year);
    printf("Genre:  %s\n", data.genre);
}

// Function to save metadata to a file
void save_metadata(const char *filename, Metadata data) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s for writing\n", filename);
        return;
    }

    fprintf(file, "Title: %s\n", data.title);
    fprintf(file, "Artist: %s\n", data.artist);
    fprintf(file, "Album: %s\n", data.album);
    fprintf(file, "Year: %d\n", data.year);
    fprintf(file, "Genre: %s\n", data.genre);

    fclose(file);
}

// Main function to implement the metadata extractor
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <metadata_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *metadata_file = argv[1];

    // Read metadata from the given file
    Metadata data = read_metadata(metadata_file);
    
    // Display the extracted metadata
    display_metadata(data);

    // Create a new metadata file as a demonstration
    const char *output_file = "output_metadata.txt";
    save_metadata(output_file, data);
    
    printf("\nMetadata saved to %s\n", output_file);

    return EXIT_SUCCESS;
}