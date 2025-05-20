//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define INDENT_SIZE 4
#define TRUE 1
#define FALSE 0

typedef struct {
    char *text;
    int length;
    int indent;
} line;

void add_line(line **lines, int *num_lines, char *text, int indent) {
    line *new_line = (line *)malloc(sizeof(line));

    new_line->text = strdup(text);
    new_line->length = strlen(text);
    new_line->indent = indent;

    (*lines)[*num_lines] = *new_line;
    (*num_lines)++;
}

void print_lines(line *lines, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        for (int j = 0; j < lines[i].indent; j++) {
            printf(" ");
        }
        printf("%s\n", lines[i].text);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char *line_text = NULL;
    size_t line_size = 0;
    ssize_t line_len;
    int indent = 0;
    int in_pre = FALSE;
    line *lines = NULL;
    int num_lines = 0;

    while ((line_len = getline(&line_text, &line_size, file))!= -1) {
        char *text = line_text;
        int text_len = line_len;

        while (text_len > 0 && isspace(text[0])) {
            text++;
            text_len--;
        }

        if (text_len == 0) {
            continue;
        }

        if (text[0] == '<' && text[1] == 'p' && text[2] == 'r' && text[3] == 'e' && text[4] == '>') {
            in_pre = TRUE;
        } else if (text[0] == '<' && text[1] == '/' && text[2] == 'p' && text[3] == 'r' && text[4] == 'e' && text[5] == '>') {
            in_pre = FALSE;
        }

        if (in_pre) {
            add_line(&lines, &num_lines, text, indent);
        } else {
            add_line(&lines, &num_lines, text, indent + INDENT_SIZE);
        }

        if (text_len > MAX_LINE_LENGTH) {
            indent += INDENT_SIZE;
        } else {
            indent = 0;
        }
    }

    fclose(file);

    print_lines(lines, num_lines);

    for (int i = 0; i < num_lines; i++) {
        free(lines[i].text);
    }
    free(lines);

    return 0;
}