//Falcon-180B DATASET v1.0 Category: File handling ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_SIZE (1024 * 1024)

typedef struct {
    char *filename;
    FILE *file;
    long filesize;
    char *buffer;
} FileContext;

FileContext *FileOpen(const char *filename) {
    FileContext *context = (FileContext *) malloc(sizeof(FileContext));
    if (context == NULL) {
        printf("Error: failed to allocate memory for file context.\n");
        exit(EXIT_FAILURE);
    }

    context->filename = strdup(filename);
    context->file = fopen(filename, "r");
    if (context->file == NULL) {
        printf("Error: failed to open file '%s'.\n", filename);
        free(context->filename);
        free(context);
        exit(EXIT_FAILURE);
    }

    fseek(context->file, 0, SEEK_END);
    context->filesize = ftell(context->file);
    rewind(context->file);

    context->buffer = (char *) malloc(MAX_LINE_LENGTH);
    if (context->buffer == NULL) {
        printf("Error: failed to allocate memory for file buffer.\n");
        fclose(context->file);
        free(context->filename);
        free(context);
        exit(EXIT_FAILURE);
    }

    return context;
}

void FileClose(FileContext *context) {
    fclose(context->file);
    free(context->filename);
    free(context->buffer);
    free(context);
}

int FileReadLine(FileContext *context, char **line) {
    char *buffer = context->buffer;
    long bytes_read = 0;
    int line_length = 0;

    while (bytes_read < MAX_LINE_LENGTH && (context->filesize - ftell(context->file)) > 0) {
        int c = fgetc(context->file);
        if (c == EOF) {
            break;
        }

        if (c == '\n') {
            *line = strndup(buffer, line_length);
            return 1;
        }

        buffer[line_length++] = c;
        bytes_read++;
    }

    *line = strndup(buffer, line_length);
    return 0;
}

int main() {
    FileContext *context = FileOpen("example.txt");
    if (context == NULL) {
        return 1;
    }

    char *line = NULL;
    while (FileReadLine(context, &line) == 1) {
        printf("%s", line);
        free(line);
        line = NULL;
    }

    FileClose(context);
    return 0;
}