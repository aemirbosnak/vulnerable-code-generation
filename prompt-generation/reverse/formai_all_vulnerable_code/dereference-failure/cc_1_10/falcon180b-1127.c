//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 256
#define MAX_VALUE_LEN 1024

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} KeyValuePair;

int compare_keys(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *fp;
    char line[1024];
    char *filename = "data.txt";
    char delimiter = '=';
    int num_pairs = 0;
    KeyValuePair *pairs = NULL;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *key, *value;
        int key_len, value_len;

        key = strtok(line, &delimiter);
        value = strtok(NULL, &delimiter);

        if (key == NULL || value == NULL) {
            printf("Error: Invalid line in file %s\n", filename);
            fclose(fp);
            return 2;
        }

        key_len = strlen(key);
        value_len = strlen(value);

        if (key_len > MAX_KEY_LEN || value_len > MAX_VALUE_LEN) {
            printf("Error: Key or value too long in file %s\n", filename);
            fclose(fp);
            return 3;
        }

        num_pairs++;
        pairs = realloc(pairs, sizeof(KeyValuePair) * num_pairs);
        strcpy(pairs[num_pairs - 1].key, key);
        strcpy(pairs[num_pairs - 1].value, value);
    }

    fclose(fp);

    qsort(pairs, num_pairs, sizeof(KeyValuePair), compare_keys);

    for (int i = 0; i < num_pairs; i++) {
        printf("%s=%s\n", pairs[i].key, pairs[i].value);
    }

    free(pairs);

    return 0;
}