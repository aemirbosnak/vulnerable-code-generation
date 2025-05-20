#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINES 100
#define LINE_SIZE 256

char lines[MAX_LINES][LINE_SIZE];
int num_lines = 0;

void write_line(int index, char *line) {
    strcpy(lines[index], line);
    num_lines++;
}

void display() {
    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", i + 1, lines[i]);
    }
}

int main() {
    char buffer[LINE_SIZE];
    char command[10];
    int index;

    while (1) {
        printf("> ");
        fgets(buffer, LINE_SIZE, stdin);
        sscanf(buffer, "%s %s", command, buffer);

        if (!strcmp(command, "quit")) {
            break;
        } else if (!strcmp(command, "write")) {
            write_line(num_lines, buffer);
        } else if (!strcmp(command, "display")) {
            display();
        } else if (sscanf(command, "read %d", &index) == 1) {
            if (index >= num_lines) {
                printf("Error: Invalid line number.\n");
            } else {
                printf("%s\n", lines[index - 1]);
            }
        } else {
            printf("Invalid command. Supported commands are 'quit', 'write', 'read' and 'display'.\n");
        }
    }

    return 0;
}
