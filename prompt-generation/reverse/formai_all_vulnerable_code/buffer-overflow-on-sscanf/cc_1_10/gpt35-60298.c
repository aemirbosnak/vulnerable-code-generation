//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum size of metadata and property values */
#define MAX_METADATA_SIZE 256
#define MAX_PROPERTY_SIZE 64

/* Define the metadata and property structs */
typedef struct Metadata {
    char name[MAX_METADATA_SIZE];
    char author[MAX_PROPERTY_SIZE];
    char date[MAX_PROPERTY_SIZE];
} Metadata;

typedef struct Property {
    char name[MAX_PROPERTY_SIZE];
    char value[MAX_PROPERTY_SIZE];
} Property;

/* Function to extract metadata from a file */
Metadata extract_metadata(const char *filename) {
    /* Open the file for reading */
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file %s for reading\n", filename);
        exit(EXIT_FAILURE);
    }

    /* Read the metadata from the file */
    Metadata metadata;
    Property property;
    char buffer[MAX_METADATA_SIZE];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        /* Parse the metadata and properties */
        if (sscanf(buffer, "@%[^:]:%[^=]=%s", metadata.name,
            property.name, property.value) == 3) {
            /* Copy the property value to the appropriate field */
            if (strcmp(property.name, "author") == 0) {
                strcpy(metadata.author, property.value);
            } else if (strcmp(property.name, "date") == 0) {
                strcpy(metadata.date, property.value);
            }
        }
    }

    /* Close the file */
    fclose(file);

    /* Return the extracted metadata */
    return metadata;
}

/* Function to print metadata in a formatted way */
void print_metadata(const Metadata *metadata) {
    printf("Name: %s\n", metadata->name);
    printf("Author: %s\n", metadata->author);
    printf("Date: %s\n", metadata->date);
}

/* Main program */
int main(int argc, char *argv[]) {
    /* Check that a filename was provided as argument */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Extract the metadata from the file */
    Metadata metadata = extract_metadata(argv[1]);

    /* Print the metadata */
    print_metadata(&metadata);

    /* Exit successfully */
    return EXIT_SUCCESS;
}