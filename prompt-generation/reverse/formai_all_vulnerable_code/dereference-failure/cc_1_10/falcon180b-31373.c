//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct metadata_t {
    char *filename;
    int filesize;
    char *mimetype;
    char *author;
    char *title;
} metadata_t;

metadata_t *parse_metadata(char *line) {
    metadata_t *metadata = malloc(sizeof(metadata_t));
    char *delimiter = ": ";
    char *token = strtok(line, delimiter);
    metadata->filename = strdup(token);
    token = strtok(NULL, delimiter);
    metadata->filesize = atoi(token);
    token = strtok(NULL, delimiter);
    metadata->mimetype = strdup(token);
    token = strtok(NULL, delimiter);
    metadata->author = strdup(token);
    token = strtok(NULL, delimiter);
    metadata->title = strdup(token);
    return metadata;
}

void print_metadata(metadata_t *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("File size: %d bytes\n", metadata->filesize);
    printf("MIME type: %s\n", metadata->mimetype);
    printf("Author: %s\n", metadata->author);
    printf("Title: %s\n", metadata->title);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <metadata file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    metadata_t *metadata = NULL;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (metadata == NULL) {
            metadata = parse_metadata(line);
        } else {
            metadata_t *new_metadata = parse_metadata(line);
            print_metadata(metadata);
            free(metadata->filename);
            free(metadata->mimetype);
            free(metadata->author);
            free(metadata->title);
            free(metadata);
            metadata = new_metadata;
        }
    }

    if (metadata!= NULL) {
        print_metadata(metadata);
        free(metadata->filename);
        free(metadata->mimetype);
        free(metadata->author);
        free(metadata->title);
        free(metadata);
    }

    fclose(fp);
    return 0;
}