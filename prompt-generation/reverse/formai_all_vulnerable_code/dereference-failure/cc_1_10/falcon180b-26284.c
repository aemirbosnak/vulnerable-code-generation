//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char* name;
    char* value;
} metadata_t;

metadata_t* metadata_extract(char* file_path) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    metadata_t* metadata = malloc(sizeof(metadata_t*));
    metadata->name = malloc(MAX_LINE_SIZE);
    metadata->value = malloc(MAX_LINE_SIZE);

    char line[MAX_LINE_SIZE];
    bool in_metadata = false;
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (line[0] == '#' && line[1] == '#') {
            in_metadata = true;
            strcpy(metadata->name, &line[2]);
        } else if (in_metadata && line[0]!= '\0') {
            strcpy(metadata->value, &line[0]);
            break;
        }
    }

    fclose(file);
    return metadata;
}

void metadata_print(metadata_t* metadata) {
    printf("Name: %s\n", metadata->name);
    printf("Value: %s\n", metadata->value);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        exit(1);
    }

    char* file_path = argv[1];
    metadata_t* metadata = metadata_extract(file_path);
    metadata_print(metadata);

    free(metadata->name);
    free(metadata->value);
    free(metadata);
    return 0;
}