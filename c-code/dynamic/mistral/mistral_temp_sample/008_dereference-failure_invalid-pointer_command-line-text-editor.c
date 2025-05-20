#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

void edit_line(char *line, int line_num) {
    char buffer[MAX_LINE];
    printf("Line %d:\n%s\n", line_num, line);
    printf("Enter new line: ");
    fgets(buffer, MAX_LINE, stdin);
    strcpy(line, buffer);
}

void print_lines(char **lines, int num_lines) {
    for (int i = 0; i < num_lines; ++i) {
        printf("%d: %s\n", i + 1, lines[i]);
    }
}

int main() {
    char *lines[100];
    int num_lines = 0;
    char line[MAX_LINE];

    while (1) {
        printf("> ");
        fgets(line, MAX_LINE, stdin);

        if (strcmp(line, "save\n") == 0) {
            break;
        } else if (strcmp(line, "list\n") == 0) {
            print_lines(lines, num_lines);
        } else if (line[0] >= '1' && line[0] <= '9') {
            int line_num = atoi(line) - 1;
            if (line_num >= num_lines) {
                printf("Invalid line number.\n");
            } else {
                edit_line(lines[line_num], line_num + 1);
            }
        } else {
            lines[num_lines] = (char *) malloc(strlen(line) + 1);
            strcpy(lines[num_lines], line);
            ++num_lines;
        }
    }

    printf("Saving...\n");

    // Dereference invalid pointer
    printf("%s\n", lines[num_lines]);

    return 0;
}
