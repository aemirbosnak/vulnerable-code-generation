//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100

typedef struct {
    char *name;
    char *value;
} Metadata;

Metadata *metadata_list = NULL;
int metadata_count = 0;

void add_metadata(char *name, char *value) {
    Metadata *new_meta = (Metadata *)malloc(sizeof(Metadata));
    new_meta->name = strdup(name);
    new_meta->value = strdup(value);
    metadata_list = realloc(metadata_list, sizeof(Metadata) * (metadata_count + 1));
    metadata_list[metadata_count] = *new_meta;
    metadata_count++;
}

void print_metadata() {
    for (int i = 0; i < metadata_count; i++) {
        printf("Name: %s\nValue: %s\n", metadata_list[i].name, metadata_list[i].value);
    }
}

char *get_metadata_value(char *name) {
    for (int i = 0; i < metadata_count; i++) {
        if (strcmp(metadata_list[i].name, name) == 0) {
            return metadata_list[i].value;
        }
    }
    return NULL;
}

void read_metadata_file(FILE *file) {
    char line[MAX_LINE_LENGTH];
    char *token = NULL;
    int token_count = 0;
    char *name = NULL;
    char *value = NULL;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        token = strtok(line, ":");
        if (token == NULL) {
            break;
        }
        name = strdup(token);
        token = strtok(NULL, ":");
        if (token == NULL) {
            break;
        }
        value = strdup(token);
        add_metadata(name, value);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <metadata_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open metadata file.\n");
        return 1;
    }

    read_metadata_file(file);
    fclose(file);

    print_metadata();

    char *author = get_metadata_value("author");
    if (author!= NULL) {
        printf("Author: %s\n", author);
    } else {
        printf("Author not found.\n");
    }

    char *title = get_metadata_value("title");
    if (title!= NULL) {
        printf("Title: %s\n", title);
    } else {
        printf("Title not found.\n");
    }

    return 0;
}