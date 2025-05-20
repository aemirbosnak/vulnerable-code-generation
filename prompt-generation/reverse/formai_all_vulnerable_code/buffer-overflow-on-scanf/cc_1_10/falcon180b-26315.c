//Falcon-180B DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *file;
} File;

typedef struct {
    char *text;
    size_t length;
} Line;

char *read_line(FILE *file) {
    char *line = NULL;
    size_t capacity = 0;
    ssize_t bytes_read;

    getline(&line, &capacity, file);
    if (line == NULL) {
        fprintf(stderr, "Error: failed to read line from file.\n");
        exit(EXIT_FAILURE);
    }

    return line;
}

void write_line(FILE *file, const char *text) {
    fprintf(file, "%s\n", text);
}

void close_file(FILE *file) {
    if (fclose(file)!= 0) {
        fprintf(stderr, "Error: failed to close file.\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    File input_file = {NULL, NULL};
    File output_file = {NULL, NULL};
    Line line = {NULL, 0};
    char *text = NULL;
    size_t length = 0;
    int count = 0;

    printf("Enter the filename for the input file: ");
    scanf("%s", input_file.filename);
    input_file.file = fopen(input_file.filename, "r");
    if (input_file.file == NULL) {
        fprintf(stderr, "Error: failed to open input file.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the filename for the output file: ");
    scanf("%s", output_file.filename);
    output_file.file = fopen(output_file.filename, "w");
    if (output_file.file == NULL) {
        fprintf(stderr, "Error: failed to open output file.\n");
        exit(EXIT_FAILURE);
    }

    while ((text = read_line(input_file.file))!= NULL) {
        length = strlen(text);
        if (length > MAX_LINE_LENGTH) {
            fprintf(stderr, "Error: input line is too long.\n");
            exit(EXIT_FAILURE);
        }
        line.text = text;
        line.length = length;
        write_line(output_file.file, text);
        count++;
    }

    printf("Number of lines written to output file: %d\n", count);

    close_file(input_file.file);
    close_file(output_file.file);

    return 0;
}