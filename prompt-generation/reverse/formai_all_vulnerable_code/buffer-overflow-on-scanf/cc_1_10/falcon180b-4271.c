//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 100
#define MAX_LINE_SIZE 1000

typedef struct {
    char file_name[MAX_FILE_NAME_SIZE];
    int line_number;
    char line[MAX_LINE_SIZE];
} Line;

void add_line(Line *lines, int num_lines, char *file_name, int line_number, char *line) {
    if (num_lines >= MAX_FILE_NAME_SIZE) {
        printf("Error: Maximum number of lines reached.\n");
        return;
    }

    strncpy(lines[num_lines].file_name, file_name, MAX_FILE_NAME_SIZE);
    lines[num_lines].line_number = line_number;
    strncpy(lines[num_lines].line, line, MAX_LINE_SIZE);

    num_lines++;
}

void print_lines(Line *lines, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        printf("File: %s, Line: %d, Text: %s\n", lines[i].file_name, lines[i].line_number, lines[i].line);
    }
}

int main() {
    char file_name[MAX_FILE_NAME_SIZE];
    FILE *file;
    char line[MAX_LINE_SIZE];
    Line lines[MAX_FILE_NAME_SIZE];
    int num_lines = 0;

    printf("Enter the name of the file to recover data from: ");
    scanf("%s", file_name);

    file = fopen(file_name, "r");

    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, "\n");
        int line_number = 1;

        while (token!= NULL) {
            add_line(lines, num_lines, file_name, line_number, token);
            line_number++;

            token = strtok(NULL, "\n");
        }
    }

    fclose(file);

    if (num_lines == 0) {
        printf("No data found in file.\n");
    } else {
        print_lines(lines, num_lines);
    }

    return 0;
}