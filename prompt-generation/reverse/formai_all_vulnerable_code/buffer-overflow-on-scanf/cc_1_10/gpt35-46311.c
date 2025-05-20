//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to extract metadata from a file
void extract_metadata(const char* filename) {
    FILE *fp;

    char *token;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found!\n");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        // extract metadata from the beginning of the file
        if (strncmp(line, "---", 3) == 0) {
            while ((read = getline(&line, &len, fp)) != -1) {
                if (strncmp(line, "---", 3) == 0) {
                    // end of metadata section
                    break;
                } else {
                    // extract key-value pairs from the metadata section
                    token = strtok(line, ":");
                    if (token != NULL) {
                        printf("Key: %s, Value: %s\n", token, strtok(NULL, "\n"));
                    }
                }
            }
            break;
        }
    }

    fclose(fp);
    if (line) {
        free(line);
    }
}

int main() {
    char filename[50];

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("\nExtracting metadata from file: %s...\n\n", filename);
    extract_metadata(filename);

    return 0;
}