//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 256
#define MAX_METADATA_LENGTH 1024

int main(int argc, char *argv[]) {
    // Check if file path is provided
    if(argc < 2) {
        printf("Please provide file path as command line argument.\n");
        return 0;
    }

    // Open the file in read mode
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Error opening file %s.\n", argv[1]);
        return 0;
    }

    // Read the file content into a buffer
    char file_content[MAX_METADATA_LENGTH];
    memset(file_content, 0, MAX_METADATA_LENGTH);
    fread(file_content, sizeof(char), MAX_METADATA_LENGTH, fp);

    // Close the file
    fclose(fp);

    // Extract the metadata
    char metadata[MAX_METADATA_LENGTH];
    memset(metadata, 0, MAX_METADATA_LENGTH);

    // Extract the author from metadata
    char author[MAX_METADATA_LENGTH];
    memset(author, 0, MAX_METADATA_LENGTH);
    char *ptr = strstr(file_content, "author:");
    if(ptr != NULL) {
        sscanf(ptr, "author:%[^\n]", author);
    }

    // Extract the title from metadata
    char title[MAX_METADATA_LENGTH];
    memset(title, 0, MAX_METADATA_LENGTH);
    ptr = strstr(file_content, "title:");
    if(ptr != NULL) {
        sscanf(ptr, "title:%[^\n]", title);
    }

    // Extract the description from metadata
    char description[MAX_METADATA_LENGTH];
    memset(description, 0, MAX_METADATA_LENGTH);
    ptr = strstr(file_content, "description:");
    if(ptr != NULL) {
        sscanf(ptr, "description:%[^\n]", description);
    }

    // Print the extracted metadata
    printf("Metadata Information:\n");
    printf("Author: %s\n", author);
    printf("Title: %s\n", title);
    printf("Description: %s\n", description);

    return 0;
}