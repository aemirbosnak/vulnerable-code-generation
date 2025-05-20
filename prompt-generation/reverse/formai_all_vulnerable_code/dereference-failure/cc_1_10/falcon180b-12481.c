//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

// Function prototypes
void extract_metadata(FILE *file, char *filename);
void display_metadata(char *filename, char *author, char *title, int num_pages);

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    char author[MAX_LINE_LENGTH];
    char title[MAX_LINE_LENGTH];
    int num_pages = 0;

    // Get filename from command line argument
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    strcpy(filename, argv[1]);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    // Extract metadata from file
    extract_metadata(file, filename);

    // Display metadata
    display_metadata(filename, author, title, num_pages);

    // Close file
    fclose(file);

    return 0;
}

// Extract metadata from file
void extract_metadata(FILE *file, char *filename) {
    char line[MAX_LINE_LENGTH];
    char author[MAX_LINE_LENGTH];
    char title[MAX_LINE_LENGTH];
    int num_pages = 0;

    // Read first few lines of file to find metadata
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (strstr(line, "Author:")!= NULL) {
            strcpy(author, line + strlen("Author:"));
            author[strcspn(author, "\n")] = '\0';
        } else if (strstr(line, "Title:")!= NULL) {
            strcpy(title, line + strlen("Title:"));
            title[strcspn(title, "\n")] = '\0';
        } else if (strstr(line, "Number of pages:")!= NULL) {
            num_pages = atoi(line + strlen("Number of pages:"));
        }
    }
}

// Display metadata
void display_metadata(char *filename, char *author, char *title, int num_pages) {
    printf("Metadata for file %s:\n", filename);
    printf("Author: %s\n", author);
    printf("Title: %s\n", title);
    printf("Number of pages: %d\n", num_pages);
}