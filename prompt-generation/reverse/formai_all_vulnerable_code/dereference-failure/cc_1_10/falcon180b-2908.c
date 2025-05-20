//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

// Function to extract metadata from a file
void extract_metadata(FILE *file, char *filename, char *author, char *title, char *date) {
    char line[MAX_LINE_SIZE];
    char *ptr;

    // Extract author name
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (strstr(line, "Author:")!= NULL) {
            ptr = strtok(line, " ");
            while (ptr!= NULL) {
                strcat(author, ptr);
                strcat(author, " ");
                ptr = strtok(NULL, " ");
            }
            break;
        }
    }

    // Extract title
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (strstr(line, "Title:")!= NULL) {
            ptr = strtok(line, " ");
            while (ptr!= NULL) {
                strcat(title, ptr);
                strcat(title, " ");
                ptr = strtok(NULL, " ");
            }
            break;
        }
    }

    // Extract date
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (strstr(line, "Date:")!= NULL) {
            ptr = strtok(line, " ");
            while (ptr!= NULL) {
                strcat(date, ptr);
                strcat(date, " ");
                ptr = strtok(NULL, " ");
            }
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[MAX_LINE_SIZE];
    char author[MAX_LINE_SIZE];
    char title[MAX_LINE_SIZE];
    char date[MAX_LINE_SIZE];

    // Check if the correct number of arguments were provided
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Copy the filename argument to a local variable
    strcpy(filename, argv[1]);

    // Open the file for reading
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    // Extract metadata from the file
    extract_metadata(file, filename, author, title, date);

    // Print extracted metadata
    printf("Author: %s\n", author);
    printf("Title: %s\n", title);
    printf("Date: %s\n", date);

    // Close the file
    fclose(file);

    return 0;
}