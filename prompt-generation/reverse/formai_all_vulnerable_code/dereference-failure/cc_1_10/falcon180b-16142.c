//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_INDENT_LEVEL 10
#define INDENT_SIZE 4

typedef struct {
    char *text;
    int indent;
} Line;

void indent(int level, char *buffer) {
    int i;
    for (i = 0; i < level; i++) {
        strcat(buffer, "    ");
    }
}

void beautify(Line *lines, int num_lines) {
    int i, j, indent_level = 0;
    char buffer[MAX_LINE_LENGTH + 1];
    for (i = 0; i < num_lines; i++) {
        if (lines[i].text[0] == '<') {
            indent_level++;
        } else if (lines[i].text[0] == '>') {
            indent_level--;
        }
        if (indent_level > MAX_INDENT_LEVEL) {
            indent_level = MAX_INDENT_LEVEL;
        }
        if (indent_level < 0) {
            indent_level = 0;
        }
        indent(indent_level, buffer);
        strcat(buffer, lines[i].text);
        strcat(buffer, "\n");
        lines[i].text = strdup(buffer);
    }
}

int main() {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    Line *lines = NULL;
    int num_lines = 0;
    file = fopen("example.html", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    while ((getline(&line, &len, file))!= -1) {
        lines = realloc(lines, sizeof(Line) * ++num_lines);
        lines[num_lines - 1].text = strdup(line);
    }
    beautify(lines, num_lines);
    for (int i = 0; i < num_lines; i++) {
        printf("%s", lines[i].text);
    }
    free(line);
    for (int i = 0; i < num_lines; i++) {
        free(lines[i].text);
    }
    free(lines);
    return 0;
}