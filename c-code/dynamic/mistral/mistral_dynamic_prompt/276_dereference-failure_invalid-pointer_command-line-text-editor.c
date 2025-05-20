#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100
#define MAX_LINES 10

char *lines[MAX_LINES];
int line_count = 0;

void add_line(char *line) {
    if (line_count == MAX_LINES) {
        printf("Editor is full.\n");
        return;
    }
    lines[line_count] = malloc(strlen(line) + 1);
    strcpy(lines[line_count], line);
    line_count++;
}

void display() {
    for (int i = 0; i < line_count; ++i) {
        printf("%s\n", lines[i]);
    }
}

int main() {
    char buffer[BUFFER_SIZE];
    char *current_line = lines[line_count - 1];
    char *cursor = current_line + strlen(current_line);

    while (1) {
        printf("\nEditor (%d/%d): %.*s$ ", line_count, MAX_LINES, (int)(cursor - current_line), current_line);

        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) break;

        if (strlen(buffer) == 1 && buffer[0] == '\n') {
            if (cursor != current_line) --cursor;
            continue;
        }

        if (strlen(buffer) + (cursor - current_line) >= BUFFER_SIZE) {
            printf("Buffer overflow!\n");
            return 1;
        }

        strcpy(cursor, buffer);
        add_line(current_line);
        current_line = lines[line_count - 1];
        cursor = current_line + strlen(current_line);
    }

    free(lines);
    return 0;
}
