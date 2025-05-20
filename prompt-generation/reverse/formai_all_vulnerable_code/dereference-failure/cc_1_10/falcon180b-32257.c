//Falcon-180B DATASET v1.0 Category: Error handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LENGTH 80
#define MAX_NUM_LINES 1000
#define MAX_NUM_CHARS 1000

typedef struct {
    char *line;
    int line_num;
} Line;

Line *lines = NULL;
int num_lines = 0;

void add_line(char *line, int line_num) {
    if (num_lines >= MAX_NUM_LINES) {
        fprintf(stderr, "Error: too many lines (max %d)\n", MAX_NUM_LINES);
        exit(1);
    }
    if (strlen(line) > MAX_LINE_LENGTH) {
        fprintf(stderr, "Error: line too long (max %d chars)\n", MAX_LINE_LENGTH);
        exit(1);
    }
    Line *new_line = malloc(sizeof(Line));
    new_line->line = strdup(line);
    new_line->line_num = line_num;
    lines = realloc(lines, sizeof(Line) * ++num_lines);
    lines[num_lines - 1] = *new_line;
}

void print_lines() {
    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", lines[i].line_num, lines[i].line);
    }
}

int main() {
    FILE *file = fopen("test.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file (%s)\n", strerror(errno));
        exit(1);
    }
    char line[MAX_LINE_LENGTH];
    int line_num = 1;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        add_line(line, line_num);
        line_num++;
    }
    fclose(file);
    print_lines();
    return 0;
}