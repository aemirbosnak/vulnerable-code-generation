//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the metadata struct
typedef struct {
    char* name;
    int age;
    char* occupation;
} Metadata;

// Function to print metadata
void printMetadata(Metadata* meta) {
    printf("Name: %s\n", meta->name);
    printf("Age: %d\n", meta->age);
    printf("Occupation: %s\n", meta->occupation);
}

// Function to extract metadata from a text file
int extractMetadata(FILE* file, Metadata* meta) {
    char line[256];
    char* delimiter = ",";
    char* token;

    // Read the first line to get the name
    fgets(line, sizeof(line), file);
    token = strtok(line, delimiter);
    meta->name = strdup(token);

    // Read the second line to get the age
    fgets(line, sizeof(line), file);
    token = strtok(line, delimiter);
    meta->age = atoi(token);

    // Read the third line to get the occupation
    fgets(line, sizeof(line), file);
    token = strtok(line, delimiter);
    meta->occupation = strdup(token);

    return 0;
}

// Main function
int main(int argc, char** argv) {
    FILE* file;
    Metadata meta;

    // Check if the correct number of arguments are provided
    if (argc!= 2) {
        printf("Usage: %s <metadata_file>\n", argv[0]);
        return 1;
    }

    // Open the metadata file
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open metadata file.\n");
        return 1;
    }

    // Extract the metadata
    extractMetadata(file, &meta);

    // Print the metadata
    printMetadata(&meta);

    // Close the metadata file
    fclose(file);

    return 0;
}