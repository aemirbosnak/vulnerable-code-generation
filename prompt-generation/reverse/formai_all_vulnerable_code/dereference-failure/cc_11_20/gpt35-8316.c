//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

int main(int argc, char *argv[]) {
    char line[MAX_LINE_LEN];
    FILE *fp;
    metadata_t metadata[100];
    int num_metadata = 0;
    int i, j;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    // read file line by line
    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        // check if line starts with '#'
        if (line[0] == '#') {
            // find first ':' character
            char *colon = strchr(line, ':');
            if (colon == NULL) {
                fprintf(stderr, "Invalid metadata line: %s", line);
                exit(1);
            }

            // split line into key/value pairs
            *colon = '\0';
            char *key = line + 1;  // skip leading '#'
            char *value = colon + 1;
            while (*value == ' ') value++;  // skip leading whitespace

            // allocate memory for new metadata entry
            metadata[num_metadata].key = (char *) malloc(strlen(key) + 1);
            metadata[num_metadata].value = (char *) malloc(strlen(value) + 1);
            if (metadata[num_metadata].key == NULL || metadata[num_metadata].value == NULL) {
                perror("malloc");
                exit(1);
            }

            // copy key and value into new metadata entry
            strcpy(metadata[num_metadata].key, key);
            strcpy(metadata[num_metadata].value, value);

            num_metadata++;
        }
    }

    // print out metadata
    for (i = 0; i < num_metadata; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }

    // free memory allocated for metadata
    for (i = 0; i < num_metadata; i++) {
        free(metadata[i].key);
        free(metadata[i].value);
    }

    fclose(fp);
    return 0;
}