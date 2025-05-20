//Falcon-180B DATASET v1.0 Category: File handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 100000

typedef struct {
    char *line;
    int line_num;
} Line;

int main() {
    FILE *fp;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    Line lines[MAX_NUM_LINES];
    int num_lines = 0;
    int i;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (num_lines >= MAX_NUM_LINES) {
            printf("Error: too many lines in file.\n");
            exit(1);
        }
        lines[num_lines].line = strdup(line);
        lines[num_lines].line_num = num_lines + 1;
        num_lines++;
    }

    fclose(fp);

    printf("Enter search string: ");
    scanf("%s", line);

    for (i = 0; i < num_lines; i++) {
        if (strstr(lines[i].line, line)!= NULL) {
            printf("%d: %s\n", lines[i].line_num, lines[i].line);
        }
    }

    for (i = 0; i < num_lines; i++) {
        free(lines[i].line);
    }

    return 0;
}