//Falcon-180B DATASET v1.0 Category: File handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILENAME_LENGTH 100

typedef struct {
    FILE *file;
    char filename[MAX_FILENAME_LENGTH];
    int line_number;
} FileContext;

void open_file(FileContext *context, const char *filename) {
    strcpy(context->filename, filename);
    context->file = fopen(filename, "r");
    if (context->file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }
    context->line_number = 1;
}

int read_line(FileContext *context, char *buffer, int max_length) {
    int length = 0;
    char c;
    while ((c = fgetc(context->file))!= EOF) {
        if (length >= max_length - 1) {
            printf("Error: line too long in file '%s' at line %d\n", context->filename, context->line_number);
            exit(1);
        }
        buffer[length++] = c;
    }
    buffer[length] = '\0';
    if (length == max_length - 1) {
        printf("Warning: line truncated in file '%s' at line %d\n", context->filename, context->line_number);
    }
    context->line_number++;
    return length;
}

void close_file(FileContext *context) {
    fclose(context->file);
}

int main() {
    FileContext context;
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    open_file(&context, filename);
    char buffer[MAX_LINE_LENGTH];
    int length;
    while ((length = read_line(&context, buffer, MAX_LINE_LENGTH)) > 0) {
        printf("%s\n", buffer);
    }
    close_file(&context);
    return 0;
}