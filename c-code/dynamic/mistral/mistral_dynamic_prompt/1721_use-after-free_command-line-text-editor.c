#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_CHARS 256

char **lines;
int num_lines = 0;

void add_line(char *line) {
    if (num_lines == MAX_LINES) {
        lines = realloc(lines, (MAX_LINES + 1) * sizeof(char *));
    }
    lines[num_lines] = strdup(line);
    num_lines++;
}

void display() {
    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i]);
    }
}

int main() {
    char buffer[MAX_CHARS];
    char *input;
    char command[MAX_CHARS];

    lines = (char **)malloc(MAX_LINES * sizeof(char *));

    while (1) {
        printf("> ");
        fgets(buffer, MAX_CHARS, stdin);
        input = strdup(buffer);

        char *token = strtok(input, " \t\n");
        strcpy(command, token);

        if (!strcmp(command, "quit")) {
            break;
        } else if (!strcmp(command, "add")) {
            token = strtok(NULL, " \t\n");
            add_line(token);
        } else if (!strcmp(command, "display")) {
            display();
        } else {
            printf("Unknown command\n");
        }

        free(input);
    }

    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}
