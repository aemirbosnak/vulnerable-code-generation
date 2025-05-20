//Falcon-180B DATASET v1.0 Category: File handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 10000

struct line_t {
    char *text;
    int length;
};

struct file_t {
    char *filename;
    FILE *fp;
    int num_lines;
    struct line_t *lines;
};

int read_file(struct file_t *file) {
    char ch;
    int line_num = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file->fp))!= -1) {
        if (line_num >= MAX_NUM_LINES) {
            fprintf(stderr, "Error: Maximum number of lines exceeded.\n");
            exit(EXIT_FAILURE);
        }

        line[read - 1] = '\0';
        file->lines[line_num].text = strdup(line);
        file->lines[line_num].length = strlen(line);

        ++line_num;
    }

    if (ferror(file->fp)) {
        fprintf(stderr, "Error: Failed to read file.\n");
        exit(EXIT_FAILURE);
    }

    return line_num;
}

int main() {
    struct file_t file;
    char *filename = NULL;
    int num_lines;
    int i;
    int max_length = 0;

    printf("Enter filename: ");
    fgets(file.filename, MAX_LINE_LENGTH, stdin);
    file.filename[strcspn(file.filename, "\n")] = '\0';

    file.fp = fopen(file.filename, "r");
    if (file.fp == NULL) {
        fprintf(stderr, "Error: Failed to open file.\n");
        exit(EXIT_FAILURE);
    }

    num_lines = read_file(&file);

    printf("Number of lines: %d\n", num_lines);

    if (num_lines == 0) {
        exit(EXIT_SUCCESS);
    }

    for (i = 0; i < num_lines; ++i) {
        if (file.lines[i].length > max_length) {
            max_length = file.lines[i].length;
        }
    }

    printf("Longest line length: %d\n", max_length);

    for (i = 0; i < num_lines; ++i) {
        printf("%3d: %-*s\n", i+1, max_length, file.lines[i].text);
    }

    for (i = 0; i < num_lines; ++i) {
        free(file.lines[i].text);
    }
    free(file.lines);
    fclose(file.fp);
    free(file.filename);

    exit(EXIT_SUCCESS);
}