//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 512

typedef struct {
    char name[MAX_LINE_LENGTH];
    int value;
} metadata_t;

int main(int argc, char *argv[]) {
    FILE *input_file;
    char line[MAX_LINE_LENGTH];
    metadata_t metadata;
    int num_metadata = 0;

    if (argc!= 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        if (sscanf(line, "name: %[^\n]", metadata.name) == 1) {
            metadata.value = 0;
            num_metadata++;
        } else if (sscanf(line, "value: %d", &metadata.value) == 1) {
            num_metadata++;
        }
    }

    fclose(input_file);

    if (num_metadata == 0) {
        printf("No metadata found in file.\n");
        exit(1);
    }

    printf("Metadata:\n");
    for (int i = 0; i < num_metadata; i++) {
        printf("Name: %s\nValue: %d\n", metadata.name, metadata.value);
    }

    return 0;
}