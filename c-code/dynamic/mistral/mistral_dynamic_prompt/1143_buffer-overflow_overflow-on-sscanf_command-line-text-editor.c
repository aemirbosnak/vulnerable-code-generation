#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256
#define MAX_LINES 100

char lines[MAX_LINES][MAX_LINE];
int num_lines = 0;

void read_line(int line) {
    char buffer[MAX_LINE];
    if (fgets(buffer, MAX_LINE, stdin) == NULL) {
        lines[line][strlen(lines[line]) - 1] = '\0';
        return;
    }
    strcpy(lines[line], buffer);
    num_lines = (num_lines >= MAX_LINES - 1) ? MAX_LINES - 1 : num_lines;
}

void print_lines() {
    for (int i = 0; i < num_lines; ++i) {
        printf("%d: %s\n", i + 1, lines[i]);
    }
}

int main(int argc, char *argv[]) {
    char command[MAX_LINE];
    int line, i;

    while (1) {
        printf("\n%d> ", num_lines + 1);
        fgets(command, MAX_LINE, stdin);
        sscanf(command, "%*s %d%n", &line, &i);
        if (line < 0 || line > num_lines) line = num_lines;
        if (strcmp(command, "exit\n") == 0) break;
        if (strcmp(command, "save\n") == 0) {
            for (i = 0; i < num_lines; ++i) {
                printf("%s", lines[i]);
                fwrite(lines[i], strlen(lines[i]) + 1, 1, stdout);
            }
            continue;
        }
        if (strcmp(command, "print\n") == 0) print_lines();
        read_line(line - 1);
    }

    return 0;
}
