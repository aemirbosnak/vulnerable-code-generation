//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: automated
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char file[MAX_SIZE];
    printf("Enter the path to the file: ");
    fgets(file, MAX_SIZE, stdin);
    // Remove newline character
    file[strlen(file)-1] = '\0';

    FILE* fp = fopen(file, "r");

    // Check if file is opened successfully
    if(fp == NULL) {
        printf("Error: Failed to open file.\n");
        return 1; // Exit with error
    }

    char line[MAX_SIZE];
    char* metadata[3]; // We will store the metadata in this array
    int foundMetadata = 0; // Tells whether metadata has been found or not

    while(fgets(line, MAX_SIZE, fp)) {
        if(strncmp(line, "///", 3) == 0) {
            // Found possible metadata tag
            char* tag = strtok(line+3, " "); // Skip the ///
            if(strcmp(tag, "METADATA") == 0) {
                // Found metadata tag
                metadata[0] = strtok(NULL, " "); // Get the name
                metadata[1] = strtok(NULL, " "); // Get the author
                metadata[2] = strtok(NULL, " "); // Get the date
                foundMetadata = 1;
                break; // No need to continue
            }
        }
    }

    fclose(fp);

    if(foundMetadata) {
        printf("Metadata found:\n");
        printf("Name: %s\n", metadata[0]);
        printf("Author: %s\n", metadata[1]);
        printf("Date: %s\n", metadata[2]);
    } else {
        printf("Metadata not found.\n");
    }

    return 0;
}