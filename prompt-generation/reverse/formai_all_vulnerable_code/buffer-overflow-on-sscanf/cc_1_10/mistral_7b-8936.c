//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_KEYWORD_LENGTH 32
#define MAX_NUM_METADATA 100

typedef struct {
    char keyword[MAX_KEYWORD_LENGTH];
    char value[MAX_LINE_LENGTH];
} metadata;

metadata metadata_array[MAX_NUM_METADATA];
int num_metadata = 0;

void extract_metadata(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    char keyword[MAX_KEYWORD_LENGTH];
    char *value_start;
    int keyword_length;

    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        if (line[0] == ';' || line[0] == '/' || line[0] == '*') {
            continue;
        }

        if (sscanf(line, "%s%n", keyword, &keyword_length) != 1) {
            continue;
        }

        keyword[keyword_length] = '\0';

        if (num_metadata >= MAX_NUM_METADATA) {
            printf("Error: Maximum number of metadata reached.\n");
            exit(EXIT_FAILURE);
        }

        value_start = strchr(line, ':') + 1;
        strncpy(metadata_array[num_metadata].value, value_start, MAX_LINE_LENGTH);
        strcpy(metadata_array[num_metadata].keyword, keyword);
        num_metadata++;
    }
}

void print_metadata(metadata *metadata, int num_metadata) {
    int i;

    printf("\nMetadata:\n");
    for (i = 0; i < num_metadata; i++) {
        printf("%s: %s\n", metadata[i].keyword, metadata[i].value);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    extract_metadata(fp);
    fclose(fp);

    print_metadata(metadata_array, num_metadata);

    return EXIT_SUCCESS;
}