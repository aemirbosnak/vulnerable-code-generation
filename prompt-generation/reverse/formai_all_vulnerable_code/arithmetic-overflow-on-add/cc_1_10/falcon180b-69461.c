//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_LINE_NUMBER 100000

typedef struct {
    char *text;
    int line_number;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
    int current_line;
} File;

void add_line(File *file, char *text) {
    Line *line = malloc(sizeof(Line));
    line->text = text;
    line->line_number = file->num_lines;
    file->lines = realloc(file->lines, sizeof(Line) * (file->num_lines + 1));
    file->lines[file->num_lines] = *line;
    file->num_lines++;
}

int main() {
    FILE *input_file = fopen("input.html", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    File file = {0};
    char *line = NULL;
    size_t line_capacity = 0;
    ssize_t line_length;

    while ((line_length = getline(&line, &line_capacity, input_file))!= -1) {
        if (line_length == 0) {
            continue;
        }

        char *text = malloc(line_length + 1);
        memcpy(text, line, line_length);
        text[line_length] = '\0';

        if (strstr(text, "<html")!= NULL) {
            file.current_line = 0;
        }

        add_line(&file, text);
    }

    fclose(input_file);

    for (int i = 0; i < file.num_lines; i++) {
        printf("%4d: %s\n", file.lines[i].line_number, file.lines[i].text);
    }

    return 0;
}