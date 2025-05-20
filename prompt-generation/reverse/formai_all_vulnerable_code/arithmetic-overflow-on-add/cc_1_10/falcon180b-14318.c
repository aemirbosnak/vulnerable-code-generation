//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

struct metadata {
    char *filename;
    int lines;
    int words;
    int characters;
};

void extract_metadata(FILE *fp, struct metadata *metadata) {
    char line[MAX_LINE_SIZE];
    int in_comment = 0;

    while (fgets(line, sizeof(line), fp)) {
        metadata->lines++;

        if (line[0] == '#') {
            in_comment = 1;
            continue;
        } else if (in_comment) {
            in_comment = 0;
            continue;
        }

        char *word = strtok(line, " \t\n");
        while (word!= NULL) {
            metadata->words++;
            word = strtok(NULL, " \t\n");
        }

        metadata->characters += strlen(line);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    struct metadata metadata;
    extract_metadata(fp, &metadata);

    printf("Filename: %s\n", metadata.filename);
    printf("Lines: %d\n", metadata.lines);
    printf("Words: %d\n", metadata.words);
    printf("Characters: %d\n", metadata.characters);

    fclose(fp);
    return 0;
}