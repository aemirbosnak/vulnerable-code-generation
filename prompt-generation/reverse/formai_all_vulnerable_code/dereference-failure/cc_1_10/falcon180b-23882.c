//Falcon-180B DATASET v1.0 Category: Error handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} Text;

int read_lines(FILE *file, Text *text) {
    Line *line = NULL;
    int num_lines = 0;
    char buffer[MAX_LINE_LENGTH];

    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        int length = strlen(buffer);
        if (length > 0 && buffer[length - 1] == '\n') {
            buffer[--length] = '\0';
        }

        Line *new_line = realloc(line, sizeof(Line) * ++num_lines);
        if (new_line == NULL) {
            fprintf(stderr, "Error: Failed to allocate memory for line.\n");
            exit(EXIT_FAILURE);
        }
        line = new_line;

        line[num_lines - 1].line = strdup(buffer);
        line[num_lines - 1].length = length;
    }

    text->lines = line;
    text->num_lines = num_lines;

    return num_lines;
}

void print_text(Text *text) {
    for (int i = 0; i < text->num_lines; i++) {
        printf("%s\n", text->lines[i].line);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Error: Invalid number of arguments.\n");
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open file '%s'.\n", argv[1]);
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    Text text = {NULL, 0};
    int num_lines = read_lines(file, &text);

    fclose(file);

    if (num_lines == 0) {
        fprintf(stderr, "Error: File is empty.\n");
        return EXIT_FAILURE;
    }

    print_text(&text);

    for (int i = 0; i < text.num_lines; i++) {
        free(text.lines[i].line);
    }
    free(text.lines);

    return EXIT_SUCCESS;
}