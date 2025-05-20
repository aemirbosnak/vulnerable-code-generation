//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 100

// Define a struct to hold metadata information
typedef struct {
    char *key;
    char *value;
} metadata;

// Function to parse a metadata field
metadata parse_metadata_field(char *line) {
    metadata meta;
    char *key_value[2];

    // Split the line into key-value pair
    key_value[0] = strtok(line, ": ");
    key_value[1] = strtok(NULL, ":");

    // Allocate memory for key and value
    meta.key = malloc(strlen(key_value[0]) + 1);
    meta.value = malloc(strlen(key_value[1]) + 1);

    // Copy key and value to metadata struct
    strcpy(meta.key, key_value[0]);
    strcpy(meta.value, key_value[1]);

    return meta;
}

// Function to print metadata information
void print_metadata(metadata *meta, int num_fields) {
    int i;

    for (i = 0; i < num_fields; i++) {
        printf("Key: %s\nValue: %s\n", meta[i].key, meta[i].value);
    }
}

// Main function
int main(int argc, char *argv[]) {
    FILE *fp;
    char line[1024];
    metadata *meta = NULL;
    int num_fields = 0;

    // Open input file
    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read metadata fields from input file
    while (fgets(line, sizeof(line), fp)!= NULL) {
        metadata field = parse_metadata_field(line);

        // Allocate memory for metadata array if necessary
        if (meta == NULL) {
            meta = malloc(sizeof(metadata));
            num_fields = 1;
        } else if (num_fields >= MAX_FIELDS) {
            printf("Maximum number of fields reached.\n");
            break;
        } else {
            meta = realloc(meta, sizeof(metadata) * (num_fields + 1));
            num_fields++;
        }

        // Copy metadata field to array
        memcpy(&meta[num_fields - 1], &field, sizeof(metadata));
    }

    // Print metadata information
    print_metadata(meta, num_fields);

    // Free memory allocated for metadata array
    free(meta);

    // Close input file
    fclose(fp);

    return 0;
}