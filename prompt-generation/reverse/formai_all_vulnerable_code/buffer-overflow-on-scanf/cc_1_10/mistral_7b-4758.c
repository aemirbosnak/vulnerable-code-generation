//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define metadata structure
typedef struct {
    char name[50];
    float value;
} Metadata;

// Function to extract metadata from a given file
Metadata extractMetadata(char *filename) {
    FILE *file;
    char line[100];
    char *token;
    Metadata metadata;
    float sum = 0.0;
    int count = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read first line to get metadata name
    fgets(line, sizeof(line), file);
    sscanf(line, "%[^:]:%s", metadata.name, line);

    // Read remaining lines to get metadata value
    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, " ");
        if (strcmp(token, metadata.name) == 0) {
            sscanf(line, "%s:%f", line, &metadata.value);
            break;
        }
        sum += strtof(token, NULL);
        count++;
    }

    // Calculate average of remaining numbers
    if (count > 0) {
        metadata.value = sum / count;
    }

    fclose(file);
    return metadata;
}

int main() {
    Metadata m;
    char filename[50];

    printf("Enter file name: ");
    scanf("%s", filename);

    m = extractMetadata(filename);
    printf("Metadata name: %s\n", m.name);
    printf("Metadata value: %.2f\n", m.value);

    return 0;
}