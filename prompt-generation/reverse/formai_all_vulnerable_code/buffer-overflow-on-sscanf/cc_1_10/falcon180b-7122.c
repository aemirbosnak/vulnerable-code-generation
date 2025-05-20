//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 512

// Function to extract metadata from a C file
void extract_metadata(FILE *file) {
    char line[MAX_LINE_SIZE];
    char *author = NULL;
    char *date = NULL;

    // Read the first line
    if (fgets(line, MAX_LINE_SIZE, file) == NULL) {
        printf("Error: Unable to read the file.\n");
        exit(1);
    }

    // Extract the author name
    if (sscanf(line, "/* Author: %s */", author)!= 1) {
        printf("Error: Invalid author format.\n");
        exit(1);
    }

    // Extract the date
    if (sscanf(line, "/* Date: %s */", date)!= 1) {
        printf("Error: Invalid date format.\n");
        exit(1);
    }

    // Print the metadata
    printf("Author: %s\n", author);
    printf("Date: %s\n", date);
}

int main() {
    char filename[MAX_LINE_SIZE];
    printf("Enter the name of the C file: ");
    scanf("%s", filename);

    // Open the file in read mode
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open the file.\n");
        exit(1);
    }

    // Extract the metadata
    extract_metadata(file);

    // Close the file
    fclose(file);

    return 0;
}