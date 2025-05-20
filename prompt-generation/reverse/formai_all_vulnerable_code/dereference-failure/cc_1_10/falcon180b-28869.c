//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *line;
    size_t length;
} Line;

typedef struct {
    Line *lines;
    size_t count;
} Text;

void add_line(Text *text, const char *line) {
    if (text->count >= MAX_LINE_LENGTH) {
        printf("Error: Too many lines!\n");
        exit(1);
    }

    size_t line_length = strlen(line);
    Line *new_line = malloc(sizeof(Line));
    new_line->line = malloc(line_length + 1);
    strcpy(new_line->line, line);
    new_line->length = line_length;

    text->lines = realloc(text->lines, sizeof(Line) * (text->count + 1));
    text->lines[text->count] = *new_line;
    text->count++;
}

void print_text(const Text *text) {
    for (size_t i = 0; i < text->count; i++) {
        printf("%s\n", text->lines[i].line);
    }
}

int main() {
    Text text = {0};

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, stdin)!= NULL) {
        add_line(&text, buffer);
    }

    print_text(&text);

    return 0;
}