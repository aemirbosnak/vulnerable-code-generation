//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_KEYS 100

typedef struct {
    char *key;
    char *value;
} KeyValue;

int num_keys = 0;
KeyValue *keys = NULL;

void add_key(char *key, char *value) {
    if (num_keys >= MAX_KEYS) {
        printf("Error: too many keys\n");
        exit(1);
    }
    keys = realloc(keys, sizeof(KeyValue) * ++num_keys);
    keys[num_keys - 1].key = strdup(key);
    keys[num_keys - 1].value = strdup(value);
}

void print_keys() {
    for (int i = 0; i < num_keys; i++) {
        printf("%s: %s\n", keys[i].key, keys[i].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <metadata_file>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        char *key = strtok(line, ":");
        char *value = strtok(NULL, ":");
        if (key == NULL || value == NULL) {
            printf("Error: invalid line format\n");
            exit(1);
        }
        add_key(key, value);
    }

    fclose(fp);
    print_keys();

    return 0;
}