//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

struct keyword {
    char *name;
    int count;
};

struct metadata {
    char *filename;
    struct keyword *keywords;
    int num_keywords;
};

void add_keyword(struct keyword *keywords, int num_keywords, char *name) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(keywords[i].name, name) == 0) {
            keywords[i].count++;
            return;
        }
    }
    struct keyword *new_keywords = realloc(keywords, sizeof(struct keyword) * (num_keywords + 1));
    if (new_keywords == NULL) {
        printf("Error: Failed to allocate memory for new keyword.\n");
        exit(1);
    }
    keywords = new_keywords;
    keywords[num_keywords].name = strdup(name);
    keywords[num_keywords].count = 1;
    num_keywords++;
}

void print_metadata(struct metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Keywords:\n");
    for (int i = 0; i < metadata->num_keywords; i++) {
        printf("%s: %d\n", metadata->keywords[i].name, metadata->keywords[i].count);
    }
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *filename = NULL;
    struct metadata metadata = {0};

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Failed to open file %s.\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *keyword = strtok(line, ",\n");
        while (keyword!= NULL) {
            add_keyword(&metadata.keywords, metadata.num_keywords, keyword);
            keyword = strtok(NULL, ",\n");
        }
    }

    fclose(file);
    metadata.filename = filename;

    print_metadata(&metadata);

    for (int i = 0; i < metadata.num_keywords; i++) {
        free(metadata.keywords[i].name);
    }
    free(metadata.keywords);

    return 0;
}