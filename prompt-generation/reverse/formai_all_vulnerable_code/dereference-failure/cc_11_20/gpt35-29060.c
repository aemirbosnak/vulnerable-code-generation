//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

/* Creating a structure to hold metadata information */
struct MetaData {
    char *title;
    char *author;
    char *date;
};

int main() {

    /* Initializing variables */
    char *file_name;
    FILE *file_pointer;
    char *line;
    int line_number = 0;
    struct MetaData metadata = {NULL, NULL, NULL};

    /* Prompting user for file name */
    printf("Enter file name: ");
    scanf("%s", file_name);

    /* Opening file */
    file_pointer = fopen(file_name, "r");

    /* Checking if file exists */
    if (file_pointer == NULL) {
        printf("File not found.");
        exit(1);
    }

    /* Looping through each line of the file */
    while (fgets(line, 100, file_pointer)) {
        line_number++;

        /* Checking for title metadata */
        if (strstr(line, "Title:") != NULL) {
            metadata.title = &line[7];
        }
        /* Checking for author metadata */
        else if (strstr(line, "Author:") != NULL) {
            metadata.author = &line[8];
        }
        /* Checking for date metadata */
        else if (strstr(line, "Date:") != NULL) {
            metadata.date = &line[6];
        }

        /* Checking if all metadata has been found */
        if (metadata.title != NULL && metadata.author != NULL && metadata.date != NULL) {
            break;
        }
    }

    /* Checking if metadata is complete */
    if (metadata.title == NULL || metadata.author == NULL || metadata.date == NULL) {
        printf("Metadata is incomplete.");
        exit(1);
    }

    /* Printing metadata */
    printf("Title: %s", metadata.title);
    printf("Author: %s", metadata.author);
    printf("Date: %s", metadata.date);

    /* Closing file */
    fclose(file_pointer);

    return 0;
}