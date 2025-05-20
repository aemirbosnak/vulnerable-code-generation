//Falcon-180B DATASET v1.0 Category: Error handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    FILE *file;
    int linenumber;
} FileContext;

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int open_file(const char *filename, FileContext *ctx) {
    ctx->file = fopen(filename, "r");
    if (ctx->file == NULL) {
        error("Failed to open file");
    }
    ctx->filename = strdup(filename);
    ctx->linenumber = 1;
    return 0;
}

int close_file(FileContext *ctx) {
    if (fclose(ctx->file)!= 0) {
        error("Failed to close file");
    }
    free(ctx->filename);
    ctx->filename = NULL;
    ctx->file = NULL;
    return 0;
}

int read_line(FileContext *ctx, char *buffer, size_t size) {
    char *line = fgets(buffer, size, ctx->file);
    if (line == NULL) {
        if (feof(ctx->file)) {
            return 1;
        } else if (ferror(ctx->file)) {
            error("Failed to read line");
        }
    }
    return 0;
}

void process_line(char *line, size_t length, int *error_count, int *warning_count) {
    // Do some processing here
    if (strstr(line, "error")!= NULL) {
        (*error_count)++;
    } else if (strstr(line, "warning")!= NULL) {
        (*warning_count)++;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        error("Usage:./program <filename>");
    }

    FileContext ctx;
    open_file(argv[1], &ctx);

    char buffer[MAX_LINE_LENGTH];
    int error_count = 0;
    int warning_count = 0;

    while (!read_line(&ctx, buffer, MAX_LINE_LENGTH)) {
        process_line(buffer, strlen(buffer), &error_count, &warning_count);
    }

    close_file(&ctx);

    printf("Found %d errors and %d warnings\n", error_count, warning_count);

    return 0;
}