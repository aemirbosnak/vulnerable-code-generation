//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT_LEVEL 10

typedef struct {
    char *line;
    int length;
    int indent_level;
} line_t;

typedef struct {
    line_t *lines;
    int num_lines;
    int max_indent_level;
} html_t;

html_t *html_new() {
    html_t *html = malloc(sizeof(html_t));
    html->lines = NULL;
    html->num_lines = 0;
    html->max_indent_level = 0;
    return html;
}

void html_free(html_t *html) {
    for (int i = 0; i < html->num_lines; i++) {
        free(html->lines[i].line);
    }
    free(html->lines);
    free(html);
}

int html_parse(html_t *html, FILE *fp) {
    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        int length = strlen(line);
        if (line[length - 1] == '\n') {
            line[length - 1] = '\0';
            length--;
        }
        if (line[0] == '<') {
            indent_level++;
        }
        line_t line_struct;
        line_struct.line = malloc(length + 1);
        strcpy(line_struct.line, line);
        line_struct.length = length;
        line_struct.indent_level = indent_level;
        html->lines = realloc(html->lines, (html->num_lines + 1) * sizeof(line_t));
        html->lines[html->num_lines++] = line_struct;
        if (indent_level > html->max_indent_level) {
            html->max_indent_level = indent_level;
        }
        if (line[0] == '/') {
            indent_level--;
        }
    }
    return 0;
}

void html_beautify(html_t *html) {
    for (int i = 0; i < html->num_lines; i++) {
        line_t *line = &html->lines[i];
        if (line->indent_level > 0) {
            for (int j = 0; j < line->indent_level; j++) {
                printf("    ");
            }
        }
        printf("%s\n", line->line);
    }
}

int main() {
    html_t *html = html_new();
    html_parse(html, stdin);
    html_beautify(html);
    html_free(html);
    return 0;
}