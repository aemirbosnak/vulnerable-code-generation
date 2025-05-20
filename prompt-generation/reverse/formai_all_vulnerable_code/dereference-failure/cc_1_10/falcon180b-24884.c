//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for metadata
typedef struct {
    char *title;
    char *author;
    char *date;
} Metadata;

// Function to extract metadata from a file
Metadata *extract_metadata(FILE *file) {
    Metadata *metadata = malloc(sizeof(Metadata));
    metadata->title = NULL;
    metadata->author = NULL;
    metadata->date = NULL;

    char line[100];
    while (fgets(line, 100, file)!= NULL) {
        if (strstr(line, "Title:")!= NULL) {
            char *title = strtok(line, ":");
            metadata->title = strdup(title);
        } else if (strstr(line, "Author:")!= NULL) {
            char *author = strtok(line, ":");
            metadata->author = strdup(author);
        } else if (strstr(line, "Date:")!= NULL) {
            char *date = strtok(line, ":");
            metadata->date = strdup(date);
        }
    }

    return metadata;
}

// Function to print metadata
void print_metadata(Metadata *metadata) {
    if (metadata->title!= NULL) {
        printf("Title: %s\n", metadata->title);
    }
    if (metadata->author!= NULL) {
        printf("Author: %s\n", metadata->author);
    }
    if (metadata->date!= NULL) {
        printf("Date: %s\n", metadata->date);
    }
}

int main() {
    FILE *file = fopen("example.txt", "r");
    Metadata *metadata = extract_metadata(file);
    print_metadata(metadata);

    fclose(file);
    free(metadata->title);
    free(metadata->author);
    free(metadata->date);
    free(metadata);

    return 0;
}