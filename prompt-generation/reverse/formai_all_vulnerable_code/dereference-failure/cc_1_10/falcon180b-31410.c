//Falcon-180B DATASET v1.0 Category: File handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 100

typedef struct {
    char *line;
    int length;
} Line;

Line *lines = NULL;
int num_lines = 0;

void add_line(char *new_line) {
    if (num_lines == MAX_NUM_LINES) {
        printf("Error: Maximum number of lines reached.\n");
        return;
    }

    Line *new_line_ptr = (Line *)malloc(sizeof(Line));
    new_line_ptr->line = strdup(new_line);
    new_line_ptr->length = strlen(new_line);

    lines = (Line *)realloc(lines, sizeof(Line) * (num_lines + 1));
    lines[num_lines] = *new_line_ptr;
    free(new_line_ptr);

    num_lines++;
}

void print_lines() {
    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", i + 1, lines[i].line);
    }
}

void free_lines() {
    for (int i = 0; i < num_lines; i++) {
        free(lines[i].line);
    }
    free(lines);
    lines = NULL;
}

int main() {
    char input_buffer[MAX_LINE_LENGTH];

    printf("Enter lines of text (type 'done' to finish):\n");

    while (fgets(input_buffer, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (strcmp(input_buffer, "done") == 0) {
            break;
        }

        add_line(input_buffer);
    }

    printf("Lines of text:\n");
    print_lines();

    free_lines();

    return 0;
}