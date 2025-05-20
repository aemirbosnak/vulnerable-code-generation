//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for metadata
struct metadata {
    char title[100];
    char author[100];
    char date[100];
};

// Function to extract metadata from a file
void extract_metadata(FILE *file, struct metadata *meta) {
    char line[100];
    int found_title = 0;
    int found_author = 0;
    int found_date = 0;

    // Loop through each line of the file
    while (fgets(line, 100, file)!= NULL) {
        // Check if the line contains the title
        if (strstr(line, "title:")!= NULL) {
            found_title = 1;
            strcpy(meta->title, line);
        }
        // Check if the line contains the author
        else if (strstr(line, "author:")!= NULL) {
            found_author = 1;
            strcpy(meta->author, line);
        }
        // Check if the line contains the date
        else if (strstr(line, "date:")!= NULL) {
            found_date = 1;
            strcpy(meta->date, line);
        }
    }

    // Check if all metadata was found
    if (found_title && found_author && found_date) {
        printf("Metadata extracted successfully!\n");
    } else {
        printf("Error: Incomplete metadata.\n");
    }
}

int main() {
    FILE *file;
    struct metadata meta;

    // Prompt user for file name
    printf("Enter the name of the file: ");
    scanf("%s", meta.title);

    // Open the file for reading
    file = fopen(meta.title, "r");

    // Check if file was opened successfully
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    // Extract metadata from the file
    extract_metadata(file, &meta);

    // Close the file
    fclose(file);

    return 0;
}