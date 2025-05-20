//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

/* Define the maximum length of metadata */
#define MAX_METADATA_LENGTH 1024

/* Define the number of metadata fields */
#define NUM_FIELDS 4

/* Define the length of each metadata field */
#define FIELD_LENGTH 256

/* Define the delimiter character */
#define DELIMITER ','

/**
 * Function to extract metadata from a given file path.
 * Returns 0 if successful or -1 if not.
 */
int extract_metadata(char *file_path) {
    /* Initialize variables */
    FILE *file;
    char metadata[MAX_METADATA_LENGTH];
    char fields[NUM_FIELDS][FIELD_LENGTH];
    int i = 0;
    int j = 0;
    int k = 0;

    /* Try to open the file */
    file = fopen(file_path, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file: %s\n", file_path);
        return -1;
    }

    /* Read the metadata from the file */
    fgets(metadata, MAX_METADATA_LENGTH, file);

    /* Loop through the metadata and extract the fields */
    for (i = 0; i < MAX_METADATA_LENGTH; i++) {
        if (metadata[i] == DELIMITER) {
            /* Move to the next field */
            j++;
            k = 0;
        } else if (metadata[i] == '\n') {
            /* End of metadata */
            break;
        } else {
            /* Add character to field */
            fields[j][k] = metadata[i];
            k++;
        }
    }

    /* Print the extracted metadata fields */
    printf("Metadata fields:\n");
    for (i = 0; i < NUM_FIELDS; i++) {
        printf("%s\n", fields[i]);
    }

    /* Close the file */
    fclose(file);

    /* Return success */
    return 0;
}

/* Main function */
int main(int argc, char **argv) {
    /* Check for correct number of command line arguments */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s file_path\n", argv[0]);
        return -1;
    }

    /* Extract metadata from the specified file */
    if (extract_metadata(argv[1]) == -1) {
        /* Error extracting metadata */
        fprintf(stderr, "Error extracting metadata from file: %s\n", argv[1]);
        return -1;
    }

    /* Return success */
    return 0;
}