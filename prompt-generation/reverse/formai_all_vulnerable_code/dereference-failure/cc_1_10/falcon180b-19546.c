//Falcon-180B DATASET v1.0 Category: File handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_FILE_LINE_COUNT 10000

typedef struct {
    char *filename;
    FILE *file;
    char *line_buffer;
    int line_count;
} FileContext;

FileContext *create_file_context(const char *filename) {
    FileContext *context = (FileContext *)malloc(sizeof(FileContext));
    context->filename = strdup(filename);
    context->file = fopen(filename, "r");
    if (context->file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }
    context->line_buffer = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    context->line_count = 0;
    return context;
}

void destroy_file_context(FileContext *context) {
    free(context->filename);
    free(context->line_buffer);
    fclose(context->file);
    free(context);
}

int read_file_line(FileContext *context, char **line) {
    char *buffer = context->line_buffer;
    int length = fread(buffer, sizeof(char), MAX_LINE_LENGTH, context->file);
    if (length <= 0) {
        return 0;
    }
    buffer[length - 1] = '\0';
    *line = buffer;
    context->line_count++;
    return length;
}

int main() {
    FileContext *context = create_file_context("test.txt");
    char *line = NULL;
    int line_count = 0;
    while (read_file_line(context, &line) > 0) {
        printf("%d: %s", line_count, line);
        line_count++;
        if (line_count >= MAX_FILE_LINE_COUNT) {
            break;
        }
    }
    destroy_file_context(context);
    return 0;
}