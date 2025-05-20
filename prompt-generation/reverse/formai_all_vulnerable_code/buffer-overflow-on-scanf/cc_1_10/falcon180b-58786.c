//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_LINE_NUMBER 1000
#define MAX_FILENAME_LENGTH 80

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char line[MAX_LINE_LENGTH];
    int line_number;
} Line;

void sanitize_line(Line *line) {
    int i = 0;
    while (line->line[i]) {
        if (line->line[i] == '<') {
            line->line[i] = '&lt;';
        } else if (line->line[i] == '>') {
            line->line[i] = '&gt;';
        } else if (line->line[i] == '&') {
            line->line[i] = '&amp;';
        }
        i++;
    }
}

void sanitize_file(Line *lines, int num_lines) {
    int i = 0;
    while (i < num_lines) {
        sanitize_line(&lines[i]);
        i++;
    }
}

int main() {
    FILE *file;
    Line lines[MAX_LINE_NUMBER];
    int num_lines = 0;
    char filename[MAX_FILENAME_LENGTH];
    char line[MAX_LINE_LENGTH];
    char buffer[MAX_LINE_LENGTH];

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_lines >= MAX_LINE_NUMBER) {
            printf("Error: maximum number of lines reached.\n");
            fclose(file);
            return 1;
        }
        strcpy(lines[num_lines].filename, filename);
        strcpy(lines[num_lines].line, line);
        lines[num_lines].line_number = num_lines + 1;
        num_lines++;
    }

    fclose(file);

    sanitize_file(lines, num_lines);

    printf("The sanitized file is:\n");

    for (int i = 0; i < num_lines; i++) {
        printf("%s:%d - %s\n", lines[i].filename, lines[i].line_number, lines[i].line);
    }

    return 0;
}