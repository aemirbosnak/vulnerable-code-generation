//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 32
#define MAX_VALUE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
    struct metadata_entry *next;
} metadata_entry;

metadata_entry *metadata_head = NULL;

void metadata_entry_free(metadata_entry *entry) {
    free(entry->key);
    free(entry->value);
    free(entry);
}

void metadata_free() {
    metadata_entry *entry = metadata_head;
    while (entry!= NULL) {
        metadata_entry *next = entry->next;
        metadata_entry_free(entry);
        entry = next;
    }
    metadata_head = NULL;
}

metadata_entry *metadata_find_key(char *key) {
    metadata_entry *entry = metadata_head;
    while (entry!= NULL) {
        if (strcmp(entry->key, key) == 0) {
            return entry;
        }
        entry = entry->next;
    }
    return NULL;
}

metadata_entry *metadata_add_key(char *key, char *value) {
    metadata_entry *entry = metadata_find_key(key);
    if (entry!= NULL) {
        free(entry->value);
        entry->value = strdup(value);
    } else {
        entry = (metadata_entry*)malloc(sizeof(metadata_entry));
        entry->key = strdup(key);
        entry->value = strdup(value);
        entry->next = metadata_head;
        metadata_head = entry;
    }
    return entry;
}

void metadata_print() {
    metadata_entry *entry = metadata_head;
    while (entry!= NULL) {
        printf("%s: %s\n", entry->key, entry->value);
        entry = entry->next;
    }
}

char *metadata_get_value(char *key) {
    metadata_entry *entry = metadata_find_key(key);
    if (entry!= NULL) {
        return entry->value;
    } else {
        return NULL;
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *key, *value;
    metadata_entry *entry;
    FILE *file;
    bool in_metadata = false;
    bool in_key = false;
    bool in_value = false;
    int line_number = 0;

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_number++;
        if (line[0] == '#' && line[1] == '#') {
            in_metadata = true;
        } else if (in_metadata) {
            if (in_key) {
                if (line[0] == ':') {
                    in_key = false;
                    in_value = true;
                }
            } else if (in_value) {
                if (line[0] == '\n') {
                    in_value = false;
                    entry = metadata_add_key(key, value);
                    free(key);
                    free(value);
                    key = NULL;
                    value = NULL;
                } else {
                    if (strlen(value) >= MAX_VALUE_LENGTH) {
                        printf("Error: value too long on line %d\n", line_number);
                        return 1;
                    }
                    strcat(value, line);
                }
            } else {
                if (strlen(key) >= MAX_KEY_LENGTH) {
                    printf("Error: key too long on line %d\n", line_number);
                    return 1;
                }
                strcat(key, line);
            }
        } else if (line[0] == '#' && line[1]!= '#') {
            in_metadata = true;
        }
    }

    metadata_print();
    metadata_free();

    fclose(file);
    return 0;
}