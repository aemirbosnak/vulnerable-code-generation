#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

void read_line(char *line, int max_line) {
    char c;
    int i = 0;

    while ((c = getchar()) != EOF && i < max_line - 1) {
        line[i] = c;
        i++;
    }

    line[i] = '\0';
}

void print_lines(char **lines, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i]);
    }
}

void write_to_file(char *filename, char **lines, int num_lines) {
    FILE *file = fopen(filename, "w");

    for (int i = 0; i < num_lines; i++) {
        fprintf(file, "%s\n", lines[i]);
    }

    fclose(file);
}

int main() {
    char *lines[10];
    int num_lines = 0;
    char line[MAX_LINE];

    while (1) {
        printf("> ");
        read_line(line, MAX_LINE);

        if (strcmp(line, "save") == 0) {
            write_to_file("editor.txt", lines, num_lines);
            break;
        } else if (strcmp(line, "quit") == 0) {
            break;
        } else {
            lines[num_lines] = (char *) malloc(strlen(line) + 1);
            strcpy(lines[num_lines], line);
            num_lines++;
        }

        printf("\n");
    }

    print_lines(lines, num_lines);

    return 0;
}
