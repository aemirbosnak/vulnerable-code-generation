#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 10
#define MAX_CHARS_PER_LINE 256

char lines[MAX_LINES][MAX_CHARS_PER_LINE];
int num_lines = 0;

void edit_line(int line) {
    char input[MAX_CHARS_PER_LINE];
    printf("Line %d:\n", line + 1);
    fgets(input, MAX_CHARS_PER_LINE, stdin);
    strcpy(lines[line], input);
}

void display_lines() {
    for (int i = 0; i < num_lines; ++i) {
        printf("%d: %s\n", i + 1, lines[i]);
    }
}

int main() {
    char command[5];
    int line = -1;

    while (1) {
        printf("text_editor> ");
        fgets(command, 5, stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "list") == 0) {
            display_lines();
        } else if (line >= 0) {
            edit_line(line);
        } else if (sscanf(command, "%d", &line) == 1) {
            if (line >= num_lines) {
                num_lines = line + 1;
                lines[line][0] = 0;
                edit_line(line);
            }
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
