//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *line;
    int length;
    int indent_level;
} line_t;

typedef struct {
    line_t *lines;
    int num_lines;
    int max_indent_level;
} html_document_t;

html_document_t *html_document_new() {
    html_document_t *document = malloc(sizeof(html_document_t));
    document->lines = NULL;
    document->num_lines = 0;
    document->max_indent_level = 0;
    return document;
}

void html_document_free(html_document_t *document) {
    for (int i = 0; i < document->num_lines; i++) {
        free(document->lines[i].line);
    }
    free(document->lines);
    free(document);
}

void html_document_add_line(html_document_t *document, char *line, int indent_level) {
    document->lines = realloc(document->lines, (document->num_lines + 1) * sizeof(line_t));
    document->lines[document->num_lines].line = strdup(line);
    document->lines[document->num_lines].length = strlen(line);
    document->lines[document->num_lines].indent_level = indent_level;
    document->num_lines++;
    if (indent_level > document->max_indent_level) {
        document->max_indent_level = indent_level;
    }
}

void html_document_print(html_document_t *document) {
    for (int i = 0; i < document->num_lines; i++) {
        printf("%*s%s", document->lines[i].indent_level * 2, "", document->lines[i].line);
    }
}

int main() {
    html_document_t *document = html_document_new();

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    int indent_level = 0;

    while ((nread = getline(&line, &len, stdin)) != -1) {
        if (line[nread - 1] == '\n') {
            line[nread - 1] = '\0';
        }

        if (strcmp(line, "<") == 0) {
            indent_level++;
        } else if (strcmp(line, "</") == 0) {
            indent_level--;
        }

        html_document_add_line(document, line, indent_level);
    }

    free(line);

    html_document_print(document);

    html_document_free(document);

    return 0;
}