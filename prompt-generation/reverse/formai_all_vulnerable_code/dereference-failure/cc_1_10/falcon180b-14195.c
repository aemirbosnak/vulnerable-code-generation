//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

// Function to extract metadata from a file
void extract_metadata(FILE *fp, char *filename) {
    char line[MAX_LINE_LEN];
    char *key, *value;
    int linenum = 0;

    // Loop through each line in the file
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        linenum++;

        // Check if the line contains metadata
        if (strstr(line, "metadata")!= NULL) {
            // Extract the key-value pair from the line
            key = strtok(line, ": ");
            value = strtok(NULL, ": ");

            // Print the metadata in a formatted way
            printf("Line %d: %s = %s\n", linenum, key, value);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <metadata_key>\n", argv[0]);
        return 1;
    }

    // Open the file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    // Extract the specified metadata
    char *metadata_key = argv[2];
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        if (strstr(line, metadata_key)!= NULL) {
            printf("%s\n", line);
            break;
        }
    }

    // Close the file
    fclose(fp);

    return 0;
}