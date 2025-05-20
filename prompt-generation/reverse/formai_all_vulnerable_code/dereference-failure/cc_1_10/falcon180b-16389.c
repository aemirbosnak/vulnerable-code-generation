//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_NUM_METADATA 10

typedef struct {
    char *key;
    char *value;
} Metadata;

int main(int argc, char **argv) {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char *token;
    Metadata metadata[MAX_NUM_METADATA];
    int num_metadata = 0;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        token = strtok(line, ":");
        if (token == NULL) {
            continue;
        }

        if (num_metadata >= MAX_NUM_METADATA) {
            printf("Error: maximum number of metadata reached\n");
            break;
        }

        metadata[num_metadata].key = strdup(token);
        metadata[num_metadata].value = strdup(strtok(NULL, ":"));
        num_metadata++;
    }

    fclose(fp);

    for (int i = 0; i < num_metadata; i++) {
        printf("Key: %s\nValue: %s\n", metadata[i].key, metadata[i].value);
    }

    for (int i = 0; i < num_metadata; i++) {
        free(metadata[i].key);
        free(metadata[i].value);
    }

    return 0;
}