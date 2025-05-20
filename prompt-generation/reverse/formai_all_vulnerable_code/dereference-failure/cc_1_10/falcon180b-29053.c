//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYS 256
#define MAX_VALUES 256
#define MAX_NUM_THREADS 10

typedef struct {
    char *key;
    char *value;
} metadata_t;

metadata_t *metadata_table;
int num_metadata;

void *metadata_extractor(void *arg);

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s input_file\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open input file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    metadata_t *metadata = NULL;
    num_metadata = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *delimiter = strchr(line, ':');
        if (delimiter!= NULL) {
            *delimiter = '\0';
            metadata = realloc(metadata, sizeof(metadata_t) * (num_metadata + 1));
            metadata[num_metadata].key = strdup(line);
            metadata[num_metadata].value = strdup(delimiter + 1);
            num_metadata++;
        }
    }

    fclose(fp);

    pthread_t threads[MAX_NUM_THREADS];
    int rc;
    int num_threads = 0;

    for (int i = 0; i < num_metadata; i++) {
        if (num_threads >= MAX_NUM_THREADS) {
            break;
        }

        rc = pthread_create(&threads[num_threads], NULL, metadata_extractor, metadata + i);
        if (rc) {
            fprintf(stderr, "Error: could not create thread.\n");
            return 1;
        }

        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *metadata_extractor(void *arg) {
    metadata_t *metadata = arg;

    printf("Key: %s\n", metadata->key);
    printf("Value: %s\n\n", metadata->value);

    free(metadata->key);
    free(metadata->value);
    free(metadata);

    return NULL;
}