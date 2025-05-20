//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_NUM_TAGS 100

typedef struct {
    char *name;
    char *value;
} tag_t;

typedef struct {
    char *file_name;
    int num_tags;
    tag_t tags[MAX_NUM_TAGS];
} metadata_t;

metadata_t *read_metadata(FILE *fp) {
    metadata_t *metadata = (metadata_t *)malloc(sizeof(metadata_t));
    char line[MAX_LINE_LENGTH];
    char *name, *value;
    int num_tags = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (strncmp(line, "Name=", 5) == 0) {
            name = strtok(line, "=");
            value = strtok(NULL, "\n");
            metadata->tags[num_tags].name = strdup(name);
            metadata->tags[num_tags].value = strdup(value);
            num_tags++;
        }
    }

    metadata->num_tags = num_tags;
    return metadata;
}

void print_metadata(metadata_t *metadata) {
    for (int i = 0; i < metadata->num_tags; i++) {
        printf("%s: %s\n", metadata->tags[i].name, metadata->tags[i].value);
    }
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE *fp;

    printf("Enter the name of the file: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    metadata_t *metadata = read_metadata(fp);
    print_metadata(metadata);

    fclose(fp);
    free(metadata);

    return 0;
}