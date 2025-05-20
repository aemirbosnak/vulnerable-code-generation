//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdarg.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Metadata;

Metadata *metadata_create(const char *key, const char *value) {
    Metadata *m = malloc(sizeof(Metadata));
    if (m == NULL) {
        printf("Error: Out of memory.\n");
        return NULL;
    }
    strncpy(m->key, key, MAX_KEY_LENGTH);
    strncpy(m->value, value, MAX_VALUE_LENGTH);
    return m;
}

void metadata_destroy(Metadata *m) {
    free(m);
}

void metadata_print(const Metadata *m) {
    printf("Key: %s\nValue: %s\n", m->key, m->value);
}

bool metadata_compare(const Metadata *m1, const Metadata *m2) {
    return strcmp(m1->key, m2->key) == 0;
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *filename = "example.txt";
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return 1;
    }
    
    Metadata *metadata = NULL;
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *key, *value;
        if (sscanf(line, "%*s %*s %ms", &key)!= 1) {
            printf("Error: Invalid line format.\n");
            continue;
        }
        value = strchr(line, ':') + 1;
        while (isspace(*value)) {
            value++;
        }
        Metadata *m = metadata_create(key, value);
        if (metadata == NULL) {
            metadata = m;
        } else if (metadata_compare(metadata, m)) {
            metadata_destroy(metadata);
            metadata = m;
        } else {
            metadata_destroy(m);
        }
    }
    
    if (metadata == NULL) {
        printf("Error: No metadata found in file.\n");
        return 1;
    }
    
    metadata_print(metadata);
    metadata_destroy(metadata);
    
    fclose(fp);
    return 0;
}