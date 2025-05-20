//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: Romeo and Juliet
/*
 * Romeo and Juliet Metadata Extractor
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_SIZE 1000

typedef struct {
    char title[MAX_METADATA_SIZE];
    char author[MAX_METADATA_SIZE];
    char publisher[MAX_METADATA_SIZE];
    char publication_date[MAX_METADATA_SIZE];
    char description[MAX_METADATA_SIZE];
} Metadata;

int main() {
    FILE *fptr;
    char filename[MAX_METADATA_SIZE];
    char line[MAX_METADATA_SIZE];
    char *token;
    char *token_ptr;
    int line_num = 0;
    Metadata metadata;

    // Prompt for file name
    printf("Enter file name: ");
    fgets(filename, MAX_METADATA_SIZE, stdin);
    filename[strcspn(filename, "\n")] = 0;

    // Open file
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read file line by line
    while (fgets(line, MAX_METADATA_SIZE, fptr) != NULL) {
        line_num++;

        // Tokenize line
        token = strtok_r(line, " ", &token_ptr);

        // Parse tokens
        if (token != NULL) {
            if (strcmp(token, "Title:") == 0) {
                token = strtok_r(NULL, " ", &token_ptr);
                if (token != NULL) {
                    strncpy(metadata.title, token, MAX_METADATA_SIZE);
                }
            } else if (strcmp(token, "Author:") == 0) {
                token = strtok_r(NULL, " ", &token_ptr);
                if (token != NULL) {
                    strncpy(metadata.author, token, MAX_METADATA_SIZE);
                }
            } else if (strcmp(token, "Publisher:") == 0) {
                token = strtok_r(NULL, " ", &token_ptr);
                if (token != NULL) {
                    strncpy(metadata.publisher, token, MAX_METADATA_SIZE);
                }
            } else if (strcmp(token, "Publication Date:") == 0) {
                token = strtok_r(NULL, " ", &token_ptr);
                if (token != NULL) {
                    strncpy(metadata.publication_date, token, MAX_METADATA_SIZE);
                }
            } else if (strcmp(token, "Description:") == 0) {
                token = strtok_r(NULL, " ", &token_ptr);
                if (token != NULL) {
                    strncpy(metadata.description, token, MAX_METADATA_SIZE);
                }
            }
        }
    }

    // Print metadata
    printf("Title: %s\n", metadata.title);
    printf("Author: %s\n", metadata.author);
    printf("Publisher: %s\n", metadata.publisher);
    printf("Publication Date: %s\n", metadata.publication_date);
    printf("Description: %s\n", metadata.description);

    // Close file
    fclose(fptr);

    return 0;
}