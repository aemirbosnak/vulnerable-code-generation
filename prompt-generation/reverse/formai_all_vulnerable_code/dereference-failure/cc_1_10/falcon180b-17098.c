//Falcon-180B DATASET v1.0 Category: File handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *filename;
    FILE *file;
    char *buffer;
    size_t buffer_size;
    size_t buffer_index;
} FileContext;

void init_file_context(FileContext *context, const char *filename) {
    context->filename = strdup(filename);
    context->file = fopen(context->filename, "r");
    if (!context->file) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    context->buffer = malloc(MAX_LINE_SIZE);
    context->buffer_size = MAX_LINE_SIZE;
    context->buffer_index = 0;
}

void destroy_file_context(FileContext *context) {
    free(context->filename);
    fclose(context->file);
    free(context->buffer);
}

int get_next_line(FileContext *context, char **line) {
    if (context->buffer_index == 0) {
        context->buffer_index = fread(context->buffer, 1, MAX_LINE_SIZE, context->file);
        if (context->buffer_index == 0) {
            *line = NULL;
            return 0;
        }
    }
    *line = context->buffer;
    char *newline = strchr(*line, '\n');
    if (newline) {
        *newline = '\0';
        context->buffer_index -= (newline - *line) + 1;
        memmove(context->buffer, newline + 1, context->buffer_index);
    } else {
        context->buffer_index = 0;
    }
    return 1;
}

int main() {
    FileContext context;
    init_file_context(&context, "example.txt");

    char *line = NULL;
    while (get_next_line(&context, &line)) {
        printf("%s", line);
    }

    destroy_file_context(&context);

    return 0;
}