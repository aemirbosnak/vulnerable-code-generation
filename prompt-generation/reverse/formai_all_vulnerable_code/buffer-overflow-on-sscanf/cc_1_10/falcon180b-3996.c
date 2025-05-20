//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_TAGS 100
#define MAX_TAG_LENGTH 50

typedef struct {
    char *name;
    char *value;
} tag_t;

typedef struct {
    tag_t *tags;
    int num_tags;
} metadata_t;

char *get_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        fprintf(stderr, "Error reading file\n");
        exit(1);
    }
    return line;
}

void parse_line(metadata_t *metadata, char *line) {
    char *tag_name, *tag_value;
    if (sscanf(line, "%s:%s", tag_name, tag_value) == 2) {
        if (metadata->num_tags >= MAX_NUM_TAGS) {
            fprintf(stderr, "Too many tags\n");
            exit(1);
        }
        metadata->tags[metadata->num_tags] = (tag_t) {
           .name = strdup(tag_name),
           .value = strdup(tag_value)
        };
        metadata->num_tags++;
    } else {
        fprintf(stderr, "Invalid line format\n");
        exit(1);
    }
}

void print_metadata(metadata_t *metadata) {
    for (int i = 0; i < metadata->num_tags; i++) {
        printf("%s: %s\n", metadata->tags[i].name, metadata->tags[i].value);
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file\n");
        exit(1);
    }

    metadata_t metadata = {0};

    char *line;
    while ((line = get_line(input_file))!= NULL) {
        parse_line(&metadata, line);
    }

    fclose(input_file);

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file\n");
        exit(1);
    }

    print_metadata(&metadata);

    fclose(output_file);

    return 0;
}