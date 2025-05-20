//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEY_SIZE 64
#define MAX_VALUE_SIZE 1024

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} Metadata;

typedef struct {
    char filename[MAX_LINE_SIZE];
    Metadata *metadata;
} FileMetadata;

void addMetadata(Metadata *metadata, const char *key, const char *value) {
    strcpy(metadata->key, key);
    strcpy(metadata->value, value);
}

Metadata *getMetadata(const char *key) {
    Metadata *metadata = malloc(sizeof(Metadata));
    strcpy(metadata->key, key);
    metadata->value[0] = '\0';
    return metadata;
}

void printMetadata(const Metadata *metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

void freeMetadata(Metadata *metadata) {
    free(metadata);
}

int main() {
    char line[MAX_LINE_SIZE];
    char *filename = NULL;
    char *key = NULL;
    char *value = NULL;
    Metadata *metadata = NULL;
    FileMetadata *fileMetadata = NULL;
    bool inMetadata = false;
    bool inKey = false;
    bool inValue = false;

    fileMetadata = malloc(sizeof(FileMetadata));
    strcpy(fileMetadata->filename, "");

    while (fgets(line, MAX_LINE_SIZE, stdin)!= NULL) {
        if (inMetadata) {
            if (inKey) {
                if (isspace(line[0])) {
                    inKey = false;
                    inValue = true;
                } else {
                    strcat(key, line);
                }
            } else if (inValue) {
                if (isspace(line[0])) {
                    inValue = false;
                    addMetadata(metadata, key, value);
                    metadata = NULL;
                    key = NULL;
                    value = NULL;
                } else {
                    strcat(value, line);
                }
            }
        } else if (isspace(line[0])) {
            continue;
        } else if (line[0] == '@') {
            if (filename == NULL) {
                filename = strdup(line + 1);
            } else {
                sprintf(fileMetadata->filename, "%s/%s", filename, line + 1);
                filename = NULL;
            }
        } else if (line[0] == '#') {
            inMetadata = true;
            metadata = getMetadata(line + 1);
        }
    }

    free(fileMetadata->filename);
    free(fileMetadata);

    return 0;
}