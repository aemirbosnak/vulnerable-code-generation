//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 10000

typedef struct {
    char *text;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
    int current_line;
} Text;

void append_text(Text *text, char *str) {
    if (text->current_line >= text->num_lines) {
        text->num_lines += 10;
        text->lines = realloc(text->lines, sizeof(Line) * text->num_lines);
    }
    Line *line = &text->lines[text->current_line];
    strncpy(line->text + line->length, str, MAX_LINE_LENGTH - line->length);
    line->length += strlen(str);
}

void print_text(Text *text) {
    for (int i = 0; i < text->num_lines; i++) {
        Line *line = &text->lines[i];
        printf("%s\n", line->text);
    }
}

void free_text(Text *text) {
    for (int i = 0; i < text->num_lines; i++) {
        free(text->lines[i].text);
    }
    free(text->lines);
}

int main() {
    FILE *input_file = fopen("input.html", "r");
    if (input_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    Text text = {NULL, 0, 0};
    char ch;
    while ((ch = fgetc(input_file))!= EOF) {
        if (ch == '\n') {
            append_text(&text, "\n");
        } else {
            char *str = malloc(2);
            str[0] = ch;
            str[1] = '\0';
            append_text(&text, str);
        }
    }

    fclose(input_file);

    print_text(&text);

    free_text(&text);

    return 0;
}