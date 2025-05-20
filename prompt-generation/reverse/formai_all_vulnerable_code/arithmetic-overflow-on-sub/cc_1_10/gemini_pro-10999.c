//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

typedef struct {
    char *line;
    int len;
    int indent;
} line_t;

typedef struct {
    line_t *lines;
    int num_lines;
} html_t;

html_t *html_init() {
    html_t *html = malloc(sizeof(html_t));
    html->lines = NULL;
    html->num_lines = 0;
    return html;
}

void html_free(html_t *html) {
    for (int i = 0; i < html->num_lines; i++) {
        free(html->lines[i].line);
    }
    free(html->lines);
    free(html);
}

void html_add_line(html_t *html, char *line, int len, int indent) {
    html->lines = realloc(html->lines, (html->num_lines + 1) * sizeof(line_t));
    html->lines[html->num_lines].line = malloc(len + 1);
    strncpy(html->lines[html->num_lines].line, line, len);
    html->lines[html->num_lines].line[len] = '\0';
    html->lines[html->num_lines].len = len;
    html->lines[html->num_lines].indent = indent;
    html->num_lines++;
}

void html_beautify(html_t *html) {
    int in_tag = 0;
    int in_attr = 0;
    int in_comment = 0;
    int indent = 0;

    for (int i = 0; i < html->num_lines; i++) {
        line_t *line = &html->lines[i];

        if (in_comment) {
            if (strstr(line->line, "-->")) {
                in_comment = 0;
            }
            continue;
        }

        if (strstr(line->line, "<!--")) {
            in_comment = 1;
            continue;
        }

        if (in_attr) {
            if (line->line[line->len - 1] == '"') {
                in_attr = 0;
            }
            continue;
        }

        if (strstr(line->line, "&#")) {
            continue;
        }

        if (strstr(line->line, "&#x")) {
            continue;
        }

        if (strstr(line->line, "<!--")) {
            continue;
        }

        if (strstr(line->line, "-->")) {
            continue;
        }

        if (strstr(line->line, "<!DOCTYPE")) {
            continue;
        }

        if (strstr(line->line, "<!ELEMENT")) {
            continue;
        }

        if (strstr(line->line, "<!ATTLIST")) {
            continue;
        }

        if (strstr(line->line, "<!ENTITY")) {
            continue;
        }

        if (strstr(line->line, "<!NOTATION")) {
            continue;
        }

        if (strstr(line->line, "<?xml")) {
            continue;
        }

        if (strstr(line->line, "<?xm")) {
            continue;
        }

        if (strstr(line->line, "<?PI")) {
            continue;
        }

        if (strstr(line->line, "<?C")) {
            continue;
        }

        if (strstr(line->line, "<?D")) {
            continue;
        }

        if (strstr(line->line, "<?F")) {
            continue;
        }

        if (strstr(line->line, "<?M")) {
            continue;
        }

        if (strstr(line->line, "<?S")) {
            continue;
        }

        if (strstr(line->line, "<?T")) {
            continue;
        }

        if (strstr(line->line, "<?V")) {
            continue;
        }

        if (strstr(line->line, "<?X")) {
            continue;
        }

        if (strstr(line->line, "<?Y")) {
            continue;
        }

        if (strstr(line->line, "<?Z")) {
            continue;
        }

        if (strstr(line->line, "<![CDATA[")) {
            continue;
        }

        if (strstr(line->line, "]]")) {
            continue;
        }

        if (strstr(line->line, "<")) {
            if (in_tag) {
                indent++;
            }
            in_tag = 1;
        } else if (strstr(line->line, ">")) {
            if (in_tag) {
                indent--;
            }
            in_tag = 0;
        } else if (strstr(line->line, "=")) {
            in_attr = 1;
        }

        line->indent = indent;
    }
}

void html_print(html_t *html) {
    for (int i = 0; i < html->num_lines; i++) {
        line_t *line = &html->lines[i];
        for (int j = 0; j < line->indent; j++) {
            printf("    ");
        }
        printf("%s", line->line);
    }
}

int main() {
    html_t *html = html_init();

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, stdin)) != -1) {
        html_add_line(html, line, read - 1, 0);
    }

    html_beautify(html);
    html_print(html);

    html_free(html);
    return 0;
}