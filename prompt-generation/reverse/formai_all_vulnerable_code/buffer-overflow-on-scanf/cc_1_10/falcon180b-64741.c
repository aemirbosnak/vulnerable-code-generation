//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define NUM_WORDS_PER_LINE 10

typedef struct {
    char *filename;
    char **keywords;
    int num_keywords;
} Metadata;

void read_metadata(Metadata *metadata) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    int i = 0;

    fp = fopen(metadata->filename, "r");

    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", metadata->filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        token = strtok(line, " ");

        while (token!= NULL) {
            if (i >= NUM_WORDS_PER_LINE) {
                break;
            }

            if (strlen(token) > MAX_WORD_LENGTH) {
                printf("Warning: Ignoring long keyword '%s' in line %d.\n", token, i + 1);
                continue;
            }

            metadata->keywords[i++] = strdup(token);

            token = strtok(NULL, " ");
        }
    }

    fclose(fp);
}

void print_metadata(Metadata *metadata) {
    int i;

    for (i = 0; i < metadata->num_keywords; i++) {
        printf("%s\n", metadata->keywords[i]);
    }
}

void free_metadata(Metadata *metadata) {
    int i;

    for (i = 0; i < metadata->num_keywords; i++) {
        free(metadata->keywords[i]);
    }

    free(metadata->keywords);
}

int main() {
    Metadata metadata;
    char filename[MAX_LINE_LENGTH];

    printf("Enter the name of the file to extract metadata from: ");
    scanf("%s", filename);

    metadata.filename = strdup(filename);
    metadata.keywords = NULL;
    metadata.num_keywords = 0;

    read_metadata(&metadata);
    print_metadata(&metadata);
    free_metadata(&metadata);

    return 0;
}