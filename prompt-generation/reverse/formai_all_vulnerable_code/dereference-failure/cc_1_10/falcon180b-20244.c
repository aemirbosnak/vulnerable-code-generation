//Falcon-180B DATASET v1.0 Category: File handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *filename;
    FILE *fileptr;
    int linenumber;
} FileContext;

void open_file(FileContext *context, const char *filename) {
    context->filename = strdup(filename);
    context->fileptr = fopen(filename, "r");
    if (context->fileptr == NULL) {
        perror("Error opening file");
        exit(1);
    }
    context->linenumber = 0;
}

char *read_line(FileContext *context) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, context->fileptr))!= -1) {
        if (line[read - 1] == '\n') {
            line[--read] = '\0';
        }
        context->linenumber++;
        return line;
    }

    if (ferror(context->fileptr)) {
        perror("Error reading line");
        exit(1);
    }

    free(line);
    return NULL;
}

void close_file(FileContext *context) {
    fclose(context->fileptr);
    free(context->filename);
    free(context);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    FileContext context;
    open_file(&context, argv[1]);

    char *line;
    while ((line = read_line(&context))!= NULL) {
        printf("%d: %s", context.linenumber, line);
    }

    close_file(&context);

    return 0;
}