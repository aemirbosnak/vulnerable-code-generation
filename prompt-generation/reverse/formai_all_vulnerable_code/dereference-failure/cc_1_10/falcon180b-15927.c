//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 64

typedef struct {
    char *name;
    char *value;
} metadata_t;

typedef struct {
    int count;
    metadata_t *metadata;
} metadata_list_t;

void add_metadata(metadata_list_t *list, char *name, char *value) {
    if (list->count >= MAX_TOKENS) {
        printf("Error: Maximum number of tokens reached.\n");
        exit(1);
    }
    list->metadata[list->count].name = strdup(name);
    list->metadata[list->count].value = strdup(value);
    list->count++;
}

void print_metadata(metadata_list_t *list) {
    printf("Metadata:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%s: %s\n", list->metadata[i].name, list->metadata[i].value);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *token;
    char *name;
    char *value;
    metadata_list_t metadata_list = {0};

    printf("Enter metadata in the following format: name:value\n");
    while (fgets(line, MAX_LINE_LENGTH, stdin)) {
        token = strtok(line, ":");
        if (token == NULL) {
            printf("Error: Invalid metadata format.\n");
            exit(1);
        }
        name = token;
        token = strtok(NULL, ":");
        if (token == NULL) {
            printf("Error: Invalid metadata format.\n");
            exit(1);
        }
        value = token;
        add_metadata(&metadata_list, name, value);
    }

    print_metadata(&metadata_list);

    return 0;
}