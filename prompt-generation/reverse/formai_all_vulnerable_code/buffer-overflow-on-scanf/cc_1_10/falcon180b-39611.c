//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINES 1000
#define MAX_LINE_LENGTH 1024

typedef struct {
    char *line;
    int line_num;
} LogLine;

int main() {
    FILE *fp;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    LogLine log_lines[MAX_LOG_LINES];
    int num_lines = 0;
    int i;

    printf("Enter the name of the log file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (num_lines >= MAX_LOG_LINES) {
            printf("Error: Log file contains more than %d lines\n", MAX_LOG_LINES);
            fclose(fp);
            return 1;
        }
        log_lines[num_lines].line = strdup(line);
        log_lines[num_lines].line_num = num_lines + 1;
        num_lines++;
    }

    fclose(fp);

    printf("Log file analysis:\n");
    for (i = 0; i < num_lines; i++) {
        printf("%d: %s\n", log_lines[i].line_num, log_lines[i].line);
    }

    for (i = 0; i < num_lines; i++) {
        free(log_lines[i].line);
    }

    return 0;
}