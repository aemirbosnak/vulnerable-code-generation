//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the metadata
typedef struct {
    char* filename;
    int filesize;
    char* author;
    char* title;
    char* subject;
    char* keywords;
} metadata;

// Function to parse the metadata from the file
metadata* parse_metadata(FILE* file) {
    metadata* result = malloc(sizeof(metadata));
    char line[256];
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strstr(line, "filename")!= NULL) {
            result->filename = strdup(line + 9);
        } else if (strstr(line, "filesize")!= NULL) {
            result->filesize = atoi(line + 9);
        } else if (strstr(line, "author")!= NULL) {
            result->author = strdup(line + 8);
        } else if (strstr(line, "title")!= NULL) {
            result->title = strdup(line + 7);
        } else if (strstr(line, "subject")!= NULL) {
            result->subject = strdup(line + 9);
        } else if (strstr(line, "keywords")!= NULL) {
            result->keywords = strdup(line + 9);
        }
    }
    return result;
}

// Function to print the metadata
void print_metadata(metadata* data) {
    printf("Filename: %s\n", data->filename);
    printf("File Size: %d\n", data->filesize);
    printf("Author: %s\n", data->author);
    printf("Title: %s\n", data->title);
    printf("Subject: %s\n", data->subject);
    printf("Keywords: %s\n", data->keywords);
}

// Function to free the metadata
void free_metadata(metadata* data) {
    free(data->filename);
    free(data->author);
    free(data->title);
    free(data->subject);
    free(data->keywords);
    free(data);
}

int main() {
    char filename[256];
    printf("Enter the filename: ");
    scanf("%s", filename);
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    metadata* data = parse_metadata(file);
    if (data == NULL) {
        printf("Error: Could not parse metadata.\n");
        fclose(file);
        return 2;
    }
    print_metadata(data);
    free_metadata(data);
    fclose(file);
    return 0;
}