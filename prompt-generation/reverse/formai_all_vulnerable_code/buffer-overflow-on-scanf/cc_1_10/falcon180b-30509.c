//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int line_num;
} Line;

int main() {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    Line lines[MAX_NUM_LINES];
    int num_lines = 0;
    int line_num = 1;
    int i;

    printf("Enter the name of the log file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_lines >= MAX_NUM_LINES) {
            printf("Error: too many lines in file %s\n", filename);
            exit(1);
        }
        lines[num_lines].line = strdup(line);
        lines[num_lines].line_num = line_num;
        num_lines++;
        line_num++;
    }

    fclose(file);

    printf("Enter the word to search for: ");
    scanf("%s", line);

    for (i = 0; i < num_lines; i++) {
        if (strstr(lines[i].line, line)!= NULL) {
            printf("Line %d: %s\n", lines[i].line_num, lines[i].line);
        }
    }

    for (i = 0; i < num_lines; i++) {
        free(lines[i].line);
    }

    return 0;
}