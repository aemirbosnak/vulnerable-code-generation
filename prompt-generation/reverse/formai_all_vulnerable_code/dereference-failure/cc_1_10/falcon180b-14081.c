//Falcon-180B DATASET v1.0 Category: File handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int line_num;
} Line;

Line lines[MAX_NUM_LINES];
int num_lines = 0;

void add_line(char *line_str, int line_num) {
    Line *new_line = (Line *)malloc(sizeof(Line));
    new_line->line = strdup(line_str);
    new_line->line_num = line_num;
    lines[num_lines++] = *new_line;
}

int main() {
    FILE *fp;
    char ch;
    int line_num = 1;

    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error: Failed to open file.\n");
        return 1;
    }

    while ((ch = fgetc(fp))!= EOF) {
        char line[MAX_LINE_LENGTH];
        int i = 0;

        while (ch!= '\n' && i < MAX_LINE_LENGTH) {
            line[i++] = ch;
            ch = fgetc(fp);
        }

        line[i] = '\0';
        add_line(line, line_num);
        line_num++;
    }

    fclose(fp);

    // Print the lines in reverse order
    for (int i = num_lines - 1; i >= 0; i--) {
        printf("%d: %s\n", lines[i].line_num, lines[i].line);
    }

    return 0;
}