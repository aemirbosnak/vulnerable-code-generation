//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int line_num;
} Line;

Line *lines = NULL;
int num_lines = 0;

void add_line(char *line, int line_num) {
    if (num_lines >= MAX_NUM_LINES) {
        printf("Error: Maximum number of lines reached.\n");
        exit(1);
    }
    lines = realloc(lines, sizeof(Line) * ++num_lines);
    lines[num_lines - 1].line = strdup(line);
    lines[num_lines - 1].line_num = line_num;
}

void print_lines() {
    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", lines[i].line_num, lines[i].line);
    }
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LEN];
    int line_num = 1;

    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        add_line(line, line_num);
        line_num++;
    }

    fclose(fp);
    print_lines();

    return 0;
}