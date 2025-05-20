//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of metadata tags to extract
#define MAX_TAGS 10

// Define the structure for a metadata tag
typedef struct {
    char key[50];
    char value[100];
} metadata_tag;

// Function to extract metadata from a file
void extract_metadata(char* filename, metadata_tag* tags) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    // Check if the file is a valid metadata file
    char header[4];
    fread(header, 1, 4, file);
    if (strcmp(header, "MET")!= 0) {
        printf("Error: Invalid metadata file\n");
        exit(1);
    }

    // Extract metadata tags
    int num_tags = 0;
    while (num_tags < MAX_TAGS && fread(&tags[num_tags], sizeof(metadata_tag), 1, file) == 1) {
        num_tags++;
    }

    // Close the file
    fclose(file);
}

// Function to print metadata tags
void print_metadata_tags(metadata_tag* tags, int num_tags) {
    printf("Metadata tags:\n");
    for (int i = 0; i < num_tags; i++) {
        printf("Key: %s\nValue: %s\n", tags[i].key, tags[i].value);
    }
}

int main() {
    // Define the metadata tags
    metadata_tag tags[MAX_TAGS];

    // Get the filename from the user
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Extract metadata from the file
    extract_metadata(filename, tags);

    // Print the metadata tags
    print_metadata_tags(tags, MAX_TAGS);

    return 0;
}