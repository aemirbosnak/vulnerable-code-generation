//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char key[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
    metadata_t metadata[100];
    int metadata_count = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (line[0] == '#') {
            sscanf(line, "#%[^:]%s", key, value);
            metadata[metadata_count].key = strdup(key);
            metadata[metadata_count].value = strdup(value);
            metadata_count++;
        }
    }

    fclose(file);

    printf("Metadata:\n");
    for (int i = 0; i < metadata_count; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }

    for (int i = 0; i < metadata_count; i++) {
        free(metadata[i].key);
        free(metadata[i].value);
    }

    return 0;
}