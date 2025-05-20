//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    int linenumber;
    char *line;
} Line;

void print_metadata(Line *lines, int num_lines) {
    printf("Filename: %s\n", lines[0].filename);
    printf("Number of lines: %d\n", num_lines);
    printf("First line: %s\n", lines[0].line);
    printf("Last line: %s\n", lines[num_lines - 1].line);
}

int main() {
    char filename[MAX_LINE_LENGTH];
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int linenumber = 0;
    Line *lines = NULL;
    int num_lines = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        linenumber++;
        if (num_lines == 0) {
            lines = (Line *) malloc(sizeof(Line));
            lines[0].filename = strdup(filename);
            lines[0].line = strdup(line);
            lines[0].linenumber = linenumber;
            num_lines++;
        } else {
            lines = (Line *) realloc(lines, sizeof(Line) * (num_lines + 1));
            lines[num_lines - 1].filename = strdup(filename);
            lines[num_lines - 1].line = strdup(line);
            lines[num_lines - 1].linenumber = linenumber;
            num_lines++;
        }
    }

    fclose(file);

    print_metadata(lines, num_lines);

    for (int i = 0; i < num_lines; i++) {
        printf("Line %d: %s\n", lines[i].linenumber, lines[i].line);
        free(lines[i].filename);
        free(lines[i].line);
    }

    free(lines);

    return 0;
}