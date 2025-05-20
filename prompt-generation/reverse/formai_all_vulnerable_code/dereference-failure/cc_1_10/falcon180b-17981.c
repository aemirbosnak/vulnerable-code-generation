//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_KEY_VALUES 100

typedef struct {
    char *key;
    char *value;
} metadata_kv;

metadata_kv *metadata_list = NULL;
int num_metadata = 0;

void add_metadata(char *key, char *value) {
    metadata_kv *new_metadata = malloc(sizeof(metadata_kv));
    new_metadata->key = strdup(key);
    new_metadata->value = strdup(value);
    metadata_list = realloc(metadata_list, sizeof(metadata_kv) * ++num_metadata);
    metadata_list[num_metadata-1] = *new_metadata;
}

void print_metadata() {
    for (int i = 0; i < num_metadata; i++) {
        printf("Key: %s, Value: %s\n", metadata_list[i].key, metadata_list[i].value);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *key_start = NULL;
    char *value_start = NULL;
    char *metadata_file = "metadata.txt";
    FILE *fp = fopen(metadata_file, "r");

    if (fp == NULL) {
        printf("Error: Could not open metadata file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int line_len = strlen(line);
        if (line_len == 0 || line[0] == '#') {
            continue;
        }

        char *equal_pos = strchr(line, '=');
        if (equal_pos == NULL) {
            printf("Error: Invalid metadata format on line %d.\n", num_metadata+1);
            exit(1);
        }

        key_start = line;
        value_start = equal_pos + 1;

        while (isspace(*(value_start-1))) {
            value_start--;
        }

        add_metadata(key_start, value_start);
    }

    fclose(fp);
    print_metadata();

    return 0;
}