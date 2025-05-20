//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000

typedef struct {
    char* line;
    int line_num;
} Line;

int num_lines = 0;
Line* lines = NULL;

void add_line(char* new_line) {
    if (num_lines == MAX_NUM_LINES) {
        printf("Error: Maximum number of lines reached.\n");
        return;
    }

    Line* new_line_struct = (Line*)malloc(sizeof(Line));
    new_line_struct->line = strdup(new_line);
    new_line_struct->line_num = num_lines;

    lines = (Line*)realloc(lines, sizeof(Line) * (num_lines + 1));
    lines[num_lines] = *new_line_struct;
    num_lines++;
}

void print_line(int line_num) {
    if (line_num < 0 || line_num >= num_lines) {
        printf("Error: Line number out of range.\n");
        return;
    }

    printf("%d: %s\n", line_num, lines[line_num].line);
}

void free_lines() {
    for (int i = 0; i < num_lines; i++) {
        free(lines[i].line);
    }
    free(lines);
}

int main() {
    char* buffer = NULL;
    size_t buffer_size = 0;

    while (getline(&buffer, &buffer_size, stdin)!= -1) {
        add_line(buffer);
    }

    printf("Enter a line number to print:\n");
    int line_num;
    scanf("%d", &line_num);
    print_line(line_num);

    free_lines();

    return 0;
}