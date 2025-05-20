//Falcon-180B DATASET v1.0 Category: File handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 256
#define MAX_LINE_NUMBER_DIGITS 6
#define MAX_LINE_NUMBER_WIDTH 7

typedef struct {
    char *filename;
    FILE *file;
    char *line;
    size_t line_length;
    size_t line_number;
} FileContext;

void initialize_file_context(FileContext *context, const char *filename) {
    context->filename = strdup(filename);
    context->file = fopen(filename, "r");
    if (context->file == NULL) {
        printf("Error: failed to open file '%s'.\n", filename);
        exit(EXIT_FAILURE);
    }
    context->line = malloc(MAX_LINE_LENGTH + 1);
    context->line_length = 0;
    context->line_number = 1;
}

void destroy_file_context(FileContext *context) {
    if (context->filename!= NULL) {
        free(context->filename);
    }
    if (context->file!= NULL) {
        fclose(context->file);
    }
    if (context->line!= NULL) {
        free(context->line);
    }
}

int get_next_line(FileContext *context) {
    char c;
    int line_number_digits = 0;
    size_t line_length = 0;
    context->line_number++;
    while ((c = fgetc(context->file))!= EOF && c!= '\n') {
        if (line_length >= MAX_LINE_LENGTH - 1) {
            printf("Error: line too long.\n");
            return 0;
        }
        context->line[line_length++] = c;
    }
    if (c == EOF && line_length == 0) {
        return 0;
    }
    context->line[line_length] = '\0';
    if (line_length >= MAX_LINE_LENGTH - 1) {
        printf("Error: line too long.\n");
        return 0;
    }
    line_number_digits = snprintf(NULL, 0, "%zu", context->line_number);
    printf("%*zu: %s", MAX_LINE_NUMBER_WIDTH, context->line_number, context->line);
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FileContext context;
    initialize_file_context(&context, argv[1]);
    while (get_next_line(&context)) {
        if (context.line_number % 100 == 0) {
            printf("\n");
        }
    }
    destroy_file_context(&context);
    return 0;
}