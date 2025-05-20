//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void extractMetadata(char *filename);
void displayMetadata(char *metadata);

int main() {
    // Get filename from user
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    // Call extractMetadata function
    extractMetadata(filename);

    return 0;
}

void extractMetadata(char *filename) {
    // Open file
    FILE *fp;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read metadata from file
    char metadata[100];
    fgets(metadata, 100, fp);

    // Remove newline character from metadata
    metadata[strcspn(metadata, "\n")] = 0;

    // Call displayMetadata function
    displayMetadata(metadata);

    // Close file
    fclose(fp);
}

void displayMetadata(char *metadata) {
    // Split metadata string by comma
    char *token = strtok(metadata, ",");
    printf("Metadata:\n");

    // Display each piece of metadata
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }
}