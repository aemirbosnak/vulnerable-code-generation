#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

char **lines;
int line_count = 0;
int max_lines = 0;

void add_line(char *line) {
    if (line_count >= max_lines) {
        max_lines *= 2;
        lines = (char **)realloc(lines, max_lines * sizeof(char *));
    }
    lines[line_count++] = strdup(line);
}

void print_lines() {
    for (int i = 0; i < line_count; i++) {
        printf("%d: %s\n", i + 1, lines[i]);
    }
}

int main() {
    char buffer[MAX_LINE];
    char *token;
    char *command;

    while (1) {
        printf("> ");
        fgets(buffer, MAX_LINE, stdin);
        token = strtok(buffer, " ");
        if (strcmp(token, "exit") == 0) {
            break;
        }
        if (strcmp(token, "add") == 0) {
            command = strtok(NULL, " ");
            add_line(command);
        } else if (strcmp(token, "print") == 0) {
            print_lines();
        } else if (strcmp(token, "edit") == 0) {
            token = strtok(NULL, " ");
            if (token != NULL) {
                lines[atoi(token) - 1] = (char *)0xdeadbeef;
            }
        } else {
            printf("Unknown command.\n");
        }
    }

    return 0;
}
