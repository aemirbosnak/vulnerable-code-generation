//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

metadata_t* metadata_list = NULL;
int metadata_count = 0;

void metadata_add(char *key, char *value) {
    metadata_t *new_metadata = (metadata_t*) malloc(sizeof(metadata_t));
    new_metadata->key = strdup(key);
    new_metadata->value = strdup(value);
    metadata_list = realloc(metadata_list, sizeof(metadata_t) * ++metadata_count);
    metadata_list[metadata_count - 1] = *new_metadata;
}

void metadata_print() {
    for (int i = 0; i < metadata_count; i++) {
        printf("%s: %s\n", metadata_list[i].key, metadata_list[i].value);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *key, *value;
    bool in_metadata = false;

    metadata_list = (metadata_t*) malloc(sizeof(metadata_t));
    metadata_count = 0;

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (in_metadata) {
            if (strlen(line) > 1 && line[0]!= '#') {
                value = strchr(line, ':');
                if (value!= NULL) {
                    *value = '\0';
                    value++;
                    while (isspace(*value)) {
                        value++;
                    }
                    metadata_add(key, value);
                }
            } else {
                in_metadata = false;
            }
        } else {
            key = strtok(line, ":");
            if (key!= NULL && strcasecmp(key, "metadata") == 0) {
                in_metadata = true;
            }
        }
    }

    metadata_print();

    return 0;
}