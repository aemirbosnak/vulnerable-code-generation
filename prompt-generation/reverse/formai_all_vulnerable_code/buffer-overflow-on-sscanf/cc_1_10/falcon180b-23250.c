//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_VALUE_PAIRS 100

// Define a structure to store metadata key-value pairs
typedef struct {
    char key[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
} Metadata;

// Function to extract metadata from a file
void extract_metadata(FILE *file, Metadata *metadata_list, int *num_metadata) {
    char line[MAX_LINE_LENGTH];
    char *key, *value;
    
    // Read in the first line of the file, which contains the number of metadata key-value pairs
    fgets(line, MAX_LINE_LENGTH, file);
    sscanf(line, "%d", num_metadata);
    
    // Loop through the remaining lines of the file, extracting metadata key-value pairs
    for (int i = 0; i < *num_metadata; i++) {
        // Read in the next line of the file
        fgets(line, MAX_LINE_LENGTH, file);
        
        // Extract the key and value from the line
        key = strtok(line, ":");
        value = strtok(NULL, ":");
        
        // Store the key-value pair in the metadata list
        strcpy(metadata_list[i].key, key);
        strcpy(metadata_list[i].value, value);
    }
}

// Function to display metadata key-value pairs
void display_metadata(Metadata *metadata_list, int num_metadata) {
    for (int i = 0; i < num_metadata; i++) {
        printf("Key: %s\nValue: %s\n", metadata_list[i].key, metadata_list[i].value);
    }
}

int main() {
    FILE *file;
    Metadata metadata_list[MAX_KEY_VALUE_PAIRS];
    int num_metadata = 0;
    
    // Open the metadata file for reading
    file = fopen("metadata.txt", "r");
    
    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error: Could not open metadata file.\n");
        return 1;
    }
    
    // Extract metadata from the file
    extract_metadata(file, metadata_list, &num_metadata);
    
    // Display the extracted metadata
    printf("Metadata:\n");
    display_metadata(metadata_list, num_metadata);
    
    // Close the metadata file
    fclose(file);
    
    return 0;
}