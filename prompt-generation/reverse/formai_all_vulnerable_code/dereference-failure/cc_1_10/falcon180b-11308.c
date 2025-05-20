//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char data[MAX_LINE_LENGTH];
} metadata_t;

int main() {
    metadata_t *metadata = NULL;
    int num_metadata = 0;
    char *line = NULL;
    size_t line_length = 0;
    FILE *file = NULL;
    int result = 0;

    // Open input file
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Read metadata from input file
    while ((result = getline(&line, &line_length, file))!= -1) {
        if (num_metadata >= MAX_FILE_NAME_LENGTH) {
            printf("Error: Too many metadata records.\n");
            exit(1);
        }
        strcpy(metadata[num_metadata].name, line);
        num_metadata++;
    }

    // Print metadata records
    printf("Metadata records:\n");
    for (int i = 0; i < num_metadata; i++) {
        printf("%s\n", metadata[i].name);
    }

    // Free memory
    if (metadata!= NULL) {
        free(metadata);
    }
    if (line!= NULL) {
        free(line);
    }
    fclose(file);

    return 0;
}