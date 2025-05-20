//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 100

typedef struct {
    char *name;
    char *value;
} keyword_t;

typedef struct {
    int count;
    keyword_t *keywords;
} metadata_t;

metadata_t *metadata_create() {
    metadata_t *metadata = (metadata_t *) malloc(sizeof(metadata_t));
    metadata->count = 0;
    metadata->keywords = (keyword_t *) malloc(MAX_KEYWORDS * sizeof(keyword_t));
    return metadata;
}

void metadata_destroy(metadata_t *metadata) {
    free(metadata->keywords);
    free(metadata);
}

int metadata_add_keyword(metadata_t *metadata, const char *name, const char *value) {
    if (metadata->count >= MAX_KEYWORDS) {
        return -1;
    }

    keyword_t *keyword = &metadata->keywords[metadata->count];
    keyword->name = strdup(name);
    keyword->value = strdup(value);

    metadata->count++;
    return 0;
}

void metadata_print(metadata_t *metadata) {
    for (int i = 0; i < metadata->count; i++) {
        keyword_t *keyword = &metadata->keywords[i];
        printf("%s: %s\n", keyword->name, keyword->value);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *filename;
    FILE *file;
    metadata_t *metadata = metadata_create();

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        char *token = strtok(line, ":");
        while (token!= NULL) {
            char *name = strtok(token, " ");
            char *value = strtok(NULL, " ");

            if (name == NULL || value == NULL) {
                continue;
            }

            int result = metadata_add_keyword(metadata, name, value);
            if (result == -1) {
                printf("Error: Too many keywords.\n");
                break;
            }
        }
    }

    fclose(file);
    metadata_print(metadata);
    metadata_destroy(metadata);

    return 0;
}