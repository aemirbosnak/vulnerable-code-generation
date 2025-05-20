//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARIABLES 100
#define MAX_VARIABLE_NAME_LENGTH 100

// Define the metadata structure
typedef struct {
    char name[MAX_VARIABLE_NAME_LENGTH];
    int num_variables;
    int *variables;
} metadata_t;

// Function to read the metadata from a file
metadata_t read_metadata(FILE *fp) {
    metadata_t metadata;
    char line[MAX_VARIABLE_NAME_LENGTH];
    int i = 0;

    // Read the first line to get the number of variables
    fgets(line, MAX_VARIABLE_NAME_LENGTH, fp);
    sscanf(line, "%d", &metadata.num_variables);

    // Read the variable names and store them in the metadata structure
    metadata.variables = (int *)malloc(metadata.num_variables * sizeof(int));
    while (fgets(line, MAX_VARIABLE_NAME_LENGTH, fp)!= NULL) {
        strcpy(metadata.name, line);
        for (int j = 0; j < metadata.num_variables; j++) {
            fgets(line, MAX_VARIABLE_NAME_LENGTH, fp);
            sscanf(line, "%d", &metadata.variables[j]);
        }
        i++;
    }

    // Close the file
    fclose(fp);

    return metadata;
}

// Function to print the metadata
void print_metadata(metadata_t metadata) {
    printf("Number of variables: %d\n", metadata.num_variables);
    printf("Variable names: %s\n", metadata.name);
    for (int i = 0; i < metadata.num_variables; i++) {
        printf("Variable %d: %d\n", i, metadata.variables[i]);
    }
}

// Function to write the metadata to a file
void write_metadata(metadata_t metadata, FILE *fp) {
    fprintf(fp, "%d\n", metadata.num_variables);
    fprintf(fp, "%s\n", metadata.name);
    for (int i = 0; i < metadata.num_variables; i++) {
        fprintf(fp, "%d\n", metadata.variables[i]);
    }
}

int main() {
    metadata_t metadata;
    FILE *fp;

    // Open the input file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open input file\n");
        return 1;
    }

    // Read the metadata from the file
    metadata = read_metadata(fp);

    // Print the metadata
    printf("Metadata:\n");
    print_metadata(metadata);

    // Close the input file
    fclose(fp);

    // Open the output file
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Error: could not open output file\n");
        return 1;
    }

    // Write the metadata to the file
    write_metadata(metadata, fp);

    // Close the output file
    fclose(fp);

    return 0;
}