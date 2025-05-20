#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

char **lines;
int num_lines = 0;

void add_line(char *line) {
    lines = realloc(lines, (num_lines + 1) * sizeof(char *));
    lines[num_lines++] = strdup(line);
}

void edit() {
    char buffer[MAX_LINE];
    printf("Editor - Line %d:\n", num_lines);
    fgets(buffer, sizeof(buffer), stdin);
    add_line(buffer);
}

void save() {
    FILE *file = fopen("output.txt", "w");
    for (int i = 0; i < num_lines; ++i) {
        fprintf(file, "%s\n", lines[i]);
    }
    fclose(file);
}

void load() {
    char buffer[MAX_LINE];
    FILE *file = fopen("output.txt", "r");
    while (fgets(buffer, sizeof(buffer), file)) {
        add_line(buffer);
    }
    fclose(file);
}

int main() {
    char command[10];

    load();

    while (1) {
        printf("\nCommands:\n1. Edit\n2. Save\n3. Quit\nEnter command: ");
        scanf("%s", command);

        if (!strcmp(command, "1")) {
            edit();
        } else if (!strcmp(command, "2")) {
            save();
        } else if (!strcmp(command, "3")) {
            break;
        }
    }

    return 0;
}
