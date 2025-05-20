//Falcon-180B DATASET v1.0 Category: File handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 10000

typedef struct {
    char *line;
    int line_num;
} Line;

Line *lines = NULL;
int num_lines = 0;

void add_line(char *new_line) {
    Line *new_line_ptr = (Line *)malloc(sizeof(Line));
    new_line_ptr->line = strdup(new_line);
    new_line_ptr->line_num = num_lines;
    lines = realloc(lines, sizeof(Line) * (num_lines + 1));
    lines[num_lines] = *new_line_ptr;
    num_lines++;
}

void print_lines() {
    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", lines[i].line_num, lines[i].line);
    }
}

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        add_line(line);
    }

    fclose(file);

    print_lines();

    for (int i = 0; i < num_lines; i++) {
        free(lines[i].line);
    }
    free(lines);

    return 0;
}