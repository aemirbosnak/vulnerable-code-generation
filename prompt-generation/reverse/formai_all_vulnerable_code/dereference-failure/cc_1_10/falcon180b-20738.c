//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_TAGS 100

typedef struct {
    char *name;
    char *value;
} tag_t;

typedef struct {
    tag_t tags[MAX_NUM_TAGS];
    int num_tags;
} metadata_t;

void init_metadata(metadata_t *metadata) {
    metadata->num_tags = 0;
}

void add_tag(metadata_t *metadata, char *name, char *value) {
    if (metadata->num_tags >= MAX_NUM_TAGS) {
        printf("Error: Too many tags.\n");
        exit(1);
    }

    metadata->tags[metadata->num_tags].name = strdup(name);
    metadata->tags[metadata->num_tags].value = strdup(value);
    metadata->num_tags++;
}

void print_metadata(metadata_t *metadata) {
    for (int i = 0; i < metadata->num_tags; i++) {
        printf("%s: %s\n", metadata->tags[i].name, metadata->tags[i].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <metadata file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    metadata_t metadata;
    init_metadata(&metadata);

    char line[MAX_LINE_LENGTH];
    char *name = NULL;
    char *value = NULL;
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (line[0] == '#') {
            continue;
        }

        if (name!= NULL) {
            value = strtok(line, ":");
            if (value == NULL) {
                printf("Error: Invalid metadata format.\n");
                exit(1);
            }

            add_tag(&metadata, name, value);
            name = NULL;
        } else {
            name = strtok(line, ":");
            if (name == NULL) {
                printf("Error: Invalid metadata format.\n");
                exit(1);
            }
        }
    }

    if (name!= NULL) {
        value = strtok(line, ":");
        if (value == NULL) {
            printf("Error: Invalid metadata format.\n");
            exit(1);
        }

        add_tag(&metadata, name, value);
    }

    fclose(fp);

    print_metadata(&metadata);

    return 0;
}