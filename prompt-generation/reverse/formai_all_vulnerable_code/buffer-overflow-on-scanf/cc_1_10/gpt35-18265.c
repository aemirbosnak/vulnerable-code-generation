//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to hold metadata information
typedef struct metadata {
    char author[50];
    char title[100];
    int year;
    char publisher[100];
} Metadata;

// Function to extract metadata from a file
Metadata extract_metadata(char *filename) {
    Metadata data;
    FILE *fptr;
    char line[100];

    // Open the file
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error: Cannot open file %s.\n", filename);
        exit(1);
    }

    // Read lines from the file and extract metadata
    while (fgets(line, sizeof(line), fptr)) {
        if (strstr(line, "Author:") != NULL) {
            strcpy(data.author, line+7);
        }
        if (strstr(line, "Title:") != NULL) {
            strcpy(data.title, line+6);
        }
        if (strstr(line, "Year:") != NULL) {
            data.year = atoi(line+5);
        }
        if (strstr(line, "Publisher:") != NULL) {
            strcpy(data.publisher, line+10);
        }
    }

    // Close the file
    fclose(fptr);

    return data;
}

int main() {
    Metadata data;
    char filename[100];

    // Get the filename from user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Extract the metadata from the file
    data = extract_metadata(filename);

    // Display the metadata
    printf("Author: %s", data.author);
    printf("Title: %s", data.title);
    printf("Year: %d", data.year);
    printf("Publisher: %s", data.publisher);

    return 0;
}