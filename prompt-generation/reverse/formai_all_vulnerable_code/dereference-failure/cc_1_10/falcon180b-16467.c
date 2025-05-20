//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_DEPTH 1000

typedef struct {
    char *line;
    int indent;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
    int depth;
} HTML;

HTML *html_parse(FILE *fp) {
    HTML *html = malloc(sizeof(HTML));
    html->lines = malloc(MAX_LINE_LENGTH * sizeof(Line));
    html->num_lines = 0;
    html->depth = 0;

    char line[MAX_LINE_LENGTH];
    int indent = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        Line *l = &html->lines[html->num_lines++];
        l->line = malloc(strlen(line) + 1);
        strcpy(l->line, line);
        l->indent = indent;

        if (line[0] == '<') {
            indent++;
        } else if (line[0] == '>') {
            indent--;
        }
    }

    return html;
}

void html_beautify(HTML *html) {
    int i;
    for (i = 0; i < html->num_lines; i++) {
        Line *l = &html->lines[i];
        int spaces = 4 * l->indent;
        printf("%*s%s\n", spaces, "", l->line);
    }
}

void html_free(HTML *html) {
    int i;
    for (i = 0; i < html->num_lines; i++) {
        free(html->lines[i].line);
    }
    free(html->lines);
    free(html);
}

int main(int argc, char *argv[]) {
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    HTML *html = html_parse(fp);
    fclose(fp);

    html_beautify(html);

    html_free(html);

    return 0;
}