//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_SIZE (1024 * 1024)
#define MAX_LINE_LENGTH 256
#define METADATA_TAG "METADATA"
#define DATA_TAG "DATA"
#define TAG_LENGTH 6

typedef struct {
    char tag[TAG_LENGTH];
    size_t length;
    char data[1];
} Tag;

void read_file(const char *filename, Tag **tags, size_t *num_tags, size_t *total_size) {
    int fd;
    size_t current_position = 0;
    size_t line_length;
    char line[MAX_LINE_LENGTH];
    Tag *tag;

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    *tags = NULL;
    *num_tags = 0;
    *total_size = 0;

    while (current_position < MAX_FILE_SIZE && fgets(line, MAX_LINE_LENGTH, fd) != NULL) {
        line_length = strlen(line);

        if (line[line_length - 1] == '\n') line[line_length - 1] = '\0';

        if (strncmp(line, METADATA_TAG, TAG_LENGTH) == 0) {
            size_t tag_length = TAG_LENGTH;
            size_t data_length = line_length - TAG_LENGTH;

            tag = malloc(sizeof(Tag) + data_length);
            strncpy(tag->tag, line, TAG_LENGTH);
            tag->length = data_length;

            *tags = realloc(*tags, sizeof(Tag) * (*num_tags + 1));
            (*tags)[*num_tags] = *tag;
            (*num_tags)++;
            *total_size += sizeof(Tag) + data_length;

            current_position += sizeof(Tag) + data_length;
        } else if (strncmp(line, DATA_TAG, TAG_LENGTH) == 0) {
            // skip data tag, read data until next tag or end of file
            size_t data_length = line_length - TAG_LENGTH;
            current_position += data_length;
        }
    }

    close(fd);
}

int main(int argc, char *argv[]) {
    Tag *tags;
    size_t num_tags;
    size_t total_size;
    char *filename;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    filename = argv[1];
    read_file(filename, &tags, &num_tags, &total_size);

    printf("Number of tags: %zu\n", num_tags);
    printf("Total size: %zu\n", total_size);

    for (size_t i = 0; i < num_tags; i++) {
        printf("Tag: %s, Length: %zu, Data: %.*s\n", tags[i].tag, tags[i].length, (int)tags[i].length, tags[i].data);
    }

    free(tags);

    return EXIT_SUCCESS;
}