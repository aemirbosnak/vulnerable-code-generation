//Falcon-180B DATASET v1.0 Category: File handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *file;
    int line_number;
} FileContext;

void open_file(FileContext *ctx, const char *filename) {
    ctx->filename = strdup(filename);
    ctx->file = fopen(filename, "r");

    if (ctx->file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    ctx->line_number = 1;
}

void close_file(FileContext *ctx) {
    if (ctx->file!= NULL) {
        fclose(ctx->file);
        ctx->file = NULL;
    }

    free(ctx->filename);
}

char *read_line(FileContext *ctx) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    ctx->line_number++;

    line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        printf("Error: Unable to allocate memory for line\n");
        exit(1);
    }

    read = getline(&line, &len, ctx->file);

    if (read <= 0) {
        if (ferror(ctx->file)) {
            printf("Error: Unable to read line %d\n", ctx->line_number);
        } else {
            printf("End of file reached\n");
        }

        free(line);
        line = NULL;
    } else {
        line[read - 1] = '\0'; // Remove newline character
    }

    return line;
}

void print_line(const char *line) {
    printf("%s", line);
}

int main() {
    FileContext ctx;
    char *line;

    open_file(&ctx, "example.txt");

    while ((line = read_line(&ctx))!= NULL) {
        print_line(line);
    }

    close_file(&ctx);

    return 0;
}