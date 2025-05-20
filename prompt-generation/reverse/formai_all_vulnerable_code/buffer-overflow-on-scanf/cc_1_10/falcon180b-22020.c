//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 10000

typedef struct {
    char *line;
    int line_num;
} LogLine;

void read_log_file(FILE *fp, LogLine *lines, int *num_lines) {
    char line[MAX_LINE_LENGTH];
    int line_num = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        lines[line_num].line = strdup(line);
        lines[line_num].line_num = line_num;
        line_num++;
    }

    *num_lines = line_num;
}

void print_log_lines(LogLine *lines, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", lines[i].line_num, lines[i].line);
    }
}

void free_log_lines(LogLine *lines, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        free(lines[i].line);
    }
    free(lines);
}

int main() {
    FILE *fp;
    char filename[MAX_LINE_LENGTH];
    LogLine lines[MAX_NUM_LINES];
    int num_lines;

    printf("Enter log file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    read_log_file(fp, lines, &num_lines);

    printf("Log file contents:\n");
    print_log_lines(lines, num_lines);

    free_log_lines(lines, num_lines);

    fclose(fp);

    return 0;
}