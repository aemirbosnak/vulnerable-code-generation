//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

typedef struct {
    char *filename;
    char *author;
    char *title;
    char *date;
    char *version;
} metadata_t;

metadata_t *parse_metadata(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error: failed to open file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LEN];
    metadata_t *metadata = malloc(sizeof(metadata_t));
    metadata->filename = strdup(filename);

    while (fgets(line, MAX_LINE_LEN, fp)) {
        char *key = strtok(line, ":");
        char *value = strtok(NULL, ":");

        if (strcmp(key, "author") == 0) {
            metadata->author = strdup(value);
        } else if (strcmp(key, "title") == 0) {
            metadata->title = strdup(value);
        } else if (strcmp(key, "date") == 0) {
            metadata->date = strdup(value);
        } else if (strcmp(key, "version") == 0) {
            metadata->version = strdup(value);
        }
    }

    fclose(fp);
    return metadata;
}

void print_metadata(metadata_t *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Author: %s\n", metadata->author);
    printf("Title: %s\n", metadata->title);
    printf("Date: %s\n", metadata->date);
    printf("Version: %s\n", metadata->version);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    metadata_t *metadata = parse_metadata(argv[1]);
    print_metadata(metadata);
    free(metadata->author);
    free(metadata->title);
    free(metadata->date);
    free(metadata->version);
    free(metadata->filename);
    free(metadata);

    return 0;
}