//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_META_KEYS 100
#define MAX_META_VALUE_LEN 100

typedef struct {
    char key[MAX_META_KEYS];
    char value[MAX_META_VALUE_LEN];
} MetaKeyValue;

int main(int argc, char *argv[]) {
    FILE *input_file;
    char line[1000];
    char delimiter = ',';
    int num_meta_keys = 0;
    MetaKeyValue meta_keys[MAX_META_KEYS];

    if (argc!= 3) {
        printf("Usage: %s <input_file> <delimiter>\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    delimiter = argv[2][0];

    // Read first line to determine number of meta keys
    fgets(line, sizeof(line), input_file);
    char *token = strtok(line, delimiter);
    while (token!= NULL) {
        num_meta_keys++;
        token = strtok(NULL, delimiter);
    }

    rewind(input_file);

    // Read meta keys and values
    while (num_meta_keys > 0) {
        fgets(line, sizeof(line), input_file);
        token = strtok(line, delimiter);
        strcpy(meta_keys[num_meta_keys - 1].key, token);
        token = strtok(NULL, delimiter);
        strcpy(meta_keys[num_meta_keys - 1].value, token);
        num_meta_keys--;
    }

    fclose(input_file);

    // Print meta keys and values
    for (int i = 0; i < num_meta_keys; i++) {
        printf("Key: %s, Value: %s\n", meta_keys[i].key, meta_keys[i].value);
    }

    return 0;
}