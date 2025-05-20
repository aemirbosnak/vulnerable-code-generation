//Falcon-180B DATASET v1.0 Category: File handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

struct Line {
    char *data;
    size_t length;
    struct Line *next;
};

struct File {
    char *filename;
    FILE *fp;
    struct Line *head;
};

void add_line(struct File *file, const char *line) {
    struct Line *new_line = malloc(sizeof(struct Line));
    new_line->data = strdup(line);
    new_line->length = strlen(line);
    new_line->next = NULL;

    if (file->head == NULL) {
        file->head = new_line;
    } else {
        struct Line *last = file->head;
        while (last->next!= NULL) {
            last = last->next;
        }
        last->next = new_line;
    }
}

void print_file(struct File *file) {
    struct Line *line = file->head;
    while (line!= NULL) {
        printf("%s", line->data);
        if (line->next!= NULL) {
            printf("\n");
        }
        line = line->next;
    }
}

int main() {
    struct File file = { 0 };
    char *filename = "example.txt";
    char *buffer = NULL;
    size_t buffer_size = 0;
    char line[MAX_LINE_SIZE];

    file.filename = filename;
    file.fp = fopen(filename, "r");

    if (file.fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, file.fp)!= NULL) {
        buffer = realloc(buffer, buffer_size + strlen(line));
        strcat(buffer, line);
        buffer_size += strlen(line);
    }

    fclose(file.fp);
    file.fp = NULL;

    add_line(&file, buffer);

    print_file(&file);

    free(buffer);
    free(file.head);

    return 0;
}