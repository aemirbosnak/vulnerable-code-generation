#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

void edit_line(char *line, int line_num) {
    char buffer[MAX_LINE];
    printf("Line %d:\n", line_num);
    fgets(buffer, MAX_LINE, stdin);
    strcpy(line, buffer);
}

int main() {
    char *lines[10];
    char *current_line = NULL;
    int num_lines = 0;

    while (1) {
        printf("\nText Editor\n");
        printf("Type 'exit' to quit.\n");
        printf("Enter a line number to edit or 'new' to create a new line:\n");
        char command[MAX_LINE];
        fgets(command, MAX_LINE, stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "new") == 0) {
            if (num_lines == 10) {
                printf("Maximum number of lines reached.\n");
            } else {
                lines[num_lines] = malloc(MAX_LINE);
                current_line = lines[num_lines];
                num_lines++;
                edit_line(current_line, num_lines);
            }
        } else {
            int line_num = atoi(command);
            if (line_num > 0 && line_num <= num_lines) {
                current_line = lines[line_num - 1];
                edit_line(current_line, line_num);
            } else {
                printf("Invalid line number.\n");
            }
        }
    }

    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }

    return 0;
}
