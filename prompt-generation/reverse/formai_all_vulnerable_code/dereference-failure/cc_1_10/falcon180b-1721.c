//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of metadata fields to extract
#define MAX_FIELDS 10

// Define the metadata field structure
typedef struct {
    char *name;
    char *value;
} MetadataField;

// Function to extract metadata from a file
int extractMetadata(FILE *file, MetadataField fields[MAX_FIELDS]) {
    int numFields = 0;
    char line[1024];
    char *delimiter = ": ";
    char *token;

    // Read the first line of the file, which contains the metadata
    fgets(line, sizeof(line), file);

    // Parse the metadata line and extract the field values
    token = strtok(line, delimiter);
    while (token!= NULL && numFields < MAX_FIELDS) {
        fields[numFields].name = strdup(token);
        fields[numFields].value = strdup(strtok(NULL, delimiter));
        numFields++;
        token = strtok(NULL, delimiter);
    }

    return numFields;
}

// Function to print the extracted metadata
void printMetadata(MetadataField fields[MAX_FIELDS], int numFields) {
    int i;

    for (i = 0; i < numFields; i++) {
        printf("%s: %s\n", fields[i].name, fields[i].value);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <metadata_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    MetadataField fields[MAX_FIELDS];
    int numFields = extractMetadata(file, fields);

    if (numFields > 0) {
        printf("Extracted metadata:\n");
        printMetadata(fields, numFields);
    } else {
        printf("No metadata found.\n");
    }

    fclose(file);
    return 0;
}