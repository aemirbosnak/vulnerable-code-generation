//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000000

typedef struct {
    char *text;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} File;

Line *read_file(const char *filename, File *file) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    Line *lines = malloc(MAX_NUM_LINES * sizeof(Line));
    int num_lines = 0;

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, fp)!= NULL) {
        int length = strlen(buffer);
        if (length > 0 && buffer[length - 1] == '\n') {
            buffer[--length] = '\0';
        }

        Line *line = malloc(sizeof(Line));
        line->text = strdup(buffer);
        line->length = length;

        lines[num_lines++] = *line;
    }

    fclose(fp);

    file->lines = lines;
    file->num_lines = num_lines;

    return lines;
}

void print_file(const File *file) {
    for (int i = 0; i < file->num_lines; i++) {
        printf("%s", file->lines[i].text);
    }
}

void free_file(File *file) {
    for (int i = 0; i < file->num_lines; i++) {
        free(file->lines[i].text);
    }
    free(file->lines);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    File file;
    Line *lines = read_file(argv[1], &file);

    for (int i = 0; i < file.num_lines; i++) {
        char *text = lines[i].text;
        int length = lines[i].length;

        // Add indentation to each line
        for (int j = 0; j < 4; j++) {
            printf(" ");
        }

        // Print the line
        printf("%s", text);

        // Add a newline character at the end of each line
        printf("\n");
    }

    free_file(&file);

    return 0;
}