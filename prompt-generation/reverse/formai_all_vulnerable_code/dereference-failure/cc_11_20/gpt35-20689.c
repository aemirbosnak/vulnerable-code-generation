//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

typedef struct Metadata {
    char *title;
    char *author;
    int year;
    char *publisher;
} Metadata;

void extract_metadata(const char *filename, Metadata *metadata) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1) {
        // Ignore blank lines
        if (read <= 1) {
            continue;
        }

        int colon_index = -1;
        for (int i = 0; i < read; i++) {
            if (line[i] == ':') {
                colon_index = i;
                break;
            }
        }

        if (colon_index == -1) {
            // Invalid line format
            continue;
        }

        char *key = malloc(colon_index + 1);
        if (key == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < colon_index; i++) {
            key[i] = line[i];
        }
        key[colon_index] = '\0';

        if (strcmp(key, "Title") == 0) {
            metadata->title = malloc(read - colon_index);
            if (metadata->title == NULL) {
                perror("Failed to allocate memory");
                exit(EXIT_FAILURE);
            }

            for (int i = colon_index + 2; i < read; i++) {
                metadata->title[i - colon_index - 2] = line[i];
            }
            metadata->title[read - colon_index - 2] = '\0';
        } else if (strcmp(key, "Author") == 0) {
            metadata->author = malloc(read - colon_index);
            if (metadata->author == NULL) {
                perror("Failed to allocate memory");
                exit(EXIT_FAILURE);
            }

            for (int i = colon_index + 2; i < read; i++) {
                metadata->author[i - colon_index - 2] = line[i];
            }
            metadata->author[read - colon_index - 2] = '\0';
        } else if (strcmp(key, "Year") == 0) {
            char *value = malloc(read - colon_index);
            if (value == NULL) {
                perror("Failed to allocate memory");
                exit(EXIT_FAILURE);
            }

            for (int i = colon_index + 2; i < read; i++) {
                value[i - colon_index - 2] = line[i];
            }
            value[read - colon_index - 2] = '\0';

            metadata->year = atoi(value);
            free(value);
        } else if (strcmp(key, "Publisher") == 0) {
            metadata->publisher = malloc(read - colon_index);
            if (metadata->publisher == NULL) {
                perror("Failed to allocate memory");
                exit(EXIT_FAILURE);
            }

            for (int i = colon_index + 2; i < read; i++) {
                metadata->publisher[i - colon_index - 2] = line[i];
            }
            metadata->publisher[read - colon_index - 2] = '\0';
        }

        free(key);
    }

    free(line);
    fclose(file);
}

int main() {
    Metadata metadata = {NULL, NULL, 0, NULL};
    extract_metadata("book.txt", &metadata);

    printf("Title: %s\n", metadata.title);
    printf("Author: %s\n", metadata.author);
    printf("Year: %d\n", metadata.year);
    printf("Publisher: %s\n", metadata.publisher);

    free(metadata.title);
    free(metadata.author);
    free(metadata.publisher);

    return 0;
}