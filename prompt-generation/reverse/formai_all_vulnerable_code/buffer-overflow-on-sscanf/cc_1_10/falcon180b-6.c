//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

// Function to extract metadata from a file
void extract_metadata(FILE *file, char *filename) {
    char line[MAX_LINE_SIZE];
    char *key, *value;

    // Extract filename
    if (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (sscanf(line, "Filename: %s", filename)!= 1) {
            printf("Error: Invalid filename.\n");
            exit(1);
        }
        printf("Filename: %s\n", filename);
    } else {
        printf("Error: Unable to read filename.\n");
        exit(1);
    }

    // Extract creation date
    if (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (sscanf(line, "Creation Date: %s", line)!= 1) {
            printf("Error: Invalid creation date.\n");
            exit(1);
        }
        printf("Creation Date: %s\n", line);
    } else {
        printf("Error: Unable to read creation date.\n");
        exit(1);
    }

    // Extract modification date
    if (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (sscanf(line, "Modification Date: %s", line)!= 1) {
            printf("Error: Invalid modification date.\n");
            exit(1);
        }
        printf("Modification Date: %s\n", line);
    } else {
        printf("Error: Unable to read modification date.\n");
        exit(1);
    }

    // Extract author
    if (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (sscanf(line, "Author: %s", line)!= 1) {
            printf("Error: Invalid author.\n");
            exit(1);
        }
        printf("Author: %s\n", line);
    } else {
        printf("Error: Unable to read author.\n");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[MAX_LINE_SIZE];

    // Check if filename is provided
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    // Open file
    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    // Extract metadata
    extract_metadata(file, filename);

    // Close file
    fclose(file);

    return 0;
}