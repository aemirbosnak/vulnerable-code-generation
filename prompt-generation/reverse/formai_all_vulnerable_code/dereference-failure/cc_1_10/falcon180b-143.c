//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    char *value;
    struct Metadata *next;
} Metadata;

Metadata *createMetadata(char *name, char *value) {
    Metadata *meta = (Metadata *)malloc(sizeof(Metadata));
    meta->name = strdup(name);
    meta->value = strdup(value);
    meta->next = NULL;
    return meta;
}

void addMetadata(Metadata **head, char *name, char *value) {
    Metadata *meta = createMetadata(name, value);
    meta->next = *head;
    *head = meta;
}

void printMetadata(Metadata *meta) {
    printf("%s: %s\n", meta->name, meta->value);
}

void freeMetadata(Metadata *meta) {
    free(meta->name);
    free(meta->value);
    free(meta);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_SIZE];
    char *token;
    Metadata *head = NULL;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        token = strtok(line, ":");
        if (token == NULL) {
            continue;
        }
        addMetadata(&head, token, strtok(NULL, ":"));
    }

    fclose(file);

    printf("Metadata:\n");
    printMetadata(head);

    freeMetadata(head);

    return 0;
}