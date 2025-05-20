//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_TAGS 100
#define MAX_TAG_LENGTH 64

typedef struct {
    char *name;
    char *value;
} tag_t;

typedef struct {
    tag_t *tags;
    int num_tags;
} metadata_t;

metadata_t *metadata_create() {
    metadata_t *metadata = (metadata_t *)malloc(sizeof(metadata_t));
    metadata->tags = NULL;
    metadata->num_tags = 0;
    return metadata;
}

void metadata_destroy(metadata_t *metadata) {
    for (int i = 0; i < metadata->num_tags; i++) {
        free(metadata->tags[i].name);
        free(metadata->tags[i].value);
    }
    free(metadata->tags);
    free(metadata);
}

void metadata_add_tag(metadata_t *metadata, char *name, char *value) {
    if (metadata->num_tags >= MAX_NUM_TAGS) {
        printf("Error: Maximum number of tags exceeded\n");
        return;
    }
    tag_t *tag = (tag_t *)malloc(sizeof(tag_t));
    tag->name = strdup(name);
    tag->value = strdup(value);
    metadata->tags = (tag_t *)realloc(metadata->tags, sizeof(tag_t) * (metadata->num_tags + 1));
    metadata->tags[metadata->num_tags] = *tag;
    metadata->num_tags++;
}

void metadata_print(metadata_t *metadata) {
    for (int i = 0; i < metadata->num_tags; i++) {
        printf("%s: %s\n", metadata->tags[i].name, metadata->tags[i].value);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *name, *value;
    metadata_t *metadata = metadata_create();
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (strncmp(line, "Tag: ", 5) == 0) {
            name = line + 5;
            value = strchr(line, ':');
            if (value == NULL) {
                printf("Error: Invalid tag format\n");
                continue;
            }
            *value = '\0';
            value++;
            metadata_add_tag(metadata, name, value);
        }
    }
    metadata_print(metadata);
    metadata_destroy(metadata);
    return 0;
}