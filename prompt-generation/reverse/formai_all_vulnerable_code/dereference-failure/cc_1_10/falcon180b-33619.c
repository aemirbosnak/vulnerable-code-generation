//Falcon-180B DATASET v1.0 Category: File handling ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    FILE *file;
    int line_number;
    char *line;
} FileContext;

void read_file(FileContext *context) {
    char c;
    int line_length = 0;
    context->line_number = 1;
    context->line = malloc(MAX_LINE_LENGTH);
    while ((c = fgetc(context->file))!= EOF) {
        if (isalnum(c)) {
            context->line[line_length++] = tolower(c);
        } else if (isspace(c)) {
            context->line[line_length] = '\0';
            printf("Line %d: %s\n", context->line_number, context->line);
            line_length = 0;
        } else {
            printf("Invalid character: %c\n", c);
        }
    }
    printf("Line %d: %s\n", context->line_number, context->line);
    free(context->line);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    FileContext context;
    context.filename = argv[1];
    context.file = fopen(context.filename, "r");
    if (context.file == NULL) {
        printf("Error opening file: %s\n", context.filename);
        exit(2);
    }
    read_file(&context);
    fclose(context.file);
    free(context.filename);
    free(context.line);
    return 0;
}