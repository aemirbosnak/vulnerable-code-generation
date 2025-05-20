//Falcon-180B DATASET v1.0 Category: Error handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *file;
    int linenumber;
} File;

typedef struct {
    char *message;
    int line;
    int column;
} Error;

Error *create_error(char *message, int line, int column) {
    Error *error = malloc(sizeof(Error));
    error->message = strdup(message);
    error->line = line;
    error->column = column;
    return error;
}

void destroy_error(Error *error) {
    free(error->message);
    free(error);
}

void print_error(Error *error) {
    printf("Error: %s\n", error->message);
    printf("Line %d, Column %d\n", error->line, error->column);
}

char *read_line(FILE *file, int *linenumber) {
    char *line = malloc(MAX_LINE_LENGTH);
    char *result = fgets(line, MAX_LINE_LENGTH, file);
    if (result == NULL) {
        Error *error = create_error("Failed to read line", *linenumber, 0);
        print_error(error);
        exit(1);
    }
    *linenumber += 1;
    return line;
}

int main() {
    File file;
    int linenumber = 1;

    file.filename = "example.txt";
    file.file = fopen(file.filename, "r");
    if (file.file == NULL) {
        Error *error = create_error("Failed to open file", linenumber, 0);
        print_error(error);
        exit(1);
    }

    char *line;
    while ((line = read_line(file.file, &linenumber))!= NULL) {
        printf("%s", line);
    }

    fclose(file.file);
    return 0;
}