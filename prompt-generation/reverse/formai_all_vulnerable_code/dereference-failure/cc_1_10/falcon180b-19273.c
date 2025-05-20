//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 256
#define MAX_VALUE_LENGTH 1024
#define MAX_NUM_KEYS 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} metadata_t;

int num_keys = 0;
metadata_t keys[MAX_NUM_KEYS];

void add_metadata(char* key, char* value) {
    if (num_keys >= MAX_NUM_KEYS) {
        fprintf(stderr, "Error: Too many metadata keys.\n");
        exit(1);
    }
    strncpy(keys[num_keys].key, key, MAX_KEY_LENGTH);
    strncpy(keys[num_keys].value, value, MAX_VALUE_LENGTH);
    num_keys++;
}

void print_metadata() {
    for (int i = 0; i < num_keys; i++) {
        printf("%s: %s\n", keys[i].key, keys[i].value);
    }
}

char* read_line(FILE* file) {
    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        return NULL;
    }
    int len = strlen(line);
    if (len && line[len-1] == '\n') {
        line[len-1] = '\0';
    }
    return strdup(line);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        exit(1);
    }
    char* line = read_line(file);
    while (line!= NULL) {
        char* key = strtok(line, ":");
        char* value = strtok(NULL, ":");
        if (key == NULL || value == NULL) {
            fprintf(stderr, "Error: Invalid metadata line.\n");
            exit(1);
        }
        add_metadata(key, value);
        line = read_line(file);
    }
    fclose(file);
    print_metadata();
    return 0;
}