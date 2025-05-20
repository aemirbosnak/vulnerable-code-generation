//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int line_number;
    int page_number;
    char content[81];
} line;

void display_line(line *line) {
    int i;

    printf("%d |%d|", line->line_number, line->page_number);
    for (i = 0; i < strlen(line->content); i++) {
        putchar(isalpha(line->content[i]) ? line->content[i] + 'A' - 'a' : line->content[i]);
    }
    putchar('\n');
}

int main(int argc, char *argv[]) {
    FILE *file;
    line *lines;
    int lines_count = 0, i = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    lines = malloc(sizeof(line));
    while (fgets(lines[i].content, sizeof(lines[i].content), file)) {
        sscanf(lines[i].content, "%d%d%s", &lines[i].line_number, &lines[i].page_number, lines[i].content);
        lines_count++;

        if (lines_count < 81) {
            lines = realloc(lines, sizeof(line) * (lines_count + 1));
        }
    }

    fclose(file);

    for (i = 0; i < lines_count; i++) {
        display_line(&lines[i]);
    }

    free(lines);
    return 0;
}